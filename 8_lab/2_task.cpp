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


void displayArr(){
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " , ";
    }
    cout << endl;
}

void changeArray(){
    for (int i = 0; i < arrSize; i++)
    {
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
    cout << "Before changing array of a2\n";
    a1.displayArr();
    a2.displayArr();
    
    a2.changeArray();
    
    cout << "After changing array of a2\n";
    a2.displayArr();
    a1.displayArr();

    //Output in case of Custom copy constructor DEEP COPY:
    // Before changing array of a2 1, 2, 3, 4, 5,
    // 1, 2, 3, 4, 5,
    // After changing array of a2 10, 10, 10, 10, 10,
    // 1, 2, 3, 4, 5,

    // Output in case of Default copy constructor SHALLOW COPY:
    // Before changing array of a2
    //  1 , 2 , 3 , 4 , 5 ,
    //  1 , 2 , 3 , 4 , 5 ,
    //  After changing array of a2
    //  10 , 10 , 10 , 10 , 10 ,
    //  10 , 10 , 10 , 10 , 10 ,
    return 0;
}