#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 10;
const ll INF = 1e18 + 10;

vector<vector<pair<int, ll>>> adj1(N);
vector<vector<pair<int, ll>>> adj2(N);

vector<ll> dist1(N, INF);
vector<ll> dist2(N, INF);

int n, m;
void dijkstra(int source, vector<vector<pair<int, ll>>> &adj)
{
    set<pair<ll, int>> st;
    st.insert({0LL, source});
    dist1[source] = 0;
    while (st.size() > 0)
    {
        auto [v_w, vertex] = *st.begin();
        st.erase(st.begin());

        for (auto [child, c_w] : adj[vertex])
        {

            if (dist1[vertex] + c_w < dist1[child])
            {
                dist1[child] = dist1[vertex] + c_w;
                st.insert({dist1[child], child});
            }
        }
    }
}
void dijkstra2(int source, vector<vector<pair<int, ll>>> &adj)
{
    set<pair<ll, int>> st;
    st.insert({0LL, source});
    dist2[source] = 0;
    while (st.size() > 0)
    {
        auto [v_w, vertex] = *st.begin();
        st.erase(st.begin());

        for (auto [child, c_w] : adj[vertex])
        {

            if (dist2[vertex] + c_w < dist2[child])
            {
                dist2[child] = dist2[vertex] + c_w;
                st.insert({dist2[child], child});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<tuple<int, int, ll>> edg;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edg.emplace_back(u, v, w);
        adj1[u].push_back({v, w});
        adj2[v].push_back({u, w});
    }
    dijkstra(1, adj1);
    dijkstra2(n, adj2);
    ll ans = LLONG_MAX;
    for (auto [u, v, w] : edg)
    {
        ans = min(ans, dist1[u] + dist2[v] + w / 2);
    }
    cout << ans << endl;

    return 0;
}