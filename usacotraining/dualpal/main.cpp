/*
ID: david25
LANG: C++14
TASK: dualpal
*/
#include <bits/stdc++.h>
#include <vector>

#define inp fin
#define outp fout

using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

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
    int n, s;
    inp >> n >> s;

    while(n){
        s++;
        int howmany = 0;
        for(int b = 2; b <= 10; b++){
            vector<char> rep = repbase(s, b);
            howmany += checkpal(rep);
        }
        if(howmany >= 2){
            outp << s << '\n';
            n--;
        }
    }


    return 0;
}