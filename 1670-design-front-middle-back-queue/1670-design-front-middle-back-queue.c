#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} FrontMiddleBackQueue;

FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue *obj = (FrontMiddleBackQueue *)malloc(sizeof(FrontMiddleBackQueue));
    obj->capacity = 2005;
    obj->arr = (int *)malloc(sizeof(int) * obj->capacity);
    obj->size = 0;
    return obj;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {
    for (int i = obj->size; i > 0; i--)
        obj->arr[i] = obj->arr[i - 1];

    obj->arr[0] = val;
    obj->size++;
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {
    int mid = obj->size / 2;

    for (int i = obj->size; i > mid; i--)
        obj->arr[i] = obj->arr[i - 1];

    obj->arr[mid] = val;
    obj->size++;
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
    obj->arr[obj->size++] = val;
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if (obj->size == 0)
        return -1;

    int ans = obj->arr[0];

    for (int i = 0; i < obj->size - 1; i++)
        obj->arr[i] = obj->arr[i + 1];

    obj->size--;

    return ans;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if (obj->size == 0)
        return -1;

    int mid = (obj->size - 1) / 2;
    int ans = obj->arr[mid];

    for (int i = mid; i < obj->size - 1; i++)
        obj->arr[i] = obj->arr[i + 1];

    obj->size--;

    return ans;
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
    if (obj->size == 0)
        return -1;

    return obj->arr[--obj->size];
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your FrontMiddleBackQueue struct will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = frontMiddleBackQueueCreate();
 * frontMiddleBackQueuePushFront(obj, val);
 * frontMiddleBackQueuePushMiddle(obj, val);
 * frontMiddleBackQueuePushBack(obj, val);
 * int param_4 = frontMiddleBackQueuePopFront(obj);
 * int param_5 = frontMiddleBackQueuePopMiddle(obj);
 * int param_6 = frontMiddleBackQueuePopBack(obj);
 * frontMiddleBackQueueFree(obj);
 */