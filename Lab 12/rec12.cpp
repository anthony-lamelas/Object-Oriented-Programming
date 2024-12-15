// Doubly linked list
// Anthony Lamelas rec12 doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
using namespace std;

class List {
    struct Node;
    friend ostream& operator<<(ostream& os, const List& rhs);

public:

    class Iterator{
        friend List;

        friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
            return lhs.current != rhs.current;
        }

        public:
            Iterator(Node* p) : current(p) {}
            
            Iterator& operator++() {
                current = current->next;
                return *this;
            }

            Iterator& operator--(){
                current = current->prev;
                return *this;
            }

            int& operator*() const {return current->data;}

        private:
            Node* current;

    };

    class constIterator{
        friend List;

        friend bool operator!=(const constIterator& lhs, 
        const constIterator& rhs) {

            return lhs.current != rhs.current;
        }

        public:
            constIterator(Node* p) : current(p) {}
            
            constIterator& operator++() {
                current = current->next;
                return *this;
            }

            constIterator operator--(){
                current = current->prev;
                return *this;
            }

            int& operator*() const {return current->data;}

        private:
            Node* current;

    };

    //Iterator Methods

    Iterator begin() {return Iterator(header->next);}
    constIterator begin() const {return constIterator(header->next);}

    Iterator end() {return Iterator(trailer);}
    constIterator end() const {return constIterator(trailer);}

    Iterator insert(const Iterator& IterNext, int data){
        Node* next = IterNext.current;
        next->prev = new Node(data, next->prev, next);
        next->prev->prev->next = next->prev;
        ++size;
        return Iterator(next->prev);
    }

    Iterator erase(const Iterator& erasee){
        Node* current = erasee.current;
        Node* previous = current->prev;
        Node* next = current->next;

        next->prev = previous;
        previous->next = next;

        delete current;
        --size;

        return Iterator(next);
    }

    List() : size(0), header(new Node()), trailer(new Node()) {
        header->next = trailer;
        trailer->prev = header;
    }

    //List Methods

    void push_back(int data){
        insert(end(), data);
    }

    void pop_back(){
        if (size){
            erase(--end());
        }
    }

    void push_front(int data){
        insert(begin(), data);
    }

    void pop_front(){
        if(size){
            erase(begin());
        }
    }

    int front() const {
        return header->next->data;
    }

    int& front(){
        return header->next->data;
    }

    int back() const {
        return trailer->prev->data;
    }

    int& back(){
        return trailer->prev->data;
    }

    int getSize() const {
        return size;
    }

    void clear(){
        Iterator iterator = begin();

        while(iterator != end()){
            iterator = erase(iterator);
        }
    }

    int operator[](size_t index) const{
        constIterator iterator = begin();

        for(size_t i = 0; i < index; ++i){
            ++iterator;
        }
        return *iterator;
    }

    int& operator[](size_t index){
        Iterator iterator = begin();

        for(size_t i = 0; i < index; ++i){
            ++iterator;
        }
        return *iterator; 
    }


    //Copy Control
    ~List(){
        cout << "~List()" << endl;
        clear();
        delete trailer;
        delete header;
    }

    List(const List& rhs) : size(0), header(new Node()), 
    trailer(new Node()) {

       header->next = trailer;
       trailer->prev = header;

       for(int data : rhs){
            push_back(data);
       }
    }

    List& operator=(const List& rhs){
        if(&rhs != this){
            cout << "List::op=(List)" << endl;
            clear();

            for(int data : rhs){
                push_back(data);
            }
        }
        return *this;
    }


private:
    struct Node {
        Node(int data = 0, Node* prev = nullptr, Node* next = nullptr) :
        data(data), prev(prev), next(next) {}

        int data;
        Node* prev;
        Node* next;
    };

    int size;
    Node* header;
    Node* trailer;
};

ostream& operator<<(ostream& os, const List& rhs){
    for (int data : rhs){
        os << data << " ";
    }
    return os;
}

bool operator==(const List::Iterator& lhs, const List::Iterator& rhs) {
    return !(lhs != rhs);
}

bool operator==(const List::constIterator& lhs,
                const List::constIterator& rhs) {
    return !(lhs != rhs);
}

// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.getSize()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList) {
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList) {
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.getSize(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << "Leaving doNothing\n";
}    

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    
    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.getSize()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.getSize()) {
        printListInfo(myList);
        myList.pop_front();
    }
    printListInfo(myList);
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.getSize() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.getSize(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.getSize(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.getSize(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);
    

    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::Iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";
    
    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.getSize()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}
