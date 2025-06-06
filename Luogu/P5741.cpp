#include <bits/stdc++.h>

using namespace std;

struct student{
    string name;
    int x;
    int y;
    int z;
    int sum;
    void setsum() {
        sum = x + y + z;
    }
}s[1010];

bool eq(int i1, int i2) {
    if(abs(s[i1].sum - s[i2].sum) <= 10) {
        if(abs(s[i1].x - s[i2].x) <= 5) {
            if(abs(s[i1].y - s[i2].y) <= 5) {
                if(abs(s[i1].z - s[i2].z) <= 5) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s[i].name >> s[i].x >> s[i].y >> s[i].z;
        s[i].setsum();
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(eq(i, j)) {
                cout << s[i].name << " " << s[j].name << endl;
            }
        }
    }


    return 0;
}