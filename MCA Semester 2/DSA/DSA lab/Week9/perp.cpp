#include <iostream>
using namespace std;

int main() {
  int n, u, v;
  cout << "Enter the number of vertices: ";
  cin >> n;

  int adjMat[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      adjMat[i][j] = 0;
    }
  }

  cout << "Enter the edges (source vertex, destination vertex): " << endl;
  while (true) {
    cin >> u >> v;
    if (u == -1 && v == -1) {
      break;
    }
    adjMat[u][v] = 1;
  }

  cout << "The adjacency matrix for the directed graph is: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << adjMat[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}