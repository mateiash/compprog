// https://kilonova.ro/problems/503
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ifstream fin("bingo.in");
ofstream fout("bingo.out");

char text[100'005];
char chars[5] = {'b', 'i', 'n', 'g', 'o'};

int stpos[5][100'005];
int drpos[5][100'005];

int dp[5][100'005];

int main(){
    int t;
    fin >> t;
    
    for(int cer = 0; cer < t; cer++){
        fin >> text;
        int len = strlen(text);

        int stpos[5][100'005] = {0};
        int drpos[5][100'005] = {0};

        int dp[5][100'005] = {0};

        for(int i = 0; i < 5; i++){
            int last = -999'999;
            //fout << chars[i] << '\n';
            for(int j = 0; j < len; j++){
                if(text[j] == chars[i]){
                    stpos[i][j] = j;
                } else {
                    stpos[i][j] = last;
                }
                last = stpos[i][j];
                //fout << stpos[i][j] << ' ';
            }
            //fout << '\n';
            last = 999'999;
            for(int j = len - 1; j >= 0; j--){
                if(text[j] == chars[i]){
                    drpos[i][j] = j;
                } else {
                    drpos[i][j] = last;
                }
                last = drpos[i][j];
                //fout << drpos[i][j] << ' ';

            }
            //fout << '\n';
        }

        for(int j = 0; j < len; j++){
            int i = 0;

            dp[i][j] = min(
                abs(j - stpos[i][j]),
                abs(drpos[i][j] - j)
            );

            //fout << dp[i][j] << ' ';
        
        }

        for(int i = 1; i < 5; i++){
            for(int j = i; j < len; j++){
                dp[i][j] = min(
                    abs(j - stpos[i][j]),
                    abs(drpos[i][j] - j)
                ) + dp[i - 1][j - 1];
            }
        }
        //fout << '\n';
        int maxx = 999'999'999;
        for(int j = 4; j < len; j++){
            maxx = min(dp[4][j], maxx);
        }fout << maxx << '\n';
    }
}