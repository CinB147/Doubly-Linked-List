#include "functions.h"
#include <iostream>
#include <cstddef>

Linked_list::Linked_list() { //defualt construct

    head = nullptr;
    tail = nullptr;
}

Linked_list::node::node(double value) { 
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}


Linked_list::Linked_list(const Linked_list& src) { //copy construct 
  
    if (!is_empty()) {  
        head = nullptr; 
        tail = nullptr;
        *this = src;       
    }
    else {    
        head = nullptr;
        tail = nullptr;
    }

}

Linked_list::~Linked_list() { //deconstruct
    if (!is_empty()) {
        node* it = head;
        while (it != nullptr) {
            it = it->prev;
            pop_front();
        }
    }
}


void Linked_list::push_back(double value) {
    node* Newnode = new node(value);                  
    node* temp;

    if (tail != NULL) //if tail is not null
    {
        temp = tail; //temp pointer is pointing at tail
        temp->next = Newnode; //next of temp will point at new node 
        tail = Newnode; // tail is now now node
        tail->prev = temp; // prev tail is temp 
        tail->next = nullptr; //tail next is null
    }
    else
    {
        head = Newnode; // head create a new node
        tail = head; // tail also get value as head
        tail->next = nullptr; // tail next is null
        tail->prev = nullptr; // tail pre is null
     
    }


}

void Linked_list::push_front(double value) {
    node* newnode = new node(value);
    newnode->value = value;
    node* move;

    if (head != NULL) {
        move = head;
        head->prev = newnode;
        head = newnode;
        head->next = move;
        head->prev = nullptr;
    }
    else {
        head = newnode;
        tail = head;
        head->prev = nullptr;
        tail->next = nullptr;
    }
    
}

void Linked_list::print() const {

    node* it = head;
    while (it != nullptr) {
        std::cout << it->value << " ";
        it = it->next;
    }
    std::cout << std::endl;
    
}
void Linked_list::print_reverse() const {
    node* it = tail;
    while (it != nullptr) {
        std::cout << it->value << " ";
        it = it->prev;
    }
    std::cout << std::endl;
}

double Linked_list::back() const {
    
    if (tail!=NULL) {
        return tail->value;
    }
    else {
        std::cout << "Failed!, there is no elements in the list" << std::endl;
        exit(1);
       
    }
}
double Linked_list::front() const {
    if (head!=NULL) {
        return head->value;
    }
    else {
        std::cout << "Failed!, there is no elements in the list" << std::endl;
        exit(1);
    }
}

double Linked_list::at(size_t pos) const {
    node* it = head;
    for (size_t i = 0; i < pos; i++) {
        it = it->next;
    }
    return it->value;
}

void Linked_list::remove(size_t pos) {
    
    node* Newnode = head;
    node* n;

    if (head != NULL)
    {
        for (size_t i = 0; i < pos; i++)
        {
            Newnode = Newnode->next; 
        }

        if (Newnode->prev != NULL)
        {
            n = Newnode->prev; 
            n->next = Newnode->next;
        }
        if (Newnode->next != NULL)
        {
            n = Newnode->next;
            n->prev = Newnode->prev;
        }
        delete Newnode;
    }
}

size_t Linked_list::size() const {
    node* it = head;

    size_t n_count = 0;
    
    if (head != NULL) {
        while (it->next != NULL) {
            it = it->next;
            n_count++;
        }
        return n_count+1;
    }
   
    return n_count;
}
Linked_list& Linked_list::operator=(const Linked_list &rhs) {

    if (this == &rhs) {
        return *this; //check if list 1 elemets is == rhs(linkedlist) return *this element list
    }
    node* Newnode = rhs.head;
    while (!is_empty()) { 
        pop_back(); //pop_back elements untill is empty
     }

    while (Newnode != nullptr) { 
        push_back(Newnode->value); //push_back values
        Newnode = Newnode->next; //next create newnode
    }
    return *this;
}

Linked_list& Linked_list::operator+=(const Linked_list& rhs) {
    node* Newnode = rhs.head;
    while (Newnode != nullptr) {
        push_back(Newnode->value);
        Newnode = Newnode->next;
    }
    return *this;
}



double Linked_list::pop_back() {
    node* Node;
    double tvalue = tail->value;
    if (tail != NULL)
    {

        Node = tail; //pointer at node's tail
        tail = Node->prev; //tail is node's prev
        delete Node; //delete node
        if (tail != NULL) 
        {
            tail->next = NULL;
        }
    }
    return tvalue;
}

double Linked_list::pop_front() {
    
    double value = head->value; 
    if (size() == 1) {//When there only 1 node in DLL
        delete head; //delete the only node in list
        head = nullptr;
        tail = nullptr;
    }
    else {

        head = head->next; //head next is head
        delete head->prev; //delete prev head's node
        head->prev = nullptr; //prev head's is null
    }

    return value;

   
}

bool Linked_list::is_empty() const {
    if (head == nullptr && tail == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
