#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<int>> prefix(n + 1, vector<int>(32, 0));

    for (int i = 0; i < 32; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((1 << i) & v[j]))
                prefix[j][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            prefix[i][j] += prefix[i - 1][j];
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j < 32; j++)
    //     {
    //         cout << prefix[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    auto ispos = [&](int mid, int l)
    {
        int k = 0;
        int len = (mid - l + 1);
        for (int i = 0; i < 32; i++)
        {
            int sum = prefix[mid][i] - prefix[l - 1][i];
            if (len == sum)
            {
                k += (1 << i);
            }
        }
        return k;
    };
    int q;
    cin >> q;
    while (q--)
    {
        int l, x;
        cin >> l >> x;
        int left = l, right = n;
        int ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (ispos(mid, l) >= x)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
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