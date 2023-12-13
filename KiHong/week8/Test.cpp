#include <iostream>
#include <stddef.h>
#include <stdlib.h>
using namespace std;
struct MyStruct1 {
    char c;
    int i;
    double d = 0;
};
struct MyStruct2 {
    MyStruct1 st;
    double d = 0;
};
typedef struct MyStruct3 {
    int i = 0;
    int k = 0;
    short s = 0;
    double d = 0;
} Struct3;
#pragma pack(push,1)
class MyClassE {
public:
    int i = 0;
    char c = 'a';
    short s = 0;
    short s2 = 0;
    double d = 0;
    void Printing() {
        int printThis = 3;
        cout << printThis << endl;
    }
};
#pragma pack(pop)
class MyClass {
public:
    int i1 = 0;
    char c[9];
    int i2 = 0;
};
class MyClass2 {
public:
    MyClass mc;
    long long ll = 0;
};
class MyClass3 {
public:
    int i = 0;
    char c = 'a';
    short s = 0;
    double d = 0;
};
int main(void) {
    bool list[1000000] = {false,};
    cout << "Size of bool sizeof : "<< sizeof(list) << endl;
    cout << "Size of bool alignof : "<< alignof(list) << endl;

    // MyStruct1 ms1;
    // MyStruct2 ms2;
    // Struct3 ms3;
    //cout << "ms1 : " << sizeof(ms1) << endl;
    //cout << "ms2 : " << sizeof(ms2) << endl;
    //cout << "ms3 : "<< sizeof(ms3) << endl;
    
    // MyClass3 mc3;
    // cout << "MyClass3 Size : "<< sizeof(mc3) << endl;
    
    // cout << endl;
    
    // cout << "Size of int : "<< sizeof(mc3.i) << endl;
    // cout << "Size of Char : "<< sizeof(mc3.c) << endl;
    // cout << "Size of Short : "<< sizeof(mc3.s) << endl;
    // cout << "Size of Double : "<< sizeof(mc3.d) << endl;
    
    // cout << endl;

    // cout << "Offset of int : "<< offsetof(MyClass3, i) << endl;
    // cout << "Offset of Char : "<< offsetof(MyClass3, c) << endl;
    // cout << "Offset of Short : "<< offsetof(MyClass3, s) << endl;
    // cout << "Offset of Double : "<< offsetof(MyClass3, d) << endl;
    
    // MyClassE mce;
    // cout << "MyClassE Size : "<< sizeof(mce) << endl;
    
    // cout << endl;
    
    // cout << "Size of int : "<< sizeof(mce.i) << endl;
    // cout << "Size of Char : "<< sizeof(mce.c) << endl;
    // cout << "Size of Short : "<< sizeof(mce.s) << endl;
    // cout << "Size of Short2 : "<< sizeof(mce.s2) << endl;
    // cout << "Size of Double : "<< sizeof(mce.d) << endl;
    
    // cout << endl;

    // cout << "Offset of int : "<< offsetof(MyClassE, i) << endl;
    // cout << "Offset of Char : "<< offsetof(MyClassE, c) << endl;
    // cout << "Offset of Short : "<< offsetof(MyClassE, s) << endl;
    // cout << "Offset of Short2 : "<< offsetof(MyClassE, s2) << endl;
    // cout << "Offset of Double : "<< offsetof(MyClassE, d) << endl;
    
    // cout << endl;

    // MyClass mc;
    // cout << "MyClass Size : "<< sizeof(mc) << endl;
    // cout << "Size of i1 : "<< sizeof(mc.i1) << endl;
    // cout << "Size of Char : "<< sizeof(mc.c) << endl;
    // cout << "Size of i2 : "<< sizeof(mc.i2) << endl;
    // cout << "Offset of i1 : "<< offsetof(MyClass, i1) << endl;
    // cout << "Offset of Char : "<< offsetof(MyClass, c) << endl;
    // cout << "Offset of i2 : "<< offsetof(MyClass, i2) << endl;
    
    // cout << endl;

    // MyClass2 mc2;
    // cout << "MyClass2 Size : "<< sizeof(mc2) << endl;
    // cout << "Size of MyClass : "<< sizeof(mc2.mc) << endl;
    // cout << "Size of ll : "<< sizeof(mc2.ll) << endl;
    // cout << "Offset of MyClass : "<< offsetof(MyClass2, mc) << endl;
    // cout << "Offset of ll : "<< offsetof(MyClass2, ll) << endl;
    return 0;
}