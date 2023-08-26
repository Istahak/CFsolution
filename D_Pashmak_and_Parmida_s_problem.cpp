#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<ll> L(n + 1), R(n + 1);
    map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        cnt[v[i]]++;
        L[i] = cnt[v[i]];
    }
    cnt.clear();
    for (int i = n; i >= 1; i--)
    {
        cnt[v[i]]++;
        R[i] = cnt[v[i]];
    }
    ll ans = 0;
    ordered_set st;
    for (int i = n; i >= 1; i--)
    {
        ans += st.order_of_key({L[i], -1});
        st.insert({R[i], i});
    }
    cout << ans << endl;
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