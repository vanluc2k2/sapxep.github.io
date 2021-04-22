#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void Nhap(string, int[]);
void Xuat(string, int[]);
void HeapSort(int[], int);
void Heapify(int[], int, int);
void BuildHeap(int[], int);

int v[1000000];

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

		//Tinh thoi gian chay cua HeapSort()
		clock_t start, end;
		start = clock();
		HeapSort(v, 1000000);
		end = clock();

		string nameout = name + ".out";
		Xuat(nameout, v);
		cout << "Sap xep file " << nameinp << " thanh cong" << endl;
		cout << "Time_used = " << (float)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	}
}

void Nhap(string fn, int a[])
{
	ifstream fi(fn);
	if (fi.fail())
		cout << "Nhap file " << fn << " that bai";
	else
	{
		for (int i = 0; i < 1000000; i++)
			fi >> a[i];
	}
}

void Xuat(string fn, int a[])
{
	ofstream fo(fn);
	if (fo.fail())
		cout << "Xuat file " << fn << " that bai";
	else
	{
		for (int i = 0; i < 1000000; i++)
			fo << setw(5) << a[i];
	}
}


void Heapify(int a[], int n, int vt)
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

void BuildHeap(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);
}

void HeapSort(int a[], int n)
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