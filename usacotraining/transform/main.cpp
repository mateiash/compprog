/*
ID: david25
LANG: C++14
TASK: transform
*/
#include <bits/stdc++.h>

#define inp fin
#define outp fout

using namespace std;

ifstream fin("transform.in");
ofstream fout("transform.out");

char mat[15][15];
char mati[15][15];
char mat2[15][15];
int N;

int check90(){
    int res = 1;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            if(mat[r][c] != mat2[c][N - r - 1]){
                res = 0;
            }
        }
    }
    return res;
}

int check180(){
    int res = 1;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            if(mat[r][c] != mat2[N - r - 1][N - c - 1]){
                res = 0;
            }
        }
    }
    return res;
}

int check270(){
    int res = 1;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            if(mat2[r][c] != mat[c][N - r - 1]){
                res = 0;
            }
        }
    }
    return res;
}

int checkflip(){
    int res = 1;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            if(mat[r][c] != mat2[r][N - c - 1]){
                res = 0;
            }
        }
    }
    return res;
}

void flip(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N/2; c++){
            swap(mat[r][c], mat[r][N - c - 1]);
        }
    }
}

int checkidentical(){
    int res = 1;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            if(mat[r][c] != mat2[r][c]){
                res = 0;
            }
        }
    }
    return res;
}

int main() {
    inp >> N;
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            char cr; inp >> cr;
            mat[r][c] = cr;
        }
    }
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            char cr; inp >> cr;
            mat2[r][c] = cr;
        }
    }

    if(check90()){
        outp << "1\n";
        return 0;
    }
    if(check180()){
        outp << "2\n";
        return 0;
    }
    if(check270()){
        outp << "3\n";
        return 0;
    }
    if(checkflip()){
        outp << "4\n";
        return 0;
    }
    flip();
    if(check90() || check180() || check270()){
        outp << "5\n";
        return 0;
    }
    flip();
    if(checkidentical()){
        outp << "6\n";
        return 0;
    }
    outp << "7\n";
    return 0;
}