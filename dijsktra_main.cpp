#include <iostream>
using namespace std;

int main() {
    int n = 5;
    AdjacencyList adjacencyList(n);
    vector<tuple<int, int, int>> edges {
        make_tuple(0, 1, 6),
        make_tuple(0, 2, 10),
        make_tuple(0, 3, 4),
        make_tuple(1, 0, 2),
        make_tuple(1, 2, 3),
        make_tuple(1, 4, 5),
        make_tuple(3, 1, 1),
        make_tuple(3, 4, 2),
        make_tuple(4, 2, 1)
    };
    for (auto [u, v, w] : edges) {
        adjacencyList[u].push_back(make_pair(v, w));
    }

    Dijkstra dijkstra(adjacencyList);
    auto [distance, path02] = dijkstra.computeShortestPath(0, 2);
    cout << "Shortest path from 0 to 2: ";
    for (int u : path02) {
        cout << u << " ";
    }
    cout << endl << "Length of the path: " << distance;
}
