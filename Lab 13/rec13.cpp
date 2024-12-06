// rec13_start.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;


void printListRF(const list<int>& my_list){
    for(const int val : my_list){
        cout << val << " ";
    }
    cout << endl;
}

void printListIter(const list<int>& my_list){

    for(list<int>::const_iterator iter = my_list.begin(); iter != my_list.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
}

void printListAuto(const list<int>& my_list){
    for(auto iter = my_list.begin(); iter != my_list.end(); ++++iter){
        cout << *iter << " ";
    } 
    cout << endl;
}

auto findVal(const list<int>& my_list, int val){
    for(auto iter = my_list.begin(); iter != my_list.end(); ++iter){
        if(*iter == val){
            return iter;
        }
    }
    return my_list.end();
}

bool pred(int n) {return (n % 2) == 0; }

class Predicate{
    public:
        bool operator()(int n) {return (n % 2) == 0; }
};

list<int>::iterator ourFind(list<int>::iterator start, list<int>::iterator end, int value) {
    cout << "Using ourFind for lists of ints" << endl;

    for (auto iter = start; iter != end; ++iter) {
        if (*iter == value) {
            return iter;
        }
    }
    return end;
}

template <typename Range, typename Target>
Range ourFind(Range begin, Range end, Target target){
        cout << "Using ourFind template" << endl;

    for (Range r = begin; r != end; ++r){
        if (*r == target){
            return r;
        }
    }
    return end;
}

void countUniqueVec(const string& file){
    ifstream ifs(file);
    string current;
    vector<string> seen;

    while(ifs >> current){
        if(find(seen.begin(),seen.end(),current) == seen.end()){
            seen.push_back(current);
        }
    }
    ifs.close();

    cout << "There were " << seen.size() << " unique words." << endl;

    // for(const string& each : seen){
    //     cout << each;
    // }
    cout << endl;
}

void countUniqueSet(const string& file){

    ifstream ifs(file);
    string current;
    set<string> seen;

    while(ifs >> current){
        if(find(seen.begin(),seen.end(),current) == seen.end()){
            seen.insert(current);
        }
    }

    cout << "There were " << seen.size() << " unique words." << endl;
    ifs.close();

    // for(const string& each : seen){
    //     cout << each;
    // }
    cout << endl;
}

void countUniqueMap(const string& file){

    ifstream ifs(file);
    string current;
    map<string, vector<int>> seen;
    int location = 0;

    while(ifs >> current){
        ++location;
        seen[current].push_back(location);
    }

    ifs.close();
    cout << "There were " << seen.size() << " unique words." << endl;

//     for (const auto& entry : seen) {
//         const string& word = entry.first;
//         const vector<int>& positions = entry.second;
    
//     cout << word << ": ";
//     for (int pos : positions) {
//         cout << pos << " ";
//     }
//     cout << endl;
// }

}



int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";

    vector<int> values = {1, 2, 4, 8};

    for(const int val : values){
        cout << val << " ";
    }

    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";

    list<int> myList(values.begin(), values.end());

    for(const int val : myList){
        cout << val << " ";
    }

    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";

    sort(values.begin(), values.end());
    for(const int val : values){
        cout << val << " ";
    }

    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";

    for(size_t i = 0; i < values.size(); i += 2){
        cout << values[i] << " ";
    }

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";

    // for(size_t i = 0; i < myList.size(); i += 2){
    //     cout << myList[i] << " ";
    // }

    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";

    for (vector<int>::iterator iter = values.begin(); iter != values.end(); iter += 2){
        cout << *iter << " ";
    }

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";

    for (list<int>::iterator iter = myList.begin(); iter != myList.end(); ++++iter){
        cout << *iter << " ";
    }

    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    
    myList.sort();

    for (list<int>::iterator iter = myList.begin(); iter != myList.end(); ++iter){
        cout << *iter << " ";
    }

    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";

    printListIter(myList);

    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";

    printListRF(myList);

    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alternate
    // items in the list
    cout << "Task 11:\n";

    printListAuto(myList);

    cout << "=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";

    cout << *findVal(myList, 2) << endl;

    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";

    cout << *findVal(myList, 5) << endl;

    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";

    auto it = find(myList.begin(), myList.end(), 2);
    if (it != myList.end()) {
        cout << *it << std::endl;
    } else {
        cout << "Value not found!\n";
    }

    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";

    auto iterr = find_if(myList.begin(),myList.end(),pred);
    if (it != myList.end()) {
        cout << *iterr << std::endl;
    } else {
        cout << "Value not found!\n";
    }

    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";

    auto iterrr = find_if(myList.begin(),myList.end(),Predicate());
    if (it != myList.end()) {
        cout << *iterrr << std::endl;
    } else {
        cout << "Value not found!\n";
    }

    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";

    auto iterrrr = find_if(myList.begin(),myList.end(), [](int n) {return (n % 2) == 0; });
    if (it != myList.end()) {
        cout << *iterrrr << std::endl;
    } else {
        cout << "Value not found!\n";
    }

    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";

    int* arr = new int[4];
    copy(myList.begin(),myList.end(), arr);

     for (size_t i = 0; i < 4; ++i) {
        cout << arr[i];
    }
    delete[] arr;
    cout << endl;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";

    cout << *ourFind(myList.begin(),myList.end(), 2) << endl;

    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";

    cout << *ourFind(myList.begin(),myList.end(), 2) << endl;

    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";

    countUniqueVec("pooh-nopunc.txt");

    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";

    countUniqueSet("pooh-nopunc.txt");

    cout << "=======\n";

    // 23. Word co-occurence using map
    cout << "Task 23:\n";

    countUniqueMap("pooh-nopunc.txt");

    cout << "=======\n";
}
