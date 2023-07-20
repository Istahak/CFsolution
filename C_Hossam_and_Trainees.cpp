#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
vector<int> primes;
set<int> s;
bool flag = false;
void prime(int n)
{
    while (n % 2 == 0)
    {
        s.insert(2);
        n /= 2;
    }
    for (auto i : primes)
    {
        while (n % i == 0)
        {
            s.insert(i);
            n /= i;
        }
    }
    if (n > 1)
        s.insert(n);
}
bool fact(int n)
{
    if (n % 2 == 0)
    {
        if (s.count(2))
            return true;
    }
    while (n % 2 == 0)
    {

        s.insert(2);
        n /= 2;
    }
    for (auto i : primes)
    {
        if (n % i == 0)
        {

            if (s.count(i))
                return true;
        }
        while (n % i == 0)
        {

            s.insert(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        if (s.count(n))
            return true;

        s.insert(n);
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    flag = false;
    s.clear();
    sort(v.begin(), v.end());
    prime(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (fact(v[i]))
        {
            flag = true;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    cin >> t;
    int sq = sqrt(1e9 + 1);
    vector<int> flag(sq + 2);
    primes.push_back(2);
    for (int i = 3; i <= sq; i += 2)
    {
        if (flag[i] == 0)
        {
            primes.push_back(i);
            for (int j = i * i; j <= sq; j += 2 * i)
            {
                flag[j] = 1;
            }
        }
    }
    while (t--)
    {

        solve();
    }

    return 0;
}