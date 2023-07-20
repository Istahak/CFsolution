#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll x = sqrtl(n);
     //cout<<x<<endl;
    ll y = sqrtl(m);
     //cout<<sqrt(n)<<endl;
    ll ans1 = 0;
    bool ok=true;
    if (y == x)
    {
        ll flag[4]={0};
        flag[0] = x * x;
        flag[1] = x * x + x;
        flag[2] = x * x + x + x;
        for (int i = 0; i <= 2; i++)
        {
            if (n <= flag[i] && flag[i] <= m)
                ans1++;
        }
        ok=false;
        
    }

    ll ans2 = (y - x - 1) * 3ll;
    ll arr[7]={0};
    arr[0] = x * x;
    arr[1] = x * x + x;
    arr[2] = x * x + x + x;
    arr[3] = y * y;
    arr[4] = y * y + y;
    arr[5] = y * y + y + y;
    for (int i = 0; i <= 5; i++)
    {
        if (n <= arr[i] && arr[i] <= m)
            ans2++;

    }
    if(ok)
      cout << ans2 << endl;
    else
        cout<<ans1<<endl;  
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
