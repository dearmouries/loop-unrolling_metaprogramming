#include<iostream>
using namespace std;
template<int n>
inline int power(const int x){
	return power<n-1>(x)*x;
}
template<>
inline int power<0>(const int x){
	return 1;
}
int main(int argc, char const *argv[])
{
	/* code */
	cout<<power<4>(3)<<"\n";
	return 0;
}