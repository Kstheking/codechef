#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T, N, H, Y1, Y2, L, sol, t, x, f;
	vector <int> ans;
	cin << T;
	while(T > 0){
	    cin << N << H << Y1 << Y2 << L;
	    sol = 0;
	    f = 0;
	    while(N > 0){
	        cin << t << x;
	        if(f) continue;
	        if(t == 1){
	            if(h-Y1 <= x){
	                sol += 1;
	            }
	            else{
	                if(L > 1){
	                    L--;
	                    sol += 1;
	                }
	                else{
	                    f = 1;
	                }
	            }
	        }
	        if(t == 2){
	            if(h+Y2 >= x){
	                sol += 1;
	            }
	            else{
	                if(L > 1){
	                    L--;
	                    sol += 1;
	                }
	                else{
	                    f = 1;
	                }
	            }
	        }
	        N--;
	    }
	    ans.push_back(sol);
	    T--;
	}

	return 0;
}
