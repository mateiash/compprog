// imi vine sa vomit ...
// scz e scris la 3am
#include <bits/stdc++.h>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("veri.in");
ofstream fout("veri.out");

vector<vector<int>> adj;
vector<vector<int>> revadj;

vector<int> stepsA;
vector<int> stepsB;
vector<int> stepsS;

int n, m; 

void bfs(vector<int>& steps, int start){
    steps.clear();
    steps.resize(n + 1);
    queue<int> nodes;
    
    steps[start] = 1;
    nodes.push(start);

    while(!nodes.empty()){
        int node = nodes.front();
        int curr = steps[node];
        for(int link : revadj[node]){
            if(steps[link]) continue;
            
            steps[link] = curr + 1;
            nodes.push(link);

        }

        nodes.pop();

    }
}

void bfsS(vector<int>& steps, int start){
    steps.clear();
    steps.resize(n + 1);
    queue<int> nodes;
    
    steps[start] = 1;
    nodes.push(start);

    while(!nodes.empty()){
        int node = nodes.front();
        int curr = steps[node];
        for(int link : adj[node]){
            if(steps[link]) continue;
            
            steps[link] = curr + 1;
            nodes.push(link);

        }

        nodes.pop();

    }
}

int letssplitgang = -1;
int mint = 999'999'999;
int pa = 999'999'999;

vector<int> steps;

vector<int> wwcd;

void bfsc(int start){
    steps.clear();
    steps.resize(n + 1);
    queue<int> nodes;
    
    steps[start] = 1;
    nodes.push(start);

    while(!nodes.empty()){
        int node = nodes.front();
        int curr = steps[node];
        for(int link : adj[node]){
            if(link == start){
                int panaaici = curr + stepsS[link] - 1;
                int panaA = stepsA[link] - 1;
                int panaB = stepsB[link] - 1;

                if(panaA == -1 || panaB == -1) return;

                int total = panaaici + max(
                    panaA, panaB
                );
                //cout << link << " link\n";
                //cout << curr << " drum\n";
                if(total < mint){
                    mint = total;
                    letssplitgang = link;
                    pa = panaaici;
                    wwcd = steps;
                } else if (total == mint && panaaici < pa){
                    mint = total;
                    letssplitgang = link;
                    pa = panaaici;
                    wwcd = steps;
                }
                return;
            }
            if(steps[link]) continue;
            
            steps[link] = curr + 1;
            nodes.push(link);

        }

        nodes.pop();

    }
}

vector<int> genc(){
    vector<int> ans; ans.push_back(letssplitgang);
    int searching = mint - stepsS[letssplitgang] + 1 - max(
                    stepsA[letssplitgang] - 1, stepsB[letssplitgang] - 1
                );
    while(searching){
        for(auto link : revadj[ans.back()]){
            if(wwcd[link] == searching){
                ans.push_back(link);
                searching--;
                break;
            }
        }
    }
    return ans;
}

vector<int> gen(vector<int>& steps, int start){
    vector<int> ans; ans.push_back(start);
    int searching = steps[start] - 1;
    while(searching){
        for(auto link : revadj[ans.back()]){
            if(steps[link] == searching){
                ans.push_back(link);
                searching--;
                break;
            }
        }
    }
    return ans;
}

vector<int> genAB(vector<int>& steps, int start){
    vector<int> ans; ans.push_back(start);
    int searching = steps[start] - 1;
    while(searching){
        for(auto link : adj[ans.back()]){
            if(steps[link] == searching){
                ans.push_back(link);
                searching--;
                break;
            }
        }
    }
    return ans;
}

int main(){

    int c; fin >> c;
    
    fin >> n >> m;

    adj.resize(n + 1);
    revadj.resize(n + 1);

    int S, A, B; fin >> S >> A >> B;

    for(int i = 1; i <= m; i++){
        int from, to;
        fin >> from >> to;

        adj[from].push_back(to);
        revadj[to].push_back(from);
    }

    bfs(stepsA, A);
    bfs(stepsB, B);
    bfsS(stepsS, S);
    
    for(int i = 1; i <= n; i++){
        bfsc(i);
    }
    
    pair<int, int> r = {letssplitgang, mint};
    if(c == 1){
        fout << r.second << '\n';
        return 0;
    }
    vector<int> generateds = gen(stepsS, letssplitgang);
    vector<int> generatedc = genc();

    fout << generateds.size() + generatedc.size() - 2 << '\n';
    for(int i = generateds.size() - 1; i >= 1; i--){
        fout << generateds[i] << ' ';
    }


    for(int i = generatedc.size() - 1; i >= 0; i--){
        fout << generatedc[i] << ' ';
    }
    fout << '\n';
    /*
    for(int i = 1; i <= n; i++){
        fout << i << ": " << stepsA[i] << '\n'; 
    }
        */

    fout.flush();
    vector<int> generateda = genAB(stepsA, letssplitgang);
    fout << generateda.size() - 1 << '\n';
    for(int i = 0; i < generateda.size(); i++){
        fout << generateda[i] << ' ';
    }
    fout << '\n';

    vector<int> generatedb = genAB(stepsB, letssplitgang);
    fout << generatedb.size() - 1 << '\n';
    for(int i = 0; i < generatedb.size(); i++){
        fout << generatedb[i] << ' ';
    }
    fout << '\n';

}