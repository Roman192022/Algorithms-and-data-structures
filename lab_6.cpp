#include <iostream>
#include <queue>

using namespace std;

struct Pair {
    int num;
    string str;
};

struct Node{
    Pair value;
    Node *left,*right;
};

void preorder(Node* root){
    if(root){
        cout << root->value.num << ": " << root->value.str << endl;
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void postorder(Node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout << root->value.num << ": " << root->value.str << endl;
    }
    return;
}

void inorder(Node* root){
    if(root){
        inorder(root->left);
        cout << root->value.num << ": " << root->value.str << endl;
        inorder(root->right);
    }
    return;
}

void addElement(Node* &root, Pair newValue){
    if(!root){
        root = new Node;
        root->value.num = newValue.num;
        root->value.str = newValue.str;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if(root->value.num > newValue.num)
        addElement(root->left, newValue);
    else
        addElement(root->right, newValue);
}

void printByLevels(Node* root){
    queue<Node*> queueOfLeafes;
    queueOfLeafes.push(root);
    while(queueOfLeafes.size() > 1){
        Node* leaf = queueOfLeafes.front();
        queueOfLeafes.pop();
        std::cout<<"Node value: "<<leaf->value.num << ": " << leaf->value.str<<std::endl;
        if(leaf->left)
            queueOfLeafes.push(leaf->left);
        if(leaf->right)
            queueOfLeafes.push(leaf->right);
    }
    return;
}

string getByNumber(Node* root, int value){
    if (root == nullptr) {
        return "";
    }

    if (value == root->value.num) {
        return root->value.str;
    } else if (value > root->value.num) {
        return getByNumber(root->right, value);
    } else {
        return getByNumber(root->left, value);
    }

}
int main()
{

    Node *root = nullptr;
    Pair pair;

    pair.num = 1;
    pair.str = "sun";
    addElement(root, pair);

    pair.num = 3;
    pair.str = "wind";
    addElement(root, pair);

    pair.num = 2;
    pair.str = "snow";
    addElement(root, pair);

    pair.num = 5;
    pair.str = "rain";
    addElement(root, pair);

    pair.num = 4;
    pair.str = "tree";
    addElement(root, pair);

    cout << "Words by numbers:" << endl;
    cout << getByNumber(root, 1) << endl;
    cout << getByNumber(root, 2) << endl;
    cout << getByNumber(root, 3) << endl;
    cout << getByNumber(root, 4) << endl;
    cout << getByNumber(root, 5) << endl;
    cout << getByNumber(root, 6) << endl;

    cout << "Preorder:\n";
    preorder(root);
    cout << "\n";
    cout << "Postorder:\n";
    postorder(root);
    cout << "\n";
    cout << "Inorder:\n";
    inorder(root);

    return 0;
}
