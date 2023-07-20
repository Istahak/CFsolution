#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    bitset<32> g(k);
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        bitset<32> bt(a[i]);
        for (int i = 0; i < 32; i++)
        {
            if (g[i] == 0 and bt[i] == 1)
                ok = false;
        }
        if (ok)
            f |= a[i];
        else
            break;
    }

    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        bitset<32> bt(b[i]);
        for (int i = 0; i < 32; i++)
        {
            if (g[i] == 0 and bt[i] == 1)
                ok = false;
        }
        if (ok)
            f |= b[i];
        else
            break;
    }

    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        bitset<32> bt(c[i]);
        for (int i = 0; i < 32; i++)
        {
            if (g[i] == 0 and bt[i] == 1)
                ok = false;
        }
        if (ok)
            f |= c[i];
        else
            break;
    }
    cout << (f == k ? "Yes" : "No") << endl;
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