#include <bits/stdc++.h>
/*
 * This code is designed to print the shortest path between the start and the end node
 * enumerated from 1 to n
 * As if the input starts with n(nodes) and m(edges) and the next m lines containes 
 * the source, destination and cost of an edge
 * if the input is 
 * 5 6
 * 1 2 2
 * 2 5 5
 * 2 3 4
 * 1 4 1
 * 4 3 3
 * 3 5 1
 * the output should be
 * 1 4 3 5
 * fix this code bugs to make it work properly.
 * */
#define S second
#define F first
using namespace std;
typedef long long ll;
const ll N = 2e9 + 5;
vector<pair<int, int>> adj[N];
ll dist[N], n, m;

void run_dijkstra(int start) {
    priority_queue<pair<ll, int>> pq;
    for (int i = 1; i < n; ++i)
        dist[i] = INT_MIN;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().S;
        ll cost = -pq.top().F;
        pq.pop();
        for (auto ch: adj[u]) {
            ll tmpcost = cost + ch.S;
            if (tmpcost < dist[ch.F]) {
                dist[ch.F] = tmpcost;
                pq.push({tmpcost, ch.F});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    while (--m) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    run_dijkstra(1);
    if (dist[n] == INT_MIN)
        cout << "-1" << '\n';
    else {
        vector<int> route;
        int track = n;
        while (track != 1) {
            route.push_back(track);
            ll d = dist[track];
            for (auto child: adj[track]) {
                ll tmpD = dist[child.F] + child.S;
                if (tmpD = d) {
                    track = child.F;
                    break;
                }
            }
        }
        route.push_back(1);
        while (!route.empty()) {
            cout << route.back() << ' ';
            route.pop_back();
        }
    }
    return 0;
}

