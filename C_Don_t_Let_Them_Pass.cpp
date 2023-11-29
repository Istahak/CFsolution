#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e3+10;
vector<int> v(1004 + 1);
int dp[N][N];
int n, m;
int ber_kor(int pos, int state)
{
    if (pos>m) return 0;
    if(dp[pos][state]!=-1) return dp[pos][state];
    int op1 = abs(state-v[pos])+ber_kor(pos+1, state);
    int op2 = INT_MAX, op3 = INT_MAX;
    if(state>1) op2 = abs(state-1-v[pos])+ber_kor(pos+1, state-1);
    if(state<n) op3 = abs(state+1-v[pos])+ber_kor(pos+1, state+1);
    return dp[pos][state] = min(op1, min(op2, op3));
}
void solve()
{
    cin >> n >> m;
    int g[n + 1][m + 1];
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (g[i][j] == 1)
            {
                v[j] = i;
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 1; i<=n; ++i){
        ans = min(ber_kor(1, i), ans);
    }
    cout<<ans<<endl;
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