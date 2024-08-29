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
    

};

#endif