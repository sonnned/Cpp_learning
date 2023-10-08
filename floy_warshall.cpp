#include <vector>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> AdjacencyMatrix;

class NoPathExistsException: public runtime_error {
public:
    NoPathExistsException() : runtime_error("No path exists between the nodes.") {}
};

class FloydWarshall {
private:
    AdjacencyMatrix distanceMatrix;
    AdjacencyMatrix predecessorMatrix;
    static constexpr int UNKNOWN = -1;
    static constexpr int INFINITY = 1'000'000'000;

    void initialize(AdjacencyMatrix const &adjacencyMatrix) {
        int n = adjacencyMatrix.size();
        this->distanceMatrix = AdjacencyMatrix(n, vector<int>(n, INFINITY));
        this->predecessorMatrix = AdjacencyMatrix(n, vector<int>(n, UNKNOWN));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    this->distanceMatrix[i][j] = 0;
                    this->predecessorMatrix[i][j] = i;
                } else if (adjacencyMatrix[i][j] > 0) {
                    this->distanceMatrix[i][j] = adjacencyMatrix[i][j];
                    this->predecessorMatrix[i][j] = i;
                }
            }
        }
    }

    void compute() {
        int n = this->distanceMatrix.size();
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (this->distanceMatrix[i][k] + this->distanceMatrix[k][j] < this->distanceMatrix[i][j]) {
                        this->distanceMatrix[i][j] = this->distanceMatrix[i][k] + this->distanceMatrix[k][j];
                        this->predecessorMatrix[i][j] = this->predecessorMatrix[k][j];
                    }
                }
            }
        }
    }
public:
    FloydWarshall(AdjacencyMatrix const &adjacencyMatrix) {
        this->initialize(adjacencyMatrix);
        this->compute();
    }

    pair<int, vector<int>> getShortestPath(int start, int end) {
        int distance = this->distanceMatrix[start][end];
        if (distance == INFINITY) {
            throw NoPathExistsException();
        }

        vector<int> path {end};
        int current = end;
        while (current != start) {
            current = this->predecessorMatrix[start][current];
            path.push_back(current);
        }
        std::reverse(path.begin(), path.end());
        return make_pair(distance, path);
    }
};
