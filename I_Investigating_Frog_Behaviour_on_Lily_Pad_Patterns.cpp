#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e6 + 10;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
void solve()
{
    set<int> st;
    for (int i = 1; i < N; i++)
        st.insert(i);
    int n;
    cin >> n;
    vector<int> v(N);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[i] = x;
        st.erase(x);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        auto it = st.lower_bound(v[x]);
        int ans = *it;
        cout << ans << endl;
        st.erase(*it);
        st.insert(v[x]);
        v[x] = ans;
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