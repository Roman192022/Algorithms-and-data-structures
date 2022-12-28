#include <iostream>

using namespace std;

struct TListItem{
    int value;
    TListItem *next, *prev;
};

struct TList{
    TListItem *first, *last;

};


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

    
    TListItem* start = list.first;
    TListItem* tmp = list.first;
    
    
    int min = start->value;
    tmp = tmp->next;

    while (tmp != start) {
        min = tmp->value < min ? tmp->value : min;
        tmp = tmp->next;
    }

    cout << "Minimum = " << min << endl;

    return 0;
}