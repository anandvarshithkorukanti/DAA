#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Store edge details
struct Edge
{
    int u, v, weight;
};

// Find the parent of a vertex
int findParent(vector<int>& parent, int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

// Join two sets using rank
void unionSet(vector<int>& parent, vector<int>& rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u == v)
        return;

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

// Apply Kruskal's algorithm
void Kruskal(vector<Edge>& edges, int V)
{
    // Sort edges by weight
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    vector<int> parent(V);
    vector<int> rank(V, 0);

    // Initially, every vertex is its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int total_weight = 0;
    int edge_count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    // Select edges with minimum weight
    for (Edge e : edges)
    {
        int u = findParent(parent, e.u);
        int v = findParent(parent, e.v);

        // Add edge only if it does not form a cycle
        if (u != v)
        {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;

            total_weight += e.weight;

            // Join the two sets
            unionSet(parent, rank, u, v);

            edge_count++;

            // MST contains V-1 edges
            if (edge_count == V - 1)
                break;
        }
    }

    cout << "Total Weight = " << total_weight << endl;
}

int main()
{
    int V = 5;

    // Define graph edges and their weights
    vector<Edge> edges =
    {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    Kruskal(edges, V);

    return 0;
}
