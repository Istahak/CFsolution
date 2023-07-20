#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<int>> time(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        vector<int> v(m);
        for (auto &x : v)
            cin >> x;
        sort(v.begin(), v.end());
        time[i] = v;
    }
    ll fs = 0, ft = 0, ans = 1, cur = 0, pre = 0;
    for (auto x : time[0])
    {
        cur = x + pre;
        if (cur > h)
            break;
        fs++;
        ft += cur;
        pre += x;
    }
    for (int i = 1; i < n; i++)
    {
        ll ccur = 0, cpre = 0, cfs = 0, cft = 0;
        for (auto x : time[i])
        {
            ccur = x + cpre;
            if (ccur > h)
                break;
            cfs++;
            cft += ccur;
            cpre += x;
        }
        if (cfs > fs)
            ans += 1;
        else if (cfs == fs)
        {
            if (ft > cft)
                ans += 1;
        }
    }
    cout << ans << endl;
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