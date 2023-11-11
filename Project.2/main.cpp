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

void turnover(double* a, double* b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

double par(double arr[], int low, int high)
{
    double piv = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= piv)
        {
            i++;
            turnover(&arr[i], &arr[j]);
        }
    }
    turnover(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        double pi = par(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{


	string str,open,line,tempstr;
	int i,j;
	double tempd;
	string sdate[N];
	double dopen[N];
	string sopen[N];
	for(i=1;i<=N;i++)
    {
        sdate[i] = "0";
        sopen[i] = "0";

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
                getline(file1,open,',');
                sopen[j] = open;
                j++;

		    }

	}

	file1.close();

    for(i=1;i<N;i++)
    {
        tempstr = sopen[i];
        tempd = stod(tempstr);
        dopen[i] = tempd;
    }
    quickSort(dopen,0,N-1);
    cout << "\nSorted array after quick sort is \n";
    for (int i = 1; i < N; i++)
        cout << dopen[i]<<sdate[i] << " \n";

    return 0;
}

