#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3, MXN = 1e5;
int dist[MXN], st, e;
vector<pair<int, int>> g[MXN];

void dijk()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    memset(dist, INF, sizeof dist);
    dist[st] = 0;
    pq.emplace(0, st);

    while(!pq.empty()) {
        auto [d, id] = pq.top();

        pq.pop();

        if(d < dist[id]) {
            for(auto [w, nid]: g[id]) {
                dist[nid] = min(dist[nid], dist[id] + w);
                pq.emplace(dist[nid], nid);
            }
        }
    }
}

int main()
{
    int n, from, to, w;
    cin >> n >> st >> e;
    for(int i = 0; i < n; ++i) {
        cin >> from >> to >> w;
        from--; to--;
        g[from].emplace_back(w, to);
        g[to].emplace_back(w, from);
    }

    dijk();

    cout << dist[e] << endl;
}
