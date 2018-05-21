#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* solve(int a_size, int* a, int sum){
    if(a_size==0){
        return "YES";
    }
    
    if(a_size==1){
        return "YES";
    }
    
    int lsum=a[0];
    int rsum=sum-a[0]-a[1];
    int i;
    
    for(i=2;i<a_size;i++)
    {
        if(lsum==rsum)
        {
            return "YES";
        }
        lsum+=a[i-1];
        rsum-=a[i];
    }
    return "NO";
}

int main() {
    int T; 
    scanf("%d", &T);
    for(int a0 = 0; a0 < T; a0++){
        int n; 
        scanf("%d", &n);
        int *a = malloc(sizeof(int) * n);
        int sum=0;
        for(int a_i = 0; a_i < n; a_i++){
        	scanf("%d",&a[a_i]);
            sum+=a[a_i];
        }
        int result_size;
        char* result = solve(n, a, sum);
        printf("%s\n", result);
    }
    return 0;
}
