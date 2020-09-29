// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
const int M = 524287, a = 389, b = 454;
const int new_a = 1, new_b = 2, new_c = 5, new_d = 6;
const double h = 4.0/17.0;
int generate(int xi)
{
	return (a * xi + b) % M;
}

void generate_spec(int *xi, int *yi)
{
	bool ok_rand = false;
	while (!ok_rand) 
	{
		*xi = generate(*xi);
		*yi = generate(*yi);
		double uxi = *xi / (double)M * 5 + 1, uyi = *yi / (double)M * h;
		if (uxi < new_b && uxi >=new_a)
			if (uyi < h / 2) ok_rand = true;
		if (uxi < new_c && uxi >=new_b)
			if (uyi < h) ok_rand = true;
		if (uxi <= new_d && uxi >= new_c) {
			double ff = (14.0 / 17.0) - (h * uxi / 2.0);
			if (uyi < ff) ok_rand = true;
		}
	}
}

int main()
{
	int xi, yi, x_periodic, res_histogram[20];
	double ui;
	printf("Inter seed:");
	scanf_s("%d", &xi);
	yi = xi+150;
	for (int i = 0; i < 20; i++) res_histogram[i] = 0;
	generate_spec(&xi, &yi);
	x_periodic = xi;
	ui = (double)xi / (double)M;
	res_histogram[(int)floor(ui / 0.05)]++;
	printf("period:");
	for (int i = 0, period = 1; i < 74321; i++, period++)
	{
		generate_spec(&xi, &yi);
		ui = (double)xi / (double)M;
		res_histogram[(int)floor(ui / 0.05)]++;
		if (xi == x_periodic) {
			printf("%d ", period);
			period = 0;
		}
	}
	printf("\nHistogram:");
	for (int i = 0; i < 20; i++) printf("%d ", res_histogram[i]);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
