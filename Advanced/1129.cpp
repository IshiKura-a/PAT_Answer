#include <iostream>

#define MAXN 50005

class Product {
public:
    int index = 0;
    int count = 1;
    Product *prev = nullptr;
    Product *next = nullptr;

    Product(int index) : index(index) {}

    bool operator>(const Product &b) const {
        return count > b.count ||
               (count == b.count && index < b.index);
    }
};

class List {
public:
    Product *head = nullptr, *tail = nullptr;
    int size = 0;
    int maxCount = 0;

    void push_back(Product *p) {
        if (size++) {
            tail->next = p;
            p->prev = tail;
            tail = p;
        } else {
            head = tail = p;
        }
    }

    void eraseAndInsert(Product *addr, Product *p) {
        // erase
        auto prev = p->prev;
        auto next = p->next;
        if (prev) prev->next = next;
        else head = next;
        if (next) next->prev = prev;
        else tail = prev;

        // insert
        prev = addr->prev;
        if (prev) prev->next = p;
        else head = p;
        p->prev = prev;
        addr->prev = p;
        p->next = addr;
    }
};

Product *productMap[MAXN];
Product *fastPrev[MAXN];

int N, K;
List product = List();

void sort(Product * p);

int main() {
    std::cin >> N >> K;
    int p;
    int i, j;
    Product* prev = nullptr, *it;
    for (i = 0; i < N; i++) {
        scanf("%d", &p);
        if (i > 0) {
            sort(prev);
            printf("%d:", p);
            it = product.head;
            for (j = 0; j < product.size && j < K; j++, it = it->next) {
                printf(" %d", it->index);
            }
            printf("\n");
        }
        auto q = productMap[p];
        if (q) {
            if(fastPrev[q->count] == q) {
                if(!q->next || q->count != q->next->count) {
                    fastPrev[q->count - 1] = nullptr;
                } else {
                    fastPrev[q->count - 1] = q->next;
                }
                q->count++;
                if(product.maxCount < q->count) product.maxCount = q->count;
                if(!fastPrev[q->count - 1] || *q > *fastPrev[q->count - 1]) {
                    fastPrev[q->count - 1] = q;
                }
            }
            productMap[p]->count++;
        } else {
            q = new Product(p);
            productMap[p] = q;
            product.push_back(q);
        }
        prev = productMap[p];
    }

    return 0;
}

void sort(Product* p) {
    auto item = p;
    auto itY = p->prev;
    while (itY && (*item) > (*itY)) {
        int i = itY->count;
        while(!fastPrev[i] && i < product.maxCount) i++;
        itY = fastPrev[i];
    }

    while(!itY || (*itY > *item)) {
        itY = itY ? itY->next : product.head;
    }
    if (p != itY) {
        product.eraseAndInsert(itY, item);
    }
}