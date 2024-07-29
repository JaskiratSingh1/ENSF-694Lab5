//
//  Flight.cpp
//  Flight Hash Table Using Linked List
//
//  Created by Mahmood Moussavi on 2024-05-25.
//
#include "Point2.h"
#include "Flight.h"
Flight::Flight(const string &flightNumber, const Point &origin, const Point &destination,
       const string &departureDate, const string &departureTime, int craftCapacity)
    : flightNumber(flightNumber), origin(origin), destination(destination),
      departureDate(departureDate), departureTime(departureTime), craftCapacity(craftCapacity) 
{
    
}
