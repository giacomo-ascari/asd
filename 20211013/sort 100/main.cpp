#include <fstream>
#include <iostream>
#include <ctime>
#define MAX 1000000
using namespace std;

int *b;

void merge(int a[], int first, int mid, int last) {
    int cur = 0;
    int i = first, j = mid;
    while (i < mid && j < last) {
        if (a[i] < a[j]) {
            b[cur] = a[i++];
        } else {
            b[cur] = a[j++];
        }
        cur++;
    }
    for (; i < mid; i++) {
        b[cur++] = a[i];
    }
    for (; j < last; j++) {
        b[cur++] = a[j];
    }
    int h = 0;
    for (int k = first; k < last; k++) {
        a[k] = b[h++];
    }
}

void merge_sort(int a[], int first, int last) {
    if (first != last-1) {
        int mid = (first + last) / 2;
        merge_sort(a, first, mid);
        merge_sort(a, mid, last);
        merge(a, first, mid, last);
    }
}

int main(){
    time_t t = time(0);  // t is an integer type

    int *a;
    int N;
    ifstream in("input.txt");

    in >> N;
    a = new int[N];
    b = new int[N];
    for (int i = 0; i < N; i++) {
        in >> a[i];
    }

    merge_sort(a, 0, N);
    ofstream out("output.txt");
    for (int i = 0; i < N; i++) {
        out << a[i] << " ";
    }

    cout << time(0) - t << "\n";
    delete(a);
    delete(b);
    return 0;
}