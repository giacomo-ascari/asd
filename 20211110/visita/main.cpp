#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

typedef struct _nodo{
    vector<int> vicini;
    bool visitato = false;
} nodo;

void visita(vector<nodo> &grafo, int n) {
    if (!grafo[n].visitato) {
        grafo[n].visitato = true;
        for (int i = 0; i < grafo[n].vicini.size(); i++) {
            visita(grafo, grafo[n].vicini[i]);
        }
    }
}

int main() {

    vector<nodo> grafo;

    ifstream in("input.txt");
    int N, M, S; //nodi, archi, partenza
    in >> N >> M >> S;
    grafo.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        in >> a >> b;
        grafo[a].vicini.push_back(b);
    }
    in.close();

    visita(grafo, S);
    int visite = 0;
    for (int i = 0; i < N; i++) {
        visite += grafo[i].visitato ? 1 : 0;
    }

    ofstream out("output.txt");
    //cout << visite << endl;
    out << visite;
    out.close();
}