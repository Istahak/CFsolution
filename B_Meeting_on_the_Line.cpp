#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<double> x(n), t(n);
    for (auto &i : x)
        cin >> i;
     double mx = INT_MIN, mi = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        if ((x[i] + p) >= mx)
        {
            mx = x[i] + p;
        }
        if ((x[i] - p) <= mi)
        {
            mi = x[i] - p;
        }
    }

   double ans = (double(mx) + double(mi)) / 2.0;
    printf("%.7lf\n",ans);
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
