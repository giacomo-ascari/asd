#include <fstream>
#include <iostream>
#define MAX 1000000
using namespace std;

void merge(int a[], int first, int mid, int last) {
    int b[MAX], cur = 0;
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
    int arr[MAX], sorted[MAX];
    int N;
    ifstream in("input.txt");

    in >> N;
    for (int i = 0; i < N; i++) {
        in >> arr[i];
    }

    merge_sort(arr, 0, N);

    ofstream out("output.txt");
    for (int i = 0; i < N; i++) {
        out << arr[i] << " ";
    }
    return 0;
}