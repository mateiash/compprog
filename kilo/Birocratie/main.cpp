#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("birocratie.in");
ofstream fout("birocratie.out");

int mat[1005][1005];
ll dp[1005][1005];
ll dpup[1005][1005];
ll dpdwn[1005][1005];
int spdiag[1005][1005];

int main(){
    int N;
    fin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            fin >> mat[i][j];
            dp[i][j] = -999'999'999'999'999'999;
            dpup[i][j] = -999'999'999'999'999'999;
            dpdwn[i][j] = -999'999'999'999'999'999;
        }
    }

    dp[1][1] = mat[1][1];
    dpdwn[1][1] = mat[1][1];
    dpup[1][1] = mat[1][1];

    for(int i = 2; i <= N; i++){
        int r = i; int c = 1;
        for(; r >= 1; c++){
            if(c - 1 >= 1)
                dpup[r][c] = max(dpup[r][c], mat[r][c] + dp[r][c - 1]);
            if(r - 1 >= 1)
                dpup[r][c] = max(dpup[r][c], mat[r][c] + dp[r - 1][c]);
            if(c - 1 >= 1)
                dpup[r][c] = max(dpup[r][c], mat[r][c] + dpup[r + 1][c - 1]);
            r--;
        }
        r++; c--;
        for(; c >= 1; c--){
            if(c - 1 >= 1)
                dpdwn[r][c] = max(dpdwn[r][c], mat[r][c] + dp[r][c - 1]);
            if(r - 1 >= 1)
                dpdwn[r][c] = max(dpdwn[r][c], mat[r][c] + dp[r - 1][c]);
            if(r - 1 >= 1)
                dpdwn[r][c] = max(dpdwn[r][c], mat[r][c] + dpdwn[r - 1][c + 1]);
            
            dp[r][c] = 
                max(dpdwn[r][c], dpup[r][c]);    
            r++;
        }
    }

    for(int i = 2; i <= N; i++){
        int r = N; int c = i;
        for(; c <= N; c++){
            if(c - 1 >= 1)
                dpup[r][c] = max(dpup[r][c], mat[r][c] + dp[r][c - 1]);
            if(r - 1 >= 1)
                dpup[r][c] = max(dpup[r][c], mat[r][c] + dp[r - 1][c]);
            if(r + 1 <= N)
                dpup[r][c] = max(dpup[r][c], mat[r][c] + dpup[r + 1][c - 1]);
            r--;
        }
        r++; c--;
        for(; r <= N; c--){
            if(c - 1 >= 1)
                dpdwn[r][c] = max(dpdwn[r][c], mat[r][c] + dp[r][c - 1]);
            if(r - 1 >= 1)
                dpdwn[r][c] = max(dpdwn[r][c], mat[r][c] + dp[r - 1][c]);
            if(c + 1 <= N)
                dpdwn[r][c] = max(dpdwn[r][c], mat[r][c] + dpdwn[r - 1][c + 1]);
            
            dp[r][c] = 
                max(dpdwn[r][c], dpup[r][c]);    
            r++;
        }
    }

    /*
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    
    fout << dp[N][N] << '\n';

    return 0;
}