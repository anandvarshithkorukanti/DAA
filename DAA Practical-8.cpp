
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
    vector<vector<int>> adjList; // Stores graph connections

public:

    // Constructor: Initializes graph with given vertices
    Graph(int v)
    {
        vertices = v;
        adjList.resize(vertices);
    }

    // Add an undirected edge between two vertices
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Display graph using adjacency list
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

    // DFS using Stack: Visits vertices depth-wise
    void DFS(int start)
    {
        vector<bool> visited(vertices, false); // Track visited vertices
        stack<int> s;

        s.push(start); // Push starting vertex

        cout << "DFS Traversal: ";

        while (!s.empty())
        {
            int current = s.top();
            s.pop(); // Remove top element

            if (visited[current])
                continue;

            visited[current] = true; // Mark as visited
            cout << current << " ";

            // Add unvisited neighbours to stack
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

    // BFS using Queue: Visits vertices level by level
    void BFS(int start)
    {
        vector<bool> visited(vertices, false); // Track visited vertices
        queue<int> q;

        visited[start] = true;
        q.push(start); // Insert starting vertex

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            int current = q.front();
            q.pop(); // Remove front element

            cout << current << " ";

            // Visit all unvisited neighbours
            for (int neighbour : adjList[current])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour); // Add neighbour to queue
                }
            }
        }
    }
};

int main()
{
    int V, E;

    cout << "===== BFS AND DFS GRAPH TRAVERSAL =====\n";

    // Input number of vertices
    cout << "\nEnter number of vertices: ";
    cin >> V;

    // Check valid number of vertices
    if (V <= 0)
    {
        cout << "Invalid number of vertices!";
        return 0;
    }

    Graph graph(V);

    // Input number of edges
    cout << "Enter number of edges: ";
    cin >> E;

    if (E < 0)
    {
        cout << "Invalid number of edges!";
        return 0;
    }

    cout << "\nEnter edges (u v):\n";

    // Read and add graph edges
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        // Check whether vertices are valid
        if (u < 0 || u >= V || v < 0 || v >= V)
        {
            cout << "Invalid edge! Enter vertices between 0 and "
                 << V - 1 << ".\n";

            i--;
            continue;
        }

        graph.addEdge(u, v);
    }

    // Display adjacency list
    graph.displayGraph();

    // Input starting vertex
    int start;

    cout << "\nEnter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= V)
    {
        cout << "Invalid starting vertex!";
        return 0;
    }

    // Measure DFS execution time
    auto dfsStart = high_resolution_clock::now();

    graph.DFS(start);

    auto dfsEnd = high_resolution_clock::now();

    auto dfsTime =
        duration_cast<nanoseconds>(dfsEnd - dfsStart).count();


    // Measure BFS execution time
    cout << "\n";

    auto bfsStart = high_resolution_clock::now();

    graph.BFS(start);

    auto bfsEnd = high_resolution_clock::now();

    auto bfsTime =
        duration_cast<nanoseconds>(bfsEnd - bfsStart).count();


    // Display execution time comparison
    cout << "\n\n===== EXECUTION TIME =====\n";

    cout << "DFS Time : " << dfsTime << " nanoseconds\n";
    cout << "BFS Time : " << bfsTime << " nanoseconds\n";

    // Compare execution times
    if (dfsTime < bfsTime)
        cout << "DFS was faster for this input.\n";
    else if (bfsTime < dfsTime)
        cout << "BFS was faster for this input.\n";
    else
        cout << "Both took the same measured time.\n";

    return 0; // End program
}
