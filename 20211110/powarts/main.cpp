#include <vector>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int ix(int i, int j, int N) {
    return i*N+j;
}

void print_matrice(vector<int> &matrice) {
    int N = sqrt(matrice.size());
    cout << "  ";
    for(int i = 0; i < N; i++) {
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        cout << i << " ";
        for (int j = 0; j < N; j++) {
            if (j == i) cout << "\\ ";
            else cout << matrice[ix(i, j, N)] << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<int> matrice;
    set<int> visitati;

    ifstream in("input.txt");
    int N, M, P; //nodi, archi, partenza
    in >> N >> M >> P;
    cout << "powarts: " << P << endl;
    matrice.resize(N*N);

    for (int i = 0; i < M; i++) {
        int from, to, days;
        in >> from >> to >> days;
        matrice[ix(from, to, N)] = days;
        //matrice[ix(to, from, N)] = days;
    }
    in.close();

    print_matrice(matrice);

    ofstream out("output.txt");
    out << 1;
    out.close();
}