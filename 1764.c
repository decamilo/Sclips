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
    qsort(result, a+b, sizeof(result[0]), compare);//둘다 합쳐서 quick sort로 정렬함
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