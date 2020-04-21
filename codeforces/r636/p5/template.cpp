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
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;
typedef pair<int, vector<int>> vertex;

void bfs(int v, int n, vertex graph[], int dist[])
{
    queue<int> bfs;
    bfs.push(v);
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    while (!bfs.empty()) {
        vertex newv = graph[bfs.front()];
        bfs.pop();
        if (visited[newv.first]) {
            continue;
        }
        visited[newv.first] = true;
        vector<int> edges = newv.second;
        for (auto i = edges.begin(); i != edges.end(); i++) {
            int visit = *i;
            if (visited[visit]) {
                continue;
            }
            if (dist[visit] > 0) {
                dist[visit] = min(dist[visit], dist[newv.first] + 1);
            } else {
                dist[visit] = dist[newv.first] + 1;
            }
            bfs.push(visit);
        }
    }
}

void solve()
{
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--;
    b--;
    c--;
    int p[m];
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(p, p + m);
    ll pSum[m + 1];
    pSum[0] = 0;
    for (int i = 1; i <= m; i++) {
        pSum[i] = pSum[i - 1] + p[i-1];
    }
    vertex graph[n];
    for (int i = 0; i < n; i++)
        graph[i].first = i;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u - 1].second.push_back(v - 1);
        graph[v - 1].second.push_back(u - 1);
    }
    int bfsA[n];
    int bfsB[n];
    int bfsC[n];
    for (int i = 0; i < n; i++) {
        bfsA[i] = 0;
        bfsB[i] = 0;
        bfsC[i] = 0;
    }
    bfs(a, n, graph, bfsA);
    bfs(b, n, graph, bfsB);
    bfs(c, n, graph, bfsC);


    ll minCost = LLONG_MAX;

    for (int middle = 0; middle < n; middle++) {
        int aToMid = bfsA[middle];
        int MidToB = bfsB[middle];
        int MidToC = bfsC[middle];
        if (aToMid + MidToB + MidToC > m) {
            continue;
        }
        minCost = min(minCost, pSum[MidToB] + pSum[aToMid + MidToB + MidToC]);
    }
    cout << minCost << endl;
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
