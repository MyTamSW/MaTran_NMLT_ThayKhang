#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);

bool ktChanDau(int);
int DemGiaTri(int[][500], int, int, int);

int main()
{
	int b[500][500];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	int c;
	cout << "\nNhap cot: ";
	cin >> c;

	int kq = DemGiaTri(b, k, l, c);
	cout << "\nSo luong so nguyen co chu dau tien la chan tren cot " << c << " la: " << kq;
	return 0;
}

void Nhap(int a[][500], int& m, int& n)
{
	cout << "Nhap m: ";
	cin >> m;
	cout << "Nhap n: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % (200 + 1) - 100;
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << "\n";
	}
}

bool ktChanDau(int k)
{
	int t = abs(k);
	int dt;
	while (t > 0)
	{
		dt = t % 10;
		t /= 10;
	}
	if (dt % 2 == 0)
		return true;
	return false;
}

int DemGiaTri(int a[][500], int m, int n, int c)
{
	int dem = 0;
	for (int i = 0;i < m;i++)
		if (ktChanDau(a[i][c]))
			dem++;
	return dem;
}