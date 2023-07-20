#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    char arr[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];

    set<int> ans[n + 1];
    for (int i = 1; i <= n; i++)
    {
        ans[i].insert(i);
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == '1')
            {
                ans[j].insert(i);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].size() << ' ';
        for (auto ans : ans[i])
            cout << ans << ' ';
        cout << endl;
    }
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