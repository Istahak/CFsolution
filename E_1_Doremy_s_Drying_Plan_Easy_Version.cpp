#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
// find_by_order(k) : iterator to the k'th element (0-indexed)
// order_of_key(k) : number of items strictly smaller than k
// auto cmp = [](int a, int b) { return a < b; };
// tree<int, null_type, decltype(cmp)> x(cmp);
// tree<int, null_type, function<bool(int, int)>> y(
//     [](int a, int b) { return a < b; });
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ordered_set left, right;
    vector<ll> diff(n + 2, 0);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        left.insert({l, i});
        right.insert({r, i});
        diff[l]++, diff[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
        diff[i] += diff[i - 1];
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n;
        int curans = -1;
        while (l <= r)
        {

            int mid = (l + r) / 2;
            int cnt = left.order_of_key({mid + 1, INT_MIN});
            int cnt2 = right.order_of_key({i, INT_MIN});
            if (cnt - cnt2 <= k)
            {
                curans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        ans = max(ans, curans - i + 1LL);
    }
    ll aa = 0;
    vector<ll> aaa;
    for (int i = 1; i <= n; i++)
    {
        if (diff[i] == 0)
        {
            aa++;
            continue;
        }
        int l = i, r = n;
        int curans = -1;
        while (l <= r)
        {

            int mid = (l + r) / 2;
            int cnt = left.order_of_key({mid + 1, INT_MIN});
            int cnt2 = right.order_of_key({i, INT_MIN});
            if (cnt - cnt2 <= 1)
            {
                curans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            if (curans != -1)
                aaa.push_back(curans - i + 1);
        }
    }
    // cout << aa << '\n';
    sort(aaa.rbegin(), aaa.rend());
    if (aaa.size() >= 2)
    {
        cout << aaa[1] << '\n';
        ans = max(ans, aa + aaa[0] + aaa[1]);
    }
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