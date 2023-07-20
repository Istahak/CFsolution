#include <bits/stdc++.h>
#define ll long long int
using namespace std;
unordered_map<char, int> mp;
void solve()
{
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    while (n--)
    {
        string s, x;
        cin >> s;
        for (auto c : s)
        {
            if (c == 'a' || c == 'b' || c == 'c')
                x.push_back('2');

            if (c == 'd' || c == 'e' || c == 'f')
                x.push_back('3');

            if (c == 'g' || c == 'h' || c == 'i')
                x.push_back('4');

            if (c == 'j' || c == 'k' || c == 'l')
                x.push_back('5');

            if (c == 'm' || c == 'n' || c == 'o')
                x.push_back('6');

            if (c == 't' || c == 'u' || c == 'v')
                x.push_back('8');

            if (c == 'p' || c == 'q' || c == 'r' || c == 's')
                x.push_back('7');

            if (c == 'w' || c == 'x' || c == 'y' || c == 'z')
                x.push_back('9');
        }
        mp[x]++;
    }
    while (m--)
    {
        string x;
        cin >> x;
        cout << mp[x] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;
    while (tt--)
        solve();

    return 0;
}