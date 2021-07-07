#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int mxN = 1e5, INF = 0x3f3f3f3f;
vector<pii> g[mxN];
int dist[mxN];

void dijk(int st)
{
    memset(dist, INF, sizeof dist);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.emplace(0, st);
    dist[st] = 0;

    int id, nid, d, w;

    while(!pq.empty()) {
        d = pq.top().first;
        id = pq.top().second;

        if(d > dist[id]) continue;

        for(pii edge: g[id]) {
            w = edge.first;
            nid = edge.second;
            pq.pop();

            if(dist[nid] > dist[id] + w) {
                dist[nid] = dist[id] + w;
                pq.emplace(dist[nid], nid);
            }
        }
    }
}

int main()
{
    int n, m, a, b, from, to, w;

    for(int i = 0; i < m; ++i) {
        cin >> from >> to >> w;
        g[from].emplace_back(w, to);
        g[to].emplace_back(w, from);
    }

    dijk(a);
}
