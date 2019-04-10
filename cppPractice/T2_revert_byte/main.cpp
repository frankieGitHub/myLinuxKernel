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

void test()
{
    int A[10] = {0};

    A[11] = 0;
}


void revint8(unsigned char input)
{
    unsigned char output = 0;

    printf("input is: %x\n", input);
    for(int i=0; i<8; i++)
    {
        if(input & (1<<i))
        {
            cout << "find bit 1, i=" << i << endl;
            output |= (1<<(7-i));
        }
    }
    printf("onput is: %x\n", output);
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
    cout << (1 << 0) << endl;
    /*
    unsigned char test = 58;
    unsigned char result = revertByte(test);

    printf("result is %d\n", result);
    cout << result << endl;
*/
    //int i = 4/2*3;
    //cout << i << endl;
    //test();
    //
    unsigned char in = 0x53;
    revint8(in);

    revT(in);

    unsigned int in2 = 0x8A;
    revT(in2);

    return 0;
}
