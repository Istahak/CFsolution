#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int mod = 1e9 + 7, N = 2e5 + 10;
ll pw[N];
long long power(long long a, long long b)
{
    long long x = 1;
    while (b)
    {
        if (b & 1)
            x = x * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return x;
}
long long addmod(long long a, long long b)
{
    long long ans = (a % mod + b % mod) % mod;
    return ans;
}
long long submod(long long a, long long b)
{
    long long ans = (a % mod - b % mod + mod) % mod;
    return ans;
}
long long mulmod(long long a, long long b)
{
    long long ans = ((a % mod) * (b % mod)) % mod;
    return ans;
}
void solve()
{
    int x, y;
    cin>>x>>y;
    if(y==100){
        cout<<-1<<endl;
        return;
    }
    int temp = x*y;
    temp+=(100-y-1);
    temp/=(100-y);
    cout<<x+temp<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // pw[0] = 1;
    // for (int i = 1; i < N; i++)
    // {
    //     pw[i] = mulmod(pw[i - 1], 2);
    // }
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}