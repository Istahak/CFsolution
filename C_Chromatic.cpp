#include <bits/stdc++.h>
using namespace std;

void test_case()
{
    int n;
    cin >> n;
    vector<int> red(n);
    vector<int> blue(n);
    for (auto &r : red)
        cin >> r;
    for (auto &b : blue)
        cin >> b;
    sort(red.begin(), red.end());
    sort(blue.rbegin(), blue.rend());
    vector<int> violet(n);
    for (int i = 0; i < n; i++)
    {
        violet[i] = red[i] + blue[i];
    }
    sort(violet.begin(), violet.end());
    cout << violet.back() - violet.front() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //   cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        test_case();
    }

    return 0;
}