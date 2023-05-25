#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

// Structure to represent a weighted edge
struct Edge {
    int destination;
    int weight;
};

// Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int source, vector<int>& distances) {
    int numVertices = graph.size();
    distances.resize(numVertices, INF);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

int main() {
    vector<vector<Edge>> graph = {
        { {1, 7}, {2, 9}, {5, 14} },
        { {0, 7}, {2, 10}, {3, 15} },
        { {0, 9}, {1, 10}, {3, 11}, {5, 2} },
        { {1, 15}, {2, 11}, {4, 6} },
        { {3, 6}, {5, 9} },
        { {0, 14}, {2, 2}, {4, 9} }
    };

    int source = 0;
    vector<int> distances;
    dijkstra(graph, source, distances);

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < distances.size(); ++i) {
        cout << i + 1 << "\t" << distances[i] << endl;
    }

    return 0;
}
