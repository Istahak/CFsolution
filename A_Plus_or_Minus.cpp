#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c)
        cout << '+' << endl;
    else
        cout << '-' << endl;
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
