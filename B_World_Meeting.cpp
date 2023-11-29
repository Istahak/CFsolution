#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N; // Number of bases
    cin >> N;

    vector<int> W(N); // Number of employees at each base
    vector<int> X(N); // Time offset for each base

    // Input the number of employees and time offset for each base
    for (int i = 0; i < N; i++)
    {
        cin >> W[i];
        cin >> X[i];
    }

    int maxEmployees = 0;

    // Iterate through each possible meeting start time in UTC
    for (int meetingStart = 0; meetingStart < 24; meetingStart++)
    {
        int employeesAvailable = 0;

        // Check if the meeting time is within working hours (9:00-18:00) at each base
        for (int i = 0; i < N; i++)
        {

            int mt = (meetingStart + X[i]) % 24;
            int me = (mt + 1) % 24;

            if (mt >= 9 && mt < 18)
            {
                employeesAvailable += W[i];
            }
        }

        // Update the maximum number of employees
        maxEmployees = max(maxEmployees, employeesAvailable);
    }

    cout << maxEmployees << endl;

    return 0;
}
