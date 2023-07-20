#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    for (auto c : s)
    {
        if (c == 'U')
            x++;
        if (c == 'D')
            x--;
        if (c == 'R')
            y++;
        if (c == 'L')
            y--;
        if (x == 1 && y == 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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