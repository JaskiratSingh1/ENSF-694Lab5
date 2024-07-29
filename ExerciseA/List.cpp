//
//  List.cpp
//  Flight Hash Table Using Linked List
//
//  Created by Mahmood Moussavi on 2024-05-25.
//
#include "Node.h"
#include "List.h"
#include "Flight.h"
#include <iostream>
using namespace std;

void List::insert(const Flight &data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

Flight* List::search(const string &flightNumber)const {
    Node* current = head;
    while (current) {
        if (current->data.flightNumber == flightNumber) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

bool List::isEmpty() const {
    return head == nullptr;
}

bool List::contains(const string &flightNumber) const {
    Node* current = head;
    while (current) {
        if (current->data.flightNumber == flightNumber) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void List::display() const {
    Node* current = head;
    while (current) {
        const Flight& flight = current->data;
        cout << "Flight Number: " << flight.flightNumber
             << ", Origin: " << flight.origin.name
             << ", Destination: " << flight.destination.name
             << ", Date: " << flight.departureDate
             << ", Time: " << flight.departureTime
             << ", Capacity: " << flight.craftCapacity << endl;
        current = current->next;
    }
}
