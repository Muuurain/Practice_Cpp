#include <bits/stdc++.h>
using namespace std;

vector<string> ret;
bool cmp(string a, string b) {
    return a < b;
}
void dfs(int n, string s, int index) {
    if(n == 0) {
        ret.push_back(s);
        return;
    }
    for(int i = index; i >= 0; i--, index--) {
        while(s[i] < '3') {
            s[i]++;
            dfs(n - 1, s, index);
            s[i]--;
            break;
        }
    }
}
int main() {
    int n;
    cin >> n;
    n -= 10;
    if(n >= 0 && n <= 20){
        string s = "1111111111";
        int index = 9;
        dfs(n, s, index);
        cout << ret.size() << endl;
        sort(ret.begin(), ret.end(), cmp);
        for(string i : ret) {
            for(int j = 0; j < 10; j++) {
                printf("%c ", i[j]);
            }
            printf("\n");
        }
    }
    else {
        cout << "0" << endl;
    }

    return 0;
}