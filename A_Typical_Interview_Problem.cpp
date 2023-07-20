#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    string ss;
    for (int i = 1; i < 300; i++)
    {
        if (i % 3 == 0)
            ss.push_back('F');
        if (i % 5 == 0)
            ss.push_back('B');
    }


    int n;
    cin >> n;
    string s;
    cin >> s;
    if (ss.find(s) != std::string::npos)
    {
        // This matches! We're still within the original string
        cout << "YES" << endl;
    }
    else
    {
        // Oops! Out of bounds. Print error message!
        cout << "NO" << endl;
    }
    // int ok = ss.find(s);
    // if (ok == -1)
    //     cout << "NO" << endl;
    // else
    //     cout << "YES" << endl;
    // cout<<ok<<endl;
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