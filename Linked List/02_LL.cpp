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

Node* convertArrayToLinkedList(vector<int>& arr) {
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* tail = head;

    for(int i=1; i<n; i++) {
        Node* temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    } 
    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* removeK(Node* head, int k) {
    if(head == NULL) return head;

    if(k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeElement(Node *head, int el)
{
    if (head == NULL)
        return head;

    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArrayToLinkedList(arr);
    printLL(head);
    cout << endl;
    head = removeK(head, 3); // remove 3rd element
    printLL(head);
    cout << endl;
    head = removeElement(head, 5); // remove  element 5 
    printLL(head);

    /******************* Performing deletion operation ************************ */
     
    return 0;
}