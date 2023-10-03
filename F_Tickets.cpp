#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e6;
int prefix[N][30];
int Unluckiness(int n)
{
    string s = to_string(n);
    string ss(6 - s.size(), '0');
    s = ss + s;
    int ans = abs(s[0] + s[1] + s[2] - s[3] - s[4] - s[5]);
    return ans;
}
void init()
{
    for (int i = 0; i < N; i++)
    {
        int dif = Unluckiness(i);
        prefix[i][dif] = 1;
    }
    for (int dif = 0; dif < 30; dif++)
    {
        for (int i = 1; i < N; i++)
        {
            prefix[i][dif] += prefix[i - 1][dif];
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    int dif = Unluckiness(n);
    int ans = 0;
    for (int i = 0; i < dif; i++)
    {
        ans += prefix[n][i];
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}