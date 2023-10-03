#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;

    auto a = s;
    auto b = s;
    auto c = s;
    swap(a[0], a[1]);
    swap(b[1], b[2]);
    swap(c[0], c[2]);
    cout << (("abc" == a or "abc" == b or "abc" == c or s == "abc") ? "YES" : "NO") << endl;
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