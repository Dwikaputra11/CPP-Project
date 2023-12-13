#include  <bits/stdc++.h>
using namespace std;

vector<string> duplicate;

bool isExist(string s){
    for(int i = 0; i < duplicate.size(); i++){
        if(s == duplicate[i]) return false;
    }
    return true;
}

void findDuplicate(string sub, string str){
    int d = 1;
    for(int i = 0; i < str.length(); i++){
        string s = str.substr(i, i + 2);
        if(s == sub) d++;
    }
    if(d >= 2) {
        if(duplicate.size() == 0) duplicate.push_back(sub);
        else{
            if(!isExist(sub)){
                cout << sub << " " << d << endl;
            } 
        }
    }
}

void ans(string s){
    for(int j = 0; j < s.length();j++){
        for(int i = j + 2; i < s.length()/2; i++){
            findDuplicate(s.substr(j,i),s);
        }
    }
}

int main(){
    string s;
    cin >> s;
    ans(s);
}
