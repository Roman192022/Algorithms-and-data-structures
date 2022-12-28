#include <iostream>

using namespace std;

struct TListItem {
    int value;
    TListItem *prev, *next;
};

struct TList {
    TListItem *first, *last;
};

TList init() {
    TList lis;
    lis.first = nullptr;
    lis.last = nullptr;
    return lis;
}

void addItem(TList &lis, int val) {
    if (lis.first == nullptr) {
        lis.first = new TListItem;
        lis.first->value = val;
        lis.first->next = nullptr;
        lis.last = lis.first;
    } else {
        TListItem *newItem = new TListItem;
        newItem->value = val;
        newItem->next = nullptr;
        newItem->prev = lis.last;
        lis.last->next = newItem;
        lis.last = lis.last->next;
    }
}

/*int popItem(TList &lis) {
    if (lis.first == nullptr) return 0;
    int num;
    num = lis.first->value;
    lis.first = lis.first->next;
    lis.first->prev = nullptr;
    return num;
}*/

void printList(TList tList) {
    TListItem *tmp = tList.first;
    while (tmp != nullptr) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
}


int main()
{

    TList list_1, list_2;
    list_1 = init();
    list_2 = init();

    int n, m;
    cout << "Enter the amount of numbers in list_1: ";
    cin >> n;
    cout << "Enter the amount of numbers in list_2: ";
    cin >> m;

    int k;
    cout << "Enter the numbers of list_1:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> k;
        addItem(list_1, k);
    }

    cout << "Enter the numbers of list_2:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> k;
        addItem(list_2, k);
    }


    TList list_3;
    list_3 = init();

    int tmp_1, tmp_2;
    TListItem* ptr = list_1.first;
    while (ptr != nullptr) {
        tmp_1 = ptr->value;
        bool isSame=false;
        TListItem* ptr2 = list_2.first;
        while (ptr2 != nullptr){
            tmp_2 = ptr2->value;
            if (tmp_1 == tmp_2)
                isSame=true;

            ptr2 = ptr2->next;
        }
        if (!isSame)
            addItem(list_3, tmp_1);

        ptr = ptr->next;
    }

    cout << "Items in list_1 that are not in list_2:" << endl;
    printList(list_3);

    return 0;
}
