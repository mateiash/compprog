#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define inp fin
#define outp fout

ifstream fin("turnuri.in");
ofstream fout("turnuri.out");

int turnuri[100'005];

int maxdr[2][100'005];
int maxst[2][100'005];

list<int> tofirst;
list<int> tosecond;

int offsets[100'005];

int main(){
    int n;
    inp >> n;

    for(int i = 1; i <= n; i++){
        inp >> turnuri[i];
    }

    for(int i = 1; i <= n; i++){
        int selected = turnuri[i];

        auto it = tosecond.begin();
        while(it != tosecond.end()){
            if(turnuri[*it] < selected){
                maxdr[1][*it] = i;
                it = tosecond.erase(it);
            } else {
                break;
            }
        }

        it = tofirst.begin();

        while(it != tofirst.end()){
            if(turnuri[*it] < selected){
                maxdr[0][*it] = i;
                tosecond.push_front(*it);
                it = tofirst.erase(it);
            } else {
                break;
            }
        }

        tofirst.push_front(i);
    }

    tofirst.clear();
    tosecond.clear();

    for(int i = n; i >= 1; i--){
        int selected = turnuri[i];

        auto it = tosecond.begin();
        while(it != tosecond.end()){
            if(turnuri[*it] < selected){
                maxst[1][*it] = i;
                it = tosecond.erase(it);
            } else {
                break;
            }
        }

        it = tofirst.begin();
        vector<int> todododod;
        while(it != tofirst.end()){
            if(turnuri[*it] < selected){
                maxst[0][*it] = i;
                todododod.push_back(*it);
                it = tofirst.erase(it);
            } else {
                break;
            }
        }

        for(int ind = todododod.size() - 1; ind >= 0; ind--){
            tosecond.push_front(todododod[ind]);
        }

        tofirst.push_front(i);
    }
    
    for(int i = 1; i <= n; i++){
        if(!maxst[0][i])
            maxst[0][i] = 0;
        if(!maxst[1][i])
            maxst[1][i] = 0;
        if(!maxdr[0][i])
            maxdr[0][i] = n + 1;
        if(!maxdr[1][i])
            maxdr[1][i] = n + 1;
    }

    /*
    for(int i = 1; i <= n; i++){
        outp << maxdr[0][i] << ' ';
    } outp << '\n';

    for(int i = 1; i <= n; i++){
        outp << maxdr[1][i] << ' ';
    } outp << '\n';
    outp << '\n';

    for(int i = 1; i <= n; i++){
        outp << maxst[0][i] << ' ';
    } outp << '\n';

    for(int i = 1; i <= n; i++){
        outp << maxst[1][i] << ' ';
    } outp << '\n';
    outp << '\n';
    */

    ll basic = 0;
    for(int i = 1; i <= n; i++){
        int st = maxst[0][i];
        int dr = maxdr[0][i];
        basic += dr - st - 1;
        //outp << dr - st - 1 << " basic\n";
        //offsets[st + 1] -= 1;
        //offsets[dr] += 1;
    }
    
    for(int i = 1; i <= n; i++){
        offsets[i] = offsets[i - 1] + offsets[i];
    }

    for(int i = 1; i <= n; i++){
        int st = maxst[0][i];
        int dr = maxdr[0][i];
        offsets[i] -= dr - st - 1 - 1;

        offsets[dr] += maxdr[1][i] - dr;
        //outp << dr << ' ' << maxdr[1][i] - dr << " dr\n";
        offsets[st] += st - maxst[1][i];
        //outp << st << ' ' << st - maxst[1][i] << " st\n";

    }
   // outp << basic << "\n\n";
    for(int i = 1; i <= n; i++){
        outp << basic + offsets[i] << '\n';
    }

    return 0;
}