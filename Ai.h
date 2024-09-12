#include <raylib.h>
#include <vector>
#include <string>
#include <float.h> // FOR FLT MAX
#include <stdio.h> // FOR FLT MAX
#include "Node.h"

#ifndef AIPATH_H
#define AIPATH_H

using namespace std;


// Ai Class
class Ai
{
public:
#define ROWS 10
#define COLS 20
#define NODE_SIZE 50

    vector<vector<Node>> grid;
    Node pointA, pointB;

    void Main();
    void Start();
    void UpdateAndDraw();


    // SEARCH ALGORITHMS
    // vector<Node*> tracedPath;
    vector<Node*> GetNeighbors(Node* node);

    // BFS
    void BFS(Node* start, Node* goal);
    vector<Node*> bfsTracedPath;
    Color bfsColor = Color{ 255, 255, 0, 150 }; // RED

    // DFS
    void DFS(Node* start, Node* goal);
    vector<Node*> dfsTracedPath;
    Color dfsColor = Color{ 0, 180, 150, 150 }; // GREEN


    // Dijkstra
    vector<Node*> dijkstraTracedPath;
    void Dijkstra(Node* start, Node* goal);
    Color dijkstraColor = Color{ 0, 0, 255, 150 }; // BLUE

    // A* Search
    float Heuristic(Node* a, Node* b);
    void AStarSearch(Node* start, Node* goal);
    vector<Node*> astarTracedPath;
    Color astarColor = Color{ 255, 255, 0, 150 }; // YELLOW

};

#endif