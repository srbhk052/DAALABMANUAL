#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int graph[MAX][MAX];
int dist[MAX];
int parent[MAX];
int V;

// Function to print shortest path
void printPath(int node)
{
    if(node == -1)
        return;

    printPath(parent[node]);
    cout << node << " ";
}

// Bellman-Ford Algorithm
void bellmanFord(int source)
{
    // Initialization
    for(int i = 0; i < V; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    // Relax all edges V-1 times
    for(int k = 0; k < V - 1; k++)
    {
        for(int u = 0; u < V; u++)
        {
            for(int v = 0; v < V; v++)
            {
                if(graph[u][v] != 0 &&
                   dist[u] != INF &&
                   dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check negative weight cycle
    for(int u = 0; u < V; u++)
    {
        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] != 0 &&
               dist[u] != INF &&
               dist[u] + graph[u][v] < dist[v])
            {
                cout << "Negative Weight Cycle Detected";
                return;
            }
        }
    }

    // Print shortest paths
    cout << "\nShortest Paths:\n";

    for(int i = 0; i < V; i++)
    {
        if(i == source)
            continue;

        if(dist[i] == INF)
        {
            cout << i << " : No Path\n";
        }
        else
        {
            cout << "Path to " << i << " : ";

            printPath(i);

            cout << " | Cost = "
                 << dist[i] << endl;
        }
    }
}

int main()
{
    int source;

    // Input number of vertices
    cin >> V;

    // Input adjacency matrix
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Input source vertex
    cin >> source;

    // Call Bellman-Ford Algorithm
    bellmanFord(source);

    return 0;
}