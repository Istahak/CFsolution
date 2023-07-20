#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int w, d, h;
    cin >> w >> d >> h;
    int a, b, f, g;
    cin >> a >> b >> f >> g;
    int xx = h + a + f + abs(b - d);
    int xxx = h + abs(w - a) + abs(w - c) + abs(b - d);
    int yy = h + abs(d - b) + abs(d - f) + abs(a - f);
    int yyy = h + b + g + abs(a - f);
    cout << min({xx, xxx, yy, yyy}) << endl;
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