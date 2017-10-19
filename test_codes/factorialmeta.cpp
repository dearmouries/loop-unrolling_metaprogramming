#include <iostream>
using namespace std;
 
template<int n> 
struct fact
{
    //enum { val = 2*funStruct<n-1>::val };
    enum { val = n * fact<n-1>::val };
};
 

template<> 
struct fact<0>
{
    enum { val = 1 };
};

 
int main()
{
    //cout << funStruct<8>::val << endl;
    cout << fact<6>::val << endl;
    return 0;
}