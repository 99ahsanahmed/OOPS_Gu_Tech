#include<iostream>
using namespace std;
class ArrayHolder{
int* arr;
int arrSize;
public:
ArrayHolder(int arrSize){
    this->arrSize = arrSize;
    arr = new int [arrSize];

    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = i+1;
    }
}

// ArrayHolder(const ArrayHolder &original){
//     arrSize = original.arrSize;
//     arr = new int [arrSize];
//     for (int i = 0; i < arrSize; i++)
//     {
//         arr[i] = original.arr[i];
//     }
// }

// void arrFull(){
//     for (int i = 0; i < arrSize; i++)
//     {
//         arr[i] = i;
//     }
// }
void displayArr(){
    
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void changeArray(){
    for (int i = 0; i < arrSize; i++)
    {
        // arr[i] = 100;
        arr[i] = 10;
    }
    
}

~ArrayHolder(){
    delete[] arr;
    arr = NULL;
}

};

int main()
{
    ArrayHolder a1(5);
    ArrayHolder a2 = a1;
    // ArrayHolder a2(5);// = a1;
   a1.displayArr();
    // a2.arrFull();
    a2.displayArr();
    a2.changeArray();
    a2.displayArr();
   a1.displayArr();
    return 0;
}