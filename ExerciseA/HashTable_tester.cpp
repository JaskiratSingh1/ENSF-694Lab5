#include "Flight.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>

void interactive_search(const HashTable& ht);
void open_input_file (string& inputFileName, ifstream& inputFile);
void read_flight_info (int argc, char** argv, vector<Flight>& records);

void interactive_search(const HashTable& ht) {
    string searchFlightNumber;
    cout << "Enter flight number to search (or 'exit' to quit): ";
    while (cin >> searchFlightNumber && searchFlightNumber != "exit") {
        Flight* flight = ht.search(searchFlightNumber);
        if (flight) {
            cout << "Record found: Flight Number: " << flight->flightNumber
            << ", Origin: " << flight->origin.name
            << ", Destination: " << flight->destination.name
            << ", Date: " << flight->departureDate
            << ", Time: " << flight->departureTime
            << ", Capacity: " << flight->craftCapacity << endl;
        } else {
            cout << "Record not found." << endl;
        }
        cout << "Enter flight number to search (or 'exit' to quit): ";
    }
}

void read_flight_info (int argc, char** argv, vector<Flight>& records){
    // open the stream to read the text file
    if (argc != 2) {
        cerr << "Usage: hashtable input.txt" << endl;
        exit(1);
    }
    string fileName = "/Users/mahmoodmoussavi/Dropbox/Data Structue Code/Flight Hash Table Using Linked List/Flight Hash Table Using Linked List/";
    fileName+= string(argv[1]);
    ifstream inputFile;
    inputFile.open(fileName.c_str());
    
    if (!inputFile) {
        cerr << "Error opening file: " << argv[1] << endl;
        exit(1);
    }
    
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string flightNumber, origin, destination, departureDate, departureTime;
        int craftCapacity;
        
        ss >> flightNumber >> origin >> destination >> departureDate >> departureTime >> craftCapacity;
        
        Flight record(flightNumber, Point(origin), Point(destination), departureDate, departureTime, craftCapacity);
        records.push_back(record);
    }
    
    inputFile.close();
}

int main(int argc, char* argv[]) {
    // Vector to store flight records
    vector<Flight> records;
    read_flight_info (argc, argv, records);

    unsigned int tableSize = (int) records.size() / 2; // Example initial table size (ensure less than 50% load)
    
    HashTable hashTable(tableSize);
    
    // First pass: Insert records into their desired slots if empty
    vector<Flight> overflowRecords;
    
    for (const auto &record : records) {
        if (!hashTable.insertFirstPass(record)) {
            overflowRecords.push_back(record);
        }
    }
    
    // Second pass: Insert overflow records into the table
    for (const auto &record : overflowRecords) {
        hashTable.insertSecondPass(record);
    }
    
    // Calculate packing density and hash efficiency
    double packingDensity = hashTable.calculatePackingDensity();
    double hashEfficiency = hashTable.calculateHashEfficiency();
    
    cout << "Packing Density: " << packingDensity << endl;
    cout << "Hash Efficiency: " << hashEfficiency << endl;
    
    // Display all data in the hash table
    cout << "Hash Table Contents:" << endl;
    hashTable.display();
    
    // Interactive search
    interactive_search(hashTable);
    return 0;
}

