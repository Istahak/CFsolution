#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string L, R;
    cin >> L >> R;
    int nl = L.size(), rl = R.size();
    int ex = rl - nl;
    string sex(ex, '0');
    L = sex + L;
    nl = L.size();
    int ans = abs(L[0] - R[0]);
    bool ok = false;
    for (int i = 1; i < rl; i++)
    {
        if (L[i - 1] < R[i - 1])
            ok = true;
        if (ok)
        {
            ans += 9;
        }
        else
        {
            ans = abs(L[i] - R[i]);
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