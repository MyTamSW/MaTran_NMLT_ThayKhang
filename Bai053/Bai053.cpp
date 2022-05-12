#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

void Nhap(int[][500], int&, int&);
void Xuat(int[][500], int, int);

bool ktChinhPhuong(int);
int DemChinhPhuong(int[][500], int, int);

int main()
{
	int b[500][500];
	int k;
	int l;

	Nhap(b, k, l);
	cout << "Ma tran ban dau:";
	cout << "\n";
	Xuat(b, k, l);

	int kq = DemChinhPhuong(b, k, l);
	cout << "\nSo luong so chinh phuong: " << kq;
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
bool ktChinhPhuong(int k)
{
	bool flag = false;
	for (int i = 0; i <= k;i++)
		if (i * i == k)
			return true;
	return flag;
}

int DemChinhPhuong(int a[][500], int m, int n)
{
	int dem = 0;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			if (ktChinhPhuong(a[i][j]))
				dem = dem + 1;
	return dem;
}