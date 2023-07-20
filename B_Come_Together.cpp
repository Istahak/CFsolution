#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    vector<int> v(6);
    for (auto &x : v)
        cin >> x;
    int ans = 0;
    if (v[3] < v[1] and v[5] < v[1])
    {
        ans += min(abs(v[3] - v[1]), abs(v[5] - v[1]));
    }
    if (v[3] > v[1] and v[5] > v[1])
    {
        ans += min(abs(v[3] - v[1]), abs(v[5] - v[1]));
    }
     if (v[2] < v[0] and v[4] < v[0])
    {
        ans += min(abs(v[2] - v[0]), abs(v[4] - v[0]));
    }
     if (v[2] > v[0] and v[4] > v[0])
    {
        ans += min(abs(v[2] - v[0]), abs(v[4] - v[0]));
    }
    cout<<ans+1<<endl;
    
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