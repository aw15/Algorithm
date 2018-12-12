#pragma once

//랜덤->압력받음->랜덤
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include"Judgment.h"

#define Enemy 1
#define ME 2

int board[18][18];


///////////////////////////////////////////////////////////////////////

void BA_2014182005(int*, int*);
void BD_2014182005(int, int);
void WA_2014182005(int*, int*);
void WD_2014182005(int, int);


void BA_2014182005(int* x, int* y)
{
	int i, j;

	///////
	for (int a = 0; a < 18; a++)
	{
		for (int b = 0; b < 18; b++)
		{
			//////

			if (a >= 0 && b >= 0 && a < 18 && b < 18)
			{

				if (board[a][b] == Enemy&&board[a + 1][b - 1] == Enemy && board[a + 2][b - 2] == Enemy&&board[a + 3][b - 3] == Enemy&&board[a + 4][b - 4] == 0)
				{
					if (a + 4 >= 18 || b -4 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}

					board[a + 4][b - 4] == ME;
					*x = a + 4;
					*y = b - 4;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b - 1] == Enemy && board[a + 2][b - 2] == Enemy&&board[a + 3][b - 3] == Enemy&&board[a - 1][b + 1] == 0)
				{
					if (b+1 >= 18 || a-1 > 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b + 1] == ME;
					*x = a - 1;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b + 1] == Enemy && board[a - 2][b + 2] == Enemy&&board[a - 3][b + 3] == Enemy&&board[a - 4][b + 4] == 0)
				{
					if (b+4 >= 18 || a-4 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 4][b + 4] == ME;
					*x = a - 4;
					*y = b + 4;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b + 1] == Enemy && board[a - 2][b + 2] == Enemy&&board[a - 3][b + 3] == Enemy&&board[a + 1][b - 1] == 0)
				{
					if (a +1 >= 18 || b-1 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b - 1] == ME;
					*x = a + 1;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b] == Enemy && board[a + 2][b] == Enemy&&board[a + 3][b] == Enemy&&board[a - 1][b] == 0)
				{
					if ( a-1 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b] == ME;
					*x = a - 1;
					*y = b;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b] == Enemy && board[a + 2][b] == Enemy&&board[a + 3][b] == Enemy&&board[a + 4][b] == 0)
				{
					if (a + 4 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 4][b] == ME;
					*x = a + 4;
					*y = b;
					return;
				}
				if (board[a][b] == Enemy&&board[a][b + 1] == Enemy && board[a][b + 2] == Enemy&&board[a][b + 3] == Enemy&&board[a][b - 1] == 0)
				{
					if (b-1 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b - 1] == ME;
					*x = a;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a][b + 1] == Enemy && board[a][b + 2] == Enemy&&board[a][b + 3] == Enemy&&board[a][b + 4] == 0)
				{
					if (b + 4 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 4] == ME;
					*x = a;
					*y = b + 4;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b + 1] == Enemy && board[a + 2][b + 2] == Enemy&&board[a + 3][b + 3] == Enemy&&board[a - 1][b - 1] == 0)
				{
					if (a -1<0 || b-1 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b - 1] == ME;
					*x = a - 1;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b + 1] == Enemy && board[a + 2][b + 2] == Enemy&&board[a + 3][b + 3] == Enemy&&board[a + 4][b + 4] == 0)
				{
					if (a + 4 >= 18 || b +4>= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 4][b + 4] == ME;
					*x = a + 4;
					*y = b + 4;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b - 1] == Enemy && board[a - 2][b - 2] == Enemy&&board[a - 3][b - 3] == Enemy&&board[a + 1][b + 1] == 0)
				{
					if (a + 1 >= 18 || b +1>= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b + 1] == ME;
					*x = a + 1;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b - 1] == Enemy && board[a - 2][b - 2] == Enemy&&board[a - 3][b - 3] == Enemy&&board[a - 4][b - 4] == 0)
				{
					if (a -4<0 || b-4 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 4][b - 4] == ME;
					*x = a - 4;
					*y = b - 4;
					return;
				}
				////////////
				if (board[a][b] == Enemy&&board[a - 1][b - 1] == 0 && board[a - 2][b - 2] == Enemy&&board[a - 3][b - 3] == Enemy)
				{
					if (a -1<0 || b -1< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b - 1] == ME;
					*x = a - 1;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b + 1] == Enemy && board[a + 2][b + 2] == 0 && board[a + 3][b + 3] == Enemy)
				{
					if (a + 2 >= 18 || b+2 >=18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 2][b + 2] == ME;
					*x = a + 2;
					*y = b + 2;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b + 1] == 0 && board[a + 2][b + 2] == Enemy&&board[a + 3][b + 3] == Enemy)
				{
					if (a + 1 >= 18 || b +1 >=18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b + 1] == ME;
					*x = a + 1;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b - 1] == Enemy && board[a - 2][b - 2] == 0 && board[a - 3][b - 3] == Enemy)
				{
					if (a -2<0 || b -2< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 2][b - 2] == ME;
					*x = a - 2;
					*y = b - 2;
					return;
				}
				/////
				if (board[a][b] == Enemy&&board[a + 1][b - 1] == 0 && board[a + 2][b - 2] == Enemy&&board[a + 3][b - 3] == Enemy)
				{
					if (a + 1 >= 18 || b -1< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b - 1] == ME;
					*x = a + 1;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b - 1] == Enemy && board[a + 2][b - 2] == 0 && board[a + 3][b - 3] == Enemy)
				{
					if (a + 2 >= 18 || b-2 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 2][b - 2] == ME;
					*x = a + 2;
					*y = b - 2;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b + 1] == 0 && board[a - 2][b + 2] == Enemy&&board[a - 3][b + 3] == Enemy)
				{
					if (a -1<0 || b +1>18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b + 1] == ME;
					*x = a - 1;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b + 1] == Enemy && board[a - 2][b + 2] == 0 && board[a - 3][b + 3] == Enemy)
				{
					if (a -2 <0 || b+2>=18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 2][b + 2] == ME;
					*x = a - 2;
					*y = b + 2;
					return;
				}
				/////

				if (board[a][b] == Enemy&&board[a][b + 1] == 0 && board[a][b + 2] == Enemy&&board[a][b + 3] == Enemy)
				{
					if (b+1 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 1] == ME;
					*x = a;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a][b + 1] == Enemy && board[a][b + 2] == 0 && board[a][b + 3] == Enemy)
				{
					if (b+2 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 2] == ME;
					*x = a;
					*y = b + 2;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b] == 0 && board[a + 2][b] == Enemy&&board[a + 3][b] == Enemy)
				{
					if (a + 1 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b] == ME;
					*x = a + 1;
					*y = b;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b] == Enemy && board[a + 2][b] == 0 && board[a + 3][b] == Enemy)
				{
					if (a + 2 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 2][b] == ME;
					*x = a + 2;
					*y = b;
					return;
				}

				if (board[a][b] == Enemy&&board[a][b + 1] == Enemy&&board[a][b + 2] == Enemy&&board[a][b + 3] == 0)
				{
					if (b+3 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 3] == ME;
					*x = a;
					*y = b + 3;
					return;
				}

				if (board[a][b] == Enemy&&board[a][b - 1] == Enemy&&board[a][b - 2] == Enemy&&board[a][b - 3] == 0)
				{
					if (b-3 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b - 3] == ME;
					*x = a;
					*y = b - 3;
					return;
				}

				if (board[a][b] == Enemy&&board[a + 1][b] == Enemy&&board[a + 2][b] == Enemy&&board[a + 3][b] == 0)
				{
					if (a + 3 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 3][b] == ME;
					*x = a + 3;
					*y = b;
					return;
				}

				if (board[a][b] == Enemy&&board[a - 1][b] == Enemy&&board[a - 2][b] == Enemy&&board[a - 3][b] == 0)
				{
					if (a - 3 <0 )
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 3][b] == ME;
					*x = a - 3;
					*y = b;
					return;
				}

				if (board[a][b] == Enemy&&board[a + 1][b + 1] == Enemy&&board[a + 2][b + 2] == Enemy&&board[a + 3][b + 3] == 0)
				{
					if (a + 3 >= 18 || b +3>= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 3][b + 3] == ME;
					*x = a + 3;
					*y = b + 3;
					return;
				}

				if (board[a][b] == Enemy&&board[a - 1][b - 1] == Enemy&&board[a - 2][b - 2] == Enemy&&board[a - 3][b - 3] == 0)
				{
					if (a -3<0 || b -3< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 3][b - 3] == ME;
					*x = a - 3;
					*y = b - 3;
					return;
				}


				/////////////////////////////////////////////////   ////방어
				if (board[a + 1][b + 1] == ME && board[a + 2][b + 2] == ME && board[a + 3][b + 3] == ME && board[a + 4][b + 4] == ME&&board[a + 5][b + 5] == 0)
				{
					if (a + 5 >= 18 || b+5>=18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 5][b + 5] = ME;
					*x = a + 5;
					*y = b + 5;
					return;
				}
				if (board[a + 1][b + 1] == ME && board[a + 2][b + 2] == ME && board[a + 3][b + 3] == ME && board[a + 4][b + 4] == ME&&board[a][b] == 0)
				{

					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a - 1][b - 1] == ME && board[a - 2][b - 2] == ME && board[a - 3][b - 3] == ME && board[a - 4][b - 4] == ME&&board[a - 5][b - 5] == 0)
				{
					if (a-5 <0 || b-5 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 5][b - 5] = ME;
					*x = a - 5;
					*y = b - 5;
					return;
				}
				if (board[a - 1][b - 1] == ME && board[a - 2][b - 2] == ME && board[a - 3][b - 3] == ME && board[a - 4][b - 4] == ME&&board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a - 1][b - 1] == ME && board[a - 2][b - 2] == ME && board[a - 3][b - 3] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a - 1][b - 1] == ME && board[a - 2][b - 2] == ME && board[a - 3][b - 3] == ME && board[a - 4][b - 4] == 0)
				{
					if (a - 4 <0 || b -4< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 4][b - 4] = ME;
					*x = a - 4;
					*y = b - 4;
					return;
				}

				if (board[a + 1][b + 1] == ME && board[a + 2][b + 2] == ME && board[a + 3][b + 3] == ME && board[a][b] == 0)
				{

					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a + 1][b + 1] == ME && board[a + 2][b + 2] == ME && board[a + 3][b + 3] == ME && board[a + 4][b + 4] == 0)
				{
					if (a + 4 >=18 || b+4 >=18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 4][b + 4] = ME;
					*x = a + 4;
					*y = b + 4;
					return;
				}

				////////////////대각선

				if (board[a][b + 1] == ME && board[a][b + 2] == ME && board[a][b + 3] == ME && board[a][b + 4] == ME&&board[a][b + 5] == 0)
				{
					if (b +5>= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 5] = ME;
					*x = a;
					*y = b + 5;
					return;
				}
				if (board[a][b + 1] == ME && board[a][b + 2] == ME && board[a][b + 3] == ME && board[a][b + 4] == ME&&board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a][b - 1] == ME && board[a][b - 2] == ME && board[a][b - 3] == ME && board[a][b - 4] == ME&&board[a][b - 5] == 0)
				{
					if (b -5< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b - 5] = ME;
					*x = a;
					*y = b - 5;
					return;
				}
				if (board[a][b - 1] == ME && board[a][b - 2] == ME && board[a][b - 3] == ME && board[a][b - 4] == ME&&board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a][b - 1] == ME && board[a][b - 2] == ME && board[a][b - 3] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a][b - 1] == ME && board[a][b - 2] == ME && board[a][b - 3] == ME && board[a][b - 4] == 0)
				{
					if (b-4 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b - 4] = ME;
					*x = a;
					*y = b - 4;
					return;
				}

				if (board[a][b + 1] == ME && board[a][b + 2] == ME && board[a][b + 3] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a][b + 1] == ME && board[a][b + 2] == ME && board[a][b + 3] == ME && board[a][b + 4] == 0)
				{
					if (b + 4 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 4] = ME;
					*x = a;
					*y = b + 4;
					return;
				}



				//////세로/////////////////////////////////////////////////

				if (board[a + 1][b] == ME && board[a + 2][b] == ME && board[a + 3][b] == ME && board[a + 4][b] == ME&&board[a + 5][b] == 0)
				{
					if (a + 5 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 5][b] = ME;
					*x = a + 5;
					*y = b;
					return;
				}
				if (board[a + 1][b] == ME && board[a + 2][b] == ME && board[a + 3][b] == ME && board[a + 4][b] == ME&&board[a][b] == 0)
				{

					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a - 1][b] == ME && board[a - 2][b] == ME && board[a - 3][b] == ME && board[a - 4][b] == ME&&board[a - 5][b] == 0)
				{
					if (a - 5 <0 )
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 5][b] = ME;
					*x = a - 5;
					*y = b;
					return;
				}
				if (board[a - 1][b] == ME && board[a - 2][b] == ME && board[a - 3][b] == ME && board[a - 4][b] == ME&&board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a - 1][b] == ME && board[a - 2][b] == ME && board[a - 3][b] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a - 1][b] == ME && board[a - 2][b] == ME && board[a - 3][b] == ME && board[a - 4][b] == 0)
				{
					if (a - 4 <0 )
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 4][b] = ME;
					*x = a - 4;
					*y = b;
					return;
				}

				if (board[a + 1][b] == ME && board[a + 2][b] == ME && board[a + 3][b] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a + 1][b] == ME && board[a + 2][b] == ME && board[a + 3][b] == ME && board[a + 4][b] == 0)
				{
					if (a + 4 >= 18 )
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 4][b] = ME;
					*x = a + 4;
					*y = b;
					return;
				}


				////////가로//////////////////승




				srand((unsigned)time(NULL));
				int k = rand() % 8;
				switch (k)
				{
				case 1:
					if (board[a][b] == ME && board[a + 1][b] == 0)
					{
						if (a + 1 >= 18)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a + 1][b] = ME;
						*x = a + 1;
						*y = b;
						return;
					}
				case 2:
					if (board[a][b] == ME && board[a][b + 1] == 0)
					{
						if (b + 1 >= 18 )
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a][b + 1] = ME;
						*x = a;
						*y = b + 1;
						return;
					}
				case 3:
					if (board[a][b] == ME && board[a + 1][b + 1] == 0)
					{
						if (a + 1 >= 18 || b +1>=18)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a + 1][b + 1] = ME;
						*x = a + 1;
						*y = b + 1;
						return;
					}
				case 4:
					if (board[a][b] == ME && board[a - 1][b] == 0)
					{
						if (a -1 <0 )
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a - 1][b] = ME;
						*x = a - 1;
						*y = b;
						return;
					}
				case 5:

					if (board[a][b] == ME && board[a][b - 1] == 0)
					{
						if (b-1 < 0)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a][b - 1] = ME;
						*x = a;
						*y = b - 1;
						return;
					}
				case 6:
					if (board[a][b] == ME && board[a - 1][b - 1] == 0)
					{
						if (a -1 <0 || b-1 < 0)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a - 1][b - 1] = ME;
						*x = a - 1;
						*y = b - 1;
						return;
					}
				case 7:
					if (board[a][b] == ME && board[a - 1][b + 1] == 0)
					{
						if (a -1 <0 || b +1>= 18)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a - 1][b + 1] = ME;
						*x = a - 1;
						*y = b + 1;
						return;
					}
				case 0:
					if (board[a][b] == ME && board[a + 1][b - 1] == 0)
					{
						if (a + 1 >= 18 || b -1< 0)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a + 1][b - 1] = ME;
						*x = a + 1;
						*y = b - 1;
						return;
					}

				}


			}
			//
		}
	}
	///////
	while (1)
	{
		srand(time(NULL));
		i = rand() % 6 + 6;
		j = rand() % 6 + 6;
		if (board[i][j] == 0) {
			break;
		}
	}

	board[i][j] = ME;
	*x = i;
	*y = j;
}

void BD_2014182005(int x, int y)
{
	board[x][y] = Enemy;
}

void WA_2014182005(int* x, int* y)
{
	int i, j;

	///////
	for (int a = 0; a < 18; a++)
	{
		for (int b = 0; b < 18; b++)
		{
			//////

			if (a >= 0 && b >= 0 && a < 18 && b < 18)
			{

				if (board[a][b] == Enemy&&board[a + 1][b - 1] == Enemy && board[a + 2][b - 2] == Enemy&&board[a + 3][b - 3] == Enemy&&board[a + 4][b - 4] == 0)
				{
					if (a + 4 >= 18 || b - 4 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}

					board[a + 4][b - 4] == ME;
					*x = a + 4;
					*y = b - 4;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b - 1] == Enemy && board[a + 2][b - 2] == Enemy&&board[a + 3][b - 3] == Enemy&&board[a - 1][b + 1] == 0)
				{
					if (b + 1 >= 18 || a - 1 > 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b + 1] == ME;
					*x = a - 1;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b + 1] == Enemy && board[a - 2][b + 2] == Enemy&&board[a - 3][b + 3] == Enemy&&board[a - 4][b + 4] == 0)
				{
					if (b + 4 >= 18 || a - 4 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 4][b + 4] == ME;
					*x = a - 4;
					*y = b + 4;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b + 1] == Enemy && board[a - 2][b + 2] == Enemy&&board[a - 3][b + 3] == Enemy&&board[a + 1][b - 1] == 0)
				{
					if (a + 1 >= 18 || b - 1 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b - 1] == ME;
					*x = a + 1;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b] == Enemy && board[a + 2][b] == Enemy&&board[a + 3][b] == Enemy&&board[a - 1][b] == 0)
				{
					if (a - 1 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b] == ME;
					*x = a - 1;
					*y = b;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b] == Enemy && board[a + 2][b] == Enemy&&board[a + 3][b] == Enemy&&board[a + 4][b] == 0)
				{
					if (a + 4 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 4][b] == ME;
					*x = a + 4;
					*y = b;
					return;
				}
				if (board[a][b] == Enemy&&board[a][b + 1] == Enemy && board[a][b + 2] == Enemy&&board[a][b + 3] == Enemy&&board[a][b - 1] == 0)
				{
					if (b - 1 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b - 1] == ME;
					*x = a;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a][b + 1] == Enemy && board[a][b + 2] == Enemy&&board[a][b + 3] == Enemy&&board[a][b + 4] == 0)
				{
					if (b + 4 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 4] == ME;
					*x = a;
					*y = b + 4;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b + 1] == Enemy && board[a + 2][b + 2] == Enemy&&board[a + 3][b + 3] == Enemy&&board[a - 1][b - 1] == 0)
				{
					if (a - 1<0 || b - 1 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b - 1] == ME;
					*x = a - 1;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b + 1] == Enemy && board[a + 2][b + 2] == Enemy&&board[a + 3][b + 3] == Enemy&&board[a + 4][b + 4] == 0)
				{
					if (a + 4 >= 18 || b + 4 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 4][b + 4] == ME;
					*x = a + 4;
					*y = b + 4;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b - 1] == Enemy && board[a - 2][b - 2] == Enemy&&board[a - 3][b - 3] == Enemy&&board[a + 1][b + 1] == 0)
				{
					if (a + 1 >= 18 || b + 1 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b + 1] == ME;
					*x = a + 1;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b - 1] == Enemy && board[a - 2][b - 2] == Enemy&&board[a - 3][b - 3] == Enemy&&board[a - 4][b - 4] == 0)
				{
					if (a - 4<0 || b - 4 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 4][b - 4] == ME;
					*x = a - 4;
					*y = b - 4;
					return;
				}
				////////////
				if (board[a][b] == Enemy&&board[a - 1][b - 1] == 0 && board[a - 2][b - 2] == Enemy&&board[a - 3][b - 3] == Enemy)
				{
					if (a - 1<0 || b - 1< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b - 1] == ME;
					*x = a - 1;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b + 1] == Enemy && board[a + 2][b + 2] == 0 && board[a + 3][b + 3] == Enemy)
				{
					if (a + 2 >= 18 || b + 2 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 2][b + 2] == ME;
					*x = a + 2;
					*y = b + 2;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b + 1] == 0 && board[a + 2][b + 2] == Enemy&&board[a + 3][b + 3] == Enemy)
				{
					if (a + 1 >= 18 || b + 1 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b + 1] == ME;
					*x = a + 1;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b - 1] == Enemy && board[a - 2][b - 2] == 0 && board[a - 3][b - 3] == Enemy)
				{
					if (a - 2<0 || b - 2< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 2][b - 2] == ME;
					*x = a - 2;
					*y = b - 2;
					return;
				}
				/////
				if (board[a][b] == Enemy&&board[a + 1][b - 1] == 0 && board[a + 2][b - 2] == Enemy&&board[a + 3][b - 3] == Enemy)
				{
					if (a + 1 >= 18 || b - 1< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b - 1] == ME;
					*x = a + 1;
					*y = b - 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b - 1] == Enemy && board[a + 2][b - 2] == 0 && board[a + 3][b - 3] == Enemy)
				{
					if (a + 2 >= 18 || b - 2 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 2][b - 2] == ME;
					*x = a + 2;
					*y = b - 2;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b + 1] == 0 && board[a - 2][b + 2] == Enemy&&board[a - 3][b + 3] == Enemy)
				{
					if (a - 1<0 || b + 1>18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 1][b + 1] == ME;
					*x = a - 1;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a - 1][b + 1] == Enemy && board[a - 2][b + 2] == 0 && board[a - 3][b + 3] == Enemy)
				{
					if (a - 2 <0 || b + 2 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 2][b + 2] == ME;
					*x = a - 2;
					*y = b + 2;
					return;
				}
				/////

				if (board[a][b] == Enemy&&board[a][b + 1] == 0 && board[a][b + 2] == Enemy&&board[a][b + 3] == Enemy)
				{
					if (b + 1 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 1] == ME;
					*x = a;
					*y = b + 1;
					return;
				}
				if (board[a][b] == Enemy&&board[a][b + 1] == Enemy && board[a][b + 2] == 0 && board[a][b + 3] == Enemy)
				{
					if (b + 2 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 2] == ME;
					*x = a;
					*y = b + 2;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b] == 0 && board[a + 2][b] == Enemy&&board[a + 3][b] == Enemy)
				{
					if (a + 1 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 1][b] == ME;
					*x = a + 1;
					*y = b;
					return;
				}
				if (board[a][b] == Enemy&&board[a + 1][b] == Enemy && board[a + 2][b] == 0 && board[a + 3][b] == Enemy)
				{
					if (a + 2 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 2][b] == ME;
					*x = a + 2;
					*y = b;
					return;
				}

				if (board[a][b] == Enemy&&board[a][b + 1] == Enemy&&board[a][b + 2] == Enemy&&board[a][b + 3] == 0)
				{
					if (b + 3 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 3] == ME;
					*x = a;
					*y = b + 3;
					return;
				}

				if (board[a][b] == Enemy&&board[a][b - 1] == Enemy&&board[a][b - 2] == Enemy&&board[a][b - 3] == 0)
				{
					if (b - 3 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b - 3] == ME;
					*x = a;
					*y = b - 3;
					return;
				}

				if (board[a][b] == Enemy&&board[a + 1][b] == Enemy&&board[a + 2][b] == Enemy&&board[a + 3][b] == 0)
				{
					if (a + 3 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 3][b] == ME;
					*x = a + 3;
					*y = b;
					return;
				}

				if (board[a][b] == Enemy&&board[a - 1][b] == Enemy&&board[a - 2][b] == Enemy&&board[a - 3][b] == 0)
				{
					if (a - 3 <0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 3][b] == ME;
					*x = a - 3;
					*y = b;
					return;
				}

				if (board[a][b] == Enemy&&board[a + 1][b + 1] == Enemy&&board[a + 2][b + 2] == Enemy&&board[a + 3][b + 3] == 0)
				{
					if (a + 3 >= 18 || b + 3 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 3][b + 3] == ME;
					*x = a + 3;
					*y = b + 3;
					return;
				}

				if (board[a][b] == Enemy&&board[a - 1][b - 1] == Enemy&&board[a - 2][b - 2] == Enemy&&board[a - 3][b - 3] == 0)
				{
					if (a - 3<0 || b - 3< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 3][b - 3] == ME;
					*x = a - 3;
					*y = b - 3;
					return;
				}


				/////////////////////////////////////////////////   ////방어
				if (board[a + 1][b + 1] == ME && board[a + 2][b + 2] == ME && board[a + 3][b + 3] == ME && board[a + 4][b + 4] == ME&&board[a + 5][b + 5] == 0)
				{
					if (a + 5 >= 18 || b + 5 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 5][b + 5] = ME;
					*x = a + 5;
					*y = b + 5;
					return;
				}
				if (board[a + 1][b + 1] == ME && board[a + 2][b + 2] == ME && board[a + 3][b + 3] == ME && board[a + 4][b + 4] == ME&&board[a][b] == 0)
				{

					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a - 1][b - 1] == ME && board[a - 2][b - 2] == ME && board[a - 3][b - 3] == ME && board[a - 4][b - 4] == ME&&board[a - 5][b - 5] == 0)
				{
					if (a - 5 <0 || b - 5 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 5][b - 5] = ME;
					*x = a - 5;
					*y = b - 5;
					return;
				}
				if (board[a - 1][b - 1] == ME && board[a - 2][b - 2] == ME && board[a - 3][b - 3] == ME && board[a - 4][b - 4] == ME&&board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a - 1][b - 1] == ME && board[a - 2][b - 2] == ME && board[a - 3][b - 3] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a - 1][b - 1] == ME && board[a - 2][b - 2] == ME && board[a - 3][b - 3] == ME && board[a - 4][b - 4] == 0)
				{
					if (a - 4 <0 || b - 4< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 4][b - 4] = ME;
					*x = a - 4;
					*y = b - 4;
					return;
				}

				if (board[a + 1][b + 1] == ME && board[a + 2][b + 2] == ME && board[a + 3][b + 3] == ME && board[a][b] == 0)
				{

					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a + 1][b + 1] == ME && board[a + 2][b + 2] == ME && board[a + 3][b + 3] == ME && board[a + 4][b + 4] == 0)
				{
					if (a + 4 >= 18 || b + 4 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 4][b + 4] = ME;
					*x = a + 4;
					*y = b + 4;
					return;
				}

				////////////////대각선

				if (board[a][b + 1] == ME && board[a][b + 2] == ME && board[a][b + 3] == ME && board[a][b + 4] == ME&&board[a][b + 5] == 0)
				{
					if (b + 5 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 5] = ME;
					*x = a;
					*y = b + 5;
					return;
				}
				if (board[a][b + 1] == ME && board[a][b + 2] == ME && board[a][b + 3] == ME && board[a][b + 4] == ME&&board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a][b - 1] == ME && board[a][b - 2] == ME && board[a][b - 3] == ME && board[a][b - 4] == ME&&board[a][b - 5] == 0)
				{
					if (b - 5< 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b - 5] = ME;
					*x = a;
					*y = b - 5;
					return;
				}
				if (board[a][b - 1] == ME && board[a][b - 2] == ME && board[a][b - 3] == ME && board[a][b - 4] == ME&&board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a][b - 1] == ME && board[a][b - 2] == ME && board[a][b - 3] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a][b - 1] == ME && board[a][b - 2] == ME && board[a][b - 3] == ME && board[a][b - 4] == 0)
				{
					if (b - 4 < 0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b - 4] = ME;
					*x = a;
					*y = b - 4;
					return;
				}

				if (board[a][b + 1] == ME && board[a][b + 2] == ME && board[a][b + 3] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a][b + 1] == ME && board[a][b + 2] == ME && board[a][b + 3] == ME && board[a][b + 4] == 0)
				{
					if (b + 4 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a][b + 4] = ME;
					*x = a;
					*y = b + 4;
					return;
				}



				//////세로/////////////////////////////////////////////////

				if (board[a + 1][b] == ME && board[a + 2][b] == ME && board[a + 3][b] == ME && board[a + 4][b] == ME&&board[a + 5][b] == 0)
				{
					if (a + 5 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 5][b] = ME;
					*x = a + 5;
					*y = b;
					return;
				}
				if (board[a + 1][b] == ME && board[a + 2][b] == ME && board[a + 3][b] == ME && board[a + 4][b] == ME&&board[a][b] == 0)
				{

					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a - 1][b] == ME && board[a - 2][b] == ME && board[a - 3][b] == ME && board[a - 4][b] == ME&&board[a - 5][b] == 0)
				{
					if (a - 5 <0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 5][b] = ME;
					*x = a - 5;
					*y = b;
					return;
				}
				if (board[a - 1][b] == ME && board[a - 2][b] == ME && board[a - 3][b] == ME && board[a - 4][b] == ME&&board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}
				if (board[a - 1][b] == ME && board[a - 2][b] == ME && board[a - 3][b] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a - 1][b] == ME && board[a - 2][b] == ME && board[a - 3][b] == ME && board[a - 4][b] == 0)
				{
					if (a - 4 <0)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a - 4][b] = ME;
					*x = a - 4;
					*y = b;
					return;
				}

				if (board[a + 1][b] == ME && board[a + 2][b] == ME && board[a + 3][b] == ME && board[a][b] == 0)
				{
					board[a][b] = ME;
					*x = a;
					*y = b;
					return;
				}

				if (board[a + 1][b] == ME && board[a + 2][b] == ME && board[a + 3][b] == ME && board[a + 4][b] == 0)
				{
					if (a + 4 >= 18)
					{
						while (1)
						{
							srand(time(NULL));
							i = rand() % 18;
							j = rand() % 18;
							if (board[i][j] == 0) {
								break;
							}
						}
						board[i][j] = ME;
						*x = i;
						*y = j;
					}
					board[a + 4][b] = ME;
					*x = a + 4;
					*y = b;
					return;
				}


				////////가로//////////////////승




				srand((unsigned)time(NULL));
				int k = rand() % 8;
				switch (k)
				{
				case 1:
					if (board[a][b] == ME && board[a + 1][b] == 0)
					{
						if (a + 1 >= 18)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a + 1][b] = ME;
						*x = a + 1;
						*y = b;
						return;
					}
				case 2:
					if (board[a][b] == ME && board[a][b + 1] == 0)
					{
						if (b + 1 >= 18)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a][b + 1] = ME;
						*x = a;
						*y = b + 1;
						return;
					}
				case 3:
					if (board[a][b] == ME && board[a + 1][b + 1] == 0)
					{
						if (a + 1 >= 18 || b + 1 >= 18)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a + 1][b + 1] = ME;
						*x = a + 1;
						*y = b + 1;
						return;
					}
				case 4:
					if (board[a][b] == ME && board[a - 1][b] == 0)
					{
						if (a - 1 <0)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a - 1][b] = ME;
						*x = a - 1;
						*y = b;
						return;
					}
				case 5:

					if (board[a][b] == ME && board[a][b - 1] == 0)
					{
						if (b - 1 < 0)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a][b - 1] = ME;
						*x = a;
						*y = b - 1;
						return;
					}
				case 6:
					if (board[a][b] == ME && board[a - 1][b - 1] == 0)
					{
						if (a - 1 <0 || b - 1 < 0)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a - 1][b - 1] = ME;
						*x = a - 1;
						*y = b - 1;
						return;
					}
				case 7:
					if (board[a][b] == ME && board[a - 1][b + 1] == 0)
					{
						if (a - 1 <0 || b + 1 >= 18)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a - 1][b + 1] = ME;
						*x = a - 1;
						*y = b + 1;
						return;
					}
				case 0:
					if (board[a][b] == ME && board[a + 1][b - 1] == 0)
					{
						if (a + 1 >= 18 || b - 1< 0)
						{
							while (1)
							{
								srand(time(NULL));
								i = rand() % 18;
								j = rand() % 18;
								if (board[i][j] == 0) {
									break;
								}
							}
							board[i][j] = ME;
							*x = i;
							*y = j;
						}
						board[a + 1][b - 1] = ME;
						*x = a + 1;
						*y = b - 1;
						return;
					}

				}


			}
			//
		}
	}
	///////
	while (1)
	{
		srand(time(NULL));
		i = rand() % 6 + 6;
		j = rand() % 6 + 6;
		if (board[i][j] == 0) {
			break;
		}
	}

	board[i][j] = ME;
	*x = i;
	*y = j;
}

void WD_2014182005(int x, int y)
{
	board[x][y] = Enemy;
}
