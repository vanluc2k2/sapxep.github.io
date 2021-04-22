#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void TaoFile(string);

int main()
{
	for (int i = 1; i <= 2; i++)
	{
		string name = "data";
		if (i < 10)
			name += "0";
		name += to_string(i);
		string nameinp = name + ".inp";
		TaoFile(nameinp);
	}
	return 0;
}

void TaoFile(string fn)
{
	srand(time(NULL));
	ofstream fo(fn);
	if (fo.fail())
		cout << "Mo file " << fn << " that bai" << endl;
	else
	{
		for (int i = 0; i < 1000000; i++)
		{
			float x = 51.3718;
			fo << setw(10) << x;
		}
		cout << "Tao file " << fn << " thanh cong" << endl;
	}
}