//sort stack using temp stack by Aryan Singhania
#include <iostream>
using namespace std;

#define EMP -9182

struct node {
     int data;
     struct node *next;
};

class myStack {

private:
     struct node *head;

public:
     myStack() {
          head = NULL;
     }

     bool isEmpty() {
          if (head == NULL) {
               return true;
          }
          return false;
     }

     void push(int elem) {

          struct node *temp = new node;
          temp->data = elem;

          temp->next = head;
          head = temp;

     }

     int top() {
          if (isEmpty()) {
               cout<<"Stack is empty"<<endl;
               return EMP;
          }
          return head->data;
     }


     int pop() {

          if (isEmpty()) {
               cout<<"Stack is empty"<<endl;
               return EMP;
          }

          struct node *temp = head;
          int data = temp->data;
          head = head->next;

          delete temp;
          return data;
     }

     void printStack() {

          struct node *temp = head;

          while (temp != NULL) {
               cout<<temp->data<<" ";
               temp = temp->next;
          }
          cout<<endl;

     }

     ~myStack() {
          while (!isEmpty()) {
               pop();
          }
     }
};

myStack mySort(myStack& toSort) {

     myStack tempStack;
     int curr = 0;

     while (!toSort.isEmpty()) {
          curr = toSort.pop();

          while (!tempStack.isEmpty() && tempStack.top() < curr) {
               toSort.push(tempStack.pop());
          }

          tempStack.push(curr);
     }

     return tempStack;
}



int main() {

     myStack s;
     int n, temp;

     cout<<"Enter number of elements in stack: ";
     cin>>n;
     cout<<endl;

     cout<<"Enter elements of stack: ";
     for (int i = 0; i < n; i++) {
          cin>>temp;
          s.push(temp);
     }

     myStack sorted = mySort(s);

     cout<<"Sorted Stack:"<<endl;
     sorted.printStack();

}
