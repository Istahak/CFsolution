#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, s, r;
    cin >> n >> s >> r;
    int mx = s - r;
    vector<int> v(n, mx);
    int sum = mx * n;
    for (int i = 1; i < n; i++)
    {
        if ((sum - s) > (mx - 1))
        {
            sum -= (mx - 1);
            v[i] = 1;
        }
        else
        {
            v[i] -= (sum - s);
            sum=s;
            
        }
    }
    for(auto ans:v)cout<<ans<<' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}