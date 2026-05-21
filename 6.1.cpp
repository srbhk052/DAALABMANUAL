#include <iostream>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
bool visited[MAX];
int V;
bool found = false;

// DFS function
void dfs(int node, int dest) {
    visited[node] = true;

    if (node == dest) {
        found = true;
        return;
    }

    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, dest);
        }
    }
}

int main() {
    int source, destination;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source and destination: ";
    cin >> source >> destination;

    for (int i = 0; i < V; i++)
        visited[i] = false;

    dfs(source, destination);

    if (found)
        cout << "Yes Path Exists";
    else
        cout << "No Such Path Exists";

    return 0;
}