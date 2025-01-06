#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char result[1000000][21];
char check[1000000][21];

int compare(const void *a, const void *b) {
    const char *str1 = (const char *)a;
    const char *str2 = (const char *)b;
    return strcmp(str1, str2);
}//qsort에서 compare는 위와 같은 파라미터를 가져야하고 우린 이걸 char 로 바꿔야함.

int main(){
    int a,b;

    scanf("%d %d", &a, &b);
    for(int i =0; i<a+b; i++){
        scanf("%s", result[i]);
    }

    int index = 0;
    qsort(result, a+b, sizeof(result[0]), compare);//둘다 합쳐서 quick sort로 정렬함(result[0]을 넣는 이유는 한 요소의 바이트 단위를 찾으려고)
    for(int i =0; i<a+b-1; i++){
        if(strcmp(result[i], result[i+1])==0){
            strcpy(check[index++], result[i]);
        }
    }
    
    printf("%d\n", index);
    
    for(int i =0; i<index; i++){
        printf("%s\n", check[i]);
    }

    /**int index =0;
    for(int i =0; i<a; i++){
        for(int j =0; j<b; j++){
            if(strcmp(hear[i], see[j])==0){
                strcpy(result[index++], hear[i]);
            }
        }
    }

    qsort(result, index, sizeof(result[0]), compare);

    printf("%d\n", index);
    
    for(int i =0; i<index; i++){
        printf("%s\n", result[i]);
    }**/
}
/*  이 좆같은 시간초과를 어떻게 해결할지 생각하기가 어려움
    비교할떄 이중 for 문을 사용하면 시간이 개오래걸림
    그래서 이용한 방법이 애초에 두 그룹을 한번에 어레이에 넣고 정렬함
    그러면 O(n)임
    같은 단어는 연속적으로 나올것이니 ...
    그렇게 하면 빠르게 체크가능
*/