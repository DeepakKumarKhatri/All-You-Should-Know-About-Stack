#include<iostream>
using namespace std;

struct Stack{
    int data;
    struct Stack* next;
};
Stack* top = NULL;

void push(int element);
int pop();
void mainMenu();
int peek(int position);
bool isEmpty();
bool isFull();
int stackTop();

int main(){
    mainMenu();
}
void mainMenu(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"0 - Exit \n";
    cout<<"1 - Push \n";
    cout<<"2 - Pop \n";
    cout<<"3 - Peek \n";
    cout<<"4 - Stack Top \n";
    cout<<"5 - Stack Is Empty? \n";
    cout<<"6 - Stack Is Full? \n";

    cout<<"Enter Your Option: ";
    int option;
    cin>>option;

    switch(option){
        case 0:
            break;
        case 1:
            cout<<"Enter A Element to Push: ";
            int element;
            cin>>element;
            push(element);
            break;
        case 2:
            cout<<"The Element Poped Is: "<<pop();
            mainMenu();
            break;
        case 3:
            cout<<"Enter Position to View At: ";
            int position;
            cin>>position;
            cout<<"The Element Is: "<<peek(position);
            mainMenu();
            break;
        case 4:
            cout<<"Stack Top: "<<stackTop();
            mainMenu();
            break;
        case 5:
            cout<<"Stack Is Empty: : "<<isEmpty();
            mainMenu();
            break;
        case 6:
            cout<<"Stack Is Full: "<<isFull();
            mainMenu();
            break;
        default:
            cout<<"*** Invalid Option ***\n";
            cout<<"*** Enter Again ***\n";
            mainMenu();
    }
}
void push(int element){
    Stack *newNode = new Stack;
    if(newNode==NULL){
        cout<<"Stack Is Full (STACK-OVER-FLOW)";
    }else {
        newNode->data = element;
        newNode->next = top;
        top = newNode;
    }
    mainMenu();
}
int pop(){
    int x = -1;
    Stack *p = top;
    if(top==NULL){
        cout<<"Stack Is Empty (STACK-UNDER-FLOW)";
    }else{
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}
int peek(int position){
    if(top==NULL){
        cout<<"Stack Is Empty (STACK-UNDER-FLOW)";
    }else{
        Stack *p = top;
        for(int i=0;p!=NULL && i<position-1;i++){
            p = p->next;
        }
        if(p!=NULL){
            return p->data;
        }else{
            return -1;
        }
    }
    mainMenu();
}
bool isEmpty(){
    if(top==NULL){
        return true;
    }else{
        return false;
    }
}
bool isFull(){
    //when p is not created then stack is full
    Stack *p = new Stack;
    if(p==NULL){
        return true;
    }else{
        return false;
    }
}
int stackTop(){
    if(top==NULL){
        return -1;
    }else{
        return top->data;
    }
}
