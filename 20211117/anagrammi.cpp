#include <iostream>
#include <vector>

using namespace std;

void find_anagrams(vector<string> words) {
    int *evaluated = new int[words.size()];
    for (int i = 0; i < words.size(); i++) evaluated[i] = 0;
    for (int i = 0; i < words.size(); i++) {
        cout << words[i];
        for (int j = i+1; j < words.size(); j++) {
            if (i == j && evaluated[i] = 0) {
                evaluated[i] = 1;

            }
        }
    }
    delete[] evaluated;
}

int main() {

    vector<string> words = {
        "rosa", "pippo", "poppi", "raso", "orsa", "giappone"
    };
    find_anagrams(words);
}