#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;


struct LessThan{

    LessThan(int n) : val(n) {}

    bool operator()(int checker){
        return checker < val;
    }
        int val;

};

template <typename Iterator, typename Predicate, typename Value>

void replace_if(Iterator start, Iterator end, Predicate pred, Value val){

    for(Iterator iter = start; start != end; ++iter){
        if(pred(*iter)){
            *iter = val;
        }
    }
}




struct Node {
    Node(int data = 0, Node* next = nullptr): data(data), next(next) {}
    int data;
    Node* next;
};

vector<Node*> split_list(Node* head, int target) {
    vector<Node*> result;
    Node* current = head;
    Node* sublist_head = head;

    while (current) {
        if (current->data == target) {
            Node* next_head = current->next;  
            current->next = nullptr;          
            
            result.push_back(sublist_head);   
            
            sublist_head = next_head;         
            current = next_head;             
        } else {
            current = current->next;          
        }
    }

    if (sublist_head) {
        result.push_back(sublist_head);
    }

    return result;
}




class Vector {
public:
    // Constructor to initialize the Vector with a dynamic array
    Vector(size_t size) : size(size), data(new int[size]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = 0; // Initialize all elements to 0
        }
    }

    // Destructor to free allocated memory
    ~Vector() {
        delete[] data;
    }

    // begin() method returns a pointer to the first element
    int* begin() {
        return data;
    }

    // end() method returns a pointer to just past the last element
    int* end() {
        return data + size;
    }

    // Const versions for use with const objects
    const int* begin() const {
        return data;
    }

    const int* end() const {
        return data + size;
    }

class Iterator{

friend bool operator!=(const Iterator& lhs, const Iterator&rhs){
    return lhs.current != rhs.current;

}

public:
    Iterator(int* ptr) : current(ptr){}

    int& operator*() const {
        return *current;
    }

    Iterator& operator++() {
        ++current;

        return *this;

    }

private:
    int* current;

};

private:
    size_t size; // Number of elements in the Vector
    int* data;   // Pointer to dynamically allocated array
};

void increaseValues(Vector& vec) {
    for (int& val : vec) { // Uses range-based for loop
        val += 1831;
    }
}




int main() {


    // Vector vec(5); // Vector with 5 elements

    // // Display original values
    // std::cout << "Original values: ";
    // for (int val : vec) {
    //     std::cout << val << " ";
    // }
    // std::cout << "\n";

    // // Increase values by 1831
    // increaseValues(vec);

    // // Display updated values
    // std::cout << "Updated values: ";
    // for (int val : vec) {
    //     std::cout << val << " ";
    // }
    // std::cout << "\n";

    // return 0;




    // list<string> all_strings{};
    // string longest = "";

    // for(list<string>::iterator iter = all_strings.begin(); iter != all_strings.end(); ++iter){

    //     if((*iter).size() > longest.size()){
    //         longest = *iter;
    //     }

    // }
    // cout << longest << endl;





}
