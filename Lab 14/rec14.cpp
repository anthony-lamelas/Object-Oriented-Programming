/*
  rec14_starter code
 */

#include <iostream>
#include <vector>
#include <algorithm>  // max
using namespace std;


// Node type for the linked list
struct Node {
    int data = 0;
    Node* next = nullptr;
};

// Node type for the ternary tree
struct TNode {
    int data = 0;
    TNode* left = nullptr;
    TNode* mid = nullptr;
    TNode* right = nullptr;
};



/////////////////////////////////////////////////////////////////////////
//
// Provided code for use in testing
//
void listPrint(const Node* headPtr);
void listClear(Node*& headPtr);
Node* listBuild(const vector<int>& vals);


//
// Your functions go here
//
//   Task 1 function:
Node* listSum(Node* L1, Node* L2) {
    if (!L1 && !L2) {
        return nullptr;

    } else if (L1 && L2) {
        Node* newNode = new Node;
        newNode->data = L1->data + L2->data;
        newNode->next = listSum(L1->next, L2->next);
        return newNode;

    } else if (L1 && !L2) {
        Node* newNode = new Node;
        newNode->data = L1->data;
        newNode->next = listSum(L1->next, nullptr);
        return newNode;

    } else if (!L1 && L2){
        Node* newNode = new Node;
        newNode->data = L2->data;
        newNode->next = listSum(nullptr, L2->next);
        return newNode;
    }
}

//   Task 2 function:
int treeMax(TNode* root){
    if (!root) throw invalid_argument("The tree is empty, so there cannot be a maximum");

    int maxValue = root->data;

    if(root->left){
        maxValue = max(maxValue, treeMax(root->left));
    }

    if(root->mid){
        maxValue = max(treeMax(root->mid), maxValue);
    }

    if(root->right){
        maxValue = max(treeMax(root->right), maxValue);
    }

    return maxValue;
}

//   Task 3 function:
bool palindrome(char* arr, int length){
    if (length < 2){
        return true;
    }

    char* left = arr;
    char* right = arr + length - 1;

    if(*left != *right){
        return false;
    }

    return palindrome(left + 1, length -2);
}

//   Task 4 function:
bool parity(int number){

    if (number < 0) throw invalid_argument("The integer is negative, this is not allowed.");

    if(number == 0){
        return true;
    }
    //even returns true

    return (number%2 == 0) == parity(number/2);
}


//   Task 5 function:
int towers(int n, char start, char target, char spare){
    if (n == 0) return 0;
    int moves = 2 * towers(n - 1, start, spare, target) + 1;
    return moves;

}

void mystery(int n) { 
   if (n > 1) { 
      cout << 'a'; 
      mystery(n/2); 
      cout << 'b'; 
      mystery(n/2); 
   } 
   cout << 'c'; 
}

//0
// c
 
//1
// c

//2
// a c b c c

//3
// a c b c c
 
//4
// a a c b c c b a c b c c c

//5 
// a a c b c c b a c b c c c

//6 
// a a c b c c b a c b c c c

//7
// a a c b c c b a c b c c c

//8
// a a a c b c c b a c b c c c b a a c b c c b a c b c c c c

//9
// a a a c b c c b a c b c c c b a a c b c c b a c b c c c c

//10
// a a a c b c c b a c b c c c b a a c b c c b a c b c c c c


int main() {
    // We have provided some test code to save you time. Certainly feel
    // free to write more!

    // Task 1:
    cout << "\n==============\n#1: Testing listSum\n";
    Node* l1 = listBuild({2, 7, 1, 8});
    cout << "List (l1): ";
    listPrint(l1);
    
    Node* l2 = listBuild({9, 1, 4, 1});
    cout << "List (l2): ";
    listPrint(l2);

    Node* l3 = listBuild({3, 1, 4, 1, 5, 9});
    cout << "List (l3): ";
    listPrint(l3);

    cout << "The sum of l1 and l2: ";
    Node* l4 = listSum(l1, l2);
    listPrint(l4);

    cout << "The sum of l1 and l3: ";
    Node* l5 = listSum(l1, l3);
    listPrint(l5);

    cout << "The sum of l3 and l1: ";
    Node* l6 = listSum(l3, l1);
    listPrint(l6);

    listClear(l1);
    listClear(l2);
    listClear(l3);
    listClear(l4);
    listClear(l5);
    listClear(l6);


    
    // Task 2:
    cout << "\n==============\n"
         << "#2) Testing max of Tree.\n";
    TNode a{1}, b{2}, c{4}, d{-8, &a, &b, &c}, e{-16}, f{-32, &d, &e};
    cout << "treeMax(&f): " << treeMax(&f) << endl;

    // How do you keep this from crashing? try/catch! Here in main!
    try{
        cout << treeMax(nullptr) << endl;
    } catch (...){
        cout << "Caught an error" << endl;
    }
    

    
    // Task 3:
    cout << "\n==============\n"
	 << "#3) Testing palindrome\n";
    cout << boolalpha
	 << "palindrome(\"racecar\", 7): " << palindrome("racecar", 7) << endl
	 << "palindrome(\"noon\", 4): " << palindrome("noon", 4) << endl
	 << "palindrome(\"raceXar\", 7): " << palindrome("raceXar", 7) << endl
	 << "palindrome(\"noXn\", 4): " << palindrome("noXn", 4) << endl;
    
    // Task 4:
    cout << "\n==============\n"
	 << "#4) Are there an even number of 1's in binary representation?\n";
    cout << boolalpha;
    for (int i = 0; i < 10; ++i) {
        cout << i << ": " << parity(i) << endl;
    }


    
    // Task 5:
    cout << "\n==============\n"
	 << "#5) How many moves are required for various sized towers?";
    for (int i = 1; i < 30; ++i) {
	cout << "towers(" << i << ", 'a', 'b', 'c'): " 
	     << towers(i, 'a', 'b', 'c') << endl;
    }

    // mystery(4);
    // cout << endl;
    // mystery(5);
    // cout <<endl;
   
}

//
// The provided utility functions:
//

// listPrint prints out the data values in the list.
// All the values are printed on a single line with blanks separating them.
void listPrint(const Node* headPtr)
{
    const Node* curr = headPtr;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
} // listPrint

// listClear frees up all of the nodes in list setting the the head
// pointer to null.
void listClear(Node*& headPtr)
{
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
} // listClear

// listBuild returns a list with the same values as in the vector.
Node* listBuild(const vector<int>& vals)
{
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
	result = new Node{vals[index-1], result};
    }
    return result;
} // listBuild
