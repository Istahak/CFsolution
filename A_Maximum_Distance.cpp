#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    for (auto &x : x)
        cin >> x;
    for (auto &x : y)
        cin >> x;
    ll ans = LLONG_MIN;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ll AA = (x[i] - x[j]);
            ll BB = (y[i] - y[j]);
            ans = max(ans, AA * AA + BB * BB);
        }
    }
    cout << ans << endl;
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