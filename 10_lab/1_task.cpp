#include<iostream>
using namespace std;
template<typename T>
T calculate(T a,T b,char op){
    if(op=='+'){
        return a+b;
    }
    else if(op=='-'){
        return a-b;
    }
    else if(op=='*'){
        return a*b;
    }
    else if(op=='/'){
        return a/b;
    }
    else{
        cout<<"Invalid operator";
    }
}

int main(){
    int a,b;
    char op;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"Enter the operator: ";
    cin>>op;
    cout<<calculate<int>(a,b,op);
}