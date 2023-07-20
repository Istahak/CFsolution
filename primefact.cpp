#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    string s;
    cin>>s;
    stack<char> st;
    if(s.size()==0){cout<<"Yes\n";return;}
    int i;
    for( i=0;i<s.size();i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else if((st.top()=='('&&s[i]==')')|| (st.top()=='['&&s[i]==']'))
        {
            st.pop();
        }
        else if(s[i]==' ')continue;
        else if(s[i]=='(' || s[i]=='[')
        {
            st.push(s[i]);
        }
        else break;
    }
    if(st.empty()&& i==s.size())cout<<"Yes\n";
    else cout<<"No\n";
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin>>t;
    while (t--)
    {

        solve();
    }

    return 0;
}