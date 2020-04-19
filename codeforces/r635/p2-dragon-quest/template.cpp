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
    int x, n, m;
    cin >> x >> n >> m;
    if (x <= 20) {
        if (x <= 10 * m) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    } else {
        for (int i = 0; i < n; ++i) {
            x = (x / 2) + 10;
            if (x <= 20) {
                break;
            }
        }
    }
    if (x <= 10 * m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}
