// Copyright 2021-2022 313CA Ciocoiu Diana Iulia
#include <stdio.h>
#include <math.h>

double media_aritmetica(long long suma, int cnt)
{
double media_aritmetica;
media_aritmetica = 0;
if (cnt == 0)
	media_aritmetica = 0;
else
	media_aritmetica = (long long)suma / (double)cnt;
return media_aritmetica;
}

int main(void)
{
int N, p, xmax_impar, cnt, a, b, c, xmin_par;
long long S;
S = 0;
cnt = 0;
p = 0;
xmax_impar = 0;
xmin_par = 10000000;
scanf("%d", &N);
scanf("%d", &a);
scanf("%d", &b);

if (N <= 2) {
	printf("0\n 0.0000000\n 0\n 0");
} else {
	for (int i = 2; i < N; i++) {
		scanf("%d", &c);
		p++;
		if (b > a && b > c) {
			S = S + b;
			cnt++;
		if (b > xmax_impar && p % 2 == 1)
			xmax_impar = b;
		if (b < xmin_par && p % 2 == 0)
			xmin_par = b;
		}
		//valoarea din b trece in a
		a = b;
		//valoarea din c trece in b
		b = c;
}

if (xmin_par == 10000000)
	xmin_par = -1;

printf("%lld\n", S);
printf("%.7lf\n", media_aritmetica(S, cnt));
printf("%d\n %d", xmax_impar, xmin_par);
}

return 0;
}

