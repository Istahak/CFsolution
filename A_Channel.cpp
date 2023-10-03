#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    if (n == a)
    {
        cout << "YES" << endl;
        return;
    }
    int cnt = 0;
    for (auto c : s)
    {
        cnt += (c == '-' ? -1 : +1);
        if (cnt + a == n)
        {
            cout << "YES" << endl;
            return;
        }
    }
    int p = count(s.begin(), s.end(), '+');
    if (a + p >= n)
    {
        cout << "MAYBE" << endl;
        return;
    }
    cout << "NO" << endl;
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