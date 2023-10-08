#include <iostream>
using namespace std;

int main() {
    int n = 4;
    AdjacencyMatrix adjacencyMatrix(n, vector<int>(n, 0));
    vector<tuple<int, int, int>> edges {
        make_tuple(0, 1, 6), 
        make_tuple(0, 2, 3), 
        make_tuple(0, 3, 12), 
        make_tuple(1, 2, 9), 
        make_tuple(1, 3, 5), 
        make_tuple(2, 3, 2),
        make_tuple(3, 1, 4),
        make_tuple(3, 2, 1)
    };
    for (auto [v, u, w] : edges) {
        adjacencyMatrix[v][u] = w;
    }

    FloydWarshall floydWarshall(adjacencyMatrix);
    auto [distance, path] = floydWarshall.getShortestPath(0, 3);
    cout << "Shortest path from 0 to 3:";
    for (int u : path) {
        cout << " " << u;
    }
    cout << endl << "Length of the path: " << distance << endl;
    
    try {
        floydWarshall.getShortestPath(2, 0);
    } catch (NoPathExistsException exc) {
        cout << "No path from 2 to 0.";
    }  
}
