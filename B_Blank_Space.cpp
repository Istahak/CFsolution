#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n;)
    {
        int cnt = 0;
        if (v[i] == 1)
        {
            i++;
            continue;
        }
        while (i < n and v[i] == 0)
            cnt++, i++;
        ans = max(ans, cnt);
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