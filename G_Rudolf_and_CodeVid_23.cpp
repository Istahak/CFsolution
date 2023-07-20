#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<pair<int, int>> adj[1 << 12];
vector<ll> dist(1 << 12, 1e9);
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

                dist[child] = dist[vertex] + c_w;
                st.insert({dist[child], child});
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int mask = 1 << n;
    for (int i = 0; i < mask; i++)
        adj[i].clear(), dist[i] = 1e9;
    string ss;
    cin >> ss;
    int source = bitset<11>(ss).to_ulong();
    for (int i = 0; i < m; i++)
    {
        int wt;
        cin >> wt;
        string a, b;
        cin >> a >> b;
        int aa = bitset<11>(a).to_ulong();
        int bb = bitset<11>(b).to_ulong();
        for (int j = 0; j < mask; j++)
        {
            int u = j;
            int v = (j & (~aa)) | bb;
            adj[u].push_back({v, wt});
        }
    }
    dijkstra(source);
    cout << (dist[0] == 1e9 ? -1 : dist[0]) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}