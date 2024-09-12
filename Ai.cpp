#include "Ai.h"
#include <vector>
#include <iostream>

using namespace std;




void Ai::Main()
{
    InitWindow(1000, 500, "AI - Pathfinding");

    Start();

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        UpdateAndDraw();

        EndDrawing();
    }

    CloseWindow();
}

void Ai::Start()
{
    // re-create the nodes
    grid.clear();
    for (int row = 0; row < ROWS; row++)
    {
        float y = NODE_SIZE * row;
        vector<Node> rowNodes;
        for (int col = 0; col < COLS; col++)
        {
            float x = NODE_SIZE * col;
            Node node = { row, col, Vector2{x, y}, DARKGRAY, LIGHTGRAY }; // fill, stroke
            rowNodes.push_back(node);
        }
        grid.push_back(rowNodes);
    }

    // take some (e.g., 5, 10, or 20) from sqaures randomly and put in blockd ones
    for (int i = 0; i < 20; i++)
    {
        int randRow = GetRandomValue(0, (int)(grid.size()) - 1);
        int randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);

        while (grid[randRow][randCol].blocked)
        {
            randRow = GetRandomValue(0, (int)(grid.size()) - 1);
            randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);
        }

        grid[randRow][randCol].blocked = true;
    }


    // choose a random home and dest from squares
    int randRow = GetRandomValue(0, (int)(grid.size()) - 1);
    int randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);

    while (grid[randRow][randCol].blocked)
    {
        randRow = GetRandomValue(0, (int)(grid.size()) - 1);
        randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);
    }
    
    pointA = grid[randRow][randCol];
    pointA.costText = "A";
    pointA.fillColor = GREEN;
    pointA.blocked = true; // this just so the color renders
    // NOT A GOOD LOGIC

    randRow = GetRandomValue(0, (int)(grid.size()) - 1);
    randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);
    while (grid[randRow][randCol].blocked)
    {
        randRow = GetRandomValue(0, (int)(grid.size()) - 1);
        randCol = GetRandomValue(0, (int)(grid[randRow].size()) - 1);
    }
    pointB = grid[randRow][randCol];
    pointB.costText = "B";
    pointB.fillColor = BLUE;
    pointB.blocked = true; // this just so the color renders
    // NOT A GOOD LOGIC

    // DFS
    // DFS(&pointA, &pointB);


    // BFS
    // BFS(&pointA, &pointB);

    // Dijkstra Algorithm
    // Dijkstra (&pointA, &pointB);

    // A* Search
    AStarSearch(&pointA, &pointB);
}

void Ai::UpdateAndDraw()
{
    for (int i = 0; i < (int)(grid.size()); i++)
        for (int j = 0; j < (int)(grid[i].size()); j++)
            grid[i][j].Draw();


    // Draw BSF Traced Path
    for (Node* node : bfsTracedPath)
        node->DrawPath( bfsColor );

    // Draw DFS Traced Path
    for (Node* node : dfsTracedPath)
        node->DrawPath(dfsColor);

    // Draw Dijkstra Traced Path
    for (Node* node : dijkstraTracedPath)
        node->DrawPath(dijkstraColor);

    // Draw A* Traced Path
    for (Node* node : astarTracedPath)
        node->DrawPath(astarColor);

        // Check if the "R" key is pressed
    if (IsKeyPressed(KEY_R)) { Start(); } // RESTART



    // draw home and dest. Reset 
    pointA.step = -1; pointA.Draw();
    pointB.step = -1; pointB.Draw();
}





