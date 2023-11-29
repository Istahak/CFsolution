#include <bits/stdc++.h>
#define ll long long int
using lll = __int128_t;
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
struct DSU
{
    int n, sz;
    vector<int> p; // root: -1 * component size, otherwise: parent
    DSU(int n) : n(n), sz(n), p(n, -1) {}
    bool same(int a, int b) { return root(a) == root(b); }
    int root(int a) { return p[a] < 0 ? a : (p[a] = root(p[a])); }
    int size(int a) { return -p[root(a)]; }
    int size() { return sz; }
    bool merge(int a, int b, bool rank = true)
    {
        int x = root(a), y = root(b);
        if (x == y)
            return false;
        sz--;
        if (rank and -p[x] < -p[y])
            swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return true;
    }
};
ll dis(ll x1, ll y1, ll x2, ll y2)
{
    ll dx = x1 - x2, dy = y1 - y2;

    return dx * dx + dy * dy;
}
void solve()
{
    ll n;
    cin >> n;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<tuple<ll, ll, ll>> circle(n);
    for (auto &[x, y, r] : circle)
        cin >> x >> y >> r;

    DSU st(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            auto [x1, y1, r1] = circle[i];
            auto [x2, y2, r2] = circle[j];
            ll ss = r1 + r2;
            ll sss = r1 - r2;
            ss *= ss;
            sss *= sss;
            ll dd = dis(x1, y1, x2, y2);
            if (dd > ss)
                continue;
            if (dd < sss)
                continue;
            st.merge(i, j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto [x1, y1, r1] = circle[i];
            auto [x2, y2, r2] = circle[j];
            if (dis(sx, sy, x1, y1) == r1 * r1 and dis(tx, ty, x2, y2) == r2 * r2)
            {
                if (st.same(i, j))
                {
                    cout << "Yes" << '\n';
                    return;
                }
            }
        }
    }

    cout << "No" << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}