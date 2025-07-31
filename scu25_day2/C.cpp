#include <bits/stdc++.h>
using namespace std;

struct node{
    double value;
    double m;
    double weigh;
    void setweigh() {
        weigh = value / m;
    }
}gold[110];
node sum;

bool cmp(node a, node b) {
    return (a.weigh > b.weigh);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, T;
    cin >> N >> T;
    for(int i = 0; i < N ;i++) {
        cin >> gold[i].m >> gold[i].value;
        gold[i].setweigh();
    }
    sort(gold, gold + N, cmp);
    for(int i = 0; i < N; i++) {
        if(sum.m + gold[i].m <= T) {
            sum.m += gold[i].m;
            sum.value += gold[i].value;
        }
        else {
            sum.value += gold[i].weigh * (T - sum.m);
            break;
        }
    }
    printf("%.2f", sum.value);

    return 0;
}