#include "graph.h"
int main(int argc, char** argv) {
    if(argc < 2){
        cerr << "Usage: Program needs one argument from command line.";
        exit(1);
    }
    
    Graph g;
    g.readFromFile(argv[1]);
    int choice = 0;
    while(choice != 3) {

        cout << "Choose the type of graph:\n";
        cout << "1. Unweighted Graph\n";
        cout << "2. Weighted Graph\n";
        cout << "3. Quit\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;
        if (choice == 3) break;
        bool weighted = (choice == 2);
        char start;
        cout << "Enter the start vertex: ";
        cin >> start;
        g.printAllShortestPaths(start, weighted);
    }
    return 0;
}
