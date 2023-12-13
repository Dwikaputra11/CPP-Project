#include <iostream>
using namespace std;

int main() {
int T, N, M;
string ans;

cin >> T;
while(T--){
    cin >> N >> M;
    int x1[N], x2[N], x3[N], temp;
    cin >> ans;
    string id[N];
    
      for (int i=0; i<N; i++){
        cin >> id[i] >> x1[i] >> x2[i] >> x3[i];  	
        if(id[i] == ans){
          temp = i;
      }
    }
    cout << endl;
    int c=0;
    for(int i=0; i<N; i++){
      if(x3[temp] < x3[i]) c++;
      else if(x3[temp] == x3[i] && x2[temp] < x2[i]) c++;
      else if(x3[temp] == x3[i] && x2[temp] == x2[i] && x1[temp] < x1[i]) c++;
    }

    if(c < M){
			cout << "YA" << endl;
		}
    else{
			cout << "TIDAK" << endl;
		}
  }
	return 0;	
}