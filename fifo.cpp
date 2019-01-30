#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	
	cout << "number of jobs: ";
	cin >> n;
	
	int as[n+1][2];
	int grantt[n+1][2];
	int table[n+1][4];
	int totalWT=0, totalTAT=0;
	
	cout << "Arrival time and Service time are:\n";
	for(int i=1; i<=n; i++)
		cin >> as[i][0] >> as[i][1];
	
	cout << "Grantt chart:\n";
	grantt[0][1] = 1;
	for(int i=1; i<=n; i++)
	{
		if(as[i][0] > grantt[i-1][1]) grantt[i][0]=as[i][0];	///starting time
		else grantt[i][0] = grantt[i-1][1];
		
		grantt[i][1] = grantt[i][0] +  as[i][1];	///finish time
		
		cout << "\t" << grantt[i][0] << "\tjob" << i << "\t" << grantt[i][1] << endl;
	}
	
	
	cout << "Calculation table:\n";
	for(int i=1; i<=n; i++)
	{
		table[i][0] = as[i][0];	///arrival time
		table[i][1] = grantt[i][1];	///finish time
		table[i][2] = grantt[i][0] - as[i][0];	///awauiting time
		table[i][3] = table[i][1] - table[i][0]; 	///turn around time
		
		totalWT += table[i][2];
		totalTAT += table[i][3];
		
		cout << "\tjob" << i << ":\t" << table[i][0] <<  "\t" << table[i][1] <<  "\t" << table[i][2] <<  "\t" << table[i][3] << endl;
	}
	
	cout << "AWT: " << totalWT*1.0/n << endl;
	cout << "ATAT: " << totalTAT*1.0/n << endl;
	
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