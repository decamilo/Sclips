#include <stdio.h>
#include <math.h>

int N,r,c;
int findNum(int,int,int);

int main(){
    scanf("%d %d %d", &N, &r, &c);
    
    int result = findNum(N, r, c);
    printf("%d", result);
}

int findNum(int N, int r, int c){
    int mid = pow(2, N-1);
    if(N==0){
        return 0;
    }

    else if(r<=mid && c<=mid){
        return findNum(N-1, r, c);
    }

    else if(r<=mid && c>mid){
        return mid*mid + findNum(N-1, r, c-mid);
    }

    else if(r>mid && c<=mid){
        return mid*mid*2 + findNum(N-1, r-mid, c);
    }

    else{
        return mid*mid*3 + findNum(N-1, r-mid, c-mid);
    }
}