#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
char c[52][52], ch;
int cnt = 0, mxx = 0, ans = -1;
int dp[54][54];
int DFS(int x, int y, int cnt, char ch)
{
    if (dp[x][y] != -1)
       {
        if(x==0 || y==0) return 0;
            else return dp[x][y];
       }
    if (c[x][y] == '.')
    {   
        if(x==0 || y==0) return 0;
       else return dp[x - 1][y - 1] = max(dp[x - 1][y - 1], cnt);
    }   
    if (c[x][y] != ch)
        return dp[x - 1][y - 1] = max(dp[x - 1][y - 1], cnt);

    cnt++;
    cout<<cnt<<endl;
    ans = max(ans, cnt);
    ch++;
    DFS(x, y + 1, cnt, ch);
    DFS(x, y - 1, cnt, ch);
    DFS(x + 1, y, cnt, ch);
    DFS(x - 1, y, cnt, ch);
    DFS(x + 1, y + 1, cnt, ch);
    DFS(x + 1, y - 1, cnt, ch);
    DFS(x - 1, y + 1, cnt, ch);
    DFS(x - 1, y - 1, cnt, ch);
   
    
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    // cin >> t;
    while (t)
    {
        for (int i = 0; i < 52; i++)
            for (int j = 0; j < 52; j++)
                c[i][j] = '.';


        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> c[i][j];

        int mx = INT_MIN;
        memset(dp, -1, sizeof(dp));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                ch = c[i][j];
                if (ch == 'A')
                    mx = max(mx, DFS(i, j, cnt, ch));
                cnt = 0;
                mxx = 0;

                memset(dp, -1, sizeof(dp));
                ans = -1;
            }

        cout << "Case " << t << ": " << mx << endl;
        t++;
    }

    return 0;
}
// https://www.spoj.com/problems/ABCPATH/
