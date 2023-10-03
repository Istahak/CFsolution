#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int>> mp;
void init()
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            mp[(1 << i) - (1 << j)] = {i, j};
        }
    }
}
void test_case()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    long long int sum = accumulate(v.begin(), v.end(), 0LL);

    int avg = sum / n;
    if (sum % n)
    {
        cout << "No" << endl;
        return;
    }

    bool ok = true;
    vector<int> bs(32, 0);
    for (auto &x : v)
    {
        int shiftamount = avg - x;
        if (shiftamount != 0)
        {
            if (mp.find(shiftamount) == mp.end())
            {
                cout << "No" << endl;
                return;
            }
            auto [add, sub] = mp[shiftamount];
            bs[add]++;
            bs[sub]--;
        }
    }
    for (auto x : bs)
    {
        if (x != 0)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    init();
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        test_case();
    }

    return 0;
}