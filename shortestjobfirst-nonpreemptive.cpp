#include <bits/stdc++.h>

using namespace std;

struct job
{
	int arr;
	int start;
	int ser;
	int fin;
	int wait;
	int tat;
	int jobno;
};

bool cmpbeg(job f, job s){
	return (f.arr<=s.arr && f.ser<=s.ser);
}

bool cmp(job f, job s){
	return f.ser <= s.ser;
}

bool cmpjob(job f, job s){
	return f.jobno <= s.jobno;
}

int main()
{
	int n;
	
	cout << "number of jobs: ";
	cin >> n;
	
	job as[n+1];
	int totalWT=0, totalTAT=0;
	as[0].fin = 0;

	
	
	cout << "Arrival time and Service time are:\n";
	for(int i=1; i<=n; i++){
		cin >> as[i].arr >> as[i].ser;
		as[i].jobno = i;
	}
	sort(as+1,as+n, cmpbeg);
	
	
	cout << "Grantt chart:\n";
	for(int j=1; j<=n; j++)
	{
		if(as[j].arr < as[j-1].fin) as[j].start = as[j-1].fin;	///start time
		else as[j].start = as[j].arr;
		
		as[j].fin = as[j].start + as[j].ser;	///finish time
		
		int i=j+1;
		for( ; as[i].arr<=as[j].fin; i++);
		sort(as+j+1, as+i, cmp);
		
		
		
		
		cout << "\t" << as[j].start << "\tjob" << as[j].jobno << "\t" << as[j].fin << endl;
	}
	
	
	cout << "Calculation table:\n";
	
	sort(as+1, as+n, cmpjob);
	
	for(int i=1; i<=n; i++){
		as[i].wait = as[i].start - as[i].arr;	///waiting time
		as[i].tat = as[i].fin - as[i].arr;	///turn around time
		
		totalWT += as[i].wait;
		totalTAT += as[i].tat;
		
		cout << "\tjob" << as[i].jobno << ":\t" << as[i].arr <<  "\t" << as[i].fin <<  "\t" << as[i].wait <<  "\t" << as[i].tat << endl;
	}
	
	cout << "AWT: " << totalWT*1.0/n << endl;
	cout << "ATAT: " << totalTAT*1.0/n << endl;
	
	return 0;
}


/*
6
1 4
1 2
10 7
12 3
12 5
15 5
*/