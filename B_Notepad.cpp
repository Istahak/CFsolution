#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n <= 2)
    {
        cout << "NO" << endl;
        return;
    }
    map<string, ll> mp;
    set<string> st;
    string ps;
    ps.push_back(s[0]);
    ps.push_back(s[1]);
    // cout<<ps<<' ';
    bool ok = false;
    mp[ps]++;
    for (int i = 2; i < n; i++)
    {
        string x;
        x.push_back(s[i - 1]);
        x.push_back(s[i]);
        if (mp[x])
        {
            
            if ((x == ps && mp[x] > 1) ||(x==ps))

            {
                cout << "YES" << endl;
                return;
            }

            break;
        }

        mp[x]++;
        st.insert(x);
        ps = x;
    }

    cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}