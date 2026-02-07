/*
ID: david25
LANG: C++14
TASK: milk2
*/
#include <bits/stdc++.h>

#define inp fin
#define outp fout

using namespace std;

ifstream fin("milk2.in");
ofstream fout("milk2.out");

map<int, int> smen;

int main() {
    int N; 
    inp >> N; 

    for(int i = 0; i < N; i++){
        int start, stop;
        inp >> start >> stop;
        smen[start]++;
        smen[stop]--;
    }

    int startda = 99999999;
    int startnu = 99999999;
    int maxda = 0;
    int maxnu = 0;
    int curr = 0;
    for(auto el : smen){
        curr += el.second;
        if(curr == 0){
            startnu = el.first;
            maxda = max(maxda, - startda + startnu);
        } else if(curr == 1 && el.second == 1){
            startda = el.first;
            maxnu = max(maxnu, - startnu + startda);

        }
    }

    outp << maxda << ' ' << maxnu << '\n';
    return 0;
}