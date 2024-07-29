//
//  Node.h
//  Flight Hash Table Using Linked List
//
//  Created by Mahmood Moussavi on 2024-05-25.
//

#ifndef Node_h
#define Node_h
#include "Flight.h"

class Node {
public:
    Flight data;
    Node* next;

    Node(const Flight &data) : data(data), next(nullptr) {}
};
#endif /* Node_h */
