#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    float theta = 0;
    while (theta < 50)
    {
        cout << cos(theta) << endl;
        theta += 0.5;
    }
}