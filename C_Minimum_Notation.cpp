#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    char c = '9';
    int ans[10];
    for (int i = 0; i < 10; i++)
        ans[i] = 0;

    
    for (auto i : s)
    {
        if (i <= c)
        {
            ans[i - '0']++;
            //cout<<i<<' '<<i-'0'<<endl;
            c = i;
            continue;
        }
        if (i == '9')
        {   
            //cout<<i<<' '<<9<<endl;
            ans[9]++;
        }
        else
        {
            //cout<<i<<' '<<i-'0'+1<<endl;
            ans[i - '0' + 1]++;
        }
    }
    //cout<<endl;
    for (int i = 0; i < 10; i++)
    {
        while (ans[i]--)
        {
            cout << i;
        }
    }
    cout << endl;
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
