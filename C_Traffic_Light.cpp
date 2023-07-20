#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    char p;
    string s;
    cin >> n >> p >> s;
    int ans = INT_MIN;
    int cnt = 0;
    int first = 0;
    bool flag = false;
    for (auto c : s)
    {
        if (c == p)
        {
            flag = true;
        }
        if (flag)
        {
            cnt++;
        }
        if (c == 'g')
        {
            cnt--;
            ans = max(ans, cnt);
            cnt = 0;
            flag = false;
        }
    }
    if (cnt)
    {
        int i = 0;
        for (auto c : s)
        {
            if (c == 'g')
                break;
            i++;
        }
        cnt += (i);
        ans = max(ans, cnt);
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
