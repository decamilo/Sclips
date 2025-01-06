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
//우리는 z형태를 어떻게 인식하느냐가 중요함. 이를 4분면에 놓고 생각한거임.
//2,3,4사분면에 있는 애들을 모두 1사분면로 이동시켜서 생각함.
//이를 recursive function으로 표현
//그렇기에 2사분면일 경우에는 이전에 거쳐온 1사분면의 mid*mid를 더해주는 것.
//3,4사분면도 동일함. 각각 2사분면까지 지나왔기에 2*mid*mid를 더해줌.
//조건에 N이 15이하이므로 우리가 2차원 array를 만들기 어려움.
//그래서 recursive로 생각했어야함.