#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;

void solve()
{
    int n;
    string s;
    cin>>n;
    int arr[n+19];
    memset(arr, 0, sizeof(arr));
    cin >> s;
    map<ll, ll> mp;
    int flag = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            flag++;
            //cout<<flag<<endl;
            if (arr[flag] == 0 && flag != 1)
            {
                mp[flag]++;
                arr[flag] = 1;
            }
        }
        else
        {
            flag--;
        }
        if (flag == 0)
        {
            memset(arr, 0, sizeof(arr));
        }
    }
    ll ans = 1;
    for (auto i : mp)
    {   
        //cout<<i.second<<' ';
        ans += i.second;
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