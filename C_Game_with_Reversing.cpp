#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int change(string &s)
{

    int n = s.length();
    int cc = 0;

    for (int i = 0; i < n / 2; i++)
    {

        if (s[i] == s[n - i - 1])
            continue;

        cc += 1;

        if (s[i] < s[n - i - 1])
            s[n - i - 1] = s[i];
        else
            s[i] = s[n - i - 1];
    }

    return cc;
}
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    // a and b
    string AS = a + b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    int xx1 = change(AS);
    if (xx1 & 1)
        xx1 += (xx1);
    else
        xx1 += (xx1 - 1);
    // a and rev b
    reverse(b.begin(), b.end());
    if (a == b)
    {
        cout << 2 << endl;
        return;
    }
    AS = a + b;
    int xx2 = change(AS);
    if (xx2 & 1)
        xx2 += (xx2 - 1);
    else
        xx2 += (xx2);
    cout << min({xx1, xx2}) << endl;
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