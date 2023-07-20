#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int a, b;
    cin >> a >> b;
    if (a != 1)
    {
        cout << a - 1 << endl;
        return;
    }
    cout << a + b << endl;
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