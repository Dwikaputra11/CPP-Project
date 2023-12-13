#include <iostream>
#include <string>
using namespace std;

int n,q;
/* link: https://tlx.toki.id/courses/competitive/chapters/03/problems/C */

string findPhoneNumber(string person[][2],int l, int r,string name){
    
    if(r >= l){
        int mid = l + (r - l)/2;
        if(person[mid][0] == name){
            return person[mid][1];
        }else if(person[mid][0] < name){
            return findPhoneNumber(person,mid + 1, r, name);
        }else{
            return findPhoneNumber(person, l, mid - 1, name);
        }
    }

    return "NIHIL";
}

int main(int argc, char const *argv[])
{

    cin >> n >> q;
    string person[n][2];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin >> person[i][j];
        }
    }

    string s;
    while(q--){
        cin >> s;
        cout << findPhoneNumber(person,0,n - 1,s) << endl;
    }


    return 0;
}
