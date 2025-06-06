#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}
int main() {
    vector<string> s;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        string t = "";
        cin >> t;
        s.push_back(t);
    }
    sort(s.begin(), s.end(), cmp);
    string ret = "";
    for(string i : s) {
        ret += i;
    }
    cout << ret;


    return 0;
}