#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for (auto c : s)
        v[c]++;
    string a, b;
    bool ok1 = false, ok2 = false;
    for (int i = 0; i < 26; i++)
    {
        if (v[i] == 0)
            continue;
        if (v[i] & 1)
        {
            
        }
        else
        {
            int f = v[i] / 2;
            while (f--)
            {
                a.push_back(i + 'a');
                b.push_back(i + 'a');
            }
            v[i]=0;
        }
    }
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