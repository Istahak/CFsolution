#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    ll one = 0, zero = 0;
    // s[0] == '1' ? one++ : zero++;

    for (int i = 0; i < n - 1;)
    {
        if (s[i] == '0')
        {
            ll ans = one + zero + 1;
            ll cnt = 0;
            while (s[i] == '0' && i < n - 1)
            {
                cout << ans << ' ';
                cnt++;
                i++;
            }
            zero += cnt;
        }
        else
        {
            ll ans = one + zero + 1;
            ll cnt = 0;
            while (s[i] == '1' && i < n - 1)
            {
                cout << ans << ' ';
                cnt++;
                i++;
            }
            one += cnt;
        }
    }
    
    cout<< endl;
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