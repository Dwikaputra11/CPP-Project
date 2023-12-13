#include <iostream>

using namespace std;

unsigned long long int coinchange(int * coins, int numOfCoins, int targetAmount) {
  int dp[targetAmount + 1];
   for (long i = 0; i <= targetAmount; i++) {
        dp[i] = 0;
    }

  dp[0] = 1;

  for (int i = 0; i < numOfCoins; i++) {
    for (int j = coins[i]; j <= targetAmount; j++) {
        dp[j] += dp[j - coins[i]];
    }
  }

  return dp[targetAmount];

}
int main() {
    int numofcoins = 5;
  int coins[5] = {1, 5, 10, 25, 50};

  int targetAmount;

    while(cin >> targetAmount){
        cout << coinchange(coins, numofcoins, targetAmount) << endl;
    }

  return 0;
}