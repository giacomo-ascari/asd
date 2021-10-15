#include <fstream>
#include <iostream>
#include <set>
#include <map>
#define M 5000000
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _interval {
    int start;
    int end;
    bool check;
} interval;

void print_interval(interval &i) {
    if (i.check)
        cout << "[" << i.start << "-" << i.end << "] ";
    else 
        cout << "/" << i.start << "-" << i.end << "/ ";
}

bool compare(interval a, interval b) {
    return a.start < b.start;
}

int main(){
    int N;
    interval *intervals;

    interval temp = {0, 0, 0};
    ifstream in("input.txt");
    in >> N;
    intervals = new interval[N*2];
    for (int i = 0; i < N; i++) {
        in >> temp.start;
        in >> temp.end;
        temp.check = true;
        intervals[i] = temp;
    }
    for (int i = N; i < N*2; i++) {
        temp.check = false;
        intervals[i] = temp;
    }
    in.close();

    int offset = N;
    for (int i = 0; i < N*2; i++) {
        //cout << "first: ";
        //print_interval(intervals[i]);
        //cout << "| ";
        if (intervals[i].check) {
            for (int j = i; j < N*2; j++) {
                if (i != j && intervals[j].check) {
                    //print_interval(intervals[j]);
                    if (intervals[i].end >= intervals[j].start && intervals[j].end >= intervals[i].start) {
                        //cout << "Y ";
                        temp.start = min(intervals[i].start, intervals[j].start);
                        temp.end = max(intervals[j].end, intervals[i].end);
                        temp.check = true;
                        intervals[i].check = false;
                        intervals[j].check = false;
                        intervals[offset++] = temp;
                        //print_interval(temp);
                        //cout << endl;
                        break;
                    }
                }
            }
            //cout << endl << endl;
        }
    }

    vector<interval> v;
    for (int i = 0; i < offset; i++) {
        //print_interval(intervals[i]);
        if (intervals[i].check) {
            v.push_back(intervals[i]);
        }
    }
    //cout << endl << endl;

    interval best = {0, 0, true};
    sort(v.begin(), v.end(), compare);

    for(auto it=v.begin(); it!=v.end()-1; it++) {
        interval i1 = *it;
        interval i2 = *(it+1);
        if (i2.start - i1.end > best.end - best.start) {
            best.start = i1.end;
            best.end = i2.start;
        }
    }

    ofstream out("output.txt");
    if (v.size() > 1)
        out << best.start << " " << best.end;
    else
        out << "0";
    out.close();

    return 0;
}