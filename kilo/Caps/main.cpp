#include <bits/stdc++.h>

#define ll long long

#define inp fin
#define outp fout

using namespace std;

ifstream fin("caps.in");
ofstream fout("caps.out");

char invert(char c, int invertf){
    if(c <= 'Z'){
            return (char) (c + invertf*(-'A' + 'a'));
            ;

    } else {
        return (char) (c + invertf*(+'A' - 'a'));
        ;

    }
}
map<char, int> freqc;

int untilsp[256][100'005];

int main(){
    ll N, Q;
    string str;
    inp >> N >> Q;
    //inp >> str;
    for(int i = 0; i < N; i++){
        char c; inp >> c;
        str.push_back(c);
    }
    int spi = 0;
    for(char c : str){
        freqc[c]++;
        untilsp[c][spi]++;
        spi++;
    }

    for(int i = 0; i < 256; i++){
        int prev = 0;
        for(int j = 0; j < N; j++){
            untilsp[i][j] = prev + untilsp[i][j];
            prev = untilsp[i][j];
        }
    }
    /*
    for(int i = 1; i <= 57; i++){
        ll pos; pos = i;
        pos--;
        ll index = (pos)/N;
        ll cpindex = index;
        ll pow4 = 1;
        ll pow4cp = 0;
        while(pow4 <= index){
            pow4 *= 4;
        } pow4 /= 4;
        pow4cp = pow4;
        int inverted = 0;
        ll cnt = 0;
        while(index && pow4){
            if(index / pow4 == 1 || index / pow4 == 2){
                inverted = (inverted + 1) % 2;
            }
            index = index % pow4;
            pow4 /= 4;
        }
        char resultc = invert(str[pos%N], inverted);
        pow4 = pow4cp;
        index = cpindex;

        while(pow4 > 1){
            cnt += (freqc[resultc] + freqc[invert(resultc, 1)])*pow4/2*(index/pow4); 
            index = index % pow4;
            pow4 /= 4;
        }
        //fout << pow4cp << " p4\n";
        //fout << index << " ind\n";
        //fout << cnt << " cnt bf\n";
        if(index == 3){
            cnt += freqc[invert(resultc, inverted)];
            cnt += freqc[invert(resultc, !inverted)];
            cnt += freqc[invert(resultc, !inverted)];
        } else if (index == 2){
            cnt += freqc[invert(resultc, inverted)];
            cnt += freqc[invert(resultc, !inverted)];
        } else if (index == 1){
            cnt += freqc[invert(resultc, !inverted)];
        }
        for(int j = 0; j <= pos%N; j++){
            char localc = invert(str[j], inverted);
            if(localc == resultc){
                cnt++;
            } 
        }

        outp << resultc;

        if(!(i%N))
            outp << '\n';

    }outp << '\n';
    */
    for(int i = 1; i <= Q; i++){
        ll pos; inp >> pos;
        pos--;
        ll index = (pos)/N;
        ll cpindex = index;
        ll pow4 = 1;
        ll pow4cp = 0;
        while(pow4 <= index){
            pow4 *= 4;
        } pow4 /= 4;
        pow4cp = pow4;
        int inverted = 0;
        ll cnt = 0;
        while(index && pow4){
            if(index / pow4 == 1 || index / pow4 == 2){
                inverted = (inverted + 1) % 2;
            }
            index = index % pow4;
            pow4 /= 4;
        }
        char resultc = invert(str[pos%N], inverted);
        pow4 = pow4cp;
        index = cpindex;

        while(pow4 > 1){
            cnt += (freqc[resultc] + freqc[invert(resultc, 1)])*pow4/2*(index/pow4); 
            index = index % pow4;
            pow4 /= 4;
        }
        //fout << pow4cp << " p4\n";
        //fout << index << " ind\n";
        //fout << cnt << " cnt bf\n";
        if(index == 3){
            cnt += freqc[invert(resultc, inverted)];
            cnt += freqc[invert(resultc, !inverted)];
            cnt += freqc[invert(resultc, !inverted)];
        } else if (index == 2){
            cnt += freqc[invert(resultc, inverted)];
            cnt += freqc[invert(resultc, !inverted)];
        } else if (index == 1){
            cnt += freqc[invert(resultc, !inverted)];
        }
        
        char localc = invert(resultc, inverted);
        //if(localc == resultc){
            cnt+= untilsp[localc][pos%N];
        //} 
        

        outp << resultc << " " << cnt << '\n';

    }

    return 0;
}