/*
ID: david25
LANG: C++14
TASK: namenum
*/
#include <bits/stdc++.h>

#define ll long long

#define inp fin
#define outp fout

using namespace std;

ifstream fin("namenum.in");
ofstream fout("namenum.out");
ifstream dict("dict.txt");

int digits[26] = {
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, -1, 7, 7,
    8, 8, 8,
    9, 9, 9, -1
};

int main() {
    ll num; inp >> num;
    string word;
    int haveone = 0;
    while(dict >> word){
        string cpword = word;
        ll cpnum = num;
        //cout << cpnum << '\n';
        int good = 1;
        while(!word.empty()){
            char c = word.back();
            //cout << c << ' ' << digits[c - 'A'] << ' ' << cpnum % 10 << '\n';
            if(digits[c-'A'] != cpnum % 10){
                good = 0;
                //cout << "nig\n";
            }

            cpnum /= 10;
            word.pop_back();
        }

        if(cpnum != 0){
            good = 0;
            //cout << "efae\n";
        }

        if(good){
            haveone = 1;
            outp << cpword << '\n';
        }
    }
    if(!haveone){
        outp << "NONE\n";
    }
    return 0;
}