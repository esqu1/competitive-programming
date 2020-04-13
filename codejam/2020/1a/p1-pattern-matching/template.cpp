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
    string patterns[n];
    for (int i = 0; i < n; ++i) {
        cin >> patterns[i];
    }
    int counters[n];

    for (int i = 0; i < n; ++i) {
        counters[i] = 0;
    }

    // Scan the prefixes
    string prefix = "";
    while (true) {
        set<char> chars;
        for (int i = 0; i < n; ++i) {
            if (patterns[i].at(counters[i]) != '*') {
                chars.insert(patterns[i].at(counters[i]));
                counters[i]++;
            }
        }
        if (chars.size() >= 2) {
            cout << "*";
            return;
        }
        if (chars.size() == 0) {
            // all asterisks, now do a suffix search
            break;
        }
        char c = *chars.begin();
        prefix += c;
    }

    // now do the same for the suffix
    int suffixCounters[n];
    for (int i = 0; i < n; ++i) {
        suffixCounters[i] = patterns[i].length() - 1;
    }
    string suffix = "";
    while (true) {
        set<char> chars;
        for (int i = 0; i < n; ++i) {
            if (patterns[i].at(suffixCounters[i]) != '*') {
                chars.insert(patterns[i].at(suffixCounters[i]));
                suffixCounters[i]--;
            }
        }
        if (chars.size() >= 2) {
            cout << "*";
            return;
        }
        if (chars.size() == 0) {
            // all asterisks, now do a suffix search
            break;
        }
        char c = *chars.begin();
        suffix = c + suffix;
    }
    cout << prefix;
    for (int i = 0; i < n; ++i) {
        for (int k = counters[i] + 1; k < suffixCounters[i]; ++k) {
            if (patterns[i].at(k) != '*') {
                cout << patterns[i].at(k);
            }
        }
        
    }
    cout << suffix;
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
