#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 100

void fun(int** arr, int m, int n, int m0, int n0, int input)
{

	int o = arr[m0][n0];
	arr[m0][n0] = input;
	if (m0 >= 1 && m0 <= m || n0 >= 1 && n0 <= n)
	{
		if (arr[m0 - 1][n0] == o)
			fun(arr, m, n, m0 - 1, n0, input);
		if (arr[m0 + 1][n0] == o)
			fun(arr, m, n, m0 + 1, n0, input);
		if (arr[m0][n0 - 1] == o)
			fun(arr, m, n, m0, n0 - 1, input);
		if (arr[m0][n0 + 1] == o)
			fun(arr, m, n, m0, n0 + 1, input);

	}
	else
		return;
}


int main()
{
	int m, n;
	cin >> m >> n;
	int** arr = (int**)malloc((m+1) * sizeof(int*));
	for (int i = 0; i <= (m+1); i++)
	{
		arr[i] = (int*)malloc((n+1) * sizeof(int));
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int m0, n0;
	int input;
	cin >> m0 >> n0>>input;
	fun(arr, m, n, m0+1, n0+1, input);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
}








