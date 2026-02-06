#include <algorithm>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ifstream fin("eq4.in");
ofstream fout("eq4.out");

ll coeff[5];
/*
0: x
1: y
2: z
3: t
4: offset
*/

ll a, b, E;

vector<ll> posibile1;
vector<ll> posibile2;

vector<pair<ll, int>> todo;

#define inp fin
#define outp fout

int main(){

    int C;
    string exp;
    inp >> C;
    inp >> exp;
    
    inp >> a >> b >> E;
    exp.push_back('+');
    int mult = 1;
    int quant = 0;
    int type = 4;
    for(int i = 0; i < exp.size(); i++){
        char c = exp[i];
        if(c == '+'){
            coeff[type] += quant * mult;
            quant = 0;
            mult = 1;
            type = 4;
        } else
        if(c == '-'){
            coeff[type] += quant * mult;
            quant = 0;
            mult = -1;
            type = 4;
        } else 
        if(c == 'x'){
            type = 0;
            quant += (exp[i-1] == '+' || exp[i-1] == '-');
        } else
        if(c == 'y'){
            type = 1;
            quant += (exp[i-1] == '+' || exp[i-1] == '-');
        } else
        if(c == 'z'){
            type = 2;
            quant += (exp[i-1] == '+' || exp[i-1] == '-');
        } else
        if(c == 't'){
            type = 3;
            quant += (exp[i-1] == '+' || exp[i-1] == '-');
        } else {
            int d = c - '0';
            quant *= 10;
            quant += d;
        }

    }

    if(C == 1){
        int rasp = 0;
        for(int i = 0; i < 5; i++){
            rasp += coeff[i];
        }
        fout << rasp << '\n';
        return 0;
    }

    E -= coeff[4];
    
    for(int i = a; i <= b; i++){
        for(int j = a; j <= b; j++){
            posibile1.push_back(i*coeff[0] + j*coeff[1]);
        }
    }

    for(int i = a; i <= b; i++){
        for(int j = a; j <= b; j++){
            posibile2.push_back(i*coeff[2] + j*coeff[3]);
        }
    }

    sort(posibile1.begin(), posibile1.end());
    sort(posibile2.begin(), posibile2.end());


    ll rez = 0;
    for(ll el : posibile1){
        auto start = lower_bound(posibile2.begin(), posibile2.end(), E - el);
        auto stop = upper_bound(posibile2.begin(), posibile2.end(), E - el);
        rez += stop - start;
    }

    outp << rez << '\n';

    return 0;
}