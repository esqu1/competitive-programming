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
    ll n;
    cin >> n;
    ll x;
    for (int i = 2; i < log(n) / log(2) + 1; i++) {
        ll p = pow(2, i);
        if (n % (p - 1) == 0) {
            cout << n / ( p - 1 ) << endl;
            break;
        }
    }
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
