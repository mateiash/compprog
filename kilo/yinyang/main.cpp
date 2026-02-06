#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mat(105, vector<int>(105));
vector<vector<int>> matT(105, vector<int>(105));

vector<vector<int>> mattarg(105, vector<int>(105));
vector<vector<int>> matTtarg(105, vector<int>(105));

ifstream fin("yinyang.in");
ofstream fout("yinyang.out");

int N, M;

int Nl = N;
int Ml = M;

bool operator<(const vector<int>& a, const vector<int>& b){
    for(int i = 1; i <= Ml; i++){
        if(a[i] < b[i]){
            return 1;
        } else if (a[i] > b[i]){
            return 0;
        }
    }
    return 0;
}

bool operator>(const vector<int>& a, const vector<int>& b){
    for(int i = 1; i <= Ml; i++){
        if(a[i] > b[i]){
            return 1;
        } else if (a[i] < b[i]){
            return 0;
        }
    }
    return 0;
}

int sortR(vector<int>& row){
    int n = Ml;
    bool swapped;
    int opps = 0;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (row[j + 1] > row[j + 1 + 1]) {
                swap(row[j + 1], row[j + 1 + 1]);
                opps++;
                swapped = true;
            }
        }
      
        
        if (!swapped)
            break;
    }
    return opps;
    
}

int sortC(vector<vector<int>>& row){
    int n = Nl;
    bool swapped;
    int opps = 0;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (row[j + 1] > row[j + 1 + 1]) {
                swap(row[j + 1], row[j + 1 + 1]);
                opps++;
                swapped = true;
            }
        }
      
        
        if (!swapped)
            break;
    }
    return opps;
}

int ras = 0;

int gentarg(int T){
    
    Nl = N;
    Ml = M;

    auto m = &mat;
    auto mtarg = &mattarg;

    if(T){
        Nl = M;
        Ml = N;
        m = &matT;
        mtarg = &matTtarg;
    }

    *mtarg = *m;

    int oppsrows = 0;
    for(int i = 1; i <= Nl; i++){
        /*
        sort(
             next((*mtarg)[i].begin()), 
             next((*mtarg)[i].begin()) + Ml);
        */
        oppsrows = max(sortR((*mtarg)[i]), oppsrows);
    }
    
    
    /*
    sort(
        next((*mtarg).begin()), 
        next((*mtarg).begin()) + Nl);
    */

    int oppscols = sortC(*mtarg);
    ras += oppscols;
    int rasp = oppscols + oppsrows;
    return rasp;
}

int main() {
    
    fin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            int el;
            fin >> el; 
            mat[i][j] = (el);
            matT[j][i] = mat[i][j];
        }
    }

    int rasp = gentarg(0);
    rasp = max(gentarg(1), rasp);
    /*
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            fout << mattarg[i][j] << ' ';
        }
        fout << '\n';
    }
    
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            fout << matTtarg[i][j] << ' ';
        }
        fout << '\n';
    }
    */
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(mattarg[i][j] < mattarg[i-1][j]){
                fout << "-1\n";
                return 0;
            }
            if(mattarg[i][j] < mattarg[i][j - 1]){
                fout << "-1\n";
                return 0;
            }
        }
        
    }
    
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(matTtarg[i][j] < matTtarg[i-1][j]){
                fout << "-1\n";
                return 0;
            }
            if(matTtarg[i][j] < matTtarg[i][j - 1]){
                fout << "-1\n";
                return 0;
            }
        }
    }
    
    fout << ras << '\n';
    return 0;
    
}