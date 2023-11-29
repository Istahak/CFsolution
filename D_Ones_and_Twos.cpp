#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif
template <class T>
class BIT
{
public:
    int n;
    vector<T> f;
    BIT(int n) : n(n)
    {
        f.resize(n + 1, (T)0);
    }
    BIT(const vector<T> &a)
    { // O(n)
        n = a.size();
        f.assign(n + 1, (T)0);
        for (int i = 1; i <= n; i++)
        {
            f[i] += a[i - 1];
            if (i + (i & -i) <= n)
            {
                f[i + (i & -i)] += f[i];
            }
        }
    }
    void update(int p, T v)
    {
        while (p <= n)
            f[p] += v, p += p & -p;
    }
    T pref(int p)
    {
        T ret = 0;
        while (p)
            ret += f[p], p -= p & -p;
        return ret;
    }
    T range(int l, int r)
    {
        return pref(r) - pref(l - 1);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    int l = -1, r = -1;
    set<int> idex[3];
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        idex[v[i]].insert(i);
    }
    BIT<ll> bt(n + 2);
    for (int i = 1; i <= n; i++)
    {
        bt.update(i, v[i]);
    }
    while (q--)
    {
        int ty, s;
        cin >> ty >> s;
        if (ty == 1)
        {
            if (idex[1].empty())
            {
                ll sum = bt.range(1, n);
                if (s % 2 == 0 and sum >= s)
                {
                    cout << "YES" << '\n';
                }
                else
                {
                    cout << "NO" << '\n';
                }
            }
            else
            {
                ll frist = (*idex[1].begin());
                ll rr = bt.range(frist, n);
                if (s <= rr)
                {
                    cout << "YES" << '\n';
                    continue;
                }
                ll rrleft = bt.range(1, frist - 1);
                if ((s - rr) % 2 == 0 and rrleft >= (s - rr))
                {
                    cout << "YES" << '\n';
                    continue;
                }
                ll second = (*idex[1].rbegin());
                ll lef = bt.range(1, second);
                if (s <= lef)
                {
                    cout << "YES" << '\n';
                    continue;
                }
                ll lefff = bt.range(second, n);
                if ((s - lef) % 2 == 0 and lefff >= (s - lef))
                {
                    cout << "YES" << '\n';
                    continue;
                }
                cout << "NO" << '\n';
            }
        }
        else
        {
            int val;
            cin >> val;
            idex[v[s]].erase(s);
            bt.update(s, -v[s]);
            v[s] = val;
            idex[val].insert(s);
            bt.update(s, val);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}