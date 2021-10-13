#include <fstream>
#include <iostream>
#define M 5000000000
#define MAX 100000
using namespace std;

int main(){
    int starts[MAX], ends[MAX];
    size_t min = SIZE_MAX, max = SIZE_MIN;
    int N;

    ifstream in("input.txt");

    in >> N;
    for (int i = 0; i < N; i++) {
        in >> starts[i];
        in >> ends[i];
        min = min(min, starts[i]);
        max = max(max, ends[i]);
    }

    unsigned char v[M];
    for (int i = 0; i < N; i++) {
        for (int j = starts[i]; j < ends[i]; j++) {
            v[j] = 1;
        }
    }

    int count = 0;
    for (size_t i = min; i < max; i++) {
        count = v[i] == 0 ? count+1 : 0;
    }

    ofstream out("output.txt");
    for (int i = 0; i < N; i++) {
        out << arr[i] << " ";
    }
    return 0;
}