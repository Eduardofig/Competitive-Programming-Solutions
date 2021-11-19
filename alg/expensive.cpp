#include <bits/stdc++.h>

using namespace std;

int n, m, st;
vector<tuple<int, int, int>> edges;

struct unionfind
{
    vector<int> par, sz;

    unionfind(int n)
    {
        par.resize(n);
        sz.resize(n, 1);

        iota(par.begin(), par.end(), 0);
    }

    int find(int u)
    {
        if(par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    int unite(tuple<int, int, int> &edge)
    {
        auto &[u, v, w] = edge;

        u = find(u);
        v = find(v);

        if(u == v) return 0;
        if(sz[u] > sz[v]) swap(u, v);
        
        par[u] = v;
        sz[v] += sz[u];

        return w;
    }

};

void solve()
{
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) { return get<2>(a) < get<2>(b); });

    //acha a soma dos pesos da msu
    unionfind uf(n);
    int tot = accumulate(edges.begin(), edges.end(), 0, [&uf](int &acc, auto &elem) { return acc + uf.unite(elem); });

    //checa se todos nos estao no mesmo componente que o inicial
    for(int i = 0; i < n; ++i) if(uf.find(i) != uf.find(st)) {
        cout << "Impossible" << endl;
        return;
    }

    cout << tot << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    unordered_map<string, int> str_enum;
    int from, to, w;

    //leitura do input e chamada da func em cada caso teste
    while(true) {
        cin >> n >> m;

        if(n == 0 && m == 0) break;

        str_enum.clear();
        for(int i = 0; i < n; ++i) {
            cin >> s;
            str_enum[s] = i;
        }

        edges.clear();
        for(int i = 0; i < m; i++) {
            cin >> s; from = str_enum[s];
            cin >> s; to = str_enum[s];
            cin >> w;

            edges.emplace_back(from, to, w);
        }

        cin >> s;
        st = str_enum[s];

        solve();
    }
}
