#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, sp;
    cin >> n >> sp;
    double speed = sp;
    double s = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        int x;
        cin >> x;
        s += x;
    }
    double ans = s / speed;
    cout << fixed << setprecision(4) << ans << '\n';
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