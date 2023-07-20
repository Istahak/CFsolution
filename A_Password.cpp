#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    while (n--)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    ll sz = mp.size();
    sz = 10 - sz;
    cout << sz * (sz - 1) * 3 << endl;
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
