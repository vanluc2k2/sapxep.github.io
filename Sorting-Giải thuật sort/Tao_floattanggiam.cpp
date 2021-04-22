#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


void Nhap(string, float[]);
void Xuat(string, float[]);
void HeapSort(float[], int);
void Heapify(float[], int, int);
void BuildHeap(float[], int);
float v[1000000];

int main()
{
	for (int i = 1; i <= 1; i++)
	{
		string name = "data";
		if (i < 10)
			name += "0";
		name = name + to_string(i);
		string nameinp = name + ".inp";
		Nhap(nameinp, v);

		//Tinh thoi gian chay cua QuickSort()
		HeapSort(v, 1000000);
		name += "out";
		string dataouttang = name + ".inp";
		Xuat(dataouttang, v);
		cout << "Sap xep file " << nameinp << " thanh cong" << endl;
	}
}

void Nhap(string fn, float a[])
{
	ifstream fi(fn);
	if (fi.fail())
		cout << "Nhap file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i < 1000000; i++)
			fi >> a[i];
	}
}

void Xuat(string fn, float a[])
{
	ofstream fo(fn);
	if (fo.fail())
		cout << "Xuat file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i <1000000; i++)
			fo << setw(10) << a[i];
	}
}


void Heapify(float a[], int n, int vt)
{
	while (vt <= n / 2 - 1)
	{
		int lc = 2 * vt + 1;
		if (lc + 1 < n && a[lc] < a[lc + 1])
			lc++;
		if (a[vt] < a[lc])
			swap(a[vt], a[lc]);
		vt = lc;
	}
}

void BuildHeap(float a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);
}

void HeapSort(float a[], int n)
{
	int length = n;
	BuildHeap(a, length);
	while (length > 1)
	{
		swap(a[0], a[length - 1]);
		length--;
		Heapify(a, length, 0);
	}
}
