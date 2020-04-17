#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    long int k, f, s, sum, d, val;
    cin >> k >> f >> s;
    sum = (f+s);
    d = sum % 10;
    k -= 2;
    if(k > 0){
      sum += d;
      k--; //k constraints
    }
    d *= 2;
    d %= 10;
    if(d != 0){
      val = k / 4;
      val *= 2;
      val %= 3;
      sum += val;
    }

    k %= 4;
    d *= 16;
    d %= 10;
    //
    while(k--){
      sum += d;
      d = (2*d)%10;
    }
    if(sum%3 == 0) cout << "YES\n";
    else cout << "NO\n";
  }
}
