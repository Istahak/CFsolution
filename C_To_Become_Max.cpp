#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), suff(n, 0);
    for (auto &c : v)
        cin >> c;

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            suff[i] = v[i];
            continue;
        }
        if (v[i] > (suff[i + 1] + 1))
        {
            suff[i] = v[i];
        }
        else
        {
            suff[i] = suff[i + 1] + 1;
        }
    }
    int l = *max_element(v.begin(), v.end()), r = suff[0];
    int ans = l;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int opneed = INT_MAX;
        int ok = 0;
        for (int kk = 0; kk < n; kk++)
        {
            int op = 0;
            int cur = mid;
            for (int i = kk; i < n - 1; i++)
            {
                if (op > k)
                {
                    ok = 0;
                    break;
                }
                if (v[i] >= cur and op <= k)
                {
                    // op = 0;
                    ok = 1;
                    break;
                }
                else
                {
                    op += (cur - v[i]);
                    cur--;
                }
            }
            if (ok)
            {
                opneed = op;
                break;
            }
            else if (op <= k)
            {
                if (cur <= v[n - 1])
                {
                    ok = 1;
                    break;
                }
            }
        }
        if (opneed <= k or ok)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
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