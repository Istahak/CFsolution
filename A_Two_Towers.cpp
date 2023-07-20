#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    for (int i = m - 1; i >= 0; i--)
    {
        a.push_back(b[i]);
    }
    int sz = a.size();
    int f = 0;
    for (int i = 0; i < sz - 1; i++)
    {
        if (a[i] == a[i + 1])
            f++;
    }
    cout << (f <= 1 ? "YES" : "NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}