/*
ID: david25
LANG: C++14
TASK: beads
*/
#include <bits/stdc++.h>

#define inp fin
#define outp fout

using namespace std;

ifstream fin("beads.in");
ofstream fout("beads.out");

typedef pair<int, char> seg;
vector<seg> segments;

int main(){
    int N;
    inp >> N;

    string s;
    inp >> s;

    int startind = 0;
    int flag = 0;
    
    for(int i = 0; i < N; i++){
        if(s[i] != s[(N + i - 1) % N]){
            startind = i;
            flag = 1;
            break;
        }
    }
    if(!flag){
        outp<<N << '\n';
        return 0;
    }

    int len = 0;
    for(int i = 0; i < N; i++) {
        int pos = (startind + i) % N;
        int nextpos = (N + pos + 1) % N;

        if(s[pos] != s[nextpos]){
            segments.push_back({len+1, s[pos]});
            len = 0;
        } else {
            len++;
        }


    }
    /*
    for(auto el : segments){
        outp << el.first << ' ' << el.second << '\n';
    }
    */
    int rez = 0;
    for(int i = 0; i < segments.size(); i++){
        char c;
        int point;
        int len = 0;
        point = (segments.size() + i) % segments.size();
        c = segments[point].second;
        int lastchecked;
        while((segments[point].second == c || segments[point].second == 'w') || c == 'w'){
            len += segments[point].first;
            if(c == 'w'){
                c=segments[point].second;
            }
            lastchecked = point;
            point = (segments.size() + point - 1) % segments.size();
        }

        point = (segments.size() + i + 1) % segments.size();
        c = segments[point].second;
        while((segments[point].second == c || segments[point].second == 'w') || c == 'w'){
            if(lastchecked == point){
                break;
            }
            len += segments[point].first;
            if(c == 'w'){
                c=segments[point].second;
            }
            point = (segments.size() + point + 1) % segments.size();
        }
        rez = max(rez, len);
    }

    outp << rez << '\n';

    return 0;
}