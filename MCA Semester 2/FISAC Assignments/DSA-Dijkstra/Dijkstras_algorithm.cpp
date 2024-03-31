#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

#define V 7 // Number of vertices in the graph

// Define a structure to represent edges
struct Edge {
    int dest;
    int weight;
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int source, vector<int>& dist) {
    dist.resize(V, INT_MAX); // Initialize distances to infinity
    dist[source] = 0; // Distance from source to itself is 0

    // Create a min heap to store vertices based on their tentative distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // Push the source vertex into the priority queue

    while (!pq.empty()) {
        int u = pq.top().second; // Extract the vertex with minimum distance
        pq.pop();

        // Iterate through all neighboring vertices of u
        for (const Edge& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;

            // Update distance if a shorter path is found
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Push updated distance and vertex into the queue
            }
        }
    }
}

int main() {
    vector<vector<Edge>> graph(V); // Adjacency list representation of the graph

    // Add edges and their weights to the graph
    graph[0].push_back({1, 4}); // A -> B: 4
    graph[0].push_back({2, 7}); // A -> C: 7
    graph[0].push_back({4, 3}); // A -> E: 3
    graph[0].push_back({5, 6}); // A -> F: 6
    graph[1].push_back({2, 8}); // B -> C: 8
    graph[1].push_back({3, 9}); // B -> D: 9
    graph[2].push_back({3, 10}); // C -> D: 10
    graph[2].push_back({4, 5}); // C -> E: 5
    graph[3].push_back({4, 6}); // D -> E: 6
    graph[3].push_back({5, 11}); // D -> F: 11
    graph[4].push_back({5, 12}); // E -> F: 12
    graph[4].push_back({6, 5}); // E -> G: 5
    graph[5].push_back({6, 10}); // F -> G: 10

    int source = 0; // Source vertex (A)
    vector<int> dist; // Vector to store shortest distances
    dijkstra(graph, source, dist); // Compute shortest distances from source

    // Print shortest distances from source to all other vertices
    cout << "Shortest distances from source vertex A (Dijkstra's algorithm):" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "A -> " << char('A' + i) << ": " << dist[i] << endl;
    }

    return 0;
}
