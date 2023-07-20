#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    double d, h;
    cin >> n >> d >> h;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    double ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        double diff = v[i + 1] - v[i];
        if (diff >= h)
        {
            ans += (0.5 * d * h);
        }
        else
        {
            // cout << diff << endl;
            diff = h - diff;
            double bas = ((diff * d) / h);
            // cout << bas << endl;
            ans += (0.5 * d * h);
            ans -= (0.5 * bas * diff);
        }
    }
    ans += (0.5 * d * h);
    printf("%.6lf\n", ans);
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}