#include <iostream>

using namespace std;

struct TListItem{
    int value;
    TListItem *next, *prev;
};

struct TList{
    TListItem *first, *last;

};

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

TList initList(){
    TList l;
    l.first = nullptr;
    l.last = nullptr;
    return l;
}

void addListItem(TList &list, int value){
    if(list.first == nullptr){
        list.first = new TListItem;
        list.first->value = value;
        list.first->next = list.last;
        list.last = list.first;
        list.first->prev = list.last;
    }else{
        TListItem* newItem = new TListItem;
        newItem->value = value;
        newItem->next = list.first;
        newItem->prev = list.last;
        list.last->next = newItem;
        list.last = list.last->next;
        list.first->prev = list.last;
    }

}

void destroyList(TList &list){
    TListItem* itemToDelete = list.first;
    TListItem* tmp;
    do{
        tmp = itemToDelete->next;
        delete itemToDelete;
        itemToDelete = tmp;
    }while(itemToDelete != list.first);

    list.first = nullptr;
    list.last = nullptr;
}

void printList(TList list){
    TListItem* tmp = list.first;
    do {
        cout<<" "<< tmp->value;
        tmp = tmp->next;
    } while (list.first != tmp);

    cout<<endl;
}



int main()
{
    TList list = initList();

    addListItem(list, 13);
    addListItem(list, 300);
    addListItem(list, -20);
    addListItem(list, 9);
    addListItem(list, -4);

    cout << "Your list: ";
    printList(list);

    TListIterator it = getBegin(list);
    TListIterator start = getBegin(list);

    int min = getValue(it);
    moveNext(it);

    while (it.pointer != start.pointer) {
        min = getValue(it) < min ? getValue(it) : min;
        moveNext(it);
    }

    cout << "Minimum = " << min << endl;

    return 0;
