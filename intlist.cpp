// intlist.cpp
// Implements class IntList
// Mukhil Thavathiru Murugan, AND 1/12/26

#include "intlist.h"

#include <iostream>
using std::cout;

// default constructor sets up empty list
IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}


// destructor deletes all nodes
IntList::~IntList() {
    Node* current = head;
	while (current != nullptr){
		Node* temp = current->next;
		delete current;
		current = temp;
	}
	head = nullptr;
	tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
	Node* current = head;
	int sum = 0;
	if (current != nullptr){
		while(current != nullptr){
			sum += current->info;
			current = current->next;
		}
		return sum;
	}
	else{
	return 0;
	}
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
	Node* current = head;
	if (current != nullptr){
		while(current != nullptr){
			if(current -> info == value){
				return true;
			}
			current = current->next;
		}
	}
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
	Node* current = head;
	if (current != nullptr){
	int max_val = current->info;
		while(current != nullptr){
			if(current -> info > max_val){
				max_val = current -> info;
			}
			current = current->next;
		}
		return max_val;
	}
    return 0;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
	Node* current = head;
	double sum = 0;
	int counter = 0;
	if (current != nullptr){
		while(current != nullptr){
		sum += current->info;
		counter += 1;
		current = current->next;
		}
		return sum/counter;
	}

    return 0.0; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
	Node* insert = new Node;
	insert->info = value;
	insert->next = nullptr;
	if (head != nullptr){
		insert->next = head;
	}
	head = insert;
}

// append value at end of list
void IntList::push_back(int value) {
	Node* push_back_node = new Node;
	push_back_node->info = value;
	push_back_node->next = nullptr;
    if(head == nullptr){
		head = push_back_node;
	}
	else{
		Node* current = head;
		while(current->next != nullptr){
			current = current->next;
		}
		current->next = push_back_node;
	}

}

// return count of values
int IntList::count() const {
	Node* current = head;
	int count = 0;
   if(head != nullptr){
		while(current -> next != nullptr){
			count += 1;
			current = current->next;
		}
	return count + 1;
	}
	else{
	return 0;
	}
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
	if(this == &source){
    	return *this;
	}
	Node* current = head;
    while(current != nullptr){
		Node* temp = current->next;
        delete current;
        current = temp;
	}
	head = nullptr;
	tail = nullptr;
	if(source.head == nullptr){
		return *this;
	}
	head = new Node();
	head->info = source.head->info;
	head->next = nullptr;

	Node* this_current = head;
	Node* source_current = source.head->next;


	while(source_current != nullptr){
		Node* newNode = new Node();
		newNode->info = source_current->info;
		newNode->next = nullptr;
		this_current->next = newNode;

		this_current = this_current->next;
		source_current = source_current->next;
	}
	tail = this_current;
	return *this;

}

// constructor sets up empty list
IntList::IntList(const IntList& source){
    head = nullptr;

	if(source.head == nullptr){
		return;
	}
	head = new Node();
	head->info = source.head->info;
	head->next = nullptr;

	Node* this_current = head;
	Node* source_current = source.head->next;

	while(source_current != nullptr){

		Node* new_node = new Node();
		new_node->info = source_current -> info;
		new_node->next = nullptr;

    	this_current->next = new_node;
    	this_current = new_node;
    	source_current = source_current->next;
	}

	tail = this_current;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

