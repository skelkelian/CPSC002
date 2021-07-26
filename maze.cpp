#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void print2DArray(int (*theArray)[30], int xNumberUsed)
{
    for (int i = 0; i < xNumberUsed; i++)
    {
        for (int j = 0; j < xNumberUsed; j++)
        {
            cout << theArray[i][j] << " ";
        }
        cout << endl;
    }

}

void fillUpArray(int (*theArray)[30], int xNumberUsed, string file_name)
{
    ifstream inputFile;
    inputFile.open(file_name);

    if (inputFile.fail() )
    {
        cout << "Cannot open inputFile!\n";
        exit(1);
    }

    for (int i = 0; i < xNumberUsed; i++)
    {
        for (int j = 0; j < xNumberUsed; j++)
        {
            inputFile >> theArray[i][j];
        }
        cout << endl;
    }

}

int main() {
    ifstream inputFile;

    int mazeSize = 1;
    cout << "Welcome to this maze game!" << endl;

    do {
        cout << "What size would you like the maze to be? You can pick either 8, 10, 12, or 14. ";
        cin >> mazeSize;
    } while (mazeSize != 8 && mazeSize != 10 && mazeSize != 12 && mazeSize != 14);

    int maze[30][30] = { { } };

    if (mazeSize == 8) {
        fillUpArray(maze, mazeSize, "maze8.txt");
        print2DArray(maze, mazeSize);
    }
    else if (mazeSize == 10) {
        fillUpArray(maze, mazeSize, "maze10.txt");
        print2DArray(maze, mazeSize);
    }
    else if (mazeSize == 12) {
        fillUpArray(maze, mazeSize, "maze12.txt");
        print2DArray(maze, mazeSize);
    }
    else {
        fillUpArray(maze, mazeSize, "maze14.txt");
        print2DArray(maze, mazeSize);
    }

    return 0;
}
