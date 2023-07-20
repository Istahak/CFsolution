#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
        cnt[v[i].first]++;
    }
    sort(v.begin(), v.end());
    vector<int> mis;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            mis.push_back(i);
        }
    }
    // for(auto x:mis)cout<<x<<' ';cout<<endl;
    int pos = 0;
    vector<pair<int, int>> ans1(n);
    vector<pair<int, int>> ans2(n);
    vector<bool> vis(n, false);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (cnt[v[i].first] > 2)
        {
            flag = true;
            break;
        }
        if (cnt[v[i].first] == 2)
        {
            if (pos >= mis.size())
            {
                flag = true;
                break;
            }
            if (mis[pos] > v[i].first)
            {
                flag = true;
                break;
            }
            // if (!vis[v[i].first])
            {
                ans1[i].second = v[i].first;
                ans2[i].second = mis[pos];
                ans1[i].first = v[i].second;
                ans2[i].first = v[i].second;
                // vis[v[i].first] = true;
                ans1[i + 1].second = mis[pos];
                ans2[i + 1].second = v[i].first;
                ans1[i + 1].first = v[i + 1].second;
                ans2[i + 1].first = v[i + 1].second;
            }
            // else
            // {
            //     ans1[i].second = mis[pos];
            //     ans2[i].second = v[i].first;
            //     ans1[i].first = v[i].second;
            //     ans2[i].first = v[i].second;
            // }
            pos++;
            i++;
        }
        else
        {
            ans1[i].second = v[i].first;
            ans2[i].second = v[i].first;
            ans1[i].first = v[i].second;
            ans2[i].first = v[i].second;
        }
    }
    if (!flag)
    {
        cout << "YES" << endl;
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());
        for (auto [x, y] : ans1)
            cout << y << ' ';
        cout << endl;
        for (auto [x, y] : ans2)
            cout << y << ' ';
        cout << endl;
    }
    else
        cout << "NO" << endl;
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