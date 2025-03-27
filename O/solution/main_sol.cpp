#include <iostream>
#include <vector>
using namespace std;

int map(string &s){
    int ret = 0;
    for (auto &c:s){
        ret = ret * 27 + c - 'a' + 1;
    }
    return ret;
}

int last_use[26 * 26 * 26 * 26];
int main(){
    int linesOfInput;

    cin >> linesOfInput;
    vector <pair<int, vector<int>>> lines(linesOfInput);
    for (auto &line:lines){
        string s;
        int N;
        cin >> s >> N;
        line.first = map(s);
        line.second.resize(N);
        for (auto &param:line.second){
            cin >> s;
            param = map(s);
        }
    }

    int answer = 0, current = 0;
    for (int i=linesOfInput-1;i>=0;--i){
        if (last_use[lines[i].first]){
            --current;
            last_use[lines[i].first] = 0;
        }

        for (int &v:lines[i].second){
            if (!last_use[v]){
                last_use[v] = i;
                ++current;
            }
        }
        answer = max(answer, current);
    }

    cout << answer << '\n';
}