/*
 *  HashTable.cpp
 *  ENSF 694 Lab 5, exercise A
 *  Completed by: Jaskirat Singh
 *  Submission date: August 2
 */

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
        //h(k) = ((a * k + b) % p) % m from notes
        hash = ((hash * 31 + c) % 17) % tableSize;
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

//Calculate hash efficiency
double HashTable::calculateHashEfficiency() const {
    unsigned int reads = 0;

    //Go over each bucket
    for(unsigned int i = 0; i < tableSize; i++) {
        //Get number of nodes in current bucket
        reads += table[i].numNodes();
    }

    //Calculate the average reads
    double averageReads = reads/numberOfRecords + 1;
    
    //Hashing efficiency = packing density / average number of reads per record
    return calculatePackingDensity() / averageReads;
}

//Display the hash table
void HashTable::display() const {
    for(unsigned int i = 0; i < tableSize; i++){
        cout << "Bucket " << i << ": ";
        table[i].display();
        cout << endl;
    }
}
