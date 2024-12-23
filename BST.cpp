#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data=x;
        left=right=nullptr;
    }
};

void insert(int data, Node *&head){
    if(head==nullptr){
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while(1){
        if(temp->data < data){
            if(temp->right==nullptr){
                temp->right = new Node(data);
                return;
            }
            temp = temp->right;
        }
        else{
            if(temp->left==nullptr){
                temp->left = new Node(data);
                return;
            }
            temp = temp->left;
        }
    }

}

void traverse(Node *head){
    if(head==nullptr){
        return;
    }
    traverse(head->left);
    cout<<head->data<<" ";
    traverse(head->right);
}
void BST(){
    Node *head = nullptr;
    insert(10,head);
    insert(20,head);
    insert(5,head);
    insert(15,head);
    insert(30,head);
    insert(25,head);
    insert(35,head);
    traverse(head);
}

int main(){
    Node *head = nullptr;
    BST();
    return 0;
}