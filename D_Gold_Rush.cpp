#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    if (m > n)
    {
        cout << "NO" << endl;
        return;
    }
    int gc = __gcd(n, m);
    n /= gc, m /= gc;
    bool ok = ((m & (m - 1)) == 0);
    int cnt2 = 0;
    while (m % 2 == 0)
    {
        m /= 2;
        cnt2++;
    }
    int cnt3 = 0;
    while (n % 3 == 0)
        n /= 3, cnt3++;
    if (n != 1)
        ok = false;
    cout << (ok && (cnt2 <= cnt3) ? "YES" : "NO") << endl;
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