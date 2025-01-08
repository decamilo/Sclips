#include <stdio.h>
#include <stdlib.h>

int arr[128][128];
int zero = 0;
int one = 0;
int findZero(int,int,int);

void divide(int x, int y, int size){
    if(findZero(x,y,size)==0){
        one++;
    }
    else if(findZero(x,y,size)== size*size){
        zero++;
    }
    else{
        divide(x,y,size/2);
        divide(x,y+size/2,size/2);
        divide(x+size/2,y,size/2);
        divide(x+size/2,y+size/2,size/2);
    }
}

int findZero(int x, int y, int size){
    int count =0;

    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(arr[i][j]==0){
                count++;
            }
        }
    }
    return count;
}


int main(){
    int num;
    scanf("%d", &num);

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    divide(0,0,num);
    printf("%d\n%d\n", zero, one);
}

/* 얘는 정사각형에서 계속 쪼개서 생각해야하는 문제였음.
당연히 recursive를 사용해야했고, 결국 merge sort처럼 계속 쪼개고 합쳐야하는 상황.
그렇기에 divide and conquer를 이용했어야함.
그래서 나도 여기서 결국 4분면으로 나눠서 divide 하고 각각의 one과 zero를 check해서 더하는 식으로 푼 것.
*/