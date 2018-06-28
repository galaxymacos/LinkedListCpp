#include <iostream>
using namespace std;


class MyLinkedList {
public:
    class ListNode {
    public:
        int val;
        ListNode *next{};

        explicit ListNode(int val) : val(val) {}
    };
private:
    int length = 0;
    ListNode *head{};
    ListNode *tail{};
public:


    /** Initialize your data structure here. */
    MyLinkedList()=default;

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=length)
            return -1;
        ListNode *headCopy = head;
        while (index > 0) {
            index--;
            headCopy = headCopy->next;
            if(headCopy ==nullptr)
                return -1;
        }
        return headCopy->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto *newNode = new ListNode(val);
        length++;
        if(head == nullptr&&tail==nullptr){
            head = newNode;
            tail = newNode;

            return;
        }
        newNode->next = head;
        head = newNode;

    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto *newNode = new ListNode(val);
        length++;
        if(head == nullptr&&tail==nullptr){
            head = newNode;
            tail = newNode;

            return;
        }
        tail->next = newNode;
        tail = tail->next;

    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>length)
            return;
        ListNode *headCopy = head;
        if(index == 0)
            addAtHead(val);
        else if(index == length)
            addAtTail(val);
        else{

            while (index > 1) {
                headCopy = headCopy->next;
                index--;
                if(headCopy ==nullptr)
                    return;
            }
            ListNode *nextNode = headCopy->next;
            headCopy->next = new ListNode(val);
            headCopy->next->next = nextNode;
            length++;
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0||index>=length){
            return;
        }
        ListNode *headCopy = head;
        ListNode *nextNode = head->next;
        if(index == 0){
            head = head->next;
            length--;
            return;
        }
        else if(index == length-1){
            while(headCopy->next->next!=nullptr){
                headCopy = headCopy->next;
            }
            tail = headCopy;
            tail->next = nullptr;
            length --;
            return;
        }
        while (index > 1) {
            headCopy = headCopy->next;
            index--;
        }
        ListNode *nextNextNode = headCopy->next->next;
        headCopy->next = nextNextNode;
        length--;
    }

    void print(){
        auto* headCopy = head;
        while(headCopy!=nullptr){
            cout<<headCopy->val<<" ";
            headCopy = headCopy->next;
        }

        cout<<endl;
    }

    bool hasCycle(ListNode *head) {
        if(head== nullptr)
            return false;
        ListNode* quickPointer = head;
        ListNode* slowPointer = head;
        do{
            slowPointer=slowPointer->next;
            if(slowPointer== nullptr||quickPointer->next==nullptr||quickPointer->next->next== nullptr)
                return false;
            quickPointer=quickPointer->next->next;

        }while(slowPointer!=quickPointer);
        return true;
    }
};

int main(){


}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
