#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(n);
    ll sum = 0;
    // vector<pair<int, int>> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // v[i].first = v1[i];
        // v[i].second = i;
    }

    ll ans = 0;
    bool flag = false;
    int mi = 0;
    int i = 0;
    for (auto c : s)
    {
        if (c == '0')
        {
            mi = v[i];
        }
        else if (c == '1')
        {
            ans += max(v[i], mi);
            if (v[i] < mi)
                mi = v[i];
        }
        i++;
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
