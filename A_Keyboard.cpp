#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    string sa = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char c;
    cin >> c;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < sa.size(); j++)
        {
            if (s[i] == sa[j])
            {
                c == 'R' ? cout << sa[j - 1] : cout << sa[j + 1];
                break;
            }
        }
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}
