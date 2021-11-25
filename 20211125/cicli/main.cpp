#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

typedef struct _nodo{
    vector<int16_t> vicini;
    int16_t visited = -1;
} nodo;

typedef struct _req{
    int16_t a, b;
    int16_t res;
} req;

int16_t BFS(int16_t N, vector<nodo> &grafo, vector<int16_t> &dist, int16_t start, int16_t end, int16_t id) {

    cout << "BFS on " << start << "-->" << end << endl;
    queue<int16_t> tovisit;
    tovisit.push(start);

    dist[start] = 0;
    grafo[start].visited = id;
    
    while (!tovisit.empty()) {
        int16_t cur = tovisit.front();
        cout << dist[cur] << ") cur: " << cur << " |";
        tovisit.pop();

        if (cur == end) {
            break;
        }

        for (int16_t i = 0; i < grafo[cur].vicini.size(); i++) {
            int16_t vicino = grafo[cur].vicini[i];
            if (grafo[vicino].visited != id) {
                grafo[vicino].visited = id;
                dist[vicino] = dist[cur]+1;
                tovisit.push(vicino);
                cout << " " << vicino;
            }
        }
        cout << endl;
    }
    return dist[end];
}

int main() {

    vector<nodo> grafo;
    vector<req> richieste;
    vector<int16_t> dist;

    ifstream in("input.txt");
    int16_t N, M, Q; //nodi, archi, richieste
    in >> N >> M >> Q;
    grafo.resize(N);
    richieste.resize(Q);
    dist.resize(N);
    for (int16_t i = 0; i < M; i++) {
        int16_t a, b;
        in >> a >> b;
        grafo[a].vicini.push_back(b);
        grafo[b].vicini.push_back(a);
    }
    for (int16_t i = 0; i < Q; i++) {
        int16_t a, b;
        in >> a >> b;
        richieste[i].a = a;
        richieste[i].b = b;
    }
    in.close();

    for (int16_t i = 0; i < Q; i++) {
        richieste[i].res = BFS(N, grafo, dist, richieste[i].a, richieste[i].b, i);
    }

    ofstream out("output.txt");
    for (int16_t i = 0; i < Q; i++) {
        out << richieste[i].res << endl;
    }
    out.close();
}