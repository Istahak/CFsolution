#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int k = b + c;
    if (a <= k)
    {
        cout << 2 * a - 1 << endl;
    }
    else
    {
        cout << 2 * k + 1 << endl;
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
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}