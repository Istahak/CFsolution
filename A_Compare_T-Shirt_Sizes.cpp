#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    string a, b;
    cin >> a >> b;
    char la = a[a.size() - 1];
    char lb = b[b.size() - 1];
    map<char, int> ma, mb;
    for (auto i : a)
    {
        ma[i]++;
    }
    for (auto i : b)
    {
        mb[i]++;
    }
    if (la < lb)
    {
        cout << ">" << endl;
    }
    else if (la > lb)
    {
        cout << "<" << endl;
    }
    else
    {
        if (ma['X'] == mb['X'])
        {
            cout << "=" << endl;
        }
        else if (ma['X'] > mb['X'])
        {
            if (la == 'L')
                cout << ">" << endl;
            else
                cout << "<" << endl;
        }
        else

        {
            if (la == 'L')
                cout << "<" << endl;
            else
                cout << ">" << endl;
        }
    }
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
