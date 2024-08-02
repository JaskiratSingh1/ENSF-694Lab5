#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

struct Vertex;
//------------------------------- Edge -------------------------------
struct Edge {
    double cost;
    Vertex* des; // points to destination vertex
    Edge* next;
public:
    Edge(Vertex* d, double c = 0.0) : cost(c), des(d), next(0) {}
    Edge() : des(0), cost(0), next(0) {}
};
//------------------------------Vertex --------------------------------
struct Vertex {
    char name;
    Edge* adj;
    double dist; // Distance from previous vertex on a shortest path
    Vertex* prev; // Points to the previous vertex on a shortest path
    Vertex* next; // Points to the next
    int numEdges;
public:
    Vertex(const char n) : next(0), numEdges(0), name(n), adj(0) {
        reset();
    }
    void reset() { dist = INFINITY; prev = nullptr; }
};
//------------------------------ Priority Queue ---------------------------
class PriorityQueue {
public:
    PriorityQueue();
    bool isEmpty() const;
    void enqueue(Vertex* v);
    Vertex* dequeue();
private:
    struct ListNode {
        Vertex* element;
        ListNode* next;
        ListNode(Vertex* theElement, ListNode* n = nullptr)
            : element(theElement), next(n) {}
    };
    ListNode* front;
};

//--------------------------------- Graph --------------------------------
class Graph {
public:
    Graph() : head(nullptr), tail(nullptr), numVertices(0) {}
    void addEdge(const char sn, const char dn, double c);
    Vertex* getVertex(const char vname);
    void dijkstra(const char start);
    void unweighted(const char start);
    void printGraph();
    void clearAll();
    void printShortestPath(Vertex* dest);
    void readFromFile(const string& filename);
    void printAllShortestPaths(const char start, bool weighted);
    void printPath(Vertex* dest);
private:
    Vertex* head; // beginning of the list of vertices
    Vertex* tail;
    int numVertices;
};
