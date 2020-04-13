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

void solve()
{
    int r, c;
    cin >> r >> c;

    int interests[r][c];
    int compInterest = 0;
    int totalInterest = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> interests[i][j];
            totalInterest += interests[i][j];
        }
    }
    compInterest = totalInterest;
    int step = 0;
    while (++step) {
        int left = false;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int left = j - 1, right = j + 1, up = i - 1, down = i + 1;
                float avg = 0;
                while (left >= 0 && interests[i][left] == -1) {
                    left--;
                }

                while (right < c && interests[i][right] == -1) {
                    right++;
                }

                while (up >= 0 && interests[up][j] == -1) {
                    up--;
                }

                while (down < r && interests[down][j] == -1) {
                    down++;
                }

                int count = 0;
                if (left >= 0 && left < c) {
                    avg += interests[i][left];
                    count++;
                }
                if (right >= 0 && right < c) {
                    avg += interests[i][right];

                    count++;
                }
                if (up >= 0 && up < r) {
                    avg += interests[up][j];

                    count++;
                }
                if (down >= 0 && down < r) {
                    avg += interests[down][j];
                    count++;
                }
                if (count > 0) {
                    avg /= count;
                } else {
                    continue;
                }
                cout << avg << endl;
                cout << interests[i][j] << endl;
                if (avg > interests[i][j]) {
                    totalInterest -= interests[i][j];
                    interests[i][j] = -1;
                    left = true;
                }
            }
        }
        if (left) {
            compInterest += totalInterest;
        } else {
            break;
        }
    }
    cout << compInterest;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
