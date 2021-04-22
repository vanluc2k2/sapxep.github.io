#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <algorithm>
using namespace std;

int v[1000000];

void Nhap(string, int[]);
void Xuat(string, int[]);

int main()
{
	for (int i = 1; i <= 5; i++)
	{
		string name = "data";
		if (i < 10)
			name += "0";
		name = name + to_string(i);
		string nameinp = name + ".inp";
		Nhap(nameinp, v);

		clock_t start, end;
		start = clock();
		sort(v, v + 999999);
		end = clock();

		string nameout = name + ".out";
		Xuat(nameout, v);
		cout << "Sap xep file " << nameinp << " thanh cong" << endl;
		cout << "Time_used = " << (float)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	}

	return 0;
}

void Nhap(string fn, int vec[])
{
	ifstream fi(fn);
	if (fi.fail())
		cout << "Nhap file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i < 1000000; i++)
			fi >> vec[i];
		cout << "Nhap file " << fn << " thanh cong" << endl;
	}
}

void Xuat(string fn, int vec[])
{
	ofstream fo(fn);
	if (fo.fail())
		cout << "Xuat file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i < 1000000; i++)
			fo << setw(5) << vec[i];
	}
}
