#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <utility>
using namespace std;
//defined molecule structure
struct moleculeStorage{
    int numCarbs;
    int numHydros;
    vector<string> moleculeNames;
};
//function prototypes
void getFile(fstream& inputFileStream);
void fillVector(vector<moleculeStorage>& moleculeVector, fstream& inputFileStream);
void vectorInsertMolecule(vector<moleculeStorage>& moleculeVector, int carbs, int hydros, string moleculeName);
int getVectorLocation(vector<moleculeStorage>& moleculeVector, int carbs, int hydros);
void printMolecule(const moleculeStorage& m);
void printMoleculeStorageVector(const vector<moleculeStorage>& moleculeVectorStorage);
bool molecule_LT(moleculeStorage mol1, moleculeStorage mol2);
void sortVector(vector<moleculeStorage>& moleculeVectorStorage);
//main
int main(){
    fstream ifs("");
    getFile(ifs);
    vector<moleculeStorage> moleculeVectorStore;
    fillVector(moleculeVectorStore, ifs);
    printMoleculeStorageVector(moleculeVectorStore);
    sortVector(moleculeVectorStore);
    printMoleculeStorageVector(moleculeVectorStore);
}

//function to ask for file and open filestream
void getFile(fstream& inputFileStream){
    while(!inputFileStream){
        cout << "enter filename\n";
        string fileName;
        cin >> fileName;
        inputFileStream.open(fileName);
    }
}
//function to push molecules from filestream into vector
void fillVector(vector<moleculeStorage>& moleculeVector, fstream& inputFileStream){
    while(inputFileStream){
        string moleculeName;
        string moleculeFormula;
        char letterChecker;
        int hydro;
        int carb;
        inputFileStream >> moleculeName >> letterChecker >> carb >> letterChecker >> hydro;
        vectorInsertMolecule(moleculeVector, carb, hydro, moleculeName);
    }
}
//helper to push molecules to vector
void vectorInsertMolecule(vector<moleculeStorage>& moleculeVector, int carbs, int hydros, string moleculeName){
    int location = getVectorLocation(moleculeVector, carbs, hydros);
    if(location == moleculeVector.size()){
        moleculeStorage newMolecule;
        newMolecule.numCarbs=carbs;
        newMolecule.numHydros=hydros;
        newMolecule.moleculeNames.push_back(moleculeName);
        moleculeVector.push_back(newMolecule);
    }
    else{
        moleculeVector[location].moleculeNames.push_back(moleculeName);
    }
}
//helper to find the location to which new molecule should be pushed in vector
int getVectorLocation(vector<moleculeStorage>& moleculeVector, int carbs, int hydros){
    for(size_t i = 0; i < moleculeVector.size(); i++){
        if((moleculeVector[i].numCarbs == carbs) && (moleculeVector[i].numHydros == hydros)){
            return i;
        }
    }
    return moleculeVector.size();
}
//helper to print an individual molecule
void printMolecule(const moleculeStorage& moleculeVector){
    cout << 'C' << moleculeVector.numCarbs << 'H' << moleculeVector.numHydros;
    for (string moleculeName : moleculeVector.moleculeNames){
        cout << " " << moleculeName;
    }
    cout << '\n';
}
//loops through vector to print all molecules
void printMoleculeStorageVector(const vector<moleculeStorage>& moleculeVectorStorage){
    for(const moleculeStorage& molecule : moleculeVectorStorage){
        printMolecule(molecule);
    }
}
//sorts the vector using selection sort
void sortVector(vector<moleculeStorage>& moleculeVectorStorage){
    for(size_t i = 0; i < moleculeVectorStorage.size(); i++){
        size_t min_index = i;
        for (size_t j = i+1; j < moleculeVectorStorage.size(); j++){
            if (molecule_LT(moleculeVectorStorage[j], moleculeVectorStorage[min_index])){
                min_index = j;
            }
        }
        swap(moleculeVectorStorage[min_index], moleculeVectorStorage[i]);
    }
}
//helper function for the sorting algorithm to compare two molecules by carbon/hydrogen values
bool molecule_LT(moleculeStorage mol1, moleculeStorage mol2){
    if(mol1.numCarbs < mol2.numCarbs){
        return true;
    }
    else if ((mol1.numCarbs == mol2.numCarbs) && (mol1.numHydros < mol2.numHydros)){
        return true;
    }
    return false;
}