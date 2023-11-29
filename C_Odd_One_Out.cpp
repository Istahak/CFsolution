#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> ele;
void solve()
{
    ll a, b;
    cin >> a >> b;
    auto it = upper_bound(ele.begin(), ele.end(), b) - ele.begin();
    auto itt = lower_bound(ele.begin(), ele.end(), a) - ele.begin();
    cout << it - itt  << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    for (ll i = 1; i * i <= 1e9; i++)
        ele.push_back(i * i);
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}