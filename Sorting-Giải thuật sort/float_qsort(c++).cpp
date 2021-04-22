#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <time.h>
using namespace std;

float v[1000000];

int compare(const void*, const void*);
void Nhap(string, float[]);
void Xuat(string, float[]);

int main()
{
	for (int i = 6; i <= 10; i++)
	{
		string name = "data";
		if (i < 10)
			name += "0";
		name = name + to_string(i);
		string nameinp = name + ".inp";
		Nhap(nameinp, v);

		//Tinh thoi gian chay cua qsort()
		clock_t start, end;
		start = clock();
		qsort(v, 1000000, sizeof(float), compare);
		end = clock();

		string nameout = name + ".out";
		Xuat(nameout, v);
		cout << "Sap xep file " << nameinp << " thanh cong" << endl;
		cout << "Time_used = " << (float)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	}

	return 0;
}

int compare(const void* a, const void* b)
{
	const float* x = (float*)a;
	const float* y = (float*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}

void Nhap(string fn, float vec[])
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

void Xuat(string fn, float vec[])
{
	ofstream fo(fn);
	if (fo.fail())
		cout << "Xuat file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i < 1000000; i++)
			fo << setw(10) << vec[i];
	}
}
