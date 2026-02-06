#include <bits/stdc++.h>

using namespace std;

int frecvdist[1005];
int distsrows[505];

int numtor[300'000];
int numtoc[300'000];

ifstream fin("traseu.in");
ofstream fout("traseu.out");

int main(){
    int N, M;
    fin >> N >> M;
    for(int r = 1; r <= N; r++){
        for(int c = 1; c <= M; c++){
            int el;
            fin >> el;

            numtor[el] = r;
            numtoc[el] = c;
        }
    }

    int rez = 0;
    for(int el = N*M; el >= 1; el--){
        int r = numtor[el];
        int c = numtoc[el];
        int dist = r - 1 + c - 1;

        for(int i = r; i <= N; i++){
            if(distsrows[i]){
                auto it = distsrows[i];
                int endc = it;

                if(endc >= c){
                    int distmax = endc - c + i - r;
                    rez = max(rez, distmax + 1);
                }
            }
        }

        distsrows[r] = max(distsrows[r],c);
        
    }

    fout << rez << '\n';

    return 0;
}