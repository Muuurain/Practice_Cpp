#include <bits/stdc++.h>

using namespace std;

struct node{
    double x;
    double y;
    double z;
}nod[51000];
bool cmp(node a, node b) {
    return a.z < b.z;
}
double dist(node a, node b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &nod[i].x, &nod[i].y, &nod[i].z);
    }
    sort(nod, nod + n, cmp);
    double ret = 0;
    for(int i = 0; i < n - 1; i++) {
        ret += dist(nod[i], nod[i + 1]);
    }
    printf("%.3f", ret);

    return 0;
}