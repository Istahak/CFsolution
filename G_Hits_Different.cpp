#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2026, M = 1e6 + 10;
ll arr[N][N];
ll ans[M];
void init()
{
    ll row = 1;
    for (int i = 1; i < N; i++)
    {
        ll cur = row, col = i + 1;
        for (int j = 1; j < N; j++)
        {
            arr[i][j] = cur * cur;
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            if (cur < M)
            {
                ans[cur] = arr[i][j];
            }
            cur += col++;
        }
        row += i;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    init();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}