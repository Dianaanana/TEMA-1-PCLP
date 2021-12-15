// Copyright 2021-2022 313CA Ciocoiu Diana Iulia
#include <stdio.h>
#include <math.h>
#define MAX 102

int main(void)
{
	int n, m;
	int x[MAX], c[MAX], sort[MAX], P, P_min, dif;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	scanf("%d", &P_min);

	P = 0;
	for (int i = 0; i < n; i++)
		P += x[i] * c[i];
	//dif reprezinta nr de puncte de care mai am nevoie
	dif = P_min - P;
	for (int i = 0; i < n; i++)
		sort[i] = (10 - x[i]) * c[i];

	int aux;
	//sortez vectorul
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sort[j] > sort[i]) {
				aux = sort[i];
				sort[i] = sort[j];
				sort[j] = aux;
			}
		}
	}
	m = 0;
	while (dif > 0) {
		dif -= sort[m];
		m++;
	}
	if (m > n)
		printf("-1");
	else
		printf("%d ", m);

	return 0;
}
