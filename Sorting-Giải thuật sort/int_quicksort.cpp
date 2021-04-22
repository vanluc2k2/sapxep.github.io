#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


void Nhap(string, int[]);
void Xuat(string, int[]);
void QuickSort(int a[], int, int);
int Partition(int a[], int, int);

int v[1000001];

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

void Nhap(string fn, int a[])
{
	ifstream fi(fn);
	if (fi.fail())
		cout << "Nhap file " << fn << " that bai" << endl;
	else
	{

	}
	{
		for (int i = 0; i < 1000000; i++)
			fi >> a[i];
	}
}

void Xuat(string fn, int a[])
{
	ofstream fo(fn);
	if (fo.fail())
		cout << "Xuat file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i < 1000000; i++)
			fo << setw(5) << a[i];
	}
}

int Partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
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
void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

