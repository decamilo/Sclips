#include <stdio.h>
#include <stdlib.h>

struct Pair
{
    int first;
    int second;
};

int compare(const void* first, const void* second){
    struct Pair p1 = *(struct Pair*)first;
    struct Pair p2 = *(struct Pair*)second;

    if(p1.second>p2.second){
        return 1;
    }
    else if(p1.second == p2.second){
        if(p1.first>p2.first){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }

}// 1은 a,b 순서바꿈, 0은 값이 같아서 유지, -1 유지

int main(){
    int num;
    scanf("%d", &num);

    struct Pair arr[100010];

    for(int i =0; i<num; i++){
        int first, second;
        scanf("%d %d", &first, &second);
        arr[i].first = first;
        arr[i].second = second;
    }

    qsort(arr, num, sizeof(arr[0]), compare);

    int count =1;
    int index =0;

    for(int i =1; i<num; i++){
        if(arr[i].first>=arr[index].second){
            index = i;
            count++;
        }
    }

    printf("%d", count);
}
/* 종료시간을 오름 차순으로 정렬. 만약에 종료시간이 같으면 시작 시간을 오름 차순으로 정리.
처음에 종료시간으로 정리하면 제일 먼저 끝나는애로 시작해서 그다음에도 제일 먼저 끝나는애가 오게됨.
결국 최적의 해를 구할 수 있음 */