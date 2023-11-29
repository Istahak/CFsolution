#include <bits/stdc++.h>
#define ll long long int
using namespace std;
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
    void update(int l, int r, T v)
    {
        update(l, v);
        update(r + 1, -v);
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
    string s;
    cin >> s;
    s = "#" + s;
    BIT<ll> bt(n + 2);
    set<int> two, three;
    auto chk_two = [&](int pos)
    {
        if (pos + 1 > n or pos <= 0)
            return false;
        ll x = s[pos] - 'a' + bt.pref(pos);
        x %= 26;
        ll y = s[pos + 1] - 'a' + bt.pref(pos + 1);
        y %= 26;
        return x == y;
    };
    auto chk_three = [&](int pos)
    {
        if (pos + 2 > n or pos <= 0)
            return false;
        ll x = s[pos] - 'a' + bt.pref(pos);
        x %= 26;
        ll y = s[pos + 2] - 'a' + bt.pref(pos + 2);
        y %= 26;
        return x == y;
    };
    auto update = [&](int pos)
    {
        // abcsaa
        //    pos-3,pos-2,pos-1,pos,pos+1,pos+2,pos+3

        for (int cur = pos - 2; cur <= pos + 2; cur++)
        {
            if (two.count(cur))
                two.erase(cur);
            if (three.count(cur))
                three.erase(cur);
        }

        for (int cur = pos - 2; cur <= pos + 2; cur++)
        {
            if (chk_two(cur))
                two.insert(cur);
            if (chk_three(cur))
                three.insert(cur);
        }
    };
    for (int i = 1; i <= n; i++)
    {
        update(i);
    }
    while (q--)
    {
        int ty, l, r;
        cin >> ty >> l >> r;
        if (ty == 1)
        {
            ll val;
            cin >> val;
            bt.update(l, r, val);
            update(l), update(r);
        }
        else
        {
            auto it = two.lower_bound(l);
            bool ok = false;
            if (it != two.end() and (*it) + 1 <= r)
                ok = true;
            it = three.lower_bound(l);
            if (it != three.end() and (*it) + 2 <= r)
                ok = true;
            cout << (ok ? "NO" : "YES") << '\n';
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
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}