#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int x = 1, y = n;
    for (; x < y; x++, y--)
    {
        cout << y << ' ' << x << ' ';
    }
    if (n & 1)
        cout << x << ' ';
    cout << endl;
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