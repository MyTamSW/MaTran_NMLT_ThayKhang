#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);

bool ktToanLe(int);
int DemToanLeDong(int[][500], int, int, int);

int main()
{
	int b[500][500];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	int d;
	cout << "\nNhap dong: ";
	cin >> d;

	int kq = DemToanLeDong(b, k, l, d);
	cout << "\nSo luong so toan le tren dong " << d << " la : " << kq;
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

bool ktToanLe(int k)
{
	bool flag = true;
	for (int t = k = abs(k); t != 0; t = t / 10)
		if ((t % 10) % 2 == 0)
			flag = false;
	return flag;
}

int DemToanLeDong(int a[][500], int m, int n, int d)
{
	int dem = 0;
	for (int j = 0;j < n;j++)
		if (ktToanLe(a[d][j]))
			dem++;
	return dem;
}