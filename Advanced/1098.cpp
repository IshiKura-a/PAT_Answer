#include<stdio.h>
#include<string.h>

#define MAXN 105
int n;
int ins[MAXN];
int heap[MAXN];
int prog[MAXN];

void buildheap();

void swap(int i, int j);

int check(int a[]);

int main() {
    int i, j;
    int en1 = 1, en2 = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &ins[i]);
        heap[i] = ins[i];
    }
    for (i = 1; i <= n; i++) scanf("%d", &prog[i]);
    buildheap();
    for (i = 1; i <= n; i++) {
        if (en2) {
            ins[0] = ins[i + 1];
            int index;
            index = 1;
            while (ins[index] <= ins[0] && index < i + 1) index++;
            j = i + 1;
            while (j > index) {
                ins[j] = ins[j - 1];
                j--;
            }
            ins[j] = ins[0];
        }
        if (en1) {
            swap(1, n - i + 1);
            int index = 1;
            while (index * 2 <= n - i) {
                j = index * 2;
                if (j + 1 <= n - i && heap[j] < heap[j + 1]) j++;
                if (heap[index] < heap[j])
                    swap(index, j);
                else break;
                index = j;
            }
        }
        if (en1 ^ en2) {
            printf("%s Sort\n", en2 ? "Insertion" : "Heap");
            for (j = 1; j <= n; j++) {
                printf("%d", en2 ? ins[j] : heap[j]);
                printf("%c", j == n ? '\n' : ' ');
            }
            break;
        }
        en1 = check(ins);
        en2 = check(heap);
    }
    return 0;
}

void swap(int i, int j) {
    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

void buildheap() {
    int i;
    for (i = n / 2; i > 0; i--) {
        int index = i * 2;
        if (index + 1 <= n && heap[index] < heap[index + 1]) index++;
        if (heap[i] < heap[index]) {
            swap(i, index);
            while (2 * index <= n) {
                int j = index * 2;
                if (j + 1 <= n && heap[j] < heap[j + 1]) j++;
                if (heap[index] < heap[j])
                    swap(index, j);
                else break;
                index = j;
            }
        }
    }
}

int check(int a[]) {
    int i;
    for (i = 1; i <= n; i++) {
        if (prog[i] != a[i]) return 1;
    }
    return 0;
}