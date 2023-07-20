#include <bits/stdc++.h>
#define ll long long int
using namespace std;
string s;
const int N = 1e6 + 10;
const ll M = 1e9 + 7;
ll dp[N];
ll ber_kor(int i)
{
    if (i == s.size() - 1)
        return 1LL;

    if (i == s.size() - 2)
    {
        if (s[i] == 'C' && s[i + 1] == 'T')
        {
            return 1LL;
        }
        else if (s[i] == 'T' && s[i + 1] == 'T')
        {
            return 1LL;
        }
        else
            return 2LL;
    }
    if (i >= s.size())
        return 0LL;
    if (dp[i] != -1)
        return dp[i];
    if (s[i] == 'T' || (s[i] == 'C' && s[i + 1] != 'T') || (s[i] == 'T' && s[i + 1] != 'T'))
        return dp[i] = ((ber_kor(i + 1)) % M + (ber_kor(i + 2)) % M) % M;
    else
        return dp[i] = ber_kor(i + 1) % M;
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> s;
    cout << ber_kor(0) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}