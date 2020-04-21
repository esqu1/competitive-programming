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
    int n;
    cin >> n;
    if (n % 4 == 2) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
    }
    int total = 0;
    for (int i = 1; i <= n / 2; i++) {
        cout << 2 * i << " "; 
        total += 2 * i;
    }
    for (int i = 1; i < n / 2; i++) {
        cout << 2 * i - 1 << " ";
        total -= 2 * i - 1;
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();     
    }
}
