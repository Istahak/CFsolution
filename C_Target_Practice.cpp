#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int target[10][10] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 2, 2, 2, 2, 2, 2, 1, 0},
    {0, 1, 2, 3, 3, 3, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 4, 4, 3, 2, 1, 0},
    {0, 1, 2, 3, 3, 3, 3, 2, 1, 0},
    {0, 1, 2, 2, 2, 2, 2, 2, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
void solve()
{
    vector<string> v(10);
    for (auto &x : v)
        cin >> x;
    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (v[i][j] == 'X')
                ans += target[i][j] + 1;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}