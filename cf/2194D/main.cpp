// unfinished
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ll mat[300'005];

ll n, m;
//ofstream fout("debug.out");
ll* matf(int r, int c){
    return &(mat[r*m + c]);
}

ll summ(int r1, int c1, int r2, int c2){
    //fout << *matf(r1 - 1, c1 - 1) << " from summ\n";
    //fout << r1- 1 << ' ' << c1 - 1 << '\n';
    return (
        *matf(r2, c2) - *matf(r1 - 1, c2) -
        *matf(r2, c1 - 1) + *matf(r1 - 1, c1 - 1)
    );
}
 

int main(){
    int t;
    cin >> t;

    for(int cer = 0; cer < t; cer++){
        cin >> n >> m;
        n++;
        m++;
        ll sum = 0;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                int el; cin >> el;
                sum += el;
                *matf(i, j) = el;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                *matf(i, j) = *matf(i - 1, j) +
                    *matf(i, j - 1) -
                    *matf(i - 1, j - 1) + *matf(i, j);
            }
            //fout << '\n';
        }
        ll gotup = 0;

        int r, c;
        for(r = 1; r < n; r++){
            for(c = m - 1; c >= 1; c--){
                if(gotup + summ(r, c, r, m - 1)== (sum + 1) / 2){
                    goto done;
                }
            }
            gotup = summ(1, 1, r, m - 1);
        }
        done:
        
        cout << (sum/2)*((sum + 1)/2) << '\n';

        for(int i = 1; i < r; i++){
            cout << 'D';
        }

        for(int i = 1; i < c; i++){
            cout << 'R';
        }

        cout << 'D';

        for(int i = c; i <= m - 1; i++){
            cout << 'R';
        }

        for(int i = r+1; i <= n - 1; i++){
            cout << 'D';
        }

        cout << '\n';


    }

    return 0;
}
