#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

unsigned char revertByte(unsigned char input) {
    unsigned char output = 0;

    int mask = 0;
    for(int i=0; i<8; i++) {
        mask = !!(input & (1<<i));
        if(mask == 1) output = output | (1 << (7-i));

        mask = 0;
    }

    return output;
}

template <class T>
T revT(T t)
{
    T tOut = 0;

    for(int i=0; i<sizeof(T)*8; i++)
    {
        if(t&(1<<i))
          tOut |= 1 << (sizeof(T)*8-1-i);
    }

    return tOut;
}

int main()
{
    unsigned char test = 0x81;
    unsigned char result = revT(test);
    //unsigned char result = revertByte(test);

    printf("result is 0x%x\n", result);
    //cout << result << endl;

    return 0;
}
