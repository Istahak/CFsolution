#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;

void solve()
{
    int n;
    cin >> n;
    map<string, int> mps;
    map<char, int> mpcf, mpcs;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ans += (mpcf[s[0]] + mpcs[s[1]] - 2 * mps[s]);
        mpcf[s[0]]++;
        mpcs[s[1]]++;
        mps[s]++;
    }

    cout << ans << endl;
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