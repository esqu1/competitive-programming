#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;

int binsearchrow(int rownum, bool isLeft, bool isHor) {
    int left = -pow(10, 9);
    int right = pow(10, 9);
    int mid = 0;
    string response;
    int result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isHor) {

            cout << mid << " " << rownum << endl;
        } else {
            cout << rownum << " " << mid << endl;
        }
        cin >> response;
        if (response.compare("CENTER") == 0) {
            return -pow(10, 9) - 1;
        }
        if (response.compare("HIT") == 0) {
            result = mid;
            if (isLeft) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (isLeft) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return result;
}

void solve(int A, int B) {
    int leftSide = binsearchrow(0, true, true);
    if (leftSide == -pow(10, 9) - 1) {
        return;
    }
    int rightSide = binsearchrow(0, false, true);
    if (rightSide == -pow(10, 9) - 1) {
        return;
    }
    int center = 0;
    string response;
    if (leftSide % 2 == 0) {
        center = (leftSide + rightSide) / 2;
        int topSide = binsearchrow(center, true, false);
        if (topSide == -pow(10, 9) - 1) {
            return;
        }
        int bottomSide = binsearchrow(center, false, false);
        if (bottomSide == -pow(10, 9) - 1) {
            return;
        }
        int vertCenter = (topSide + bottomSide) / 2;
        cout << center << " " << vertCenter << endl; 
        cin >> response;
    } else {
        double centerApprox = (leftSide + rightSide) / 2;
        center = floor(centerApprox);
        int i = 0;
        while (i < 2) {
            int topSide = binsearchrow(center + i, true, false);
            if (topSide == -pow(10,9) - 1) {
                return;
            }
            int bottomSide = binsearchrow(center + i, false, false);
            if (bottomSide == -pow(10, 9) - 1) {
                return;
            }
            int vertCenter = (topSide + bottomSide) / 2;
            cout << center << " " << vertCenter << endl;
            cin >> response;
            if (response.compare("CENTER") != 0) {
                i++;
                continue;
            } else {
                break;
            }
            i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b;
    cin >> t >> a >> b;
    for (int i = 1; i <= t; ++i) {    
        solve(a, b);     
    }
}
