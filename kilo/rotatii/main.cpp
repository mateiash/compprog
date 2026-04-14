#include <bits/stdc++.h>

using namespace std;

ifstream fin("rotatii.in");
ofstream fout("rotatii.out");

int trs[100'005];
int rots[100'005];

int main() {

    int C;
    fin >> C;

    if(C == 1){
        int N; fin >> N;

        for(int i = 1; i <= N; i++){
            char el; fin >> el;

            if(el == 'N'){
                trs[i] = 0;
            }
            if(el == 'V'){
                trs[i] = 1;
            }
            if(el == 'S'){
                trs[i] = 2;
            }
            if(el == 'E'){
                trs[i] = 3;
            }
        }

        for(int i = 1; i <= N; i++){
            string el; fin >> el;

            if(el == "0"){
                rots[i] = 0;
            }
            if(el == "90"){
                rots[i] = 1;
            }
            if(el == "180"){
                rots[i] = 2;
            }
            if(el == "270"){
                rots[i] = 3;
            }
        }
        int x = 0, y = 0;
        for(int i = 1; i <= N; i++){
            auto el = trs[i];
            if(el == 0){
                y++;
            }
            if(el == 1){
                x--;
            }
            if(el == 2){
                y--;
            }
            if(el == 3){
                x++;
            }
            auto elp = rots[i];
            if(elp == 0){
                
            }
            if(elp == 1){
                swap(x, y);
                y*=-1;
            }
            if(elp == 2){
                x*=-1;
                y*=-1;
            }
            if(elp == 3){
                swap(x, y);
                x*=-1;
            }
        }
        

        fout << x << ' ' << y << '\n';

        return 0;

    }

    if(C == 2){
        int T; fin >> T;

        for(int cer = 0; cer < T; cer++){
            int N; fin >> N;
            
            for(int i = 1; i <= N; i++){
                char el; fin >> el;

                if(el == 'N'){
                    trs[i] = 0;
                }
                if(el == 'V'){
                    trs[i] = 1;
                }
                if(el == 'S'){
                    trs[i] = 2;
                }
                if(el == 'E'){
                    trs[i] = 3;
                }
            }
            int a, b; fin >> a >> b;
            if(N - abs(a) - abs(b) >= 0 && (N - abs(a) - abs(b)) % 2 == 0 ){
                fout << "DA\n";
            } else {
                fout << "NU\n";
            }

        }
    }

    int N; fin >> N;
            
    for(int i = 1; i <= N; i++){
        char el; fin >> el;

        if(el == 'N'){
            trs[i] = 0;
        }
        if(el == 'V'){
            trs[i] = 1;
        }
        if(el == 'S'){
            trs[i] = 2;
        }
        if(el == 'E'){
            trs[i] = 3;
        }
    }
    int a, b; fin >> a >> b;
    if(N - abs(a) - abs(b) >= 0 && (N - abs(a) - abs(b)) % 2 == 0 ){
        fout << "DA\n";
    } else {
        fout << "NU\n";
    }

    return 0;
}