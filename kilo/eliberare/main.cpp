#include <bits/stdc++.h>

using namespace std;

ifstream fin("eliberare.in");
ofstream fout("eliberare.out");

int rs, cs;
int eliberate[1105][1105];
char mat[1105][1105];

typedef pair<int, int> ip;

ip order[1210005];
int howmany = 0;

void elib(int r, int c){
    ip opos = {r, c};
    int* dir; int sens; int goal;
    char m = mat[r][c];

    if(m == '^'){
        dir = &r;
        sens = -1;
        goal = 1;
    }
    if(m == '<'){
        dir = &c;
        sens = -1;
        goal = 1;
    }
    if(m == '>'){
        dir = &c;
        sens = 1;
        goal = cs;
    }
    if(m == 'v'){
        dir = &r;
        sens = 1;
        goal = rs;
    }

    while(*dir != goal){
        *dir += sens;
        if(eliberate[r][c] == 0){
            elib(r, c);
        }
    }

    eliberate[opos.first][opos.second] = 1;

    order[howmany] = opos;
    howmany++;

}

int main(){

    fin >> rs >> cs;

    for(int i = 1; i <= rs; i++){
        for(int j = 1; j <= cs; j++){
            fin >> mat[i][j];
        }
    }

    for(int i = 1; i <= rs; i++){
        for(int j = 1; j <= cs; j++){
            if(eliberate[i][j] == 0){
                elib(i, j);

                for(int i = 0; i < howmany; i++){
                    ip el = order[i];
                    fout << el.first << ' ' << el.second << '\n';
                    //fout.flush();
                }
                //printelib();
                howmany = 0;
            }
        }
    }


    return 0;
}