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

struct TListIterator{
    TListItem* pointer;
};

TListIterator initTListIterator(){
    TListIterator tmp;
    tmp.pointer = nullptr;
    return tmp;
}

int isValid(TListIterator it){
    return it.pointer != nullptr;
}

void moveNext(TListIterator &it){
    if(isValid(it)){
        it.pointer = it.pointer->next;
    }
    return;
}

void movePrev(TListIterator &it){
    if(isValid(it)){
        it.pointer = it.pointer->prev;
    }
    return;
}

int getValue(const TListIterator &it){
    if(isValid(it)){
        return it.pointer->value;
    }
    return 0;
}
void setValue(const TListIterator &it, int newValue){
    if(isValid(it)){
        it.pointer->value = newValue;
    }
    return;
}

TListIterator getBegin(TList l){
    TListIterator tmp;
    tmp.pointer = l.first;
    return tmp;
}

TListIterator getEnd(TList l){
    TListIterator tmp;
    tmp.pointer = l.last;
    return tmp;
}


void deleteListItem(TList &l, TListIterator &it){
    if(!isValid(it)){
        return;
    }
    if(it.pointer == l.first){
        l.first = it.pointer->next;
    }
    if(it.pointer == l.last){
        l.last = it.pointer->prev;
    }
    TListItem* next = it.pointer->next;
    TListItem* prev = it.pointer->prev;
    delete it.pointer;
    it.pointer = next;
    if (prev != nullptr)
    {
        prev->next = next;
    }
    if(next != nullptr){
        next->prev = prev;
    }
    if(l.first == nullptr){
        l.last = nullptr;
    }
    if (l.last == nullptr){
        l.first = nullptr;
    }
    return;

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
    TListIterator iter_1 = getBegin(list_1);
    while (isValid(iter_1) != 0) {
        tmp_1 = getValue(iter_1);
        bool isSame = false;
        TListIterator iter_2 = getBegin(list_2);
        while (isValid(iter_2) != 0){
            tmp_2 = getValue(iter_2);
            if (tmp_1 == tmp_2)
                isSame = true;

            moveNext(iter_2);
        }
        if (!isSame)
            addItem(list_3, tmp_1);

        moveNext(iter_1);
    }

    cout << "Items in list_1 that are not in list_2:" << endl;
    printList(list_3);

    return 0;
}