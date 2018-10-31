#include<iostream>
#include<omp.h>
#include<cstdlib>
using namespace std;
#define MAX 10

int main()
{
	int a[MAX][MAX],b[MAX],c[MAX],i,j,k;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			a[i][j]=rand()%1000;
		}
	}
	cout<<"Matrix elements are:\n";
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			cout<<a[i][j];
			cout<<"\t";
		}
		cout<<"\n";
	}
	
	for(i=0;i<MAX;i++)
	{
		b[i]=rand()%1000;
	}
	cout<<"Vector elements are :\n";
	for(i=0;i<MAX;i++)
	{
		cout<<b[i];
		cout<<"\t";
	}

	cout<<"Resultant vector is :\n";
	#pragma omp parallel for
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			c[i]=a[i][j]+b[j];
		}
		
	}
	for(i=0;i<MAX;i++)
	{
		cout<<c[i];
		cout<<"\n";	
	}
}

/*output:
prjlab@prjlab-HP-Pro-3330-MT:~$ g++ prog1.cpp -fopenmp
prjlab@prjlab-HP-Pro-3330-MT:~$ ./a.out
Matrix elements are:
383	886	777	915	793	335	386	492	649	421	
362	27	690	59	763	926	540	426	172	736	
211	368	567	429	782	530	862	123	67	135	
929	802	22	58	69	167	393	456	11	42	
229	373	421	919	784	537	198	324	315	370	
413	526	91	980	956	873	862	170	996	281	
305	925	84	327	336	505	846	729	313	857	
124	895	582	545	814	367	434	364	43	750	
87	808	276	178	788	584	403	651	754	399	
932	60	676	368	739	12	226	586	94	539	
Vector elements are :
795	570	434	378	467	601	97	902	317	492	
Resultant vector is :
913
1228
627
534
862
773
1349
1242
891
1031
*/
