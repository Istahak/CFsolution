#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
ll exrta(ll i)
{   
    if(i==0) return 0;
    return (i * (i + 1)) / 2;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0;
    int i = 1, j = 1;
    ll cnt = 0;
    bool flag = false;
    while (i <= n)
    {
        while (v[i] >= j && i <= n)
        {
            if (!flag)
            {
                ans -= exrta(cnt);
            }
            i++;
            j++;
            cnt++;
            flag = true;
        }

        if (flag)
        {
            ans += exrta(cnt);
            flag = false;
        }
        j--;
        cnt--;
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
