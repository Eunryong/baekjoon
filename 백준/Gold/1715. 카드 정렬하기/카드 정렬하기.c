#include<stdio.h>
#include<memory.h>
typedef struct {
    int heap[100001];
    int size;
}queue;

void push(queue *q, int num) {
    // q->size++;
    int i = ++q->size;
    while ((i > 1) && (num < q->heap[i / 2])) {
        q->heap[i] = q->heap[i / 2];
        i /= 2;
    }
    q->heap[i] = num;
}

int pop(queue *q) {
    if (q->size == 0) {
        return 0;
    }
    int ret = q->heap[1];
    int tmp = q->heap[q->size];
    q->size--;
    int parent = 1, child = 2;
    while (child <= q->size) {
        if (child < q->size && q->heap[child] > q->heap[child + 1]) {
            child++;
        }
        if (tmp <= q->heap[child]) break;
        q->heap[parent] = q->heap[child];
        parent = child;
        child = child * 2;
    }
    q->heap[parent] = tmp;
    return ret;
}



int main() {
    int n;
    queue q;
    q.size = 0;
    memset(&q.heap, 0, sizeof(q.heap));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(&q, x);
    }
    int ans = 0;
    // while (q.size) {
    //     printf("%d\n", pop(&q));
    // }
    while (q.size > 1) {
        int x = pop(&q);
        int y = pop(&q);
        ans += x + y;
        push(&q, x + y);
    }
    printf("%d",  ans);
    return 0;
}