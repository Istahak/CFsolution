#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int sort_digits(int n)
{

    string s = to_string(n);
    while (s.length() < 4)
    {
        s = "0" + s;
    }

    sort(s.begin(), s.end());
    int p = stoi(s);
    reverse(s.begin(), s.end());
    int q = stoi(s);

    return q - p;
}
void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    // k %= 495;
    for (int i = 1; i <= k; i++)
    {
        n = sort_digits(n);
        if (n == 6174 || n==0)
            break;
    }
     cout << n << endl;
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
