#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = s;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '1')
            continue;
        for (int j = i; j <= s.size(); j += i)
        {
            if (s[j - 1] == '1')
                break;
            else
            {
                if (s1[j - 1] == '0')
                    ans += i;
                s1[j - 1] = '1';
                // cout<<ans<<endl;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
