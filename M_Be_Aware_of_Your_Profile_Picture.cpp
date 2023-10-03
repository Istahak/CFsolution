#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> cnt(k, 0);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
        for (int j = k - 1; j >= 0; j--)
        {
            if (((1 << j) & x))
                cnt[j]++;
        }
    }
    int ans = 0;
    vector<int> vis(n, false);
    set<int> take;
    for (int i = k - 1; i > 0; i--)
    {
        if (cnt[i] == n)
        {
            ans += (1 << i);
            take.insert(i);
        }
        else
        {
            vector<int> idx;
            for (int id = 0; id < n; id++)
            {
                if ((v[id] & (1 << i)) == 0)
                {
                    idx.push_back(id);
                }
            }
            bool ok = true;
            for (auto d : idx)
            {
                if (vis[d])
                    ok = false;
            }
            if (ok)
            {
                ans += (1 << i);
                for (auto d : idx)
                {
                    vis[d] = true;
                }
                take.insert(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        if ((v[i] & 1) == 0)
            cnt[0]++;
        else
        {
            bool ok = false;
            for (int j = k - 1; j >= 0; j--)
            {
                if ((v[i] & (1 << j)) == 0)
                {
                    cnt[j]++, ok = true;
                    break;
                }
                else
                {
                    if (take.count(j) == 0)
                    {
                        cnt[j]--;
                        ok = true;
                        break;
                    }
                }
            }
        }
    }
    if (cnt[0] == n)
        ans++;
    cout << ans << '\n';
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