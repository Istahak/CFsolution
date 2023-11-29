#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll INF = LLONG_MAX;

// Function to add an edge to the residual graph
void addEdge(vector<vector<tuple<int, ll, ll>>> &graph, int from, int to, ll capacity)
{
    graph[from].emplace_back(to, capacity, 0);
    graph[to].emplace_back(from, 0, 0); // Add reverse edge with 0 capacity
}

// Function to find an augmenting path in the residual graph using BFS
bool findAugmentingPath(const vector<vector<tuple<int, ll, ll>>> &graph, vector<int> &parent, int source, int sink)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (auto &[to, capacity, flow] : graph[current])
        {

            if (!visited[to] && capacity - flow > 0)
            {
                parent[to] = current;
                if (to == sink)
                {
                    return true;
                }
                q.push(to);
                visited[to] = true;
            }
        }
    }

    return false;
}

// Ford-Fulkerson algorithm
ll fordFulkerson(vector<vector<tuple<int, ll, ll>>> &graph, int source, int sink)
{
    ll maxFlow = 0;
    int n = graph.size();
    vector<int> parent(n, -1);

    while (findAugmentingPath(graph, parent, source, sink))
    {
        ll pathFlow = LLONG_MAX;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            for (auto &[to, capacity, flow] : graph[u])
            {
                if (to == v)
                {
                    pathFlow = min(pathFlow, capacity - flow);
                    break;
                }
            }
        }

        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            for (auto &[to, capacity, flow] : graph[u])
            {

                if (to == v)
                {
                    flow += pathFlow;
                    break;
                }
            }

            // Update the reverse edge
            for (auto &[to, capacity, flow] : graph[v])
            {

                if (to == u)
                {
                    flow -= pathFlow;
                    break;
                }
            }
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; // Number of nodes and edges

    cin >> n >> m;
    vector<vector<tuple<int, ll, ll>>> graph(n);

    // Input edges and capacities
    for (int i = 0; i < m; i++)
    {
        int from, to;
        ll capacity;

        cin >> from >> to >> capacity;
        from--, to--;
        addEdge(graph, from, to, capacity);
    }

    int source = 0, sink = n - 1;

    // cin >> source >> sink;
    // source--, sink--;

    ll maxFlow = fordFulkerson(graph, source, sink);

    cout << maxFlow << endl;

    return 0;
}
