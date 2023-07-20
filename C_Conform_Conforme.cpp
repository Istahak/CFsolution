#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    unordered_map<int, int> mp;
    for (auto &i : v)
        cin >> i, mp[i]++;
    unordered_map<int, int> cnt, cnt1;
    for (int i = 0; i < n; i++)
    {
        v[i] = mp[v[i]];
        cnt[v[i]]++;
    }
    k--;
    vector<int> pre = v;
    int flag = 1;
    while (k--)
    {
        if (flag & 1)
        {
            for (int i = 0; i < n; i++)
            {
                v[i] = cnt[v[i]];
                cnt1[v[i]]++;
            }
            cnt.clear();
            flag++;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                v[i] = cnt1[v[i]];
                cnt[v[i]]++;
            }
            cnt1.clear();
            flag++;
        }
        if (pre == v)
            break;
        pre = v;
    }

    for (auto ans : v)
        cout << ans << ' ';
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}