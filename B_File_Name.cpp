#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    int ans = 0;
    for (auto c : s)
    {
        if (c == 'x')
        {
            cnt++;
            if (cnt >= 3)
                ans++;
        }
        else
            cnt = 0;
    }
    cout << ans << endl;
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