// intlist.cpp
// Implements class IntList
// Mihir Kondapalli, 2/3/24

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    
    if(source.first==nullptr)
    {
        first = nullptr;
    }
    else
    {
        first = new Node;
        Node* copy_temp = source.first;
        first->info = copy_temp->info;
        Node* temp = first;
        copy_temp = copy_temp->next;
        while(copy_temp!=nullptr)
        {
            temp->next = new Node;
            temp->next->info = copy_temp->info;
            temp = temp->next;
            copy_temp = copy_temp->next;
        }

        temp->next = nullptr;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* temp = first;
    Node* deltemp;
    while(temp!=nullptr)
    {
        deltemp = temp;
        temp = temp->next;
        delete deltemp;
    }
}


// return sum of values in list
int IntList::sum() const {
    Node* temp = first;
    int sum = 0;
    while(temp!=nullptr)
    {
        sum+=temp->info;
        temp = temp->next;
    }

    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* temp = first;
    
    while(temp!=nullptr)
    {
        if(temp->info == value)
        {
            return true;
        }
    }

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {

    if(first==nullptr){
        return 0;
    }
    
    int max = first->info;

    Node* temp = first->next;
    while(temp!=nullptr)
    {
        if(temp->info > max)
        {
            max = temp->info;
        }
        temp = temp->next;
    }

    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    return (double) sum() / count();
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* new_first = new Node;
    new_first->info = value;
    new_first->next = first;
    first = new_first;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    
    Node* del_temp = first;
    first = nullptr;
    while(del_temp!=nullptr)
    {
        Node* curr = del_temp;
        del_temp = del_temp->next;
        delete curr;
    }
    
    Node* copy_temp = source.first;
    
    while(copy_temp != nullptr)
    {
        append(copy_temp->info);
        copy_temp = copy_temp->next;
    }

    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
