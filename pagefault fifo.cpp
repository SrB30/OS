#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, f;
    cout << "page = " ;
    cin >> n;

    cout << "frame = " ;
    cin >> f;

    int a[n];
    int b[f]={0};


    for(int i=0; i<n; i++)
        cin >> a[i];

    int prev = -1;
    int fa =0;
    for(int i=0; i<n; i++)
    {
        int j=0;
        for( ; j<f; j++)
            if(b[j] == a[i])
                break;
        if(j>=f)
        {
            if(prev ==f-1) prev=-1;
            b[++prev] = a[i];
        }

        for(int k=0; k<f; k++)
            cout << " " << b[k];
        if(j>=f){ fa++; cout << " f";}
        cout << endl;
    }

    cout << "Total page fault = " << fa;

    return 0;
}

/*
16
3
1 2 3 1 4 5 6 7 1 2 3 9 4 3 5 6
*/
