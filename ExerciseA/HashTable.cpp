//
//  HashTable.cpp
//  ExerciseA
//
//  Created by Jaskirat Singh on 7/29/24.
//

#include "HashTable.h"

//Constructor
HashTable::HashTable(unsigned int size): tableSize(size), numberOfRecords(0){
    table.resize(size);
}

//Hash function
unsigned int HashTable::hashFunction(const string &flightNumber) const {
    //Implementation of a hash function based on the flight number
    unsigned int hash = 0;
    //Iterate through all characters
    for(char c : flightNumber) {
        //h(k) = ((a * k + b) % p) % m
        hash = ((hash * 31 + c) % 1117) % tableSize;
    }
    return hash;
}

//Insert flight into hash table
void HashTable::insert(const Flight &flight) {
    //Get hash
    unsigned int index = hashFunction(flight.flightNumber);
    //Insert into table
    table[index].insert(flight);
    numberOfRecords++;
}

//Insert flight into hash table in the first pass
bool HashTable::insertFirstPass(const Flight &flight) {
    unsigned int index = hashFunction(flight.flightNumber);
    //Check if space is available
    if(table[index].isEmpty()) {
        table[index].insert(flight);
        numberOfRecords++;
        return true;
    }
    return false;
}

//Insert flight into hash table in the second pass
void HashTable::insertSecondPass(const Flight &flight) {
    //Insert into linked list
    insert(flight);
}

//Search for a flight in the hash table
Flight* HashTable::search(const string &flightNumber) const {
    unsigned int index = hashFunction(flightNumber);
    return table[index].search(flightNumber);
}

//Calculate packing density
double HashTable::calculatePackingDensity() const {
    return numberOfRecords / tableSize;
}

// Calculate hash efficiency
double HashTable::calculateHashEfficiency() const {
    
    return calculatePackingDensity();// /avg reads per record
}

//Display the hash table
void HashTable::display() const {
    for(unsigned int i = 0; i < tableSize; i++){
        cout << "Bucket " << i << ": ";
        table[i].display();
        cout << endl;
    }
}
