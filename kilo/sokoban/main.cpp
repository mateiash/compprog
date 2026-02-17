// unfinished
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ifstream fin("sokoban.in");
ofstream fout("sokoban.out");

typedef pair<int, int> ip;

struct state{
    ip p;
    ip c;
};

char mat[1005][1005];
int sp[1005][1005];

int sum(int r1, int c1, int r2, int c2){
    return sp[r2][c2] + sp[r1 - 1][c1 - 1] -
        (sp[r2][c1 - 1] + sp[r1 - 1][c2])
    ;
}

int N, M, Nc, Mc;
ip p, b, f;

ip operator+(const ip& a, const ip& b){
    return {a.first + b.first, a.second + b.second};
}

ip bfs[4] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int runbfs(){
    vector<state> current, next;

    current.push_back({p, b});

    int step = 0;

    while(!current.empty()){
        for(state s: current){
            if(s.p == f){
                cout << s.p.first << ' ' << s.p.second << '\n';
                cout << s.c.first << ' ' << s.c.second << '\n';
                return step;
            }

            for(int i = 0; i < 4; i++){
                ip newpos = bfs[i] + s.p;

                if(
                    newpos.first == 0 || 
                    newpos.first == N + 1 || 
                    newpos.second == 0 || 
                    newpos.second == M + 1
                ) {
                    continue;
                }

                if(
                    mat[newpos.first][newpos.second] == 'w' || 
                    mat[newpos.first][newpos.second] == 'W'
                ) {
                    continue;
                }
                if(
                    newpos.first >= s.c.first &&
                    newpos.second >= s.c.second &&
                    newpos.first <= s.c.first + Nc - 1 &&
                    newpos.second <= s.c.second + Mc - 1
                ){
                    state newstate = {
                        newpos,
                        bfs[i] + s.c,
                    };

                    cout << "yes\n";

                    if (newstate.c.first < 1 || newstate.c.first + Nc - 1 > N || 
                        newstate.c.second < 1 || newstate.c.second + Mc - 1 > M) {
                        continue; 
                    }

                    if(
                        sum(
                            newstate.c.first, newstate.c.second, 
                            newstate.c.first + Nc - 1, newstate.c.second + Mc - 1
                        ) == 0
                    ){
                        next.push_back(newstate);
                        
                    } else {
                        cout << "failed sum\n";
                        cout << newstate.c.first << ' ' << newstate.c.second << '\n'; 
                    }


                    continue;

                }

                next.push_back({newpos, s.c});
                cout << "pb no move\n";
                
            }
        }
        cout << '\n';
        current = next;
        next.clear();
        step++;
    }
    return -1;
}

int main(){
    fin >> N >> M >> Nc >> Mc;

    int setbox = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            fin >> mat[i][j];
            if(mat[i][j]=='P'){
                p = {i, j};
            }
            if(mat[i][j]=='F'){
                f = {i, j};
            }
            if(mat[i][j]=='B' && !setbox){
                setbox = 1;
                b = {i, j};
            }
        }
    }
    /*
    cout << p.first << ' ' << p.second << '\n';
    cout << b.first << ' ' << b.second << '\n';
    */
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            int el = (mat[r][c] == 'W');

            sp[r][c] = sp[r][c - 1] +
                sp[r - 1][c] -
                sp[r - 1][c - 1] + el;
            cout << sp[r][c] << ' ';
        }
        cout << '\n';
    }

    fout << runbfs() << '\n';

    return 0;
}
