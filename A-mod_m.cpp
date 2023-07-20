#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
        s.insert(i);
    }
    if (s.size() == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        v[i] = abs(v[i + 1] - v[i]);
    }
    v.pop_back();
    n--;
    int gc = v[0];
    for (int i = 1; i < n; i++)
    {
        gc = __gcd(gc, v[i]);
    }
    if (gc > 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
    return 0;
}