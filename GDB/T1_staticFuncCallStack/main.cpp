#include <iostream>

using namespace std;


static int fun1()
{
    int i = 10;
    cout << i << endl;

    return i;
}

int main()
{
    cout << "hello" << endl;

    fun1();
    cout << "end" << endl;
    return 0;
}
