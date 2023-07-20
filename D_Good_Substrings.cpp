#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int m = 1e9 + 9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    int n;
    cin >> s >> t >> n;
    set<pair<ll, ll>> ans;
    int sz = s.size();
    for (int i = 0; i < sz; i++)
    {
        ll x = 0;
        ll p = 1;
        ll y = 0;
        ll q = 1;
        int f = 0;
        for (int j = i; j < sz; j++)
        {

            if (t[s[j] - 'a'] == '0')
                f++;
            if (f > n)
                break;
            x = (x + p * (s[j] - 'a' + 1) % m);
            p = (p * 31ll) % m;
            y = (y + q * (s[j] - 'a' + 1) % m);
            q = (q * 29ll) % m;
            ans.insert({x, y});
        }
    }
    cout << ans.size() << endl;

    return 0;
}