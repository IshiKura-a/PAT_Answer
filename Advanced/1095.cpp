#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>

using namespace std;
#define MAXK 80005
#define MAXN 10005

typedef struct node1 {
    int h, m, s;
} TIME;
typedef struct node2 {
    char plate[10];
    TIME t;
    int tag;
} rec;
typedef struct node3 {
    int duration;
    char plate[10];
} car;

int n, k;
int MaxDuration = 0;
rec record[MAXK];
int mBegin[MAXN];
int mEnd[MAXN];
car stay[MAXN];

int Time_To_Index(TIME p);

int cmp(const void *x, const void *y);

int cmpp(const void *x, const void *y);

int main() {
    scanf("%d%d\n", &n, &k);
    memset(record, 0, sizeof(record));
    memset(mBegin, 0, sizeof(mBegin));
    memset(mEnd, 0, sizeof(mEnd));
    memset(stay, 0, sizeof(stay));
    int i;
    TIME p;
    char status[10];
    for (i = 1; i <= n; i++) {
        scanf("%s", record[i].plate);
        scanf("%d:%d:%d", &p.h, &p.m, &p.s);
        scanf("%s", status);
        record[i].t = p;
        record[i].tag = status[0] == 'i';
    }
    qsort(record + 1, n, sizeof(rec), cmp);

    int index = 0;
    rec cur;
    memset(cur.plate, 0, sizeof(cur.plate));
    cur.tag = 0;
    for (i = 1; i <= n; i++) {
        if (strcmp(cur.plate, record[i].plate)) {
            strcpy(cur.plate, record[i].plate);
            if (record[i].tag) {
                cur.tag = 1;
                cur.t = record[i].t;
            } else cur.tag = 0;
        } else {
            if (cur.tag && !record[i].tag) {
                int p = Time_To_Index(cur.t),
                        q = Time_To_Index(record[i].t);
                mBegin[++mBegin[0]] = p;
                mEnd[++mEnd[0]] = q;
                if (strcmp(stay[index].plate, record[i].plate)) {
                    index++;
                    strcpy(stay[index].plate, record[i].plate);
                }
                stay[index].duration += q - p;
                if (MaxDuration < stay[index].duration)
                    MaxDuration = stay[index].duration;
                cur.tag = 0;
            } else {
                cur.t = record[i].t;
                cur.tag = record[i].tag;
            }
        }
    }
    qsort(mBegin + 1, mBegin[0], sizeof(int), cmpp);
    qsort(mEnd + 1, mEnd[0], sizeof(int), cmpp);
    for (i = 1; i <= k; i++) {
        scanf("%d:%d:%d", &p.h, &p.m, &p.s);
        int target = Time_To_Index(p);
        int low = upper_bound(mBegin + 1, mBegin + mBegin[0] + 1, target) - mBegin,
                high = upper_bound(mEnd + 1, mEnd + mEnd[0] + 1, target) - mEnd;

        printf("%d\n", low - high);
    }
    for (i = 1; i <= n; i++) {
        if (stay[i].duration == MaxDuration)
            printf("%s ", stay[i].plate);
    }
    printf("%02d:%02d:%02d", MaxDuration / 3600, MaxDuration % 3600 / 60, MaxDuration % 3600 % 60);
    return 0;
}

int Time_To_Index(TIME p) {
    int res;
    res = p.h * 60 * 60 + p.m * 60 + p.s;
    return res;
}

int cmp(const void *x, const void *y) {
    rec *p = (rec *) x,
            *q = (rec *) y;
    if (strcmp(p->plate, q->plate)) return strcmp(p->plate, q->plate);
    else if ((p->t).h - (q->t).h) return (p->t).h - (q->t).h;
    else if ((p->t).m - (q->t).m) return (p->t).m - (q->t).m;
    else return (p->t).s - (q->t).s;
}

int cmpp(const void *x, const void *y) {
    return *(int *) x - *(int *) y;
}