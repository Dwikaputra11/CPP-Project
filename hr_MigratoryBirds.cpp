#include <iostream>
using namespace std;

int main(){
    
    unsigned int num;
    cin >> num;
    unsigned int arr[num];
    unsigned int count[num] = {0};
    unsigned int max = 0;
    unsigned int temp;

    for(int i = 0; i<num; i++){
        cin >> arr[i];
        temp = arr[i];
        count[temp]++;
        if(max < arr[i]){
            max = arr[i];
        }
        cout << max << endl;
    }

    unsigned int countMax = 0;
    for(int i = 0; i < max; i++){
        if(countMax < count[i]){
            countMax = count[i];
        }
    }

    cout << countMax;


    
    return 0;
}