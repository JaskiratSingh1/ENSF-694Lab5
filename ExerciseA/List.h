//
//  List.hpp
//  Flight Hash Table Using Linked List
//
//  Created by Mahmood Moussavi on 2024-05-25.
//

#ifndef List_hpp
#define List_hpp
#include "Flight.h"
#include "Node.h"

// Custom List class to handle collisions
class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}
    void insert(const Flight &data);
    Flight* search(const string &flightNumber)const;
    bool isEmpty() const;
    bool contains(const string &flightNumber) const;
    void display() const;
};


#endif /* List_hpp */
