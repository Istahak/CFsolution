#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5 + 10;
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
    vector<int> v(N);
    BIT<ll> bt(N);
    int i = 1;
    for (; i <= n; i++)
    {

        cin >> v[i];
        bt.update(i, 1);
    }
    while (q--)
    {
        char c;
        cin >> c;
        if (c == 'c')
        {
            int s;
            cin >> s;
            int l = 1, r = i - 1;
            int ans = -1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                int curs = bt.range(1, m);

                if (curs >= s)
                {
                    ans = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            if (ans == -1)
            {
                cout << "none\n";
            }
            else
            {
                cout << v[ans] << '\n';
                bt.update(ans, -1);
            }
        }
        else
        {

            int x;
            cin >> x;
            v[i] = x;
            bt.update(i, 1);
            i++;
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
        cout << "Case " << cs << ":\n";
        solve();
    }
    return 0;
}