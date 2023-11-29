#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    while (true)
    {
        string s = to_string(n);
        int a = s[0] - '0';
        int b = s[1] - '0';
        int c = s[2] - '0';
        if (a * b == c)
        {
            cout << s << '\n';
            return;
        }
        n++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}