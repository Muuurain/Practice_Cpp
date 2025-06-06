#include <bits/stdc++.h>

using namespace std;

struct students{
    string id;
    int xy;
    int sz;
    int sum;
    double zh;

    void setsum() {
        sum = xy + sz;
    }

    void setzh() {
        zh = xy * 7 + sz * 3;
    }
}st[1010];

bool isg(students a) {
    if(a.sum > 140) {
        if(a.zh >= 800) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> st[i].id >> st[i].xy >> st[i].sz;
        st[i].setzh();
        st[i].setsum();
        if(isg(st[i])) {
            cout << "Excellent" << endl;
        }
        else {
            cout << "Not excellent" << endl;
        }
    }

    return 0;
}