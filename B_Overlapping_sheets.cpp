#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N_MAX = 16;
const int INF = 1e9;

int N;                     // Number of vertices
int weight[N_MAX][N_MAX];  // Weight of edges between vertices
int dp[1 << N_MAX][N_MAX]; // dp[mask][last] represents the maximum weight of chosen edges with mask as the subset of vertices and last as the last vertex in the subset

int maxWeight(int mask, int last)
{
    if (mask == (1 << N) - 1)
    {
        return 0; // All vertices are included in the subset
    }

    if (dp[mask][last] != -1)
    {
        return dp[mask][last]; // Return memoized result
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        if (!(mask & (1 << i)) && last != i)
        {
            ans = max(ans, weight[last][i] + maxWeight(mask | (1 << i), i));
        }
    }

    return dp[mask][last] = ans;
}

int main()
{
    cin >> N;

    // Input edge weights
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i ; j < N; j++)
        {
            cin >> weight[i][j];
        }
    }

    // Initialize the dp table with -1 (unvisited)
    memset(dp, -1, sizeof(dp));

    int ans = 0;

    // Iterate through all possible starting vertices
    for (int i = 0; i < N; i++)
    {
        ans = max(ans, maxWeight(1 << i, i));
    }

    cout << ans << endl;

    return 0;
}
