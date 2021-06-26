// Assigning n tasks to n people in most optimal way
// output is the minimum cost of entire problem
#include <bits/stdc++.h>
using namespace std;
int no_of_bits(int num) //number of set bits
{
  int count = 0;
  while (num)
  {
    count += num & 1;
    num = num >> 1;
  }
  return count;
}

int check_bit_set(int num, int bit)
{
  /*
    Ex: 
    num = 7 -> 111
    bit = 2 => 2nd bit (we have to consider from 0)
    x = 100
    num & x = 100 i.e. not zero
  */
  int x = 1 << bit;
  return (num & x);
}

int bit_set(int num, int bit)
{
  /* 
    ex:
    num = 4 -> 100
    bit = 1 => set first bit
    x = 010
    num | x = 110
  */
  int x = 1 << bit;
  return (num | x);
}

int bit_unset(int num, int bit)
{
  /*
    ex:
    num = 7 -> 111
    bit = 1 => unset first bit
    x = 010
    ~x = 101
    num & (~x) = 111 & 101 = 101
  */
  int x = 1 << bit;
  return (num & (~x));
}

int assignment_problem()
{
  int n;
  /*
      j-------> job cost
    x 3 2 7 
    | 5 1 3
    | 2 7 2
    x is the persons
  */
  cout << "enter the dimension of matrix : ";
  cin >> n;
  cout << "enter matrix values: " << endl;
  int m[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> m[i][j];

  int len = pow(2, n);
  int dp[len];
  dp[0] = 0;
  for (int i = 1; i < len; i++)
    dp[i] = INT_MAX;

  for (int i = 0; i < len; i++)
  {
    cout << "mask number: " << i << endl;
    int x = no_of_bits(i);
    cout << "\tnumber of set bits: " << x << endl;
    //i = mask
    //x = number of set bits in the current mask
    for (int j = 0; j < n; j++)
    {
      //if the jth bit is set then skip
      if (check_bit_set(i, j))
        continue;
      else
      {
        int z = bit_set(i, j); // mask OR 1 << j
        dp[z] = min(dp[z], (dp[i] + m[x][j]));
      }
    }
  }
  return dp[len - 1];
}

int main()
{
  int x = 7, y = 4, z = 2;
  int a = 0;
  // cout << bit_unset(7, 1);
  cout << assignment_problem();
  return 0;
}
