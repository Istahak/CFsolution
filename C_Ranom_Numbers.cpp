#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 2e9 + 5;
int value[] = {1, 10, 100, 1000, 10000};

int getMax(vector<vector<vector<int>>> &dp, string &str, int currIdx = 0, int currMax = 0, int rem = 1)
{
    if (currIdx == str.length())
        return 0;
    int &memo = dp[currIdx][currMax][rem];
    if (memo != -INF)
        return memo;
    int charIdx = str[currIdx] - 'A';
    int possibleAnswer = -INF;

    if (rem == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            int temp = value[i];
            if (i >= currMax)
                possibleAnswer = max(possibleAnswer, temp + getMax(dp, str, currIdx + 1, i, 0));
            else
                possibleAnswer = max(possibleAnswer, -temp + getMax(dp, str, currIdx + 1, currMax, 0));
        }
    }

    int temp = value[charIdx];
    if (charIdx >= currMax)
        possibleAnswer = max(possibleAnswer, temp + getMax(dp, str, currIdx + 1, charIdx, rem));
    else
        possibleAnswer = max(possibleAnswer, -temp + getMax(dp, str, currIdx + 1, currMax, rem));

    return memo = possibleAnswer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        reverse(s.begin(), s.end());

        int n = s.length();

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(6, vector<int>(2, -INF)));

        int answer = getMax(dp, s);

        cout << answer << endl;
    }

    return 0;
}