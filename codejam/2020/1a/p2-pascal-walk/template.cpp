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

int C(int n, int k)
{
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return res;
}

int rowsum(int x)
{
    int r = 1, k = 1;
    int total = 0;
    bool right = true;
    while (r < x) {
        total += C(r - 1, k - 1);
        if (right) {
            k++;
        }
        r++;
        right = !right;
    }
    // r = x
    while (k >= 2) {
        total += C(r - 1, k - 1);
        k--;
    }
    return total;
}

void solve()
{
    int n;
    cin >> n;
    int i = 1;
    while (true) {
        if (rowsum(i) > n) {
            break;
        }
        i++;
    }
    i--; 
    int diff = n - rowsum(i);

    int r = 1, k = 1;
    bool right = true;
    while (r < i) {
        cout << r << " " << k << endl;
        if (right) {
            k++;
        } 
        r++;
        right = !right;
    }
    while (k >= 2) {
        cout << r << " " << k << endl;
        k--;
    }
    while (diff > 0) {
        cout << r++ << " " << 1 << endl;
        diff--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << endl;
        solve();
    }
}
