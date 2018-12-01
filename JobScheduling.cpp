#include<bits/stdc++.h>
using namespace std;

const int m = 100;

int main()
{
    int arr1[m][2];
    int arr3[m][4];
    int arr2[m];

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
            cin >> arr1[i][j];  /// Arr[i][0]=Arrival Time, Arr[i][1]=Service Time of ith job
    }

    int totalWT =0, totalTAT=0;

    for(int i=0; i<n; i++)  ///Loop for calculating time
    {
        arr3[i][0] = arr1[i][0];

        if(arr3[i-1][1] > arr3[i][0] && i>0)
         arr3[i][1] = arr3[i-1][1] + arr1[i][1];
        else
            arr3[i][1] = arr1[i][0] + arr1[i][1];

        if(arr3[i-1][1] >= arr3[i][0] && i!=0)
            arr3[i][2] = arr3[i-1][1] - arr1[i][0];
        else
            arr3[i][2] = arr3[i][0] - arr1[i][0];
        arr3[i][3] = arr3[i][1] - arr3[i][0];

        totalWT += arr3[i][2];
        totalTAT += arr3[i][3];

    }


    cout <<endl << endl << "Grantt Chart: " << endl;

    for(int i=0, job=0; job<n ; i++, job++)     ///Loop for Grant chart
    {
        if(i==0){
                arr2[i++] = arr3[job][0];
                arr2[i++] = arr3[job][1];
            cout << arr2[i-2] << "  " << arr2[i-1] << endl;
        }
        else if(arr3[job-1][1] < arr3[job][0])
        {
            arr2[i++] = arr3[job][0];
            arr2[i++] = arr3[job][1];
               cout << arr2[i-2] << "  " << arr2[i-1] << endl;
        }
        else if(arr3[job-1][1] >= arr3[job][0]){
            arr2[i++] = arr3[job-1][1];
            arr2[i++] = arr3[job][1];
             cout << arr2[i-2] << "  " << arr2[i-1] << endl;
        }
    }

    cout << endl << "Calculating Time :" << endl;
    for (int i=0; i<n ; ++i )
    {
         cout << arr3[i][0] << " " << arr3[i][1] << " " << arr3[i][2] << " " << arr3[i][3] << endl;
    }

    cout << endl << endl;
    cout << "AWT : " << totalWT*1.0/n << endl;
    cout << "ATAT : " << totalTAT*1.0/n << endl;

    return 0;
}

/*
5
1 5
10 3
12 4
13 6
15 2
*/
