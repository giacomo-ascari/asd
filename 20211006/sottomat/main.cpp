#include <fstream>
#include <iostream>
#define MAX 200
using namespace std;

int main(){
    int mat[MAX][MAX];
    int R, C;
    ifstream in("input.txt");

    in >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            in >> mat[i][j];
        }
    }

    int mx = 0;
    int sum = 0;
    int i = 0, j = 0;

    ofstream out("output.txt");
    out << mx << endl;
    return 0;
}