/*
  A child is running up a set of stairs with n steps and can hop either 1 steps, or 2 steps, or 3 steps, at a time.
  Implement a method to count how many possible ways the child can run up the stairs.
*/

#include <iostream>
#include <map>

//basic way O(3^n)

int countWays(int n ){
  if(n < 0){
    return 0;
  }else if(n == 0){
    return 1;
  }else{
    return countWays(n - 1) + countWays(n -2) + countWays(n - 3);
  }
}

// dynamic programming

int countWays2(int n, int memo[]){
  if(n < 0)
    return 0;
  else if (n == 0){
    return 1;
  }else if(memo[n] > -1){
    return memo[n];
  }else{
    memo[n] = countWays2(n -1, memo) + countWays2(n -2, memo) +
      countWays2(n -3, memo);
    return memo[n];
  }
}

int countWays2(int n){
  int memo[n +1];
  for(int i = 0; i < n+1; i++)
    memo[i] = -1;
  return countWays2(n,memo);
}

int main(){
  int ways = countWays2(20);
  std::cout << ways << std::endl;
  return 0;
}
