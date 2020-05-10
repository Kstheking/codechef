#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int activities, laddus = 0, info;
    string origin, activity;
    cin >> activities >> origin;
    while(activities--){
      cin >> activity;
      if(activity == "CONTEST_WON"){
        laddus += 300;
        cin >> info;
        if(info < 20) laddus += (20 - info);
      }
      else if(activity == "TOP_CONTRIBUTOR"){
        laddus += 300;
      }
      else if(activity == "BUG_FOUND"){
        cin >> info;
        laddus += info;
      }
      else if(activity == "CONTEST_HOSTED"){
        laddus += 50;
      }
    }
    if(origin == "INDIAN") cout << laddus/200 << "\n";
    else cout << laddus/400 << "\n";
  }
}
