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

double getMax(double arr[], int size) {
   double max = arr[1];
   for(int i = 2; i<=size; i++) {
      if(arr[i] > max)
         max = arr[i];
   }
   return max; //the max element from the array
}
void countingSort(double *arr, int size, string strarr[]) {
   double output[size+1];
   string strout[size+1];
   double max = getMax(arr, size);
   int count[(int)max+1];   //create count array (max+1 number of elements)
   for(int i = 0; i<=(int)max; i++)
      count[i] = 0;     //initialize count array to all zero
   for(int i = 1; i <=size; i++)
      count[(int)arr[i]]++;     //increase number count in count array.
   for(int i = 1; i<=(int)max; i++)
      count[i] += count[i-1];     //find cumulative frequency
   for(int i = size; i>=1; i--)
   {
      output[count[(int)arr[i]]] = arr[i];
      strout[count[(int)arr[i]]] = strarr[i];
      count[(int)arr[i]] -= 1; //decrease count for same numbers
   }
   for(int i = 1; i<=size; i++)
   {
      arr[i] = output[i]; //store output array to main array
      strarr[i] = strout[i];
   }
}
int main()
{


	string str,close,line,tempstr;
	int i,j;
	int iclose[N];
	int tempint;
	double tempd;
	double dclose[N];
	string sdate[N];
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

    for(i=1;i<=N;i++)
    {
        tempstr = sclose[i];
        tempd = stod(tempstr);
        dclose[i] = tempd;
    }

    countingSort(dclose,N,sdate);
    cout<<"Sorted array after counting Sort is \n";
      for (int i = 1; i <= N; i++)
        cout << dclose[i] << "|" << sdate[i] << " \n";

    return 0;
}
