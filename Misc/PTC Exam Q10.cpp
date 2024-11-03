#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



//Write a function that increments all the elemetns of a passed in vector ofi nts. you must ust a ranged-based for loop to increment the elements.
void increment(vector<int>& vect){

    for(int& num : vect){
        num += 1;
    }
}