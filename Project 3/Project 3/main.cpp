#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>

using namespace std;

#define N 3202

void heapify(double arr[], int n, int i, string strarr[])
{
    int max=i;
    int l=2*i+1;//left
    int r=2*i+2;//right

    if(l<n&&arr[l]>arr[max])
        max=l;

    if(r<n&&arr[r]>arr[max])
        max=r;

    if(max!=i)
    {
        swap(arr[i],arr[max]);
        swap(strarr[i], strarr[max]);
        heapify(arr,n,max,strarr);
    }
}
void heapSort(double arr[],int n, string strarr[])
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i,strarr);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        swap(strarr[0],strarr[i]);
        heapify(arr,i,0,strarr);
    }
}
int main()
{


	string str,close,line,tempstr;
	int i,j;
	double tempd;
	string sdate[N];
	double dclose[N];
	string sclose[N];
	for(i=1;i<=N;i++)
    {
        sdate[i] = "0";
        sclose[i] = "0";

    }

	ifstream file1;

	file1.open("ainv.us.txt");

	if (!file1.is_open())
    {
        cout <<"Cannot find file \nProgram will now exit\n";
        system("pause");
        exit(1);
    }

	if(file1.good())
	{

	        i = 1;
            j = 1;
            file1.ignore(256,'n');
            while(getline(file1,line))
            {
                getline(file1,str,',');
                sdate[i] = str;
                i++;
                getline(file1,close,',');
                getline(file1,close,',');
                getline(file1,close,',');
                sclose[j] = close;
                j++;

		    }

	}

	file1.close();

    for(i=1;i<N;i++)
    {
        tempstr = sclose[i];
        tempd = stod(tempstr);
        dclose[i] = tempd;
    }

    heapSort(dclose,N-1,sdate);

     cout << "\nSorted array after heap sort is \n";
    for (int i = 1; i < N; i++)
        cout << dclose[i] << "|" << sdate[i] << " \n";

    return 0;
}
