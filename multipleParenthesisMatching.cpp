#include<iostream>
using namespace std;

struct DStack{
    char data;
    DStack* next = NULL;
};
DStack* top = NULL;

void push(char i);
char pop();
bool isEmpty();
bool parenthesisMatching();

int main(){
    cout<<"Is Parenthesis Matching: "<<parenthesisMatching;
}
bool parenthesisMatching(){
    char *exp;
    exp = "{([a+b]*[c-d])\e}";
    for(int i=0;i<exp[i]!='\0';i++){
        if(exp[i]=='(' ||exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        else if(exp[i]==')' || '}' || ']'){
            if(isEmpty()){
                return false;
            } else{
                int x;
                x = pop();
                if(x!=exp[i]){
                    return false;
                }
            }
        }
    }
    if(isEmpty()){
        return true;
    } else{
        return false;
    }
}
void push(char element){
    DStack *newNode = new DStack;
    cin>>newNode->data;
    if(newNode==NULL){
        cout<<"Stack Is Full (STACK-OVER-FLOW)";
    }
    if(top==NULL){
        top = newNode;
    }else{
        newNode->next = top;
        top = newNode;
    }
}
char pop(){
    char x = -1;
    DStack *p = top;
    if(top==NULL){
        cout<<"Stack Is Empty (STACK-UNDER-FLOW)";
    }else{
        x = top->data;
        top = top->next;
        delete p;
    }
    return x;

}
bool isEmpty() {
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}