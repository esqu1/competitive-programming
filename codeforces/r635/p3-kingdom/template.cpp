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

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    bool adjMatrix[n + 1][n + 1];
    int deg[n + 1];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        deg[u]++;
        deg[v]++;
    }
    int visited[n];
    vector<pii> q;
    vector<pii> leaves;
    q.push_back(make_pair(1, 0));
    while (q.size() > 0) {
        pii v = q.back();
        q.pop_back();
        int vertex = v.first;
        int dist = v.second;
        if (visited[vertex]) {
            continue;
        }
        if (deg[vertex] == 1) {
            leaves.push_back(v);
            continue;
        }
        for (int i = 0; i <= n; ++i) {
            if (adjMatrix[vertex][i]) {
                q.push_back(make_pair(i, dist + 1));
            }
        }
    }
    sort(leaves.begin(), leaves.end(), sortbysec);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
