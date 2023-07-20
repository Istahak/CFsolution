#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<int, int>> vf(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        vf[i].first = v[i];
        vf[i].second = -i;
    }
    sort(vf.begin(), vf.end());
    set<int> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x = vf[i].first;
        int y = -vf[i].second;
        if (m >= x)
        {
            cnt++;
            m -= x;
            //cout << x << endl;
            //y = 0;
            //cout << m << endl;
        }
        else
            y++;
        s.insert(-y);
    }
    s.insert(-cnt);
    int ans = 1;
    for (auto i : s)
    {
        if (i == (-cnt))
            break;
        else
            ans++;
        //cout << i << ' ';
    }
    //cout << endl;
    cout << ans << endl;
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