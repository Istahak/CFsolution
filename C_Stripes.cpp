
#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    //int n;
    //cin >> n;
    char v[8][8];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> v[i][j];
    char ans = 'c';
    bool flag = true;
    for (int i = 0; i < 8; i++)
    {
        int cnt = 0;
        for (int j = 0; j < 8; j++)
        {
            if (v[i][j] == 'R')
            {
                cnt++;
            }
        }
        if (cnt == 8)
        {
            ans = 'R';
            flag = false;
        }
    }
    if (flag)
    {
        for (int i = 0; i < 8; i++)
        {
            int cnt = 0;
            for (int j = 0; j < 8; j++)
            {
                if (v[j][i] == 'B')
                {
                    cnt++;
                }
            }
            if (cnt == 8)
            {
                ans = 'B';
                flag = false;
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
