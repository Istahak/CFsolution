#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> cnt(10, 0);
        int flag = 0;
        int k = i + 101;
        if (k <= n)
        {
            for (int j = i; j < k; j++)
            {
                if (!cnt[s[j] - '0'])
                    flag++;
                cnt[s[j] - '0']++;
                int mx = max({cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], cnt[5], cnt[6], cnt[7], cnt[8], cnt[9]});
                if (mx <= flag)
                    ans++;
            }
        }
        else
        {
            for (int j = i; j < n; j++)
            {
                if (!cnt[s[j] - '0'])
                    flag++;
                cnt[s[j] - '0']++;
                int mx = max({cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], cnt[5], cnt[6], cnt[7], cnt[8], cnt[9]});
                if (mx <= flag)
                    ans++;
            }
        }
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