#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
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
    int n, q;
    cin >> n >> q;
    vector<int> cnt(10, 0);
    auto ok = [&](int di)
    {
        while (di)
        {
            cnt[di % 10]++;
            di /= 10;
        }
    };
    auto okk = [&](int di)
    {
        while (di)
        {
            cnt[di % 10]--;
            di /= 10;
        }
    };
    ordered_set st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ok(x);
        st.insert(x);
    }
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '?')
        {
            int k;
            cin >> k;
            if (st.find(k) == st.end())
            {
                cout << -1 << '\n';
                continue;
            }
            int ans = 0;
            while (k)
            {
                ans += cnt[k % 10];
                k /= 10;
            }
            cout << ans << '\n';
        }
        if (c == '+')
        {
            int k;
            cin >> k;
            if (st.find(k) == st.end())
            {
                ok(k);
                st.insert(k);
            }
            else
            {
                st.erase(k);
                okk(k);
            }
        }
        if (c == '-')
        {
            int k;
            cin >> k;
            // k--;
            if (st.size() >= k)
            {
                k = st.size() - k;
                auto it = st.find_by_order(k);
                // cout << (*it) << '\n';
                okk(*it);
                st.erase(it);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}