#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i <= n / 2; i++)
    {
        int x = 0;
        while (i <= (n / 2) && s[i] != s[n - i - 1])
            x++,i++;
        if (x)
            cnt++,i--;
    }
    if (cnt >= 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}