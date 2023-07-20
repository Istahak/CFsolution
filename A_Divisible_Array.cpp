#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
    }
    else
    {
        int x = 2;
        for (int i = 1; i <= n; i++)
        {
            cout << x << ' ';
            x += 2;
        }
    }
    cout << endl;
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