#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll l, r;
    cin >> l >> r;
    bitset<63> bl(l), br(r);
    int f = -1;
    for (int i = 62; i >= 0; i--)
    {
        if (bl[i] != br[i])
        {
            f = i;
            break;
        }
    }
    cout << (1LL << (f + 1)) - 1 << endl;
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