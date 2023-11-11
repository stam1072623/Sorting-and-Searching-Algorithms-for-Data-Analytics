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
void merge(double arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    double L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(double arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int main()
{


	string str1,open1,line,str2,open2,str3,open3,tempstr;
	int i,j;
	double tempd1;
	string sdate1[N];
	double dopen1[N];
	string sopen1[N];
	double tempd2;
	string sdate2[N];
	double dopen2[N];
	string sopen2[N];
	double tempd3;
	string sdate3[N];
	double dopen3[N];
	string sopen3[N];
	for(i=1;i<=N;i++)
    {
        sdate1[i] = "0";
        sopen1[i] = "0";
        sdate2[i] = "0";
        sopen2[i] = "0";
        sdate3[i] = "0";
        sopen3[i] = "0";
    }

	ifstream file1;
	ifstream file2;
	ifstream file3;

	file1.open("ainv.us.txt");
	file2.open("agn.us.txt");
	file3.open("ale.us.txt");

	if (!file1.is_open())
    {
        cout <<"Cannot find file \nProgram will now exit\n";
        system("pause");
        exit(1);
    }
    if(!file2.is_open())
    {
        cout <<"Cannot find file \nProgram will now exit\n";
        system("pause");
        exit(1);
    }
    if(!file3.is_open())
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
                getline(file1,str1,',');
                sdate1[i] = str1;
                i++;
                getline(file1,open1,',');
                sopen1[j] = open1;
                j++;

		}

	}

	file1.close();
	if(file2.good())
    {
            i = 1;
            j = 1;
            file2.ignore(256,'n');
            while(getline(file2,line))
            {
                getline(file2,str2,',');
                sdate2[i] = str2;
                i++;
                getline(file2,open2,',');
                sopen2[j] = open2;
                j++;

		}
    }
    file2.close();
    if(file3.good())
    {
            i = 1;
            j = 1;
            file3.ignore(256,'n');
            while(getline(file3,line))
            {
                getline(file3,str3,',');
                sdate3[i] = str3;
                i++;
                getline(file3,open3,',');
                sopen3[j] = open3;
                j++;
            }
    }
    file3.close();
    for(i=1;i<N;i++)
    {
        tempstr = sopen1[i];
        tempd1 = stod(tempstr);
        dopen1[i] = tempd1;
    }
    for(i=1;i<N;i++)
    {
        tempstr = sopen2[i];
        tempd2 = stod(tempstr);
        dopen2[i] = tempd2;
    }
    for(i=1;i<N;i++)
    {
       tempstr = sopen3[i];
       tempd3 = stod(tempstr);
       dopen3[i] = tempd3;
    }
    //for(i = 1; i<N; i++)
    //{
    //  cout << dopen[i] << "\n";
    //}

mergeSort(dopen1,0,N-1);
cout << "\nSorted array after merge sort in file ainv.us is \n";
    for (int i = 1; i < N; i++)
        cout << dopen1[i]<< "\n" ;
mergeSort(dopen2,0,N-1);
cout << "\nSorted array after merge sort in file agn.us is \n";
     for (int i = 1; i < N; i++)
        cout << dopen2[i]<< "\n";
mergeSort(dopen3,0,N-1);
cout << "\nSorted array after merge sort in file ale.us is \n";
     for (int i = 1; i < N; i++)
        cout << dopen3[i]<<"\n" ;
    return 0;
}
