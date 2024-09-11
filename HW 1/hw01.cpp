/*
Anthony Lamelas
hw01.cpp
September 9, 2024
CS2124 24F
Decrypts text encoded with Casesar cypher 
*/

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


//Returns decrypted character given the encrypted character and rotation distance
//Only works for uppercase characters
char decryptChar(char& letter, int distance) {
    if (distance >= 26) {
        distance %= 26;
    }

    if (letter >= 'A' and letter <= 'Z') {
        letter -= distance;
      if (letter < 'A') {
        letter += 26; //Wrap if necessary
        } else if (letter > 'Z') {
        letter -= 26; //Wrap if necessary
        }
    }
    return letter;   
}

//Takes a string and changes it using decryptChar
//Returns nothing
void decryptLine(string& line, int distance) {
    for (char& letter : line){
        decryptChar(letter, distance);
    }
}

int main() {
    //Checks if file exists
    ifstream encrypted("encrypted.txt");
    if (!encrypted) {
        cerr << "Failed to open encrypted";
        exit(1);
    }
    //Gets the distance of each letter to be rotated from the first line
    int distance;
    encrypted >> distance;

    //Iterates through the file and saves each line into a vector
    string line;
    vector <string> lines;
    while (getline(encrypted, line)) {
        lines.push_back(line);
    }
    encrypted.close();

    //Decrypts lines in vector in reverse order
     for (size_t index = lines.size() - 1; index > 0; index--) {
        decryptLine(lines[index], distance);
        cout << lines[index] << endl;
    }
}