#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e6 + 10, M = 1e9 + 7;
int n;
ll dp[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    dp[0] = 1;
    for (auto curr : v)
    {
        vector<int> divisor;
        for (ll i = 1; i * i * 1LL <= curr; i++)
        {
            if (curr % i == 0)
            {
                if ((curr / i) == i)
                    divisor.push_back(i);
                else
                {
                    divisor.push_back(i);
                    divisor.push_back(curr / i);
                }
            }
        }
        sort(divisor.rbegin(), divisor.rend());
        for (auto x : divisor)
            dp[x] += dp[x - 1], dp[x] %= M;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dp[i], ans %= M;
    cout << ans << endl;

    return 0;
}
