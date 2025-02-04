#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

/******************** Insertion in node ********************** */


Node *convertArrayToLinkedList(vector<int> &arr)
{
    int n = arr.size();
    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* insertElementAtStart(Node* head, int val) {
    return new Node(val, head);
}


Node* insertAtTail(Node* head, int val) {
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    Node* newNode = new Node(val);
    temp->next = newNode;
    temp = newNode;
    return head;
} 

Node* insertAtPosition(Node* head, int el, int k) {
    if(head == NULL) {
        if(k==1) {
            return new Node(el);
        }
        else {
            return head;
        }
    }
    if(k==1) {
        Node* newNode = new Node(el);
        newNode->next = head;
        return newNode;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!= NULL) {
        cnt++;
        if(cnt == k-1) {
            Node* x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    } 
    return head;
} 

int main() {
    vector<int> arr = {12, 22, 59};
    Node *head = convertArrayToLinkedList(arr);
    printLL(head);
    // head = insertElementAtStart(head, 11);
    cout << '\n';
    // head = new Node(1, head);
    // printLL(head);

    cout << "\n";
    cout << "insert at tail->\n";
    head = insertAtTail(head, 999);
    printLL(head);

    cout << endl;
    head = insertAtPosition(head, 0, 3);
    printLL(head);

    return 0;
}