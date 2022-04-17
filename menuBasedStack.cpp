#include<iostream>
using namespace std;

struct Stack{
    //Size of stack
    int size;
    //Top most pointer which will initially be -1
    int top = -1;
    //An array which will have same size as stack
    int *stackArray;
};
void push(Stack *st,int x);
int pop(Stack *st);
int peek(Stack st,int position);
int stackTop(Stack st);
bool isEmpty(Stack st);
bool isFull(Stack st);
bool Palindrome(Stack st);

struct Stack st;
void mainMenu(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"0 - Exit \n";
    cout<<"1 - Push \n";
    cout<<"2 - Pop \n";
    cout<<"3 - Peek \n";
    cout<<"4 - Stack Top \n";
    cout<<"5 - Stack Is Empty? \n";
    cout<<"6 - Stack Is Full? \n";
    cout<<"7 - Palindrome \n";

    cout<<"Enter Your Option: ";
    int option;
    cin>>option;

    switch(option){
        case 0:
            break;
        case 1:
            st.stackArray = new int[st.size];
            cout << "Enter Element to Pass: ";
            int x;
            cin >> x;
            push(&st, x);
            mainMenu();
            break;
        case 2:
            cout<<"The Element Deleted Is: "<<pop(&st);
            mainMenu();
            break;
        case 3:
            cout<<"Enter Position to View At: ";
            int position;
            cin>>position;
            cout<<"The Element at "<<position<<" Is: "<<peek(st,position);
            mainMenu();
            break;
        case 4:
            cout<<"The Element at Stack Top: "<<stackTop(st);
            mainMenu();
            break;
        case 5:
            if(isEmpty(st)) {
                cout << "Stack Is Empty?: " << "true";
            } else{
                cout << "Stack Is Empty?: " << "false";
            }
            mainMenu();
            break;
        case 6:
            if(isFull(st)) {
                cout << "Stack Is Full?: " << "true";
            } else{
                cout << "Stack Is Full?: " << "false";
            }
            mainMenu();
            break;
        case 7:
            if(Palindrome(st)){
                cout << "Stack Is Palindrome: " << "true";
            } else{
                cout << "Stack Is Palindrome: " << "false";}
            mainMenu();
            break;
        default:
            cout<<"*** Invalid Option ***\n";
            cout<<"*** Enter Again ***\n";
            mainMenu();
    }
}
int main(){
    cout<<"Enter Stack Size: ";
    cin>>st.size;
    mainMenu();
}

void push(Stack *st,int x){
    if(st->top==st->size-1){
        cout<<"Stack Is Full (STACK-OVER-FLOW)";
    }
    else{
        st->top++;
        st->stackArray[st->top] = x;
    }
}
int pop(Stack *st){
    int x = -1;
    if(st->top==-1){
        cout<<"Stack Is Empty (STACK-UNDER-FLOW)";
    }
    else{
        x = st->stackArray[st->top];
        st->top--;
    }
    return x;
}

int peek(Stack st,int position){
    int x = -1;
    if(st.top-position+1<0){
        cout<<"\n\n<<<<<<<<<<<<<< INVALID POSITION >>>>>>>>>>>>>>>\n\n";
    }else{
        x = st.stackArray[(st.top - position) + 1];
        return x;
    }
}
int stackTop(Stack st){
    if(st.top==-1){
        cout<<"Stack Is Empty (STACK-UNDER-FLOW)";
    } else{
        return st.stackArray[st.top];
    }
}
bool isEmpty(Stack st){
    if(st.top==-1){
        return true;
    } else{
        return false;
    }
}
bool isFull(Stack st){
    if(st.top==st.size-1){
        return true;
    } else{
        return false;
    }
}
bool Palindrome(Stack st){
    if(isEmpty(st)){
        cout<<"Stack Is Empty (STACK-UNDER-FLOW)";
    }
    else {
        int j = st.size-1;
        for (int i = 0; i < st.size; i++) {
            if(st.stackArray[i] != st.stackArray[j]){
                return false;
            } else{
                j--;
            }
        }
    }
    return true;
}
