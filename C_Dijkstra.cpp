#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, ll>> adj[N];
const ll INF = 1e18 + 10;
vector<ll> dist(N, INF);
vector<int> par(N);
int n, m;
void dijkstra(int source)
{
    set<pair<ll, int>> st;
    st.insert({0LL, source});
    dist[source] = 0;
    while (st.size() > 0)
    {
        auto [v_w, vertex] = *st.begin();
        st.erase(st.begin());

        for (auto [child, c_w] : adj[vertex])
        {

            if (dist[vertex] + c_w < dist[child])
            {
                par[child] = vertex;
                dist[child] = dist[vertex] + c_w;
                st.insert({dist[child], child});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(1);
    if (dist[n] == INF)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    int curr = n;
    while (curr != 1)
    {
        ans.push_back(curr);
        curr = par[curr];
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    for (auto ans : ans)
        cout << ans << ' ';
    cout << endl;

    return 0;
}