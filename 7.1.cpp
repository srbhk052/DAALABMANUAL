// dijkstra's algorithm to find the shortest path from Akshay's house to his friends' houses in a graph representation of the city.
#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int graph[MAX][MAX];
int dist[MAX];
bool visited[MAX];
int parent[MAX];
int V;

// Function to print shortest path
void printPath(int node)
{
    if (node == -1)
        return;

    printPath(parent[node]);
    cout << node << " ";
}

// Dijkstra Algorithm
void dijkstra(int source)
{

    // Initialization
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[source] = 0;

    // Main Algorithm
    for (int count = 0; count < V - 1; count++)
    {

        int u = -1;
        int minDist = INF;

        // Find minimum distance vertex
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {

            if (graph[u][v] != 0 &&
                !visited[v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print Result
    cout << "\nShortest Paths from Akshay's House:\n";

    for (int i = 0; i < V; i++)
    {

        if (i == source)
            continue;

        if (dist[i] == INF)
        {
            cout << "Friend at node " << i
                 << " : No Path Available\n";
        }
        else
        {
            cout << "Friend at node " << i << " : ";

            printPath(i);

            cout << " Distance = "
                 << dist[i] << endl;
        }
    }
}

int main()
{

    int source;

    cout << "Enter number of locations: ";
    cin >> V;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter Akshay's house node: ";
    cin >> source;

    dijkstra(source);

    return 0;
}