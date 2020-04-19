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

void solve() {
    int x2, y2;
    cin >> x2 >> y2;
    int x = abs(x2);
    int y = abs(y2);
    int i = 0;
    string build = "";
    while (x != 0 || y != 0) {
        if ((x & (1 << i)) == (y & (1 << i))) {
            cout << "IMPOSSIBLE" << endl;
            break;
        }
        if ((x & (1 << i)) != 0) {
            if (x == (1 << i) && y == 0) {
                build += (x2 > 0 ? 'E' : 'W');
                break;
            }

            int diff = (x & (1 << (i+1))) ^ (y & (1 << (i+1)));
            if (x2 > 0) {
                build += (diff ? 'E' : 'W');
            } else {
                build += (diff ? 'W' : 'E');
            }
            if (diff) {
                x -= 1 << i;
            } else {
                x += 1 << i;
            }
        } else { 
            if (y == (1 << i) && x == 0) {
                build += (y2 > 0 ? 'N' : 'S');
                break;
            }

            int diff = (x & (1 << (i+1))) ^ (y & (1 << (i+1)));
            if (y2 > 0) {
                build += (diff ? 'N' : 'S');
            } else {
                build += (diff ? 'S' : 'N');
            }
            
            if (diff) {
                y -= 1 << i;
            } else {
                y += 1 << i;
            } 
        }
        i++;
    }
    cout << build << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();     
    }
}
