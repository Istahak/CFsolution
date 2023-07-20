#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        v[x] = i;
    }
    for(int i=1;i<=n;i++)cout<<v[i]<<' ';cout<<endl;
    return 0;
}