#include <stdio.h>

long long int count(int S[], int n, int target)
{
    long T[target+1];
 
    for (long i = 0; i <= target; i++) {
        T[i] = 0;
    }
 
    T[0] = 1;
 
    for (long i = 0; i < n; i++)
    {
        for (int j = S[i]; j <= target; j++) {
            T[j] += T[j - S[i]];
            printf("%d", T[j] + "\n");
        }
    }
 
    return T[target];
}
 
int main()
{
    int S[] = { 1, 5, 10, 25, 50 };
    int n = sizeof(S) / sizeof(S[0]);
 
    int target;
    while(cin >> target){
        cout << count(S,n,target);
    }

 
    return 0;
}