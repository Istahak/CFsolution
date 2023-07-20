#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool isPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26, 0);
    for (auto c : s)
        cnt[c - 'a']++;
    int ok = 0, okk = 0;
    for (auto x : cnt)
    {
        if (x & 1)
            ok++;
        else if (x == 0)
            continue;
        else
            okk++;
    }
    bool f = false;
    if (isPalindrome(s))
    {
        if (n & 1)
        {
            if (ok == 1 && okk >= 2)
            {
                f = true;
            }
            if (ok == 1 && okk >= 1)
            {
                int y;
                for (auto x : cnt)
                {
                    if (x & 1)
                    {
                        y = x;
                    }
                }
                if (y >= 3)
                    f = true;
            }
        }
        else
        {
            if (okk >= 2)
                f = true;
        }
    }
    else
    {
        if (n & 1)
        {
            if (ok == 1)
                f = true;
        }
        else
        {
            if (ok == 0)
                f = true;
        }
    }
    cout << (f ? "YES" : "NO") << endl;
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