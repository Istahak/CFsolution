#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> mx, my;
    int row = 0, col = 0;
    for (int i = 1; i <= 3; i++)
    {
        int x, y;
        cin >> x >> y;
        mx[x]++;
        my[y]++;
    }
    for (auto i : mx)
    {
        if (i.second == 2)
            row = i.first;
    }
    for (auto i : my)
    {
        if (i.second == 2)
            col = i.first;
    }
    //cout << row << ' ' << col << endl;
    int x, y;
    cin >> x >> y;
    if ((row == 1 && col == 1) || (row == 1 && col == n) || (row == n && col == 1) || (row == n && col == n))
    {
        cout << ((row == x || col == y) ? "YES" : "NO") << endl;
    }
    else
    {
        cout << ((row % 2 == x % 2 || col % 2 == y % 2) ? "YES" : "NO") << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
