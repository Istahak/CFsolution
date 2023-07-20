#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
const int N = 1e5 + 7;
vector<pair<int,int>> g[N];
vector<ll> dis(N, LLONG_MAX);
vector<bool> vis(N);
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }
    set<pair<ll,int>> st;
    st.insert({0, 1});
    dis[1] = 0;
    while (!st.empty())
    {
        auto node = *st.begin();
        int vertex = node.second;
        st.erase(st.begin());
        if (vis[vertex])
            continue;
        vis[vertex] = true;
        for (auto child : g[vertex])
        {
            int child_v = child.first;
            ll wt = child.second;
            if (dis[vertex] + wt < dis[child_v])
            {
                dis[child_v] = dis[vertex] + wt;
                st.insert({dis[child_v], child_v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << ' ';
    }
    cout << endl;

    return 0;
}
