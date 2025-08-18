#include<bits/stdc++.h>

using namespace std;

vector< vector<string> > aim_num = {{" one ", " two ", " three ", " four ", " five ", " six ", " seven ", " eight ", " nine ", " ten ", 
                    " eleven ", " twelve ", " thirteen ", " fourteen ", " fifteen ", " sixteen ", " seventeen ", 
                    " eighteen ", " nineteen ", " twenty "},
                    {" a ", " both "},
                    {" another "},
                    {" first ", " second ", " third "}};
vector<int> ans_num;
int main() {
    string s0;
    getline(cin, s0);
    string s = " ";
    string ans = "";
    for(int i = 0; i < s0.length(); i++) {
        if(s0[i] >= 'A' && s0[i] <= 'Z') {
            s0[i] -= 'A' - 'a';
        }
        s += s0[i];
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < aim_num[i].size(); j++) {
            int temp = 0;
            string::size_type pos = -1;
            do {
                pos = s.find(aim_num[i][j], pos + 1);
                if(pos != string::npos) {
                    ans_num.push_back(j + 1);
                }
            }while(pos != string::npos);
        }
    }
    if(ans_num.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < ans_num.size(); i++) {
        ans_num[i] = (ans_num[i] * ans_num[i]) % 100;
    }
    sort(ans_num.begin(), ans_num.end());
    char temp[5] = {'\0'};
    sprintf(temp, "%d", ans_num[0]);
    ans += temp;
    for(int i = 1; i < ans_num.size(); i++) {
        char temp[5] = {'\0'};
        sprintf(temp, "%02d", ans_num[i]);
        ans += temp;
    }
    cout << ans << endl;

    return 0;
}