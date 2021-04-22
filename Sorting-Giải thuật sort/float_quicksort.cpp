#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


void Nhap(string, float[]);
void Xuat(string, float[]);
void QuickSort(float a[], int, int);
int Partition(float a[], int, int);

float v[1000000];

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

		//Tinh thoi gian chay cua QuickSort()
		clock_t start, end;
		start = clock();
		QuickSort(v, 0, 999999);
		end = clock();

		string dataouttang = name + ".out";
		Xuat(dataouttang, v);
		cout << "Sap xep file " << nameinp << " thanh cong" << endl;
		cout << "Time_used = " << (float)(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
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
		for (int i = 0; i < 1000000; i++)
			fo << setw(10) << a[i];
	}
}

int Partition(float arr[], int low, int high)
{
	float pivot = arr[high];    // pivot
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left++;
		while (right >= left && arr[right] > pivot) right--;
		if (left >= right) break;
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
	swap(arr[left], arr[high]);
	return left;
}
void QuickSort(float arr[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

