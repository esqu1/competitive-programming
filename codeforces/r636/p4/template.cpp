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

bool sortfst(const pair<int,int> &a, 
                      const pair<int,int> &b) 
{ 
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first && a.second > b.second) {
        return true;
    } else {
        return false;
    }
        
}

void solve2() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    pii hotspots[4 * n / 2];
    for (int i = 0; i < 4*n / 2; i += 4) {
        int j = i / 4;
        int mi = min(arr[j], arr[n-j-1]);
        int ma = max(arr[j], arr[n-j-1]);

        hotspots[i] = make_pair(mi+1, -1);
        hotspots[i+1] = make_pair(mi + ma, -1);
        hotspots[i+2] = make_pair(ma + k+1, 1);
        hotspots[i+3] = make_pair(mi + ma + 1,  1);
    }
    sort(hotspots, hotspots + 2 * n, sortfst);

    int minTotal = 200000;
    int runningTotal = n;
    int currIndex = 0;
    for (int i = 0; i < 4*n / 2; i++) {
        runningTotal += hotspots[i].second;
        if (runningTotal < minTotal) {
            minTotal = runningTotal;
        }
    }
    cout << minTotal << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    int maxmin = 0;
    int minmax = 200000;
    for (int i = 0; i < n/2; i++) {
        maxmin = max(min(arr[i], arr[n-i-1]) + 1, maxmin);
        minmax = min(max(arr[i], arr[n-i-1]) + k, minmax);
    }
    int minsumindex = -1;
    int minsum = 200000; 
    for (int i = 0; i < n/2; i++) {
        int s = arr[i] + arr[n-i -1];
        if (s >= maxmin && s <= minmax &&  s < minsum) {
            minsumindex = i;
            minsum = s;
        }
    }
    if (minsumindex == -1) {
        minsum = maxmin;
    }
    
    int total = 0;
    for (int i = 0; i < n/2; ++i) {
        int s = arr[i] + arr[n-i-1];
        if (s == minsum) {
            continue;
        }
        if (s >= min(arr[i], arr[n-i-1]) + 1 && s <= k + max(arr[i], arr[n-i-1])) {
            total += 1;
        } else if (s != minsum) {
            total += 2;
        }
    }
    cout << total << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve2();     
    }
}
