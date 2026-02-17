#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ifstream fin("sokoban.in");
ofstream fout("sokoban.out");

char mat[1005][1005];
int forbfs[1005][1005];

typedef pair<int, int> ip;

int main(){
    int N, M, Nc, Mc;
    fin >> N >> M >> Nc >> Mc;

    int setbox = 0;
    ip p, b;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            fin >> mat[i][j];
            if(mat[i][j]=='P'){
                p = {i, j};
            }
            if(mat[i][j]=='B' && !setbox){
                setbox = 1;
                b = {i, j};
            }
        }
    }

    cout << p.first << ' ' << p.second << '\n';
    cout << b.first << ' ' << b.second << '\n';

    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            if(mat[r][c] == 'w' || mat[r][c] == 'W'){
                forbfs[r][c] = 1;
            }
            if(mat[r][c] == 'W'){
                for(int rp = r - Nc + 1; rp <= r; rp++){
                    for(int cp = c - Mc + 1; cp <= c; cp++){
                        int rpp, cpp;
                        rpp = rp - (b.first - p.first);
                        cpp = cp - (b.second - p.second);
                        if(rpp < 1){
                            continue;
                        }
                        if(cpp < 1){
                            continue;
                        }

                        if(rpp > N){
                            continue;
                        }
                        if(cpp > M){
                            continue;
                        }
                        
                        forbfs[rpp][cpp] = 1;
                    }
                }
                
            }
        }
    }

    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            cout << forbfs[r][c];
        }
        cout << '\n';
    }


    return 0;
}
