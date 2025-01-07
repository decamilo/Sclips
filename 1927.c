#include <stdio.h>
#include <stdlib.h>

struct heap {
    int arr[1000000];
    int size;
};

void Minheapify(struct heap* heap, int child, int parent);
void downheapify(struct heap* heap, int start);
void swap(int* a, int* b);

struct heap* Make_heap() {
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    h->size = 0;
    return h;
}

void Min_heap(struct heap* heap, int push) {
    heap->size++;
    heap->arr[heap->size] = push;

    int child = heap->size;
    int parent = child / 2;
    Minheapify(heap, child, parent);
}

int Pop(struct heap* heap) {
    if (heap->size == 0) {
        printf("0\n");
        return 0;
    } else {
        int popnum = heap->arr[1];
        printf("%d\n", popnum);
        int new = heap->arr[heap->size];
        heap->size--;
        heap->arr[1] = new;

        downheapify(heap, 1);

        return popnum;
    }
}

void Minheapify(struct heap* heap, int child, int parent) {
    while (parent) {
        if (heap->arr[child] < heap->arr[parent]) {
            swap(&heap->arr[child], &heap->arr[parent]); // 배열 값 교환
            child = parent;
            parent = child / 2;
        } else {
            break;
        }
    }
}

void downheapify(struct heap* heap, int start) {
    int left = 2 * start;

    while (left <= heap->size) {
        int right = left + 1;
        int smallerChild = left;

        if (right <= heap->size && heap->arr[right] < heap->arr[left]) {
            smallerChild = right;
        }

        if (heap->arr[start] <= heap->arr[smallerChild]) {
            break;
        }

        swap(&heap->arr[start], &heap->arr[smallerChild]);

        start = smallerChild;
        left = 2 * start;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num;
    scanf("%d", &num);

    struct heap* heap = Make_heap();

    for (int i = 0; i < num; i++) {
        int oper;
        scanf("%d", &oper);

        if (oper == 0) {
            Pop(heap);
        } else {
            Min_heap(heap, oper);
        }
    }

    free(heap); // 메모리 해제
    return 0;
}
