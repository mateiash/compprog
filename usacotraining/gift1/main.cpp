/*
ID: david25
LANG: C++14
TASK: gift1
*/
#include <bits/stdc++.h>
#include <string>

#define inp fin
#define outp fout

using namespace std;

ifstream fin("gift1.in");
ofstream fout("gift1.out");

map<string, int> sums;
vector<string> names;

int main(){
    int N; inp >> N;

    for(int i = 0; i < N; i++){
        string s; inp >> s;
        sums[s] = 0;
        names.push_back(s);
    }

    for(int i = 0; i < N; i++){
        string s; inp >> s;
        int sum, people; inp >> sum >> people;    
        if(people == 0){
            continue;
        }
        sums[s] += sum % people - sum;
        for(int j = 0; j < people; j++){
            string s; inp >> s;
            sums[s] += sum / people;
        }
    }

    for(auto name : names){
        outp << name << ' ' << sums[name] << '\n';
    }

    return 0;
}