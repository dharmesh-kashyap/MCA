#include <iostream>

using namespace std;

const int MAX = 100; 

class UndirectedGraphList {
private:
    int vertices;
    int *adjacencyList[MAX];
    int listSizes[MAX];

public:
    UndirectedGraphList(int V) : vertices(V) {
        for (int i = 0; i < V; ++i) {
            adjacencyList[i] = new int[V];
            listSizes[i] = 0;
        }
    }

    void addEdge(int from, int to) {
        adjacencyList[from][listSizes[from]++] = to;
        adjacencyList[to][listSizes[to]++] = from; 
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Vertex " << i << " --> ";
            for (int j = 0; j < listSizes[i]; ++j) {
                cout << adjacencyList[i][j] << " ";
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

    UndirectedGraphList graph(vertices);
    cout << "Enter the edges (from to):" << endl;
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph.addEdge(from, to);
    }

    cout << "Adjacency List:" << endl;
    graph.printGraph();

    return 0;
}
