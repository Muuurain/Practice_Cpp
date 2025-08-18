#include <bits/stdc++.h>

using namespace std;

struct node{
    int a, b, c;
    int sum;
    int order;
    void setsum() {
        sum = a + b + c;
    }
}student[400];

bool cmp(node s1, node s2) {
    if(s1.sum != s2.sum) return s1.sum > s2.sum;
    else return s1.a > s2.a;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &student[i].a, &student[i].b, &student[i].c);
        student[i].setsum();
        student[i].order = i + 1;
    }
    stable_sort(student, student + n, cmp);
    for(int i = 0; i < 5; i++) {
        cout << student[i].order << " " << student[i].sum << endl;
    }

    return 0;
}