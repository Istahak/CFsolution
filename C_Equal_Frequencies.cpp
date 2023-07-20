#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(26, 0);
    for (auto c : s)
    {
        cnt[c - 'a']++;
    }
    int ans = n;
    for (int k = 1; k <= 26; k++)
    {
        if (n % k != 0)
            continue;
        int d = n / k;
        int tot = k;
        vector<int> v;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] >= d)
                tot--;
            else
                v.push_back(d - cnt[i]);
        }
        sort(v.begin(), v.end());
        int res = 0;
        for (int i = 0; i < tot; i++)
            res += v[i];
        ans = min(ans, res);
    }
    cout << ans << endl;
    string t = s;
    for (int k = 1; k <= 26; k++)
    {
        if (n % k != 0)
            continue;
        int d = n / k;
        int tot = k;
        vector<pair<int, int>> v;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] >= d)
                tot--;
            else
                v.push_back({d - cnt[i], i});
        }
        sort(v.begin(), v.end());
        int res = 0;
        for (int i = 0; i < tot; i++)
            res += v[i].first;
        if (res == ans)
        {
            vector<int> f(26, 1);
            for (int i = tot; i < (int)v.size(); i++)
            {
                f[v[i].second] = 0;
            }
            for (int i = 0; i < n; i++)
            {
                if (f[s[i] - 'a'] == 0 || cnt[s[i] - 'a'] > d)
                {
                    cnt[s[i] - 'a']--;
                    for (int j = 0; j < 26; j++)
                    {
                        if (cnt[j] < d && f[j])
                        {
                            cnt[j]++;
                            t[i] = 'a' + j;
                            break;
                        }
                    }
                }
            }
            break;
        }
    }
    cout << t << endl;
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