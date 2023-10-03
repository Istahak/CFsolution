#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool ok = false;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W' and ok)
        {
            cnt--;
        }
        else if (s[i] == 'B' and !ok)
        {

            cnt = k - 1;
            ans++;
            ok = true;
        }
        else if (s[i] == 'B' and ok)
        {
            if (cnt == 0)
            {
                cnt = k - 1;
                ans++;
                ok = true;
            }
            else
            {
                cnt--;
            }
        }
        if (cnt == 0)
            ok = false;
    }

    cout << ans << '\n';
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