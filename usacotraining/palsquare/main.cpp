/*
ID: david25
LANG: C++14
TASK: palsquare
*/
#include <bits/stdc++.h>

#define inp fin
#define outp fout

using namespace std;

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

vector<char> repbase(int n, int b){
    vector<char> rep;
    while(n){
        int d = n % b;
        if(d < 10){
            rep.push_back('0' + d);
        } else {
            rep.push_back('A' + d - 10);
        }
        //rep.push_back(n%b);
        n /= b;
    }
    reverse(rep.begin(), rep.end());
    return rep;
}

int checkpal(vector<char> rep){
    for(int i = 0; i < rep.size()/2; i++){
        if(rep[i] != rep[rep.size() - 1 - i]){
            return 0;
        }
    }

    return 1;

}

int main(){
    int b;
    inp >> b;

    for(int i = 1; i <= 300; i++){
        vector<char> rep1 = repbase(i, b);
        vector<char> rep2 = repbase((i*i), b);

        if(checkpal(rep2)){
            for(char c : rep1){
                outp << c;
            }
            outp << ' ';
            for(char c : rep2){
                outp << c;
            }
            outp << '\n';

        }
    }


    return 0;
}