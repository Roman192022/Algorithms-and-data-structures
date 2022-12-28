#include <iostream>

using namespace std;

struct Queue_el {
    int value;
    Queue_el *next;
};

struct Queue {
    Queue_el *head;
    Queue_el *tail;
};

Queue init() {
    Queue q;
    q.head = nullptr;
    q.tail = nullptr;
    return q;
}

bool isEmpty(Queue &q) {
    return q.head == nullptr;
}


void enQueue(Queue &q, int value) {
    if (isEmpty(q)) {
        q.head = new Queue_el;
        q.head->value = value;
        q.head->next = nullptr;
        q.tail = q.head;
    } else {
        q.tail->next = new Queue_el;
        q.tail->next->value = value;
        q.tail->next->next = nullptr;
        q.tail = q.tail->next;
    }
}

int deQueue(Queue &q) {
    if (isEmpty(q)) return false;

    int result = q.head->value;
    Queue_el *item = q.head;
    q.head = q.head->next;
    delete item;
    if (q.head == nullptr) q.tail = q.head;
    return result;
}


void printQueue(Queue q)
{
    Queue_el *curr = q.head;
    while (curr != nullptr)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }

    cout << endl;
}


int main()
{
    Queue q;
    q = init();

    int n;
    cout << "Enter the amount of numbers in your queue: ";
    cin >> n;

    cout << "Enter your queue:" << endl;
    int el;
    for (int i = 0; i < n; i++) {
        cin >> el;
        enQueue(q, el);
    }

    Queue q_sort;
    q_sort = init();

    int minim, tmp;
    for (int i = 0; i < n; i++) {
        minim = deQueue(q);
        for (int j = i + 1; j < n; j++) {
           tmp = deQueue(q);
           if (tmp < minim) {
              enQueue(q, minim);
              minim = tmp;
           } else {
              enQueue(q, tmp);
           }
        }
        enQueue(q_sort, minim);
    }

    cout << endl << "Sorted queue: ";
    printQueue(q_sort);

    return 0;
}
