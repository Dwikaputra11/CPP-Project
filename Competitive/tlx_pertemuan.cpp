#include <iostream>
#include <cstring>
using namespace std;

string name[501];
int n;

bool comp(string a, string b, int l){
    char car_a[l + 1], car_b[l + 1];
    strcpy(car_a,a.c_str());
    strcpy(car_b,b.c_str());
    for(int i = 0; i < l; i++){
        bool isSame = car_a[i] == car_b[i];
        if(isSame){
            if((i + 1) < l && car_a[i + 1] > car_b[i + 1]) return true;
        }
    }
    if(car_a[0] > car_b[0]) return true;
    else return false;
}

void sort(){
    for(int interval =n/2; interval > 0; interval/=2){
        cout << "Interval: " << interval << endl;
        for(int i = interval; i < n ; i++){
            string temp = name[i];
            int j;
            for(j = i; j >= interval && name[j - interval].length() >= temp.length(); j-= interval){
                if(name[j - interval].length() == temp.length()){
                    if(comp(name[j - interval], temp, temp.length())) name[j] = name[j - interval];
                }else{
                    name[j] = name[j - interval];
                }
            }
            name[j] = temp;
            for(int i = 0; i < n; i++)
                cout << name[i] << " - ";
            cout << "\n";
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << name[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name[i];
    }

    sort();
    
    return 0;
}
