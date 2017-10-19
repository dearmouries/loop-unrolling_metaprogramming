#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


template <int N>
struct TMP_COPY_UNROLL {

	static void iteration(int *f, int* t){
		*t++=*f++;
		TMP_COPY_UNROLL<N-1>::iteration(f, t);
	}
};


template <>
struct TMP_COPY_UNROLL<0> {
	static void iteration(int* f, int* t){
		
	}
};


template<int N>
static void Copy(int n, int* from, int* to){

	for (int i = 0; i < n/N; ++i) {
		TMP_COPY_UNROLL<N>::iteration(from+i * N, to+i * N);
	}
	from+=N*(n/N);to+=N*(n/N);
	for (int i = 0; i < n%N; ++i) {
		*to++ = *from++;
		
	}
}


int main(int argc, char const *argv[])
{

	int a[100];int b[100];
	int *ptr1=a;
	int *ptr2=b;
	for(int i=0;i<100;i++){
		a[i]=i;
	}
	//cout<<endl;
	clock_t tStart1 = clock();
	Copy<10>(100,ptr1,ptr2);
	clock_t tStop1 = clock();
	double time1 = (tStop1-tStart1)/double(CLOCKS_PER_SEC)*1000;
	cout << "time1: " << (tStop1-tStart1)/double(CLOCKS_PER_SEC)*1000 << endl;
	//cout<<time1<<endl;

	clock_t tStart2 = clock();
	Copy<10>(100,ptr1,ptr2);
	clock_t tStop2 = clock();
	cout << "time2: " << (tStop2-tStart2)/double(CLOCKS_PER_SEC)*1000 << endl;
	double time2 = (tStop2-tStart2)/double(CLOCKS_PER_SEC)*1000;

	clock_t tStart3 = clock();
	Copy<10>(100,ptr1,ptr2);
	clock_t tStop3 = clock();
	cout << "time3: " << (tStop3-tStart3)/double(CLOCKS_PER_SEC)*1000 << endl;
	double time3 = (tStop3-tStart3)/double(CLOCKS_PER_SEC)*1000;

	clock_t tStart4 = clock();
	Copy<10>(100,ptr1,ptr2);
	clock_t tStop4 = clock();
	cout << "time4: " << (tStop4-tStart4)/double(CLOCKS_PER_SEC)*1000 << endl;
	double time4 = (tStop4-tStart4)/double(CLOCKS_PER_SEC)*1000;

	clock_t tStart5 = clock();
	Copy<10>(100,ptr1,ptr2);
	clock_t tStop5 = clock();
	cout << "time5: " << (tStop5-tStart5)/double(CLOCKS_PER_SEC)*1000 << endl;
	double time5 = (tStop5-tStart5)/double(CLOCKS_PER_SEC)*1000;


	// for(int i=0;i<100;i++){
	// 	cout<<b[i]<<" ";
	// }
	FILE *fptr;
   fptr = fopen("output.csv","a");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   
   fprintf(fptr,"%d",10);
   fprintf(fptr,",");
   fprintf(fptr,"%lf",time1);
   fprintf(fptr,",");
   fprintf(fptr,"%lf",time2);
   fprintf(fptr,",");
   fprintf(fptr,"%lf",time3);
   fprintf(fptr,",");
   fprintf(fptr,"%lf",time4);
   fprintf(fptr,",");
   fprintf(fptr,"%lf",time5);
   fprintf(fptr,"\n");
   fclose(fptr);
	return 0;
}