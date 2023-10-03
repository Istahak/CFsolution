#include <bits/stdc++.h>
#define lll __int128_t
using namespace std;
void solve()
{
    long long int n;
    cin >> n;

    lll ans = -1;
    lll l = 1, r = n;
    auto ispossible = [&](lll mid)
    {
        lll cur = mid * (mid - 1);
        cur /= 2;
        return cur;
    };
    while (l <= r)
    {
        lll mid = l + (r - l) / 2;

        if (ispossible(mid) <= n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    lll cur = ispossible(ans);
    lll extra = n - cur;
    long long int aaa = ans + extra;
    cout << aaa << endl;
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