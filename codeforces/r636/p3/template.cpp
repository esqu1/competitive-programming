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
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    ll total = 0;
    ll compTo = 0;
    for (int i = 0; i < n; ++i) {
        if (compTo == 0){
            compTo = arr[i];
        } else {
            compTo = max(arr[i], compTo);
        }
        if (i < n - 1 && arr[i+1] * arr[i] < 0) {
            total += compTo;
            compTo = 0;
        } else if (i == n - 1) {
            total += compTo;
            compTo = 0;
        }
             
    }
    cout << total << endl;
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
