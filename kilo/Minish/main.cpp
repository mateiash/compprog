#include <bits/stdc++.h>

using namespace std;

#define ll long long

ifstream fin("minish.in");
ofstream fout("minish.out");

int variabile[26];
int cnt = 0;

typedef pair<int, int> ip;
vector<ip> operatii;

int main(){
    for(int i = 0; i < 26; i++){
        fin >> variabile[i];
        if(variabile[i]){
            cnt++;
        }
    }

    while(cnt > 1){
        int maxv = -1;
        int maxp = -1;
        for(int i = 0; i < 26; i++){
            if(variabile[i] > maxv){
                maxv = variabile[i];
                maxp = i;
            }
        }

        int maxvp = -1;
        int maxpp = -1;
        for(int i = 0; i < 26; i++){
            if(variabile[i] > maxvp && i != maxp){
                maxvp = variabile[i];
                maxpp = i;
            }
        }

        ll minv = 999'999'999'999'999'999;
        ll minp = -1;
        for(int i = 0; i < 26; i++){
            if(variabile[i] < minv && variabile[i]){
                minv = variabile[i];
                minp = i;
            }
        }
        //cout << maxp << ' ' << maxpp << ' ' << minp << '\n';
        if(maxvp >= maxv / 2){
            variabile[maxp] -= maxvp;
            operatii.push_back({maxp, maxpp});
        } else if (maxv % 2 == 0) {
            variabile[maxp] /= 2;
            operatii.push_back({maxp, maxp});
        } else if (minv % 2){
            variabile[maxp] -= minv;
            operatii.push_back({maxp, minp});
            variabile[maxp] /= 2;
            operatii.push_back({maxp, maxp});
        } else {
            variabile[minp] /= 2;
            operatii.push_back({minp, minp});
        }

        cnt = 0;
        for(int i = 0; i < 26; i++){
            if(variabile[i]){
                cnt++;
            }
            //cout << variabile[i] << ' ';
        }
        //cout << '\n';
    }

    for(int i = 0; i < 26; i++){
        if(variabile[i]){
            fout << (char) (i + 'a') << '=' << variabile[i] << '\n';
        }
    }

    for(auto it = --operatii.end(); it >= operatii.begin(); it--){
        fout << (char) ((*it).first + 'a');
        fout << "+=";
        fout << (char) ((*it).second + 'a');
        fout << '\n';
    }
    

    return 0;
}