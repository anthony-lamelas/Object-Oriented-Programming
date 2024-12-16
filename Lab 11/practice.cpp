#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//
//  From linked list library in the course's sample code
//
struct Node {
    int data = 0;
    Node* next = nullptr;
};



//Reverse

Node* reverse(Node* head) {
    Node* newHead = nullptr;
    while (head != nullptr) {
        Node* newNode = new Node{head->data, nullptr}; // Create a new node
        newNode->next = newHead; // Add it to the front of the new list
        newHead = newNode;
        head = head->next;
    }
    return newHead;
}




//Reverse In Place
void reverseInPlace(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Save the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to the next node
    }

    head = prev; // Update head to the new front
}

//Is Sublist

Node* isSublist(Node* head, Node* sub) {

    while (head != nullptr) {
        Node* current = head;
        Node* tempSub = sub;

        // Try matching sublist starting from the current node
        while (current != nullptr && tempSub != nullptr && current->data == tempSub->data) {
            current = current->next;
            tempSub = tempSub->next;
        }

        // If we matched the entire sublist, return the starting node
        if (tempSub == nullptr) {
            return head;
        }

        // Move to the next node in the main list
        head = head->next;
    }

    return nullptr; // Sublist not found
}
