#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int ask(int x, int y)
{
    cout << "? " << x << ' ' << y << endl;
    int q;
    cin >> q;
    return q;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), vv(n);
    int x = -1, y = -1;
    int a = INT_MAX, b = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        v[i] = ask(0, i);
        vv[i] = ask(i, 0);
        a = min(a, v[i]);
        b = min(b, vv[i]);
    }
    cout << a << ' ' << b << endl;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    cout << x << ' ' << y << endl;
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