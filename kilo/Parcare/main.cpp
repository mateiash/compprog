#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef pair<ll, ll> ip;

ifstream fin("parcare.in");
ofstream fout("parcare.out");

int main(){
	ll N, M, T;
	fin >> N >> M >> T;
	set<int> libere;
	
	for(int i = 1; i <= N; i++){
		libere.insert(i);
	}
	
	vector<ip> starts;
	vector<ip> ends;
	
	for(int i = 1; i <= M; i++){
		int s, p;
		fin >> s >> p;
		
		starts.push_back({s, i});
		ends.push_back({p, i});
	}
	
	sort(ends.begin(), ends.end());
	set<ip> ocupate;
	int ps = 0; int pp = 0;
	int t = 1;
	/*
	for(auto el : starts) {
		cout << el.first << ' ' << el.second << '\n';
	}
	cout << '\n';
	for(auto el : ends) {
		cout << el.first << ' ' << el.second << '\n';
	}
	*/
	vector<int> dropped(200'005);
	while(ps < starts.size() || pp < ends.size()){
		if(pp < ends.size() && ends[pp].first == t){ 
			int car = ends[pp].second;
			//cout << car << " leaving" << endl;
			if(dropped[car]) { pp++; goto fini; };
			auto it = ocupate.upper_bound({car, -1});
			ip op = *it;
			ocupate.erase(op);
			libere.insert(op.second);
			pp++;
			//cout << "left" << endl;
		}
		int car,spot;
		
		if(ps >= starts.size() || starts[ps].first != t) {goto fini;};

		car = starts[ps].second;
		//cout << car << " entering" << endl;
		
		if(ocupate.size() >= N){
			//cout << "nvm" << endl;
			fout << "-1\n";
			dropped[car] = 1;
			ps++;
			goto fini;
		}
		
		spot = *(libere.begin());
		fout << spot << '\n';
		ocupate.insert({car, spot});
		libere.erase(spot);
		ps++;
		fini:
		//cout << t << endl;
		//cout << ps << ' ' << pp << endl;
		if(t == T) break;
		t++;
	}
	vector<int> ans(N + 1);
	for(auto el : ocupate){
		ans[el.second] = starts[el.first - 1].first; 
	}
	for(int i = 1; i <= N; i++){
		if(ans[i] == 0) fout << "-1 ";
		else fout << ans[i] << ' ';
	}
	fout << '\n';
		
	
	return 0;
} 
