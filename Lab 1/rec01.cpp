//Anthony Lamelas



/*
  rec01_start.cpp
  spring 2024
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


//
// Function prototypes for tasks 15-17
//

// Task 15. Function to display a vector of ints

  void printVector (const std::vector<int> & vec) {
    for (int num : vec){
      std::cout << num << std::endl;
    }
  }

// Task 16. Function to modify the vector, using indices

void modVector (const std::vector<int> & vec){

}



// Task 17. Function to modify the vector, using a ranged for




//
// main
//
int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"

    std:: cout << "Task 1: Hello World \n";

    // Task 2  Printing hello ...  Using "using namespace"
    using namespace std;

    cout << "Task 2: Hello World \n" << endl;


    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable
    int x;
    cout <<"Task 3" << x << endl;

    
    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.


    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;

    cout << "\nSize of int:" <<sizeof(x) << endl;
    cout << "\nSize of int:" <<sizeof(y) << endl;
    cout << "\nSize of int:" <<sizeof(z) << endl;
    cout << "\nSize of int:" <<sizeof(pie) << endl;

    
    // Task 5  Attempt to assign the wrong type of thing to a variable

    //x = "felix";

    //
    // Conditions
    //

    // Task 6  Testing for a range

        if (y >= 10 && y <= 20){
          cout << "Task 6: True\n" << endl;
        }  else {
          cout << "Task 6: False\n" << endl;
        } 

    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop
      cout << "Task 7:" << endl;

    for (int i = 10; i<21; i++){
      cout << i << endl;
    }

    // Then with a while loop
    int i = 10;
    while (i<21) {
      cout << i << endl;
      i++;
    }

    // Finally with a do-while loop << i
    i = 10;
    do {
      cout << i << endl;
      i++;
    } while (i<21);


    // Task 8  Looping to successfully open a file, asking user for the name
    ifstream ifs;

    do{
      string filename;
      cout<<"What is the file name?";
      cin>> filename;
      ifs.open(filename);
    } while(!ifs);

    string line;
    getline(ifs, line);
    cout << line <<endl;

    
    
    // Task 9  Looping, reading file word by "word".

    string word;
    while (ifs >> word) {
      cout << word << endl;
    }

    ifs.close();
    // Task 10 Open a file of integers, read it in, and display the sum.

    ifstream numbers;
    int sum = 0;
    string filename2 = "integers.txt";

    if (!numbers){
      cerr << "File not found." << endl;
      exit(1);
    }
    numbers.open(filename2); 

    int num;
    while(numbers >> num){
      sum += num;
    }   
    cout << "Task 10: " << sum << endl;

    numbers.close();


    // Taks 11 Open and read a file of integers and words. Display the sum.

    ifstream mixed;
    int sum2 = 0;
    string filename3 = "mixed.txt";

    if (!mixed){
      cerr << "File not found." << endl;
      exit(1);
    }

    mixed.open(filename3); 

    int num2;
    while(mixed >> num2){
      sum2 += num2;
    }   
    cout << "Task 11: " << sum2 << endl;

    mixed.close();

    //
    // Vectors
    //

    // Task 12 Filling a vector of ints

    vector<int> vectInts;

    for(int i = 10; i <101; i+=2){
      vectInts.push_back(i);
    }
    
    // Task 13 Displaying the vector THREE times
    //         a) using the indices,
                cout << "Task 13a" << endl;
                for(int i = 0; i < vectInts.size(); i++){
                  cout << vectInts[i] << endl;
                }

    //         b) using a "ranged for"
                cout << "Task 13b" << endl;
                for (int x : vectInts){
                  cout << x << endl;
                }

    //         c) using indices again but backwards
                cout << "Task 13c" << endl;
                
                for (size_t i = vectInts.size(); i > 0; i--){
                  cout << vectInts[i - 1] << endl;
                }

    // Task 14. Initialize a vector with the primes less than 20. 

          vector<int> primes{2,3,5,7,9,11,13,17,19};

          for (int value : primes){
            cout << value << endl;
          }

    //
    // Function calls
    //
    
    // Task 15  Function to print a vector


    // Task 16  Function to double the values in a vector


    // Task 17  Function to double the values in a vector, using a ranged for 

    
}

//
// Function definitions for tasks 15-17
//

// Task 15. Function to display a vector of ints




// Task 16. Function to modify the vector, using indices



// Task 17. Function to modify the vector, using a ranged for


