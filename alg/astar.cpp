#include <bits/stdc++.h>

#define SOLVE_METHOD solve_astar
#define SHOW_N_VISITED true

using namespace std;

int dist[10][10][10][10],
    dir_i[8] = {1, 0, 0, 0, -1, 0, 0, 0},
    dir_j[8] = {0, 1, 0, 0, 0, -1, 0, 0},
    dir_k[8] = {0, 0, 1, 0, 0, 0, -1, 0}, 
    dir_l[8] = {0, 0, 0, 1, 0, 0, 0, -1},
    next_i, next_j, next_k, next_l;

bool allowed[10][10][10][10];

tuple<int, int, int, int> st, target;

void calc_next(int &i, int &j, int &k, int &l)
{
    if(i > 9) i = 0;
    else if(i < 0) i = 9;

    if(j > 9) j = 0;
    else if(j < 0) j = 9;

    if(k > 9) k = 0;
    else if(k < 0) k = 9;

    if(l > 9) l = 0;
    else if(l < 0) l = 9;
}

int calc_manhattan(int i, int j, int k, int l)
{
    auto[ni, nj, nk, nl] = target;

    int a = min({abs(ni - i), abs(i + 9 - ni), abs(ni + 9 - i)}),
        b = min({abs(nj - j), abs(j + 9 - nj), abs(nj + 9 - j)}),
        c = min({abs(nk - k), abs(k + 9 - nk), abs(nk + 9 - k)}),
        d = min({abs(nl - l), abs(l + 9 - nl), abs(nl + 9 - l)});

    return a + b + c + d;
}

//Solucao sem heuristica
void solve_breadth_first_search()
{
    int a, b, c, d, n, n_visited = 0;

    memset(dist, -1, sizeof dist);
    memset(allowed, true, sizeof allowed);

    cin >> a >> b >> c >> d;
    st = {a, b, c, d};

    cin >> a >> b >> c >> d;
    target = {a, b, c, d};

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        allowed[a][b][c][d] = false;
    }

    queue<tuple<int, int, int, int>> q;

    auto [i, j, k, l] = st;

    dist[i][j][k][l] = 0;
    q.push(st);

    while(!q.empty()) {
        n_visited++;

        auto [i, j, k, l] = q.front();

        if(q.front() == target) {
            cout << dist[i][j][k][l] << endl;
            if(SHOW_N_VISITED) cout << n_visited << endl;
            return;
        }

        q.pop();

        for(int m = 0; m < 8; ++m) {
            next_i = i + dir_i[m];
            next_j = j + dir_j[m];
            next_k = k + dir_k[m];
            next_l = l + dir_l[m];

            calc_next(next_i, next_j, next_k, next_l);

            if(dist[next_i][next_j][next_k][next_l] == -1 && allowed[next_i][next_j][next_k][next_l]) {
                dist[next_i][next_j][next_k][next_l] = dist[i][j][k][l] + 1;
                q.emplace(next_i, next_j, next_k, next_l);
            }
        }
    }

    cout << -1 << endl;
}

//Solucao com a heuristica da best first search
void solve_best_first_search()
{
    int a, b, c, d, n, n_visited = 0;

    memset(dist, -1, sizeof dist);
    memset(allowed, true, sizeof allowed);

    cin >> a >> b >> c >> d;
    st = {a, b, c, d};

    cin >> a >> b >> c >> d;
    target = {a, b, c, d};

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        allowed[a][b][c][d] = false;
    }

    //Fila de prioridade que toma como parametro a distancia manhattan da coordenada ao target
    priority_queue<pair<int, tuple<int, int, int, int>>, vector<pair<int, tuple<int, int, int, int>>>,
        greater<pair<int, tuple<int, int, int, int>>>> pq;

    auto [i, j, k, l] = st;

    dist[i][j][k][l] = 0;
    pq.emplace(calc_manhattan(i, j, k, l), st);

    while(!pq.empty()) {
        n_visited++;

        auto [i, j, k, l] = pq.top().second;

        if(pq.top().second == target) {
            cout << dist[i][j][k][l] << endl;
            if(SHOW_N_VISITED) cout << n_visited << endl;
            return;
        }

        pq.pop();

        for(int m = 0; m < 8; ++m) {
            next_i = i + dir_i[m];
            next_j = j + dir_j[m];
            next_k = k + dir_k[m];
            next_l = l + dir_l[m];

            calc_next(next_i, next_j, next_k, next_l);

            if(dist[next_i][next_j][next_k][next_l] == -1 && allowed[next_i][next_j][next_k][next_l]) {
                dist[next_i][next_j][next_k][next_l] = dist[i][j][k][l] + 1;
                pq.emplace(calc_manhattan(next_i, next_j, next_k, next_l), make_tuple(next_i, next_j, next_k, next_l));
            }
        }
    }

    cout << -1 << endl;
}

//Solucao com a heuristica A*
void solve_astar()
{
    int a, b, c, d, n, n_visited = 0;

    memset(dist, -1, sizeof dist);
    memset(allowed, true, sizeof allowed);

    cin >> a >> b >> c >> d;
    st = {a, b, c, d};

    cin >> a >> b >> c >> d;
    target = {a, b, c, d};

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        allowed[a][b][c][d] = false;
    }

    //Fila de prioridade que toma como parametro a distancia manhattan da coordenada ao target e a distancia percorrida ate agora
    priority_queue<pair<int, tuple<int, int, int, int>>, vector<pair<int, tuple<int, int, int, int>>>,
        greater<pair<int, tuple<int, int, int, int>>>> pq;

    auto [i, j, k, l] = st;

    dist[i][j][k][l] = 0;
    pq.emplace(0, st);

    while(!pq.empty()) {
        n_visited++;

        auto [i, j, k, l] = pq.top().second;

        if(pq.top().second == target) {
            cout << dist[i][j][k][l] << endl;
            if(SHOW_N_VISITED) cout << n_visited << endl;
            return;
        }

        pq.pop();

        for(int m = 0; m < 8; ++m) {
            next_i = i + dir_i[m];
            next_j = j + dir_j[m];
            next_k = k + dir_k[m];
            next_l = l + dir_l[m];

            calc_next(next_i, next_j, next_k, next_l);

            if(dist[next_i][next_j][next_k][next_l] == -1 && allowed[next_i][next_j][next_k][next_l]) {
                dist[next_i][next_j][next_k][next_l] = dist[i][j][k][l] + 1;
                pq.emplace(calc_manhattan(next_i, next_j, next_k, next_l) + dist[next_i][next_j][next_k][next_l],
                        make_tuple(next_i, next_j, next_k, next_l));
            }
        }
    }

    cout << -1 << endl;

}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) SOLVE_METHOD();
}
