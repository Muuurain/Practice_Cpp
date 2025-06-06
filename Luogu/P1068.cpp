#include <bits/stdc++.h>

using namespace std;

struct people{
    int id;
    int score;
}p[6000];

bool cmp(people a, people b) {
    if(a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].id, &p[i].score);
    }
    sort(p, p + n, cmp);
    int minp = m * 1.5;
    int mins = p[minp - 1].score;
    int num = minp;
    while(p[num].score == mins) num++;
    cout << mins << " " << num << endl;
    for(int i = 0; i < num; i++) {
        printf("%d %d\n", p[i].id, p[i].score);
    }

    return 0;
}