#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArrayToLinkedList(int *arr, int size) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<size; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

int lengthOfLinkedList(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void searchKeyInLL(Node* head, int key) {
    Node *temp = head;
    while (temp)
    {
        if(key == temp->data) {
            cout << "True, Key is present\n";
            return;
        }
        temp = temp->next;
    }
    cout << "No, Given key is not present\n";
}

Node* removeHead(Node* head) {
    // suppose the head which we have to provide in function is already pointing to head
    if(head == NULL) {
        return head;
    }

    Node* temp = head;
    head = head->next;
    delete(temp);
    return head;
}

void printLL(Node* head) {
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void removeLastNode(Node* head) {
    if(head->next == nullptr || head == NULL) return delete(head);

    Node* tail = head;
    while(tail->next->next != NULL) {
        tail = tail->next;  
    }
    cout << "deleting last node element of head-> " << tail->next->data << '\n'; 
    free(tail->next);
    tail->next = nullptr;
}

int main() {
    int arr[] = {91, 42, 23, 24, 50, 60};
    int size = sizeof(arr)/sizeof(arr[0]);
    // cout << size << endl;

    Node* head = convertArrayToLinkedList(arr, size);
    // cout << head->data << endl; 
    // cout << head->next->data << endl;

    /************** traversal in linked list **************/
    Node* temp = head;
    while(temp) {
        cout << temp-> data << " ";
        temp = temp->next; 
    }
    cout << endl;

    /************** length in linked list **************/
    int lengthofLinkedList = lengthOfLinkedList(head);
    cout << "length of LisnkedList -> " << lengthofLinkedList << endl;

    /************** Search element in linked list **************/
    searchKeyInLL(head, 24);

    /************** remove head from linked list **************/
    Node* newhead = removeHead(head);
    cout << newhead->data << endl;
    printLL(newhead);

    cout << '\n';

    /************** remove last node from linked list **************/
    removeLastNode(head);
    printLL(head);

    return 0;
}