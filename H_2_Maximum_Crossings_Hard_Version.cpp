#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define endl "\n"

using namespace std;
using namespace __gnu_pbds;
using namespace std;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// long long int a, b;
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ordered_set s;

    for (ll i = 0, x; i < n; i++)
    {
        cin >> x;
        s.insert(x);
        ans += (i - s.order_of_key(x));
    }
    // for(auto s:s)cout<<s<<' ';cout<<endl;
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