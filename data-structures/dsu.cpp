#include <bits/stdc++.h>

using namespace std;

struct dsu
{
    vector<int> par;
    vector<int> sz;

    dsu(int n)
    {
        par.resize(n);
        sz.resize(n);

        for(int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    void unite(int u, int v)
    {
        u = find(u);
        v = find(v);

        if(sz[u] > sz[v]) {
            swap(u, v);
        }

        par[u] = v;
        sz[v] += sz[u];
    }

    int find(int u)
    {
        int start = u;
        while(par[u] != u) {
            u = par[u];
        }

        par[start] = u;
        return u;

        //if(par[u] == u) {
            //return u;
        //}
        //return par[u] = find(par[u]);
    }
};
