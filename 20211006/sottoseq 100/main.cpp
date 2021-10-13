#include <fstream>
#include <iostream>
#define MAX 1000000
using namespace std;

int main(){
    int arr[MAX];
    int N;
    ifstream in("input.txt");

    in >> N;
    for (int i = 0; i < N; i++) {
        in >> arr[i];
    }

    int mx = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
        }
        mx = max(sum, mx);
    }

    ofstream out("output.txt");
    out << mx << endl;
    return 0;
}