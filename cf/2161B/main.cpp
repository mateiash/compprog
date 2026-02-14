#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

//ofstream fout("debug.out");

int mat[105][105];

int diag1[305];
int diag2[305];


int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        memset(diag1, 0, sizeof(diag1));
        memset(diag2, 0, sizeof(diag2));
        int n;
        cin >> n;
        int sum = 0;
        for(int r = 1; r <= n; r++){
            for(int c = 1; c <= n; c++){
                char el; cin >> el;
                if(el != '#'){
                    mat[r][c] = 0;
                    continue;
                }
                mat[r][c] = 1;
                sum++;
            }
        }
        int good = 0;
        for(int r = 1; r <= n; r++){
            for(int c = 1; c <= n; c++){
                int d1ind = 150 + r - c;
                diag1[d1ind]+=mat[r][c];
            }
        }

        for(int i = 150 + 1 - n; i <= 150 + n - 1; i++){
            //fout << diag1[i] << ' ';
            if(diag1[i] + diag1[i + 1] == sum){
                good = 1;
            }
        }//fout << '\n';

        for(int r = 1; r <= n; r++){
            for(int c = 1; c <= n; c++){
                int d2ind = 150 + r - (n - c + 1);
                diag2[d2ind]+=mat[r][c];
            }
        }

        for(int i = 150 + 1 - n; i <= 150 + n - 1; i++){
            //fout << diag2[i] << ' ';
            if(diag2[i] + diag2[i + 1] == sum){
                good = 1;
            }
        }//fout << '\n';
        
        for(int r = 1; r <= n - 1; r++){
            for(int c = 1; c <= n - 1; c++){
                if(
                    mat[r][c] + mat[r][c + 1] +
                    mat[r + 1][c] + mat[r + 1][c + 1] == sum
                ){
                    good = 1;
                }
            }
        }

        if(good){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }


    }

    return 0;
}
