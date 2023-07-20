#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
vector<int> primes;
void sive()
{
    int n = sqrt(1e8 + 2);
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i * 1ll <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
}
int maxprime(int n)
{
    int mx = INT_MIN;

    for (auto i : primes)
    {
        while (n % i == 0)
        {
            mx = max(i, mx);
            n /= i;
        }
    }
    if (n > 1)
        mx = max(mx, n);

    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    sive();
    int nuans = INT_MIN;
    string ans = "aaaa";
    while (t--)
    {
        string s;
        int n;
        cin >> s >> n;
        int flag = maxprime(n);
       // cout<<flag<<endl;
        if (flag > nuans)
        {
            ans = s;
            nuans = flag;
        }
    }
    cout << ans << endl;
    return 0;
}