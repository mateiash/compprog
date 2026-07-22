#include <bits/stdc++.h>

using namespace std;

ifstream fin("transform.in");
ofstream fout("transform.out");

#define ll long long

typedef pair<int, int> ip;

set<ip> byrows1;
set<ip> bycols1;

set<ip> byrows2;
set<ip> bycols2;

vector<ip> starts1;
vector<ip> starts2;

int main(){
    int N;
    fin >> N;

    for(int i = 1; i <= 2*N; i++){
        int r, c;
        fin >> r >> c;

        byrows1.insert({r, c});
        bycols1.insert({c, r});
    }
    
    for(int i = 1; i <= 2*N; i++){
        int r, c;
        fin >> r >> c;
        
        byrows2.insert({r, c});
        bycols2.insert({c, r});
    }

    starts1.resize(2*N + 1);
    starts2.resize(2*N + 1);

    set<ip> brc = byrows1;

    // its all graphs ...
    // always has been
    while(!brc.empty()){
        ip start = *starts1.begin();
        bool nextdir = 0;
        ip nxt = start;
        do{
            
        }while(start != nxt);
    }

    return 0;
}