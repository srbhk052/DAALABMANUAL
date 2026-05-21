#include <iostream>
using namespace std;

const int MAX = 100;

// DFS function to detect cycle
bool dfs(int graph[MAX][MAX],
         bool visited[],
         bool recStack[],
         int V,
         int current)
{
    visited[current] = true;
    recStack[current] = true;

    // Traverse adjacent vertices
    for(int i = 0; i < V; i++)
    {
        if(graph[current][i] == 1)
        {
            // If vertex not visited
            if(!visited[i])
            {
                if(dfs(graph,
                       visited,
                       recStack,
                       V,
                       i))
                {
                    return true;
                }
            }

            // If vertex already in recursion stack
            else if(recStack[i])
            {
                return true;
            }
        }
    }

    // Remove vertex from recursion stack
    recStack[current] = false;

    return false;
}

int main()
{
    int V;

    // Input number of vertices
    cin >> V;

    int graph[MAX][MAX];

    // Input adjacency matrix
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    // Check all vertices
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfs(graph,
                   visited,
                   recStack,
                   V,
                   i))
            {
                cout << "Yes Cycle Exists";
                return 0;
            }
        }
    }

    cout << "No Cycle Exists";

    return 0;
}