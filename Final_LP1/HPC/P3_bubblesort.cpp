#include<stdio.h>  
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <omp.h>
using namespace std;

int a[40001];
void sortArray(int [], int);
int q=0;

int main(int argc, char* argv[])
{   
int x=40000;
int values[40000];
for (int i=0;i<x;i++)
{
    values[i]=rand();
}
cout << "Sorting Array .......\n";
clock_t start = clock();
sortArray(values, x);
 cout << "The Array Now Sorted\n";
printf("Elapsed Time : %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
cout << "\n";
}
 void sortArray(int array[], int size)  
{
  bool swap;
   int temp;
  do
  {
   swap = false;
  for (int count = 0; count < (size - 1); count++)
   {
   if (array[count] > array[count + 1])
  {
    temp = array[count];
    array[count] = array[count + 1];
    array[count + 1] = temp;
    swap = true;
  }
  }
  }while (swap);
}

/*
prjlab@prjlab-HP-280-G3-MT:~$ g++ bbl.cpp
prjlab@prjlab-HP-280-G3-MT:~$ ./a.out
Sorting Array .......
The Array Now Sorted
Elapsed Time : 5.016772
*/
