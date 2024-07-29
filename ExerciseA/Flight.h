//
//  Flight.h
//  Flight Hash Table Using Linked List
//
//  Created by Mahmood Moussavi on 2024-05-25.
//

#ifndef Flight_hpp
#define Flight_hpp
#include "Point2.h"

// Flight class to represent a flight
class Flight {
public:
    string flightNumber;
    Point origin;
    Point destination;
    string departureDate;
    string departureTime;
    int craftCapacity;

    Flight() = default;
    Flight(const string &flightNumber, const Point &origin, const Point &destination,
           const string &departureDate, const string &departureTime, int craftCapacity);
};

#endif /* Flight_hpp */
