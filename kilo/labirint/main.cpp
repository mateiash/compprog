#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long

#define BIG 999'999'999

using namespace std;

ifstream fin("labirint.in");
ofstream fout("labirint.out");

typedef pair<int, int> xyp;

int n, m;
int lab[1005][1005];
int fromorigin[1005][1005];
int fromend[1005][1005];

int white;

xyp operator+(const xyp& p1, const xyp& p2){
    return {
        p1.first + p2.first,
        p1.second + p2.second
    };
}

const xyp dfs[4] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
};

int* acces(int mat[][1005], xyp pos){
    return &mat[pos.first][pos.second];
}

void run_dfs(int rez[][1005], xyp start){

    vector<xyp> current, next;
    current.push_back(start);
    *acces(rez, start) = 1;
    int explored = 1;
    while(!current.empty()){
        for(xyp pos : current){
            int cstep = *acces(rez, pos);

            for(int i = 0; i <= 3; i++){
                xyp npos = pos+dfs[i];
                if(npos.first > n || npos.second > m){
                    continue;
                }

                if(npos.first < 1 || npos.second < 1){
                    continue;
                }

                if(*acces(rez, npos) != 0){
                    continue;
                }

                
                if(*acces(lab, npos) == -1){
                    *acces(rez, npos) = -1;
                    explored++;
                    continue;
                }

                *acces(rez, npos) = cstep+1;
                next.push_back(npos);
                explored++;
                continue;

            }
        }

        current = next;
        next.clear();
    }

}

int main(){
    
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char el; fin >> el;
            lab[i][j] = -(el - '0');
        }
    }
    
    run_dfs(fromorigin, {1, 1});
    run_dfs(fromend, {n, m});

    int mind = fromorigin[n][m];
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fout << fromorigin[i][j] << ' ';
        }fout << '\n';
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            fout << fromend[i][j] << ' ';
        }fout << '\n';
    }
        */

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            if(fromend[i][j] == 0 || fromend[i][j] == 0 || lab[i][j] == 0){
                fout << 0;
                continue;
            }

            int minfe = BIG;
            int minfo = BIG;
            for(int k = 0; k <= 3; k++){
                xyp pprime = {i, j}; 
                pprime = pprime + dfs[k];

                if(pprime.first > n || pprime.second > m){
                    continue;
                }

                if(pprime.first < 1 || pprime.second < 1){
                    continue;
                }

                int fe = *acces(fromend, pprime);
                int fo = *acces(fromorigin, pprime);

                if(fe == 0 && pprime != make_pair(n, m)){
                    fe = *acces(fromend, pprime) = BIG;
                }

                if(fo == 0 && pprime != make_pair(1, 1)){
                    fo = *acces(fromorigin, pprime) = BIG;
                }

                if(fe != -1)
                    minfe = min(minfe, fe);
                if(fo != -1)
                    minfo = min(minfo, fo);

            }

            if(minfe + minfo + 1 < mind){
                fout << 1;
            } else {
                fout << 0;
            }

            //fout << fromend[i][j] << ' ';
        }
        fout << '\n';
    }




    return 0;
}
