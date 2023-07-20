#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    double x, y;
    cin >> x >> y;
    double vcr, vm;
    cin >> vcr >> vm;
    double dis = sqrt((x / 2) * (x / 2) + y * y);
    double vca = (dis * vcr) / (2 * x - dis);

    vca = max(vca, vcr);
    printf("%.15g\n", vca);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}