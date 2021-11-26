#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <climits>

#define MAX_N 50000
#define MAX_M 500000
#define MAX_Q 50000

//#define TEST

using namespace std;

typedef struct _nodo{
    int16_t visited = MAX_Q;
} nodo;

typedef struct _req{
    int16_t a, b;
    int16_t res;
} req;

int16_t BFS(int16_t **map, int16_t N, nodo *grafo, int16_t *temp_dist, int16_t start, int16_t end, int16_t id) {

    queue<int16_t> tovisit;
    tovisit.push(start);

    temp_dist[start] = 0;
    grafo[start].visited = id;
    
    while (!tovisit.empty()) {
        int16_t cur = tovisit.front();
        tovisit.pop();

        if (cur == end) {
            return temp_dist[end];
        } /*else if (map[cur][end] > 0) {
            #ifdef TEST
            cout << " (opt " << cur << "," << end << ")";
            #endif
            return temp_dist[cur] + map[cur][end];
        }*/

        for (int16_t i = 0; i < N; i++) {
            int16_t distanza = map[cur][i];
            if (distanza == 1) {
                if (grafo[i].visited != id) {
                    grafo[i].visited = id;
                    map[start][i] = temp_dist[cur]+1;
                    map[i][start] = temp_dist[cur]+1;
                    temp_dist[i] = temp_dist[cur]+1;
                    tovisit.push(i);
                }
            }
        }
    }
    return -1;
}

int16_t optimize(int16_t **map, int16_t N, nodo *grafo, int16_t *temp_dist, int16_t start, int16_t end, int16_t id) {
    int result;
    /*#ifdef TEST
    for (int16_t i = 0; i < N; i++) {
        for (int16_t j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    #endif*/
    if (map[start][end] != 0) {
        #ifdef TEST
        cout << "OPT on " << start << "-->" << end;
        #endif
        result = map[start][end];
    } else {
        #ifdef TEST
        cout << "BFS on " << start << "-->" << end;
        #endif
        result = BFS(map, N, grafo, temp_dist, end, start, id);
        //BFS(map, N, grafo, temp_dist, end, start, id);
    }
    #ifdef TEST
    cout << " = " << result << endl;
    #endif
    return result;
}

int main() {
    nodo *grafo;
    req *richieste;
    int16_t *temp_dist;
    int16_t **map;

    ifstream in("input.txt");
    int16_t N, M, Q; //nodi, archi, richieste
    in >> N >> M >> Q;

    grafo = new nodo[M];
    richieste = new req[Q];
    temp_dist = new int16_t[N];
    map = new int16_t*[N];
    for (int16_t i = 0; i < N; i++) {
        map[i] = new int16_t[N];
        temp_dist[i] = 0;
        for (int16_t j = 0; j < N; j++) {
            map[i][j] = 0;
        }
    }
    
    for (int16_t i = 0; i < M; i++) {
        int16_t a, b;
        in >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    for (int16_t i = 0; i < Q; i++) {
        int16_t a, b;
        in >> a >> b;
        richieste[i].a = a;
        richieste[i].b = b;
    }
    in.close();

    for (int16_t i = 0; i < Q; i++) {
        richieste[i].res = optimize(map, N, grafo, temp_dist, richieste[i].a, richieste[i].b, i);
    }

    ofstream out("output.txt");
    for (int16_t i = 0; i < Q; i++) {
        out << richieste[i].res << endl;
    }
    out.close();
}