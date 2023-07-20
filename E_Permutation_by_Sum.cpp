#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int sum(int n)
{
    return (n * (n + 1)) / 2;
}
void solve()
{
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int len = r - l + 1;
    int mi = sum(len);
    int mx = 0;
    for (int i = n; i > n - len; i--)
        mx += i;
    if (mx < s or mi > s)
    {
        cout << -1 << endl;
        return;
    }
    queue<int> good, bed;
    int ss = 0;
    for (int i = n; i >= 1; i--)
    {
        int need = s - ss;
        int eneed = len - good.size();

        if (eneed and need >= i + sum(eneed-1))
        {
            good.emplace(i);
            ss += i;
        }
        else
        {
            bed.emplace(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i >= l and r >= i)
        {
            cout << good.front() << ' ';
            good.pop();
        }
        else
        {
            cout << bed.front() << ' ';
            bed.pop();
        }
    }
    cout << endl;
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