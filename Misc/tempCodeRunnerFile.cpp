template <typename Iter, typename Pred>

// int count(Iter begin, Iter end, Pred predicate){
//     int count = 0;

//     for (Iter it = begin; it != end; ++it){
//         if(predicate(*it)){
//             count++;
//         }
//     }
//     return count;
// }

// int baseThree(int val){

//     if(val % 3 == 0){
//         return;
//     }

//     baseThree(val / 3);

//     cout << (val % 3);
// }


// struct TernNode {int data; TernNode *left, *mid, *right; };

// int treeMin(TernNode* root){


//     if(!root){
//         throw invalid_argument("no root");
//     }

//     int minVal = root->data;

//     if(!root->left && !root->right && !root->mid){
//         return minVal;
//     }

//     if(root->right){
//         if(treeMin((root->right)) < minVal){
//             minVal = treeMin((root->right));
//         }
//     }

//     if(root->left){
//         if(treeMin((root->left)) < minVal){
//             minVal = treeMin((root->left));
//         } 
//     }

//     if(root->mid){
//         if(treeMin((root->mid)) < minVal){
//             return treeMin((root->mid));
//         } 
//     }

//     return minVal;
// }


// #include <iostream>
// using namespace std;

// class SLL {  // SLL is short for Singly Linked List
//     struct Node {
//         Node(int data = 0, Node* next = nullptr) : data(data), next(next), prev(prev) {}
//         int data;
//         Node* next;