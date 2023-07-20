#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, h, l, r;
ll arr[20006];
ll dp[2006][2006];
ll rec(int index, int curr_hour)
{
    if (index == n + 1)
        return 0;
    if (dp[index][curr_hour] != -1)
        return dp[index][curr_hour];
    int step1 = (curr_hour + arr[index]) % h;
    int step2 = (curr_hour + arr[index] - 1) % h;
    int x = 0, y = 0;
    if (step1 >= l && step1 <= r)
        x = 1;
    if (step2 >= l && step2 <= r)
        y = 1;
    ll ans = max((x + rec(index + 1, step1)), (y + rec(index + 1, step2)));
    return dp[index][curr_hour] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin >> n >> h >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << rec(1, 0) << endl;
    return 0;
}