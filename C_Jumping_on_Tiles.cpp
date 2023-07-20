#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
// long long int a, b;
void solve()
{
    string s;
    cin >> s;
    char first = s[0];
    char last = s[s.size() - 1];
    vector<pair<char, ll>> v;
    for (int i = 0; i < s.size(); i++)
    {
        v.push_back({s[i], i + 1});
    }
    sort(v.begin(), v.end());

    if (first <= last)
    {
        ll cost = 0;
        vector<int> va;
        // va.push_back(1);
        bool flag = true;
        char mid = first;
        int indfis = 0, indlas = 0;
        for (int i = 0; i < v.size(); i++)
        {

            if (v[i].first == first && flag)
                indfis = i, flag = false;
            if (v[i].first == last)
            {
                indlas = i;
            }
        }
        for (int i = indfis; i <= indlas; i++)
        {
            cost += v[i].first - mid;
            va.push_back(v[i].second);
            mid = v[i].first;
        }

        cout << cost << ' ' << va.size() << endl;
        for (auto i : va)
            cout << i << ' ';
        cout << endl;
    }
    else
    {
        sort(v.rbegin(), v.rend());
        ll cost = 0;
        vector<int> va;
        // va.push_back(1);
        bool flag = true;
        char mid = first;
        int indfis = 0, indlas = 0;
        for (int i = 0; i < v.size(); i++)
        {

            if (v[i].first == first && flag)
                indfis = i, flag = false;
            if (v[i].first == last)
            {
                indlas = i;
            }
        }
        for (int i = indfis; i <= indlas; i++)
        {
            cost += mid - v[i].first;
            if (v[i].second != 1 && v[i].second != s.size())
                va.push_back(v[i].second);
            mid = v[i].first;
        }

        cout << cost << ' ' << va.size() + 2 << endl;
        cout << 1 << ' ';
        for (auto i : va)
            cout << i << ' ';
        cout << s.size() << endl;
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