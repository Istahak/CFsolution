#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1, 0);
    for (int i = n; i >= 2; i--)
    {
        if (ans[i])
            continue;
        int k = log2(i) + 1;
        int p = (1 << k) - 1;
        int pp = (i ^ p);
        ans[i] = pp;
        ans[pp] = i;
    }
    for (int i = 1; i <= n; i++)
    {

        cout << (ans[i] == 0 ? i : ans[i]) << " ";
    }
    cout << endl;
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