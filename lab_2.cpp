#include <iostream>
#include <math.h>

using namespace std;

struct Binary {
    bool value;
    Binary *next;
};


bool isEmpty(Binary *binary) {
    return binary == nullptr;
}

void push (Binary* &binary, bool value) {
    if (isEmpty(binary)) {
        binary = new Binary;
        binary->value = value;
        binary->next = nullptr;
    } else {
        Binary *current = binary;
        binary = new Binary;
        binary->value = value;
        binary->next = current;
    }
}
bool pop (Binary* &binary) {
    if (isEmpty(binary)) return false;

    Binary *current = binary;
    bool tmp = current->value;
    binary = binary->next;
    delete current;
    current = nullptr;
    return tmp;

}

int main()
{
    int n;
    cout << "Enter the amount of bool digits: ";
    cin >> n;

    Binary* bool_num = nullptr;

    int k;
    cout << "Enter your boolean number: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> k;
        push(bool_num, k);
    }

    int num = 0, pow_binary = 0;
    while (!isEmpty(bool_num)) {
        num += pop(bool_num) * pow(2, pow_binary);
        pow_binary++;
    }
    cout << "Your number = " << num;

    return 0;
}
