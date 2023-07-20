#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool is_palindrome(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
void solve()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    if (is_palindrome(v))
    {
        cout << 0 << endl;
        return;
    }
    int gc = 0;
    for (int i = 0; i < n / 2; i++)
    {
        gc = __gcd(gc, abs(v[i] - v[n - i - 1]));
    }
    cout << gc << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case #" << cs << ": ";
        solve();
    }
    return 0;
}