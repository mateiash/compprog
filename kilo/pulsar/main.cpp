#include <bits/stdc++.h>

using namespace std;

ifstream fin("pulsar.in");
ofstream fout("pulsar.out");

int C, N, P;
int space[60][505][505];

int lcmt = 1;

typedef struct {
    int x;
    int y;
    int r;
    int t;
} pulsar;

pulsar pulsari[15'005];

typedef pair<int, int> xyp;

xyp operator+(const xyp& p1, const xyp& p2){
    return {
        p1.first + p2.first,
        p1.second + p2.second
    };
}

xyp dir[5] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
    {0,0}
};



set<xyp> current, nextv;
int run_bfs(xyp start, xyp end){
    current.clear();
    nextv.clear();
    current.insert(start);
    int ct = 0;
    int done = 0;
    while(!done){
        for(xyp pos : current){
            for(int i = 0; i <= 4; i++){
                xyp npos = pos+dir[i];
                if(npos.first > N || npos.second > N){
                    continue;
                }

                if(npos.first < 1 || npos.second < 1){
                    continue;
                }

                if(space[(ct+1)%lcmt][npos.first][npos.second] != 0){
                    continue;
                }

                if(npos == end){
                    done = 1;
                    return ct + 1;
                }
                
                nextv.insert(npos);

            }
        }
        ct++;
        current = nextv;
        nextv.clear();
    }
}


void calcmat(int ct){
    int moment = ct % 60;
    for(int p = 1; p <= P; p++){
        int x = pulsari[p].x;
        int y = pulsari[p].y;
        
        int r = (pulsari[p].t + ct) % pulsari[p].r;

        //cout << x << ' ' << y << ' ' << r << '\n';
        for(int i = x - r; i <= x + r; i++){
            if(i < 1 || i > N)
                continue;
            for(int j = y - r; j <= y + r; j++){
                if(j < 1 || j > N)
                    continue;

                if(abs(x - i) + abs(y - j) <= r){
                    space[moment][i][j] = 1;
                }
            }
        }
        
    }
}

int main(){
    fin >> C >> N >> P;

    for(int i = 1; i <= P; i++){
        fin >>
            pulsari[i].x >> 
            pulsari[i].y >> 
            pulsari[i].r >> 
            pulsari[i].t; 
        lcmt = lcm(pulsari[i].r, lcmt);
        
    }

    for(int i = 0; i < lcmt; i++){
        calcmat(i);
    }

    if(C == 1){
        int maxrez = -1;
        for(int i = 0; i < lcmt; i++){
            
            int rez = 0;
            for(int x = 1; x <= N; x++){
                for(int y = 1; y <= N; y++){
                    if(space[i][x][y])
                        rez++;
                }
            }
            maxrez = max(rez, maxrez);
            
        }
        fout << maxrez << '\n';
        return 0;
    }
    int xs, ys, xe, ye;
    fin >> xs >> ys>> xe >> ye;

    fout << run_bfs({xs, ys}, {xe, ye}) << '\n';

    return 0;
}