// Copyright 2021-2022 313CA Ciocoiu Diana Iulia
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int T, B, n, m, a, nr_corpuri, sp;
	int s_linii[100], s_coloane[100], puzzle[100][100];
	sp = 0;
	scanf("%d", &T);
	while (T > 0) {
		//B = 1 (Corect)
		B = 1;
		scanf("%d %d", &n, &m);
		//calculez suma el. pe fiecare linie
		for (int i = 0; i < n; i++) {
			s_linii[i] = 0;
			scanf("%d", &nr_corpuri);

			for (int j = 0; j < nr_corpuri; j++) {
				scanf("%d", &a);
				s_linii[i] += a;
			}
		}
		//calculez suma el. pe fiecare linie
		for (int i = 0; i < m; i++) {
			s_coloane[i] = 0;
			scanf("%d", &nr_corpuri);

			for (int j = 0; j < nr_corpuri; j++) {
				scanf("%d", &a);
				s_coloane[i] += a;
			}
		}
		//citesc puzzle-ul
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				scanf("%d", &puzzle[i][j]);
		}

		for (int i = 0; i < n; i++) {
			sp = 0;
			for (int j = 0; j < m; j++)
				sp += puzzle[i][j];
			if (sp != s_linii[i]) {
				//B = 1 (Eroare)
				B = 0;
				break;
			}
		}

		for (int i = 0; i < m; i++) {
			sp = 0;
			for (int j = 0; j < n ; j++)
				sp += puzzle[j][i];
			if (sp != s_coloane[i]) {
				//B = 1 (Eroare)
				B = 0;
				break;
			}
		}
		if (B == 1)
			printf("Corect\n");
		else
			printf("Eroare\n");
		T--;
	}
	return 0;
}

