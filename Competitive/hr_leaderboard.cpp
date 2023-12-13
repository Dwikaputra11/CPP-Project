
#include <iostream>
#include <algorithm>

using namespace std;

int comp (int a, int b){
    if(a < b) return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    int begin[n];
    int count[n] = {0};
    int a = 0,temp;
    for(int i = 0; i < n; i++){
        cin >> begin[i];
    }
    
    int m;
    cin >> m;
    int input[n];
    for(int i = 0; i < m; i++){
        cin >> input[i];
    }
    a = begin[0];
    count[0] = begin[0];
    int* max = max_element(begin,begin+n,comp);
    int* min = min_element(begin,begin+n,comp);
    cout << *max << " " <<*min << endl;
    int itr = 1;
    for(int i = 1; i < n; i++){
        if(a != begin[i]){
            a = begin[i];
            count[itr] = begin[i];
            ++itr; 
        }
    }
    cout << "Count\n";
     for(int i = 0; i < n; i++){
        cout << count[i] << endl;
    }
    int y = 0;
    int standing[m];
    int limit = n + 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(input[i] < *min){
               standing[i] = ++limit;
               *min = input[i];
               // y = j; 
               break;
            } else if(input[i] > *max){
                standing[i] = 1;
                *max = input[i];
            }
            else if(input[i] == count[j]){
              standing[i] = j + 1;
               // y = j;
              break;  
            } 
            else if(input[i] < count[j] && input[i] > count[j + 1]){
              standing[i] = j + 2;
               // y = j;
              break;
            }
        }
    }

    cout << "Standing\n";
    for(int i = 0; i < m; i++){
        cout << standing[i] << endl;
    }
    
}