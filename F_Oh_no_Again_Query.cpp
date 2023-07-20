#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5 + 10;
struct query
{
    int type;
    int u;
    int x;
};
vector<pair<int, int>> edg(N);
stack<int> wt[N];
vector<bool> deleted(N);
vector<query> qu(N);
vector<int> par(N);
vector<int> who[N];
multiset<int> values[N];
int n, m, q;
int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(x);
}
void marge(int u, int v)
{
    int ru = par[u];
    int rv = par[v];
    if (ru == rv)
        return;
    int szu = who[ru].size();
    int szv = who[rv].size();
    if (szu < szv)
        swap(ru, rv);
    for (auto x : who[rv])
    {
        par[x] = ru;
        who[ru].push_back(x);
    }
    for (auto x : values[rv])
    {
        values[ru].emplace(x);
    }
    who[rv].clear();
    values[rv].clear();
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        wt[i].push(x);
    }
    for (int i = 1; i <= m; i++)
        cin >> edg[i].first >> edg[i].second;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> qu[i].type;
        if (qu[i].type == 1)
        {
            cin >> qu[i].u;
            deleted[qu[i].u] = true;
        }
        if (qu[i].type == 2)
        {
            cin >> qu[i].u >> qu[i].x;
            wt[qu[i].u].push(qu[i].x);
        }
        if (qu[i].type == 3)
            cin >> qu[i].u;
    }
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        who[i].push_back(i);
        values[i].emplace(wt[i].top());
    }
    for (int i = 1; i <= m; i++)
    {
        if (deleted[i])
            continue;
        auto &[u, v] = edg[i];
        marge(u, v);
    }
    vector<int> ans;
    for (int i = q; i >= 1; i--)
    {
        auto &[t, u, x] = qu[i];

        if (t == 1)
        {
            auto &[uu, v] = edg[u];
            marge(uu, v);
        }
        if (t == 2)
        {
            int ru = par[u];
            int cuv = wt[u].top();
             wt[u].pop();
             values[ru].erase(values[ru].find(cuv));
             values[ru].emplace(wt[u].top());
        }
        if (t == 3)
        {
            int ru = par[u];
            int aaa = *values[ru].rbegin();
            ans.push_back(aaa);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto aa : ans)
        cout << aa << endl;
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