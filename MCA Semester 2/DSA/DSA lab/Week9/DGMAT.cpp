#include <iostream>

using namespace std;

const int MAX = 100;

class DirectedGraphMatrix {
private:
    int vertices;
    int adjacencyMatrix[MAX ][MAX];

public:
    DirectedGraphMatrix(int V) : vertices(V) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                adjacencyMatrix[i][j] = 0; 
            }
        }
    }

    void addEdge(int from, int to, int weight = 1) {
        adjacencyMatrix[from][to] = weight;
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    DirectedGraphMatrix graph(vertices);
    cout << "Enter the edges (from to):" << endl;
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph.addEdge(from, to);
    }

    cout << "Adjacency Matrix:" << endl;
    graph.printGraph();

    return 0;
}
