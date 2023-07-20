#include <bits/stdc++.h>
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> in(n + 1, 0);
    ordered_set st;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (in[x] == 0)
            in[x] = i;
        st.insert(i);
    }
    int f = -1;
    while (q--)
    {
        int x;
        cin >> x;
        int ans = st.order_of_key(in[x]);
        st.erase(st.find(in[x]));
        in[x] = f;
        st.insert(f);
        f--;
        cout << (++ans) << endl;
    }
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