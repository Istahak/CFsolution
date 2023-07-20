#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x] = i;
    }
    int mi = INT_MAX, mx = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, mp[i]), mi = min(mi, mp[i]);
        // cout<<mx<<' '<<mi<<endl;
        cout << (mx - mi + 1 == i);
    }
    cout << endl;
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