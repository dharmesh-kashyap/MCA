#include <iostream>
#include <vector>

using namespace std;

const int MAX_VERTICES = 100;

class DirectedGraphMatrix {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    DirectedGraphMatrix(int V) : vertices(V) {
        adjMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;  // For simplicity, assuming edge weight as 1
    }

    void displayMatrix() {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    DirectedGraphMatrix graph(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "Adjacency Matrix:" << endl;
    graph.displayMatrix();

    return 0;
}
