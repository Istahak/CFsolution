#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    int tk = m / k;
    int t1 = m % k;
    int total1 = min(a1, t1);
    t1 -= total1;
    a1 -= total1;
    ak += (a1 / k);
    int totalak = min(ak, tk);
    tk -= totalak;
    ak -= totalak;
    cout << tk + t1 << endl;
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