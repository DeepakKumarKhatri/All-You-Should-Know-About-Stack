#include<iostream>
//Include stack header in file
#include<stack>
using namespace std;

int main(){
    //Creating Stack in STL
    stack<int> s;
    //Push Method (Insert In Stack From The Top Only)
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    //Will yield the total size of Stack
    cout<<s.size()<<endl;//5
    //Will yield the top most element of Stack
    cout<<s.top()<<endl;//5
    //Will tell stack is empty or not?
    cout<<s.empty()<<endl;//false
    //Will delete the top most element of Stack
    s.pop();//5 gone
    s.pop();//4 gone
    cout<<s.size()<<endl;//Now the size is 3
}
