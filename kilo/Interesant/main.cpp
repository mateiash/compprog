#include <bits/stdc++.h>

using namespace std;

ifstream fin("interesant.in");
ofstream fout("interesant.out");

#define inp fin
#define outp fout

string genlen(int n){
    string s;
    for(int i = 0; i < n; i++){
        s.push_back('z');
    }
    return s;
}

int checker(string a, string b){
    auto it = a.begin();
    for(char c : b){
        char lasta = *(it);
        //cout << lasta << ' ' << c << '\n';
        if(c == lasta){
            it++;
        }
        if(it == a.end()){
            return 1;
        }
    }
    return 0;
}

struct epicstring{
    string s;
    int ind;
};

bool operator<(const epicstring& a, const epicstring& b){
    if(a.s.size() != b.s.size()) return a.s.size() < b.s.size();
    return a.s < b.s;
}

bool cmp(const epicstring& a, const epicstring& b){
    return a.ind < b.ind;
}

set<epicstring> cuvinte;
vector<epicstring> outputord;

int main()
{
    int C, N;
    inp >> C >> N;
    for(int i = 0; i < N; i++){
        string s;
        inp >> s;
        cuvinte.insert({s, i});
    }
    
    int maxlen = (*prev(cuvinte.end())).s.size();
    //cout << maxlen << '\n';
    
    if(C == 1){
        outp << (*cuvinte.upper_bound({genlen(maxlen-1)})).s << '\n';
        return 0;
    }

    auto it = cuvinte.upper_bound({genlen(maxlen - 1)});
    while(it != cuvinte.begin()){
        it = prev(it);
        //cout << (*it).s << '\n';
        string tocheck = (*it).s;
        auto startit = cuvinte.upper_bound({genlen(tocheck.size())});
        //cout << (*startit).s << '\n';
        while(startit != cuvinte.end()){
            string checkagainst = (*startit).s;
            if(checker(tocheck, checkagainst)){
                it = cuvinte.erase(it);
                //cout << tocheck << " erased!\n";
                break;
            }
            startit++;
        }
        
        //cout << '\n';
        
    }
    outp << cuvinte.size() << '\n';
    for(auto el : cuvinte){
        outputord.push_back(el);
    }
    sort(outputord.begin(), outputord.end(), cmp);
    for(auto el : outputord){
        outp << el.s << '\n';
    }
    
    return 0;
}