#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Prim's Algorithm
int Prim(int start_vertex, vector<vector<pair<int, int>>> &graph)
{
    // Min-priority queue: (weight, vertex)
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > PQ;
    vector<bool> visited(graph.size(), false);
    PQ.push({0, start_vertex});
    int total_weight = 0;
    while (!PQ.empty())
    {
     
        int weight = PQ.top().first;
        int u = PQ.top().second;
        PQ.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        total_weight += weight;
        for (auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (!visited[v])
            {
                PQ.push({w, v});
            }
        }
    }
    return total_weight;
}

int main()
{
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});
    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});
    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});
    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});
    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});
    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});
    graph[3].push_back({4, 9});
    graph[4].push_back({3, 9});
    int total = Prim(0, graph);
    cout << "Minimum Spanning Tree Weight = " << total << endl;
    return 0;
}
