#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
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

ll obj(ll x, ll y, ll z)
{
    return (x - y) * (x - y) + (y - z) * (y - z) + (x - z) * (x - z);
}

void solve()
{
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    int reds[nr], greens[ng], blues[nb];
    for (int i = 0; i < nr; ++i)
        cin >> reds[i];
    for (int i = 0; i < ng; ++i)
        cin >> greens[i];
    for (int i = 0; i < nb; ++i)
        cin >> blues[i];

    sort(reds, reds + nr);
    sort(greens, greens + ng);
    sort(blues, blues + nb);

    int i = 0, j = 0, k = 0;

    ll minVal = obj(reds[nr - 1], greens[ng - 1], blues[nb - 1]);
    while (i < nr - 1 || j < ng - 1 || k < nb - 1) {
        ll val = obj(reds[i], greens[j], blues[k]);
        if (val < minVal)
            minVal = val;
        if (i >= nr - 1) {
            if (j >= ng - 1) {
                if (k >= nb - 1) {
                    break;
                } else {
                    k++;
                }
            } else {
                if (greens[j] <= blues[k]) {
                    j++;
                } else {
                    if (k >= nb - 1) {
                        j++;
                    } else {
                        k++;
                    }
                }
            }
        } else {
            if (j >= ng - 1) {
                if (k >= nb - 1) {
                    i++;
                } else {
                    if (reds[i] <= blues[k]) {
                        i++;
                    } else {
                        k++;
                    }
                }
            } else {
                if (k >= nb - 1) {
                    if (greens[j] <= reds[i]) {
                        j++;
                    } else {
                        i++;
                    }
                } else {
                    if (greens[j] <= reds[i] && greens[j] <= blues[k]) {
                        j++;
                    } else {
                        if (blues[k] <= reds[i] && blues[k] <= greens[j]) {
                            k++;
                        } else {
                            i++;
                        }
                    }
                }
            }
        }
    }
    cout << minVal << endl;
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
