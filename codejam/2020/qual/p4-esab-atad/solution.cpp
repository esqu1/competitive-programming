#include <iostream>

using namespace std;

int main()
{
    int t, b;
    cin >> t >> b;
    for (int i = 1; i <= t; ++i) {
        int hypothesis[b];
        if (b == 10) {
            for (int j = 1; j <= 10; ++j) {
                cout << j << endl;
                int response;
                cin >> response;
                hypothesis[j - 1] = response;
            }
            for (int k = 0; k < 10; ++k) {
                cout << hypothesis[k];
            }
            cout << endl;
            char result;
            cin >> result;
            if (result == 'Y') {
                continue;
            } else {
                break;
            }
        } else if (b == 20) {
            int lefthalf = 0, righthalf = 0;
            int response;
            for (int j = 1; j <= 5; ++j) {
                cout << j << endl;
                cin >> response;
                hypothesis[j - 1] = response;
                lefthalf = (lefthalf << 1) + response;
                cout << 21 - j << endl;
                cin >> response;
                hypothesis[20 - j] = response;
                righthalf = (righthalf << 1) + response;
            }
            if (lefthalf == righthalf) {
                // then query one bit and we know what happens
                cout << 5 << endl;
                cin >> response;
                if (response == (lefthalf & 1)) {
                    // then we know the operation made them stay in place,
                    // and we can query freely
                    for (int j = 6; j <= 10; ++j) {
                        cout << j << endl;
                        cin >> response;
                        hypothesis[j - 1] = response;
                        lefthalf = (lefthalf << 1) + response;
                        cout << 21 - j << endl;
                        cin >> response;
                        hypothesis[20 - j] = response;
                        righthalf = (righthalf << 1) + response;
                    }
                }
            }
            // at this point, we have 1/2 of the bits
        }
    }
    return 0;
}
