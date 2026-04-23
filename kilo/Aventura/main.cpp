#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ifstream fin("aventura.in");
ofstream fout("aventura.out");

vector<vector<int>> requires;
vector<vector<int>> requiredby;

vector<int> niveledependente;
vector<int> activate;

void run_bfs(int start){
    activate[start] = 1;
    //cout << start << ": node\n";
    for(auto el : requires[start]){
        niveledependente[el]--;
        
        //cout << el << ' ';
        //cout << '(' << niveledependente[el] << ") ";
        
        if(niveledependente[el] == 0 && activate[el] == 0){
            run_bfs(el);
        }
    }
    //cout << endl;
}

int main(){
    int t;
    fin >> t;

    for(int cer = 0; cer < t; cer++){
        requiredby.clear();
        requires.clear();

        niveledependente.clear();
        activate.clear();

        int N; fin >> N;
        requiredby.resize(N + 1);
        requires.resize(N + 1);

        niveledependente.resize(N + 1);
        activate.resize(N + 1);
        
        //cout << "citite: " << endl;

        for(int i = 1; i <= N; i++){
            int k; fin >> k;

            niveledependente[i] = k;
            for(int j = 1; j <= k; j++){
                int l; fin >> l;
                //cout << l; cout.flush();
                requires[l].push_back(i);
                requiredby[i].push_back(l);
            }

        }

        for(int i = 1; i <= N; i++){
            if(niveledependente[i] == 0 && activate[i] == 0){
                run_bfs(i);
            }
        }

        ll ans = 0;
        for(int i = 1; i <= N; i++){
            if(activate[i] == 1) ans++;
        }

        fout << ans << '\n';



    }

    return 0;
}
