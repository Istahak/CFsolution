#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1), extra(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        int flag = v[i];
        while (flag % 2 == 0)
        {
            cnt++;
            flag >>= 1;
        }
        int ex = 0;
        flag = i;
        while (flag % 2 == 0)
        {
            ex++;
            flag >>= 1;
        }
        extra[i] = ex;
    }
    sort(extra.rbegin(), extra.rend());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(cnt>=n) break;
        cnt+=extra[i];
        ans++;
    }
    cout<<(cnt>=n ? ans:-1)<<endl;
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
