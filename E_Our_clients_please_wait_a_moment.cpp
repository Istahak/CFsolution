#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll INF = LLONG_MAX;
const int N = 1e3 + 10;
vector<pair<int, ll>> adj[N];
vector<ll> dist(N, INF);
vector<pair<int, ll>> adj1[N];
vector<ll> dist1(N, INF);
vector<int> par(N);
int n, m;
void dijkstra1(int source)
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

void dijkstra2(int source)
{
    set<pair<ll, int>> st;
    st.insert({0LL, source});
    dist1[source] = 0;
    while (st.size() > 0)
    {
        auto [v_w, vertex] = *st.begin();
        st.erase(st.begin());

        for (auto [child, c_w] : adj1[vertex])
        {

            if (dist1[vertex] + c_w < dist1[child])
            {

                dist1[child] = dist1[vertex] + c_w;
                st.insert({dist1[child], child});
            }
        }
    }
}
void solve()
{
    ll A, B, C;
    cin >> n >> A >> B >> C;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll x;
            cin >> x;
            ll costc = x * A;
            ll costb = x * B + C;
            adj[i].push_back({j, costc});
            adj1[i].push_back({j, costb});
        }
    }
    dijkstra1(0);
    dijkstra2(n - 1);
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {

        ans = min(ans, dist[i] + dist1[i]);
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}