#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f, mxN = 100;

typedef pair<int, int> pii;
typedef long long int ll;

vector<pii> g[mxN];
int dist[mxN];

void djikstra(int st)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    memset(dist, INF, sizeof dist);
    dist[st] = 0;
    pq.emplace(0, st);

    pii curr;
    int neigh, w;

    while(!pq.empty()) {
        curr = pq.top();
        pq.pop();
        for(pii edge: g[curr.second]) {
            neigh = edge.first;
            w = edge.second;
            if(dist[curr.first] + w < dist[neigh]) {
                dist[neigh] = dist[curr.first] + w;
                pq.emplace(dist[curr.first] + w, neigh);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, from, to, w;

    for(int i = 0; i < n; ++i) {
        cin >> from >> to >> w;
        g[from].emplace_back(to, w);
        g[to].emplace_back(from, w);
    }

    int st;
    cin >> st;
    djikstra(st);
    for(int i = 0; i < mxN; ++i) cout << "distancia de " << i << " a " << st << " = " << dist[i] << endl; 
}
