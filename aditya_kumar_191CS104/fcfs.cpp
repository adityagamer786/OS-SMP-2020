#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

int main(){
  int n, i;
  cin >> n;
  vector<int> vat(n), vbt(n), ct(n), wt(n), tat(n); // ct : completion time
  for(i = 0; i < n; i++) cin >> vat[i];
  for(i = 0; i < n; i++) cin >> vbt[i];
  set<pair<int, int>> process;
  for(i = 0; i < n; i++){
    process.insert(mp(vat[i], vbt[i]));
  }
  int free_time = 0;
  i = 0;
  for(auto x: process){
    int at = x.first, bt = x.second;
    if(at >= free_time){
      wt[i] = 0;
      ct[i] = at+bt;
      tat[i] = bt;
    }
    else{
      wt[i] = free_time - at;
      ct[i] = free_time+bt;
      tat[i] = free_time+bt-at;
    }
    free_time = ct[i];
    i++;
  }
  // for(i = 0; i < n; i++) cout << ct[i] << " " << wt[i] << " " << tat[i] << endl;
  float avg_wt = 0, avg_tat = 0;
  for(int x: wt) avg_wt += x;
  avg_wt /= (float)n;
  for(int x: tat) avg_tat += x;
  avg_tat /= (float)n;
  cout << "avg waiting time: " << avg_wt << endl << "avg turn around time: " << avg_tat << endl;
}
