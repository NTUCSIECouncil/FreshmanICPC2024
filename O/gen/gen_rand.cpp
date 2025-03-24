#include <bits/stdc++.h>
#include "jngen.h"
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    int Q_tot = atoi(argv[2]);
    cout << N << '\n';

    vector <pair<int, int>> ranges(N);
    for (int i=0;i<N;++i){
        ranges[i] = make_pair(i, rnd.next(i, N-1));
        if (ranges[i].second != i) --Q_tot;
    }
    Q_tot = max(Q_tot, 0);

    set <string> variable_name_pool, variable_list, variable_alive;
    vector<set<string>> dead_at(N);
    for (int i=0;i<N;++i){
        string name;
        if (variable_name_pool.empty()){
            name = rnd.next("[a-z]{1,4}");
            while (variable_list.find(name) != variable_list.end()){
                name = rnd.next("[a-z]{1,4}");
            }
            variable_list.insert(name);
        }
        else{
            name = *variable_name_pool.begin();
            variable_name_pool.erase(variable_name_pool.begin());
        }

        cout << name << ' ';
        TArray<string> param;
        for (string const &s:dead_at[i]){
            variable_alive.erase(s);
            param.push_back(s);
            variable_name_pool.insert(s);
        }
        dead_at[ranges[i].second].insert(name);
        int X = rnd.wnext(0, Q_tot, -1);
        X = min(X, (int)variable_alive.size());
        Q_tot -= X;
        while (X--){
            string t = rnd.choice(variable_alive);
            param.push_back(t);
        }

        if (ranges[i].second > i) variable_alive.insert(name);

        cout << param.size();
        param.shuffle();
        for (auto &s:param) cout << ' ' << s;
        cout << '\n';
    }
}