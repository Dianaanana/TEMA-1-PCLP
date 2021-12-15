// Copyright 2021-2022 313CA Ciocoiu Diana Iulia
#include <stdio.h>
#include <math.h>

int n_descrescator(int n)
{
	int v[15], m, a, l, aux;
	m = n;//in m stochez valoarea lui n
	a = 0;
	l = 0;
	//aflu nr. de cifre ce reprezinta lungimea vectorului (l)
	while (m) {
		l++;
		m /= 10;
	}
	//stochez cifrele intr-un vector
	for (int i = 0; i < l ; i++) {
		v[i] = n % 10;
		n /= 10;
	}
	//sortez vectorul
	for (int i = 0; i < l - 1; i++) {
		for (int j = i + 1; j < l; j++) {
			if (v[j] > v[i]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	//creez nr descrescator din elementele vectorului
	for (int i = 0; i < l; i++)
		a = a * 10 + v[i];//a=nr descrescator
	return a;
}

int n_crescator(int n)
{
	int v[15], m, a, l, aux;//in m stochez valoarea lui n
	m = n;
	a = 0;
	l = 0;
	//aflu nr. de cifre ce reprezinta lungimea vectorului (l)
	while (m) {
		l++;
		m /= 10;
	}
	//stochez cifrele intr-un vector
	for (int i = 0; i < l; i++) {
		v[i] = n % 10;
		n /= 10;
	}
	//sortez vectorul
	for (int i = 0; i < l - 1; i++) {
		for (int j = i + 1; j < l; j++) {
			if (v[j] > v[i]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	for (int i = l - 1; i >= 0; i--) {
		if (v[i] == 0)
			continue;
		a = a * 10 + v[i];
	}
	return a;
}

int main(void)
{
	int N, cnt, v[100], nr_scaderi, aux;
	nr_scaderi = 0;
	aux = 0;
	cnt = 0;
	scanf("%d", &N);
	while (N) {
		v[cnt] = n_descrescator(N) - n_crescator(N);
		N = v[cnt];
		if (cnt >= 1) {
			for (int i = 0; i < cnt; i++) {
				if (v[cnt] == v[i]) {
					nr_scaderi = i;
					aux = 1;
					break;
				}
			}
			if (aux == 1)
				break;
		}
	cnt++;
	}
	if (nr_scaderi == 0)
		nr_scaderi = cnt - 1;

	printf("%d\n", nr_scaderi);
	for (int i = nr_scaderi; i < cnt; i++)
		printf("%d ", v[i]);

	return 0;
}

