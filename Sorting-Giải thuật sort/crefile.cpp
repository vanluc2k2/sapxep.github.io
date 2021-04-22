#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void TaoRandom(string);
void TaoTangDan(string);
void TaoGiamDan(string);
void TaoBangNhau(string);
int main()
{
	for (int i = 1; i <= 2; i++)
	{
		string name = "data";
		if (i < 10)
			name += "0";
		name += to_string(i);
		string nameinp = name + ".inp";
		TaoRandom(nameinp);
	}
	return 0;
}

void TaoRandom(string fn)
{
	ofstream fo(fn);
	if (fo.fail())
		cout << "Mo file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i < 1000000; i++)
		{
			int x = 5;
			fo << setw(4) << x;
		}
		cout << "Tao file " << fn << " thanh cong" << endl;
	}
}
