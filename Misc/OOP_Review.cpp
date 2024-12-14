#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;



//Iterators

//begin() is first element
//end() is after last element works for for adding to last element
// for (iterator iter = myList.begin(); iter != myList.end() ++iter)
// for (List::Iterator iter = myList.begin(); iter != myList.end() ++iter)

//When defining iterator class you need:
//Node* current in private
//operator*
//operator++
//operator==
//operator!=


//Templates

// template <typename T>

// or

/* template <typename T, typename U> can receive different datatypes as arguments
--in this case the return type needs to be set as auto
*/

template <typename Iter, typename Pred>

int count(Iter startRange, Iter endRange, Pred pred){

    int result = 0;

   for(Iter it = startRange; it != endRange; ++it){
        if predicate(*it){
            ++count;
        }
    }
    return count;
}


//STL algorithms

//half open range
/*
includes begin but excludes end
vector<int> v = {1, 2, 3, 4};
sort(v.begin(), v.begin() + 3); // Sorts first 3 elements
*/

//sort
//sorts a range


 //find
 //finds a specific element
 
 
//find_if
//finds element mathcing a condition (predicate function)


//functors
//Function object, overloads () operator

struct MultiplyBy {
    int factor; // The state: a factor to multiply by
    MultiplyBy(int f) : factor(f) {} // Constructor to set the factor

    int operator()(int x) const { // Overload () operator
        return x * factor;
    }
};

int main() {
    MultiplyBy multiplyBy2(2); // Functor instance with factor = 2
    MultiplyBy multiplyBy5(5); // Functor instance with factor = 5
    MultiplyBy multiplyBy3(3); // Functor instance with factor = 3


    cout << multiplyBy2(10) << endl; // Output: 20
    cout << multiplyBy5(3) << endl;  // Output: 15

    vector<int> nums = {1, 2, 3, 4};
    for (int num : nums) {
        cout << multiplyBy3(num) << " "; // Output: 3 6 9 12
    }

}



//lambda expressions
//define custom logic inline, very concise
//[capture](parameters) -> return_type { body }
auto isEven = [](int x) { return x % 2 == 0; }; // Lambda to check even numbers


//auto (do not use on exam unless specified)
//Deduces types automatically

//pair
//Holds two values
//pair<int, string>


//map
//key,value pairs, basically a dictionary


//set
//Unique ordered elements
//no duplicates are allowed, automatically sorted, faster than list


//Try/catch
// try block for you code that might THROW an eception
// cathc block handles the exception (makes code not crash)
// catch(...) is for all errors

int main() {
    try {
        int x = 10, y = 0;
        if (y == 0) throw "Division by zero!"; // Throw exception
        cout << x / y;
    } catch (const char* err) {
        cout << "Error: " << err << endl; // Handle exception
    }
    return 0;
}

//throw
// signals an exception has occurred, program then jumps to catch block


//exception hierarchy
//runtime_error, logic_error, bad_alloc, out_of_range, etc.

//assert
//debuggin tool that checks condition at runtime and terminates program
// if the condition is false
//NDEBUG, if you define it then assert statements are disabled
// #define NDEBUG


#include <cassert>
int main() {
    int x = 10, y = 0;
    assert(y != 0 ); // Terminates if y == 0
    cout << x / y;
    return 0;
}