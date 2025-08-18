#include <bits/stdc++.h>

using namespace std;

struct person{
    int dire;
    string name;
}p[100010];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> p[i].dire >> p[i].name;
    }
    int plc = 1;
    for(int i = 1; i <= m; i++) {
        int a, s;
        cin >> a >> s;
        if(a + p[plc].dire == 1) {
            if(plc + s > n) {
                plc = plc + s - n;
            }
            else {
                plc += s;
            }
        }
        else {
            if(plc - s < 1) {
                plc = plc - s + n;
            }
            else {
                plc -= s;
            }
        }
    }
    cout << p[plc].name << endl;

    return 0;
}