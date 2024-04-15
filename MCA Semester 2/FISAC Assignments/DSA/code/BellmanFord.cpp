#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 7 // Number of vertices in the graph

// Define a structure to represent edges
struct Edge {
    int src;
    int dest;
    int weight;
};

// Function to implement Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int source, vector<int>& dist) {
    dist.resize(V, INT_MAX); // Initialize distances to infinity
    dist[source] = 0; // Distance from source to itself is 0

    // Relax edges |V| - 1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative cycles
    for (const Edge& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative cycle. Cannot find shortest paths." << endl;
            return;
        }
    }
}

int main() {
    vector<Edge> edges; // List of edges in the graph

    // Add edges and their weights to the graph
    edges.push_back({0, 1, 4}); // A -> B: 4
    edges.push_back({0, 2, 7}); // A -> C: 7
    edges.push_back({0, 4, 3}); // A -> E: 3
    edges.push_back({0, 5, 6}); // A -> F: 6
    edges.push_back({1, 2, 8}); // B -> C: 8
    edges.push_back({1, 3, 9}); // B -> D: 9
    edges.push_back({2, 3, 10}); // C -> D: 10
    edges.push_back({2, 4, 5}); // C -> E: 5
    edges.push_back({3, 4, 6}); // D -> E: 6
    edges.push_back({3, 5, 11}); // D -> F: 11
    edges.push_back({4, 5, 12}); // E -> F: 12
    edges.push_back({4, 6, 5}); // E -> G: 5
    edges.push_back({5, 6, 10}); // F -> G: 10

    int source = 0; // Source vertex (A)
    vector<int> dist; // Vector to store shortest distances
    bellmanFord(edges, source, dist); // Compute shortest distances from source

    if (dist[0] != INT_MAX) {
        // Print shortest distances from source to all other vertices
        cout << "Shortest distances from source vertex A (Bellman-Ford algorithm):" << endl;
        for (int i = 0; i < V; ++i) {
            cout << "A -> " << char('A' + i) << ": " << dist[i] << endl;
        }
    }

    return 0;
}
