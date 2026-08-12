#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <chrono>

using namespace std;
using namespace chrono;

class Graph
{
    int vertices;
    vector<vector<int>> adjList;

public:

    // Constructor
    Graph(int v)
    {
        vertices = v;
        adjList.resize(vertices);
    }

    // Add an undirected edge
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Display adjacency list
    void displayGraph()
    {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < vertices; i++)
        {
            cout << i << " -> ";

            for (int node : adjList[i])
            {
                cout << node << " ";
            }

            cout << endl;
        }
    }

    // DFS using Stack
    void DFS(int start)
    {
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(start);

        cout << "DFS Traversal: ";

        while (!s.empty())
        {
            int current = s.top();
            s.pop();

            if (visited[current])
                continue;

            visited[current] = true;
            cout << current << " ";

            // Add neighbours to stack
            for (int i = adjList[current].size() - 1; i >= 0; i--)
            {
                int neighbour = adjList[current][i];

                if (!visited[neighbour])
                {
                    s.push(neighbour);
                }
            }
        }
    }

    // BFS using Queue
    void BFS(int start)
    {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbour : adjList[current])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
};

int main()
{
    int V, E;

    cout << "===== BFS AND DFS GRAPH TRAVERSAL =====\n";

    // Input vertices
    cout << "\nEnter number of vertices: ";
    cin >> V;

    if (V <= 0)
    {
        cout << "Invalid number of vertices!";
        return 0;
    }

    Graph graph(V);

    // Input edges
    cout << "Enter number of edges: ";
    cin >> E;

    if (E < 0)
    {
        cout << "Invalid number of edges!";
        return 0;
    }

    cout << "\nEnter edges (u v):\n";

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= V || v < 0 || v >= V)
        {
            cout << "Invalid edge! Enter vertices between 0 and "
                 << V - 1 << ".\n";

            i--;
            continue;
        }

        graph.addEdge(u, v);
    }

    // Display graph
    graph.displayGraph();

    // Starting vertex
    int start;

    cout << "\nEnter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= V)
    {
        cout << "Invalid starting vertex!";
        return 0;
    }

    // ---------------- DFS TIME ----------------

    auto dfsStart = high_resolution_clock::now();

    graph.DFS(start);

    auto dfsEnd = high_resolution_clock::now();

    auto dfsTime =
        duration_cast<nanoseconds>(dfsEnd - dfsStart).count();


    // ---------------- BFS TIME ----------------

    cout << "\n";

    auto bfsStart = high_resolution_clock::now();

    graph.BFS(start);

    auto bfsEnd = high_resolution_clock::now();

    auto bfsTime =
        duration_cast<nanoseconds>(bfsEnd - bfsStart).count();


    // ---------------- RESULT ----------------

    cout << "\n\n===== EXECUTION TIME =====\n";

    cout << "DFS Time : " << dfsTime << " nanoseconds\n";
    cout << "BFS Time : " << bfsTime << " nanoseconds\n";

    if (dfsTime < bfsTime)
        cout << "DFS was faster for this input.\n";
    else if (bfsTime < dfsTime)
        cout << "BFS was faster for this input.\n";
    else
        cout << "Both took the same measured time.\n";

    return 0;
}
