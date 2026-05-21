#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int graph[MAX][MAX];
int V;

// Recursive function to find shortest path
// with exactly k edges
int shortestPath(int src, int dest, int k)
{
    // Base cases
    if (k == 0 && src == dest)
        return 0;

    if (k == 1 && graph[src][dest] != 0)
        return graph[src][dest];

    if (k <= 0)
        return INF;

    int ans = INF;

    // Traverse all adjacent vertices
    for (int i = 0; i < V; i++)
    {
        if (graph[src][i] != 0 && src != i)
        {
            int sub = shortestPath(i, dest, k - 1);

            if (sub != INF)
            {
                ans = min(ans,
                          graph[src][i] + sub);
            }
        }
    }

    return ans;
}

int main()
{
    int source, destination, k;

    // Input number of vertices
    cin >> V;

    // Input adjacency matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Input source and destination
    cin >> source >> destination;

    // Convert to 0-based indexing
    source--;
    destination--;

    // Input value of k
    cin >> k;

    int ans = shortestPath(source,
                           destination,
                           k);

    if (ans == INF)
    {
        cout << "no path of length k is available";
    }
    else
    {
        cout << "Weight of shortest path from ("
             << source + 1 << ","
             << destination + 1
             << ") with "
             << k
             << " edges : "
             << ans;
    }

    return 0;
}