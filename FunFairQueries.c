#include<stdio.h>

const int k = 25;
const int N = 1000000;
const int ZERO = 1e6 + 1; 

int table[1000000][26]; 
int Arr[1000000];

int main()
{ 
    int n, L, R, q, i, j;
    scanf("%d",&n); 
    scanf("%d",&q);
    
    for(int i = 0; i < n; i++)
        scanf("%d",&Arr[i]); 

    for(i = 0; i < n; i++)
        table[i][0] = Arr[i];
    for(j = 1; j <= k; j++) {
        for(int i = 0; i <= n - (1 << j); i++)
        {
            if(table[i][j - 1]<table[i + (1 << (j - 1))][j - 1])
            {
                table[i][j] = table[i][j - 1];
            }
            else
            {
                table[i][j] = table[i + (1 << (j - 1))][j - 1];
            }
        }
           
    }

    
    for(i = 0; i < q; i++) {
        scanf("%d%d",&L,&R);
        int answer = ZERO;
        for(int j = k; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                if(answer>table[L][j])
                {
                    answer = table[L][j];
                }
                
                L += 1 << j; 
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}