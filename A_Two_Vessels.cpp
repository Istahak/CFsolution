#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    double a, b, c;
    cin >> a >> b >> c;
    double d = (abs(a - b) / 2);
    cout << ceil(d / c) << endl;
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