#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> NodeAndDistance;
typedef vector<vector<NodeAndDistance>> AdjacencyList;

class NoPathExistsException: public runtime_error {
public:
    NoPathExistsException() : runtime_error("No path exists between the nodes.") {}
};

class Dijkstra {
private:
    AdjacencyList adjacencyList;
    vector<int> distances;
    vector<int> parents;
    static constexpr int UNKNOWN = -1;

    void runDijkstra(int start) {
        auto comparator = [](NodeAndDistance p1, NodeAndDistance p2) {
            return p1.second > p2.second || (p1.second == p2.second && p1.first > p2.first);
        };
        priority_queue<NodeAndDistance, vector<NodeAndDistance>, decltype(comparator)> distanceQueue(comparator);
        vector<bool> visited(this->adjacencyList.size(), false);

        distanceQueue.push(make_pair(start, 0));
        parents[start] = start;
        distances[start] = 0;

        while (!distanceQueue.empty()) {
            auto [u, distance] = distanceQueue.top();
            distanceQueue.pop();
            if (visited[u]) continue;
            visited[u] = true;

            for (auto [v, weight] : this->adjacencyList[u]) {
                if (distances[v] == UNKNOWN || distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    parents[v] = u;
                    distanceQueue.push(make_pair(v, distances[v]));
                }
            }
        }
    }
public:
    Dijkstra(AdjacencyList &_adjacencyList) 
        : adjacencyList {_adjacencyList}  
        , distances {vector<int>(_adjacencyList.size(), UNKNOWN)}
        , parents {vector<int>(_adjacencyList.size(), UNKNOWN)}
    {}

    pair<int, vector<int>> computeShortestPath(int start, int end) {
        this->runDijkstra(start);
        if (this->parents[end] == UNKNOWN) {
            throw NoPathExistsException();
        }

        int distance = this->distances[end];

        vector<int> path;
        path.push_back(end);
        int current = end;
        while (current != start) {
            current = parents[current];
            path.push_back(current);
        }

        std::reverse(path.begin(), path.end());
        return make_pair(distance, path);
    }
};
