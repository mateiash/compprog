/*
ID: david25
LANG: C++14
TASK: friday
*/
#include <bits/stdc++.h>

#define inp fin
#define outp fout

using namespace std;

ifstream fin("friday.in");
ofstream fout("friday.out");

int weekdays[7];
int point = 5;

int months[12] = 
{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int N;
    inp >> N;

    for(int year = 1900; year < 1900 + N; year++){
        int leap = 0;
        if(year % 100 == 0){
            if(year % 400 == 0){
                leap = 1;
            } 
        } else {
            if(year % 4 == 0){
                leap = 1;
            }
        }
        for(int month = 0; month < 12; month++){
            weekdays[point]++;
            point += months[month] + (month == 1) * (leap);
            point %= 7;
        }
    }

    outp << weekdays[5] << ' ';
    outp << weekdays[6] << ' ';
    for(int i = 0; i < 4; i++){
        outp << weekdays[i] << ' ';
    }
    outp << weekdays[4] << '\n';
    


    return 0;
}