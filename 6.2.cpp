#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
int color[MAX];
int V;

bool isBipartite() {
    queue<int> q;

    for (int start = 0; start < V; start++) {
        if (color[start] != -1)
            continue;

        color[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < V; i++) {
                if (graph[node][i] == 1) {
                    if (color[i] == -1) {
                        color[i] = 1 - color[node];
                        q.push(i);
                    }
                    else if (color[i] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < V; i++)
        color[i] = -1;

    if (isBipartite())
        cout << "Yes Bipartite";
    else
        cout << "Not Bipartite";

    return 0;
}