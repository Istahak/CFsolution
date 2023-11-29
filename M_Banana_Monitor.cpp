#include <iostream>

using namespace std;

int main() {
    unsigned int a, b;
    cin >> a >> b;

    unsigned int result = 0;
    unsigned int mask = 1;

    while (true) {
        if (((a & mask) == 0) && ((b & mask) != 0)) {
            result |= mask;
        }
        mask <<= 1;
        if (mask == 0) {
            break;
        }
    }

    cout << result << endl;

    return 0;
}
