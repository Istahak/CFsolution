#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
string a;
void solve()
{
    string s;
    cin >> s;
    auto found = a.find(s);
    if (found != string::npos)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    for (int i = 0; i < 50; i++)
    {
        a.push_back('Y');
        a.push_back('e');
        a.push_back('s');
    }
    t = 1;
    cin >> t;
    while (t--)
    {

        solve();
    }

    return 0;
}