#pragma once
#include "Judgment.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_2013180016 19
#define BLACK_2013180016 1
#define WHITE_2013180016 2
#define EMPTY 0
#define ONE_CON 1
#define TWO_CON 10
#define THREE_CON 100
#define FOUR_CON 1000

typedef struct pan {
	int stone;
	int priority;							//가중치
}PAN;
typedef struct prior {
	int indexX;
	int indexY;
	int maxpriority;
}PRIOR;

int turn = 0;
PAN pan[SIZE_2013180016][SIZE_2013180016] = {0,};

void findVertexContinueCount(PAN pan[SIZE_2013180016][SIZE_2013180016]) {
	int i = 0;
	int j = 0;
	int k = 0;
	int jNext = 0;
	int jPrev = 0;
	int jPprev = 0;
	int jNnext = 0;
	int id = 0;

	int black = 0;
	int white = 0;

	for (i = 0; i < 19; i++) {
		for (j = 0; j < 19; j++) {
			if (j > 0) {
				jPrev = j - 1;

			}
			if (j > 1) {
				jPprev = j - 2;
			}
			if (j >= 0 && j<18) {
				jNext = j + 1;
			}
			if (j >= 0 && j < 17) {
				jNnext = j + 2;
			}

			if (pan[j][i].stone == 1) {
				if (j > 0 && j < 18) {
					pan[j - 1][i].priority += ONE_CON;
					pan[j + 1][i].priority += ONE_CON;
				}
				else if (j == 0) {
					pan[j + 1][i].priority += ONE_CON;
				}
				else if (j == 18) {
					pan[j - 1][i].priority += ONE_CON;
				}
				if (black < 1) {
					black = 1;
				}
			}
			if (pan[j][i].stone == 1 && pan[jNext][i].stone == 1) {
				if (j > 0 && j < 18) {
					pan[j - 1][i].priority += TWO_CON;
					pan[jNext + 1][i].priority += TWO_CON;
				}
				else if (j == 0) {
					pan[jNext + 1][i].priority += TWO_CON;
				}
				else if (j == 17) {
					pan[j - 1][i].priority += TWO_CON;
				}
				if (black < 2) {
					black = 2;
				}
			}
			if (pan[jNext][i].stone == 1 && pan[j][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[jPprev][i].stone == 1 ||
				pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
				pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3) {
				if (black < 4) {
					black = 4;
				}

				if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1) {
					//pan[jPprev][i].stone = 3;
					if (j > 1 && j < 18) {
						pan[jPprev][i].priority += THREE_CON;
					}
					if (j < 17) {
						pan[jNext + 1][i].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1) {
					if (j > 1) {
						//pan[jPrev][i].stone= 3;
						pan[jPrev][i].priority += THREE_CON;
					}
					if (j > 2 && j < 17) {
						pan[jPprev - 1][i].priority += THREE_CON;
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 2) {
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 17) {
						pan[jPprev - 1][i].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1) {
					if (j > 1 && j<18) {
						//pan[j][i].stone = 3;
						pan[j][i].priority += THREE_CON;
					}
					if (j > 2 && j < 17) {
						pan[jPprev - 1][i].priority += THREE_CON;
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 2) {
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 17) {
						pan[jPprev - 1][i].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3) {
					if (j > 1 && j < 18) {
						//pan[jNext][i].stone = 3;
						pan[jNext][i].priority += THREE_CON;
					}
					if (j < 17) {
						pan[jPprev - 1][i].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[jNext][i].stone == 1 && pan[j][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[jPprev][i].stone == 1) {
					if (j > 2 && j < 17) {
						pan[jNext + 1][i].priority += FOUR_CON;
						pan[jPprev - 1][i].priority += FOUR_CON;
					}
				}
			}
			if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
				pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
				pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 0 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 3 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
				pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1 ||
				pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 0 ||
				pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 3) {
				if (black < 5) {
					black = 5;
				}
				if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1) {
					if (j > 1 && j < 17) {
						//pan[jPprev][i].stone = 3;
						pan[jPprev][i].priority += FOUR_CON;
					}
					if (j < 16) {
						pan[jNnext + 1][i].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1) {
					if (j > 1 && j < 17) {
						//pan[jPrev][i].stone = 3;
						pan[jPrev][i].priority += FOUR_CON;
					}
					if (j > 2 && j < 16) {
						pan[jPprev - 1][i].priority += FOUR_CON;
						pan[jNnext + 1][i].priority += FOUR_CON;
					}
					else if (j == 2) {
						pan[jNnext + 1][i].priority += FOUR_CON;
					}
					else if (j == 16) {
						pan[jPprev - 1][i].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}

				}
				if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 0 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 3) {
					if (j > 1 && j < 17) {
						//pan[jNnext][i].stone = 3;
						pan[jNnext][i].priority += FOUR_CON;
					}
					if (j > 2) {
						pan[jPprev - 1][i].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1) {
					if (j > 1 && j < 17) {
						//pan[j][i].stone = 3;
						pan[j][i].priority += FOUR_CON;
					}
					if (j > 2 && j < 16) {
						pan[jPprev - 1][i].priority += FOUR_CON;
						pan[jNnext + 1][i].priority += FOUR_CON;
					}
					else if (j == 2) {
						pan[jNnext + 1][i].priority += FOUR_CON;
					}
					else if (j == 16) {
						pan[jPprev - 1][i].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1) {
					if (j > 1 && j < 17) {
						//pan[jNext][i].stone = 3;
						pan[jNext][i].priority += FOUR_CON;
					}
					if (j > 2 && j < 16) {
						pan[jPprev - 1][i].priority += FOUR_CON;
						pan[jNnext + 1][i].priority += FOUR_CON;
					}
					else if (j == 2) {
						pan[jNnext + 1][i].priority += FOUR_CON;
					}
					else if (j == 16) {
						pan[jPprev - 1][i].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 0 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 3) {
					if (j > 1 && j < 17) {
						//pan[jPprev][i].stone = 3;
						//pan[jNnext][i].stone = 3;
						pan[jPprev][i].priority += THREE_CON;
						pan[jNnext][i].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}

			}

			if (pan[jNext][i].stone == 1 && pan[j][i].stone == 1 && pan[jPrev][i].stone == 1 ||
				pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
				pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
				pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 ||
				pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3 ||
				pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 ||
				pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1) {

				if (pan[jNext][i].stone == 1 && pan[j][i].stone == 1 && pan[jPrev][i].stone == 1) {
					if (black < 3) {
						black = 3;
					}
					if (j > 1 && j < 17) {
						pan[jNext + 1][i].priority += THREE_CON;
						pan[jPrev - 1][i].priority += THREE_CON;
					}
					else if (j == 1) {
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 17) {
						pan[jPrev - 1][i].priority += THREE_CON;
					}
				}
				if (pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
					pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1) {
					if (j >= 1 && j <= 17) {
						//pan[jPrev][i].stone = 3;
						pan[jPprev][i].priority += TWO_CON;
					}
					if (j < 17) {
						pan[jNext + 1][i].priority += TWO_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}
				if (pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 ||
					pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1) {
					if (j >= 1 && j <= 17) {
						//pan[j][i].stone = 3;
						pan[j][i].priority += TWO_CON;
					}
					if (j > 1 && j < 17) {
						pan[jPrev - 1][i].priority += TWO_CON;
						pan[jNext + 1][i].priority += TWO_CON;
					}
					else if (j == 1) {
						pan[jNext + 1][i].priority += TWO_CON;
					}
					else if (j == 17) {
						pan[jPrev - 1][i].priority += TWO_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}
				if (pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 ||
					pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3) {
					if (j >= 1 && j <= 17) {
						//pan[jNext][i].stone = 3;
						pan[jNext][i].priority += TWO_CON;
					}
					if (j < 17) {
						pan[jNext + 1][i].priority += TWO_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}

			}
			if (pan[j][i].stone == 2) {
				if (j > 0 && j<18) {
					pan[j - 1][i].priority += ONE_CON;
					pan[j + 1][i].priority += ONE_CON;
				}
				else if (j == 0) {
					pan[j + 1][i].priority += ONE_CON;
				}
				else if (j == 18) {
					pan[j - 1][i].priority += ONE_CON;
				}
				if (white < 1) {
					white = 1;
				}
			}
			if (pan[jNext][i].stone == 2 && pan[j][i].stone == 2) {
				if (j > 0 && j < 18) {
					pan[j - 1][i].priority += TWO_CON;
					pan[jNnext + 1][i].priority += TWO_CON;
				}
				else if (j == 0) {
					pan[jNnext + 1][i].priority += TWO_CON;
				}
				else if (j == 17) {
					pan[j - 1][i].priority += TWO_CON;
				}
				if (white < 2) {
					white = 2;
				}
			}
			if (pan[jNext][i].stone == 2 && pan[jPprev][i].stone == 2 && pan[j][i].stone == 2 && pan[jPrev][i].stone == 2 ||
				pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 ||
				pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3) {
				if (white < 4) {
					white = 4;
				}
				if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2) {
					if (j >= 2 && j <= 17) {
						//pan[jPprev][i].stone = 3;
						pan[jPprev][i].priority += THREE_CON;
					}
					if (j < 17) {
						pan[jNext + 1][i].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2) {
					if (j >= 1 && j <= 17) {
						//pan[jPrev][i].stone = 3;
						pan[jPrev][i].priority += THREE_CON * 3;
					}
					if (j > 2 && j < 17) {
						pan[jPprev - 1][i].priority += THREE_CON;
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 2) {
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 17) {
						pan[jPprev - 1][i].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2) {
					if (j >= 2 && j <= 17) {
						//pan[j][i].stone = 3;
						pan[j][i].priority += THREE_CON * 3;
					}
					if (j > 2 && j < 17) {
						pan[jPprev - 1][i].priority += THREE_CON;
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 2) {
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 17) {
						pan[jPprev - 1][i].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3) {
					if (j >= 2 && j <= 17) {
						//pan[jNext][i].stone = 3;
						pan[jNext][i].priority += THREE_CON;
					}
					if (j > 2) {
						pan[jPprev - 1][i].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
			}
			if (pan[jNext][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 ||
				pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
				pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
				pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 ||
				pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1 ||
				pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 ||
				pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3)
			{
				if (pan[jNext][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1) {
					if (j > 1 && j < 17) {
						pan[jNext + 1][i].priority += THREE_CON;
						pan[jPrev - 1][i].priority += THREE_CON;
					}
					else if (j == 1) {
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 17) {
						pan[jPrev - 1][i].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 ||
					pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1) {
					if (j >= 1 && j <= 17) {
						//pan[jPrev][i].stone = 3;
						pan[jPrev][i].priority += TWO_CON;
					}
					if (j < 17) {
						pan[jNext + 1][i].priority += TWO_CON;
					}
					if (black<2) {
						black = 2;
					}
				}
				if (pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 ||
					pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2) {
					if (j >= 1 && j <= 17) {
						//pan[j][i].stone = 3;
						pan[j][i].priority += TWO_CON;
					}
					if (j > 1 && j < 17) {
						pan[jNext + 1][i].priority += TWO_CON;
						pan[jPrev - 1][i].priority += TWO_CON;
					}
					else if (j == 1) {
						pan[jNext + 1][i].priority += TWO_CON;
					}
					else if (j == 17) {
						pan[jPrev - 1][i].priority += TWO_CON;
					}
					if (black<2) {
						black = 2;
					}
				}
				if (pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 ||
					pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3) {
					if (j >= 1 && j <= 17) {
						//pan[jNext][i].stone = 3;
						pan[jNext][i].priority += TWO_CON;
					}
					if (j < 17) {
						pan[jPrev - 1][i].priority += TWO_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}
			}
			if (pan[jNext][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 ||
				pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 ||
				pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 ||
				pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 ||
				pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 ||
				pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 ||
				pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3) {

				if (pan[jNext][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2) {
					if (white < 3) {
						white = 3;
					}
					if (j > 1 && j < 17) {
						pan[jNext + 1][i].priority += THREE_CON;
						pan[jPrev - 1][i].priority += THREE_CON;
					}
					else if (j == 1) {
						pan[jNext + 1][i].priority += THREE_CON;
					}
					else if (j == 17) {
						pan[jPrev - 1][i].priority += THREE_CON;
					}
				}
				if (pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 ||
					pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2) {
					if (j >= 1 && j <= 17) {
						//pan[jPrev][i].stone = 3;
						pan[jPrev][i].priority += TWO_CON;
					}
					if (j < 17) {
						pan[jNext + 1][i].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
				if (pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 ||
					pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2) {
					if (j >= 1 && j <= 17) {
						//pan[j][i].stone = 3;
						pan[j][i].priority += TWO_CON;
					}
					if (j > 1 && j < 17) {
						pan[jNext + 1][i].priority += TWO_CON;
						pan[jPrev - 1][i].priority += TWO_CON;
					}
					else if (j == 1) {
						pan[jNext + 1][i].priority += TWO_CON;
					}
					else if (j == 17) {
						pan[jPrev - 1][i].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
				if (pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 ||
					pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3) {
					if (j >= 1 && j <= 17) {
						//pan[jNext][i].stone = 3;
						pan[jNext][i].priority += TWO_CON;
					}
					if (j < 17) {
						pan[jPrev - 1][i].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
			}
			if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
				pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
				pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 0 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 3 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 2 ||
				pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 2 ||
				pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 0 ||
				pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 3) {
				if (white < 5) {
					white = 5;
				}
				if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2) {
					if (j > 2 && j < 16) {
						pan[jPrev][i].priority += FOUR_CON;
						pan[jPprev - 1][i].priority += THREE_CON;
						pan[jNnext + 1][i].priority += THREE_CON;
					}
					else if (j == 2) {
						pan[jPrev][i].priority += FOUR_CON;
						pan[jNnext + 1][i].priority += THREE_CON;
					}
					else if (j == 16) {
						pan[jPrev][i].priority += FOUR_CON;
						pan[jPprev - 1][i].priority += THREE_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2) {
					if (j >= 2 && j < 16) {
						pan[jPprev][i].priority += FOUR_CON;
						pan[jNnext + 1][i].priority += FOUR_CON;
					}
					else if (j == 16) {
						pan[jPprev][i].priority += FOUR_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 0 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 3) {
					if (j > 2 && j <= 16) {
						//pan[jNnext][i].stone = 3;
						pan[jNnext][i].priority += FOUR_CON;
					}
					else if (j == 2) {
						pan[jNnext][i].priority += FOUR_CON;
						pan[jPprev - 1][i].priority += FOUR_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2) {
					if (j > 2 && j < 16) {
						pan[jPprev - 1][i].priority += THREE_CON;
						pan[jNnext + 1][i].priority += THREE_CON;
						pan[j][i].priority += FOUR_CON;
					}
					else if (j == 2) {
						pan[jNnext + 1][i].priority += THREE_CON;
						pan[j][i].priority += FOUR_CON;
					}
					else if (j == 16) {
						pan[jPprev - 1][i].priority += THREE_CON;
						pan[j][i].priority += FOUR_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 2) {
					if (j > 2 && j<16) {
						pan[jNext][i].priority += FOUR_CON;
						pan[jPprev - 1][i].priority += THREE_CON;
						pan[jNnext + 1][i].priority += THREE_CON;
					}
					else if (j == 2) {
						pan[jNnext + 1][i].priority += THREE_CON;
						pan[jNext][i].priority += FOUR_CON;
					}
					else if (j == 16) {
						pan[jPprev - 1][i].priority += THREE_CON;
						pan[jNext][i].priority += FOUR_CON;
					}

					if (white < 4) {
						white = 4;
					}
				}
				if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 0 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 3) {
					if (j >= 2 && j <= 16) {
						//pan[jPprev][i].stone = 3;
						pan[jPprev][i].priority += THREE_CON;
						//pan[jNnext][i].stone = 3;
						pan[jNnext][i].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}

			}

		}
		/*if (black < white) {
			printf("세로 %d줄의 백돌이 %d개로 연속됩니다.\n", i, white);
		}
		else if (black > white) {
			printf("세로 %d줄의 흑돌이 %d개로 연속됩니다.\n", i, black);
		}*/
		black = 0;
		white = 0;
	}
}
void findCrossContinueCount(PAN pan[SIZE_2013180016][SIZE_2013180016]) {
	int i = 0;
	int j = 0;
	int k = 0;
	int iNext = 0;
	int iPrev = 0;
	int iPprev = 0;
	int iNnext = 0;
	int black = 0;
	int white = 0;

	for (j = 0; j < 19; j++) {
		for (i = 0; i < 19; i++) {
			if (i > 0) {
				iPrev = i - 1;

			}
			if (i > 1) {
				iPprev = i - 2;
			}
			if (i >= 0 && i<18) {
				iNext = i + 1;
			}
			if (i >= 0 && i < 17) {
				iNnext = i + 2;
			}


			if (pan[j][i].stone == 1) {
				if (i > 0 && i < 18) {
					pan[j][i - 1].priority += ONE_CON;
					pan[j][i + 1].priority += ONE_CON;
				}
				else if (i == 0) {
					pan[j][i + 1].priority += ONE_CON;
				}
				else if (i == 18) {
					pan[j][i - 1].priority += ONE_CON;
				}

				if (black < 1) {
					black = 1;
				}
			}
			if (pan[j][i].stone == 1 && pan[j][iNext].stone == 1) {
				if (i > 0 && i < 17) {
					pan[j][i - 1].priority += TWO_CON;
					pan[j][iNext + 1].priority += TWO_CON;
				}
				else if (i == 0) {
					pan[j][iNext + 1].priority += TWO_CON;
				}
				else if (i == 17) {
					pan[j][i - 1].priority += TWO_CON;
				}
				if (black < 2) {
					black = 2;
				}
			}
			if (pan[j][i].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1 ||
				pan[j][i].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1 ||
				pan[j][i].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1) {
				if (pan[j][i].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1) {
					if (i > 1 && i < 17) {
						pan[j][iNext + 1].priority = THREE_CON;
						pan[j][iPrev - 1].priority = THREE_CON;
					}
					else if (i == 1) {
						pan[j][iNext + 1].priority = THREE_CON;
					}
					else if (i == 17) {
						pan[j][iPrev - 1].priority = THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[j][i].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1 ||
					pan[j][i].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1) {
					if (i >= 0 && i < 17) {
						pan[j][i].priority = TWO_CON;
						pan[j][iNext + 1].priority += TWO_CON;
					}
					else if (i == 17) {
						pan[j][i].priority = TWO_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}
			}
			if (pan[j][i].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iPprev].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 0 && pan[j][iNext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 3 && pan[j][iNext].stone == 1 ||
				pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 ||
				pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3) {
				if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1) {
					if (i > 2 && i < 17) {
						//pan[j][iPrev].stone = 3;
						pan[j][iPrev].priority += THREE_CON;
						pan[j][iNext + 1].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
						if (black < 3) {
							black = 3;
						}
					}
					else if (i == 2) {
						pan[j][iPrev].priority += THREE_CON;
						pan[j][iNext + 1].priority += THREE_CON;
					}
					else if (i == 17) {
						pan[j][iPrev].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;

					}
				}
				if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 0 && pan[j][iNext].stone == 1 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 3 && pan[j][iNext].stone == 1) {
					if (i>2 && i<17) {
						pan[j][iPprev - 1].priority += THREE_CON;
						pan[j][iNext + 1].priority += THREE_CON;
						pan[j][i].priority += THREE_CON;
					}
					else if (i == 2) {
						pan[j][iNext + 1].priority += THREE_CON;
						pan[j][i].priority += THREE_CON;
					}
					else if (i == 17) {
						pan[j][iPprev - 1].priority += THREE_CON;
						pan[j][i].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}

				}
				if (pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 ||
					pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1) {
					if (i >= 2 && i < 17) {
						//pan[j][iPprev].stone = 3;
						pan[j][iPprev].priority += THREE_CON;
						pan[j][iNext + 1].priority += THREE_CON;
					}
					if (i == 17) {
						pan[j][iPprev].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3) {
					if (i > 2 && i < 17) {
						//pan[j][iNext].stone = 3;
						pan[j][iNext].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
					}
					if (i == 2) {
						pan[j][iNext].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[j][i].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iPprev].stone == 1) {
					if (i > 2 && i < 17) {
						pan[j][iPprev - 1].priority += FOUR_CON;
						pan[j][iNext + 1].priority += FOUR_CON;
					}
					else if (i == 2) {
						pan[j][iNext + 1].priority += FOUR_CON;
					}
					else if (i == 17) {
						pan[j][iPprev - 1].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
			}

			if (pan[j][i].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iPprev].stone == 1 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 0 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 3 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 0 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 3 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 0 ||
				pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 3 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 1 ||
				pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 1) {
				if (pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 0 ||
					pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 3) {
					if (i >= 2 && i <= 16) {
						pan[j][iPprev].stone = 3;
						pan[j][iPprev].priority += THREE_CON;
						pan[j][iNnext].stone = 3;
						pan[j][iNnext].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}

				if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 1) {
					if (i >= 2 && i <= 16) {
						pan[j][iPrev].stone = 3;
						pan[j][iPrev].priority += THREE_CON;
						pan[j][iNext].stone = 3;
						pan[j][iNext].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1) {
					if (i >= 2 && i < 16) {
						pan[j][iPrev].stone = 3;
						pan[j][iPrev].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
					}
					else if (i == 16) {
						pan[j][iPrev].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
					}
					else if (i == 2) {
						pan[j][iPrev].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += THREE_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1) {
					if (i >= 2 && i < 16) {
						//pan[j][iPprev].stone = 3;
						pan[j][iPprev].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += FOUR_CON;
					}
					else if (i == 16) {
						pan[j][iPprev].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 0 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 3) {
					if (i > 2 && i <= 16) {
						//pan[j][iNnext].stone = 3;
						pan[j][iNnext].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += FOUR_CON;
					}
					else if (i == 2) {
						pan[j][iNnext].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 0 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 3 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1) {

					if (i > 2 && i < 16) {
						pan[j][i].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
						pan[j][iNnext + 1].priority += THREE_CON;
					}
					else if (i == 2) {
						pan[j][i].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += THREE_CON;
					}
					else if (i == 16) {
						pan[j][i].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 1) {
					if (i > 2 && i < 16) {
						pan[j][iNext].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
					}
					else if (i == 2) {
						pan[j][iNext].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += FOUR_CON;
					}
					else if (i == 16) {
						pan[j][iNext].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[j][i].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iPprev].stone == 1 && pan[j][iNnext].stone == 1) {
					if (black < 5) {
						black = 5;
					}
				}
			}
			if (pan[j][i].stone == 2) {
				if (i >0 && i < 18) {
					pan[j][i - 1].priority += ONE_CON;
					pan[j][i + 1].priority += ONE_CON;
				}
				else if (i == 0) {
					pan[j][i + 1].priority += ONE_CON;
				}
				else if (i == 18) {
					pan[j][i - 1].priority += ONE_CON;
				}
				if (white < 1) {
					white = 1;

				}
			}

			if (pan[j][i].stone == 2 && pan[j][iNext].stone == 2) {
				if (i > 0 && i < 17) {
					pan[j][i - 1].priority += TWO_CON;
					pan[j][iNext + 1].priority += TWO_CON;
				}
				else if (i == 0) {
					pan[j][iNext + 1].priority += TWO_CON;
				}
				else if (i == 17) {
					pan[j][i - 1].priority += TWO_CON;
				}
				if (white < 2) {
					white = 2;
				}
			}
			if (pan[j][i].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][iNext].stone == 2 ||
				pan[j][iPrev].stone == 2 && pan[j][i].stone == 0 && pan[j][iNext].stone == 2 ||
				pan[j][iPrev].stone == 2 && pan[j][i].stone == 3 && pan[j][iNext].stone == 2 ||
				pan[j][iPrev].stone == 0 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 ||
				pan[j][iPrev].stone == 3 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 ||
				pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 0 ||
				pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 3) {
				if (white < 3) {
					white = 3;
				}
				if (pan[j][iPrev].stone == 2 && pan[j][i].stone == 0 && pan[j][iNext].stone == 2 ||
					pan[j][iPrev].stone == 2 && pan[j][i].stone == 3 && pan[j][iNext].stone == 2) {
					if (i > 1 && i < 17) {
						pan[j][i].priority += TWO_CON;
						pan[j][iPrev - 1].priority += TWO_CON;
						pan[j][iNext + 1].priority += TWO_CON;
					}
					else if (i == 1) {
						pan[j][i].priority += TWO_CON;
						pan[j][iNext + 1].priority += TWO_CON;
					}
					else if (i == 17) {
						pan[j][i].priority += TWO_CON;
						pan[j][iPrev - 1].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
				if (pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2) {
					if (i > 1 && i < 17) {
						pan[j][iPrev - 1].priority += THREE_CON;
						pan[j][iNext + 1].priority += THREE_CON;
					}
					else if (i == 1) {
						pan[j][iNext + 1].priority += THREE_CON;
					}
					else if (i == 17) {
						pan[j][iPrev - 1].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 0 ||
					pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 3) {
					if (i > 1 && i < 17) {
						//pan[j][iNext].stone = 3;
						pan[j][iNext].priority += TWO_CON;
						pan[j][iPrev - 1].priority += TWO_CON;
					}
					if (i == 1) {
						pan[j][iNext].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
			}
			if (pan[j][i].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iPprev].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 0 && pan[j][iNext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 3 && pan[j][iNext].stone == 2 ||
				pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 ||
				pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 0 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 3) {
				if (white < 4) {
					white = 4;
				}
				if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2) {

					if (i > 2 && i < 17) {
						pan[j][iPrev].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
						pan[j][iNext + 1].priority += THREE_CON;
					}
					else if (i == 2) {
						pan[j][iPrev].priority += THREE_CON;
						pan[j][iNext + 1].priority += THREE_CON;
					}
					else if (i == 17) {
						pan[j][iPrev].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 0 && pan[j][iNext].stone == 2 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 3 && pan[j][iNext].stone == 2) {
					if (i > 2 && i < 17) {
						pan[j][i].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
						pan[j][iNext + 1].priority += THREE_CON;
					}
					else if (i == 2) {
						pan[j][i].priority += THREE_CON;
						pan[j][iNext + 1].priority += THREE_CON;
					}
					else if (i == 17) {
						pan[j][i].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 ||
					pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2) {
					if (i >= 2 && i < 17) {
						pan[j][iNext + 1].priority += THREE_CON;
						pan[j][iPprev].priority += THREE_CON;
					}
					if (i == 17) {
						pan[j][iPprev].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 0 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 3) {
					if (i > 2 && i <= 17) {
						pan[j][iNext].stone = 3;
						pan[j][iNext].priority += THREE_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
					}
					if (i == 2) {
						pan[j][iNext].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
			}


			if (pan[j][i].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iPprev].stone == 2 && pan[j][iNnext].stone == 2 ||
				pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2 ||
				pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 0 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 3 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 0 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 3 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 2 ||
				pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 2 ||
				pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 0 ||
				pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 3) {
				if (white < 5) {
					white = 5;
				}
				if (pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2) {
					if (i >= 2 && i < 16) {

						pan[j][iPprev].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += FOUR_CON;
					}
					else if (i == 16) {
						pan[j][iPprev].priority += FOUR_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 0 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 3) {
					if (i > 2 && i <= 16) {
						pan[j][iNnext].stone = 3;
						pan[j][iNnext].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += FOUR_CON;
					}
					if (i == 2) {
						pan[j][iNnext].priority += FOUR_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2) {
					if (i > 2 && i < 16) {
						pan[j][iPrev].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
						pan[j][iNnext + 1].priority += THREE_CON;
					}
					else if (i == 2) {
						pan[j][iPrev].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += FOUR_CON;
					}
					else if (i == 16) {
						pan[j][iPrev].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += FOUR_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 0 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 3 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 2) {
					if (i > 2 && i < 16) {
						pan[j][i].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
						pan[j][iNnext + 1].priority += THREE_CON;
					}
					else if (i == 2) {
						pan[j][i].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += THREE_CON;
					}
					else if (i == 16) {
						pan[j][i].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += THREE_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 2) {
					if (i>2 && i<16) {
						pan[j][iNext].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += FOUR_CON;
					}
					else if (i == 2) {
						pan[j][iNext].priority += FOUR_CON;
						pan[j][iNnext + 1].priority += FOUR_CON;
					}
					else if (i == 16) {
						pan[j][iNext].priority += FOUR_CON;
						pan[j][iPprev - 1].priority += FOUR_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 0 ||
					pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 2 && pan[j][i].stone == 2 && pan[j][iNext].stone == 2 && pan[j][iNnext].stone == 3) {
					if (i >= 2 && i <= 16) {
						pan[j][iPprev].stone = 3;
						pan[j][iPprev].priority += THREE_CON;
						pan[j][iNnext].stone = 3;
						pan[j][iNnext].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
			}
		}
		//if (black < white) {
		//	printf("가로 %d줄의 백돌이 %d개로 연속됩니다.\n", j, white);
		//}
		//else if (black > white) {
		//	printf("가로 %d줄의 흑돌이 %d개로 연속됩니다.\n", j, black);
		//}
		black = 0;
		white = 0;
	}
}
void findDiagonalContinueCount(PAN pan[SIZE_2013180016][SIZE_2013180016]) {
	int i = 0;
	int j = 0;
	int k = 0;
	int dNext = 1;
	int dPrev = 1;
	int dPprev = 1;
	int diagonal = 0;
	int black = 0;
	int white = 0;
	int count = 17;
	int colum = 1;
	int space = 1;


	while (diagonal <= 18) {
		diagonal = colum + 1;
		for (i = 0; i <= count; i++) {
			if (pan[i + colum][i].stone == 1) {
				if (i > 0 && i + colum < 18) {
					pan[i + colum + 1][i + 1].priority += ONE_CON;
					pan[i + colum - 1][i - 1].priority += ONE_CON;
				}
				else if (i == 0) {
					pan[i + colum + 1][i + 1].priority += ONE_CON;
				}
				else if (i == 18) {
					pan[i + colum - 1][i - 1].priority += ONE_CON;
				}
				if (black < 1) {
					black = 1;
				}
			}
			if (pan[i][i + colum].stone == 1) {
				if (i + colum > 0 && i < count - 1) {
					pan[i + 1][i + colum + 1].priority += ONE_CON;
					pan[i - 1][i + colum - 1].priority += ONE_CON;
				}
				else if (i == 0) {
					pan[i + 1][i + colum + 1].priority += ONE_CON;
				}
				else if (i == count - 1) {
					pan[i - 1][i + colum - 1].priority += ONE_CON;
				}
				if (black < 1) {
					black = 1;
				}
			}
			if (pan[i + dNext][i + colum + dNext].stone == 1 && pan[i][i + colum].stone == 1) {
				if (i > 0 && i < count - 2) {
					pan[i + dNext + 1][i + colum + dNext + 1].priority += TWO_CON;
					pan[i - 1][i + colum - 1].priority += TWO_CON;
				}
				else if (i == 0) {
					pan[i + dNext + 1][i + colum + dNext + 1].priority += TWO_CON;
				}
				else if (i == count - 2) {
					pan[i - 1][i + colum - 1].priority += TWO_CON;
				}

				if (black < 2) {
					black = 2;
				}
			}
			if (pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1) {
				if (i > 0 && i < count - 2) {
					pan[i + colum - 1][i - 1].priority += TWO_CON;
					pan[i + colum + dNext + 1][i + dNext + 1].priority += TWO_CON;
				}
				else if (i == 0) {
					pan[i + colum + dNext + 1][i + dNext + 1].priority += TWO_CON;
				}
				else if (i == count - 2) {
					pan[i + colum - 1][i - 1].priority += TWO_CON;
				}
				if (black < 2) {
					black = 2;
				}
			}
			if (pan[i][i + colum].stone == 1 && pan[i + dNext][i + colum + dNext].stone == 1 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 1 ||
				pan[i][i + colum].stone == 0 && pan[i + dNext][i + colum + dNext].stone == 1 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 1 ||
				pan[i][i + colum].stone == 3 && pan[i + dNext][i + colum + dNext].stone == 1 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 1 ||
				pan[i][i + colum].stone == 1 && pan[i + dNext][i + colum + dNext].stone == 0 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 1 ||
				pan[i][i + colum].stone == 1 && pan[i + dNext][i + colum + dNext].stone == 3 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 1 ||
				pan[i][i + colum].stone == 1 && pan[i + dNext][i + colum + dNext].stone == 1 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 0 ||
				pan[i][i + colum].stone == 1 && pan[i + dNext][i + colum + dNext].stone == 1 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 3) {
				if (black < 3) {
					black = 3;
				}

				if (pan[i][i + colum].stone == 0 && pan[i + dNext][i + colum + dNext].stone == 1 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 1 ||
					pan[i][i + colum].stone == 3 && pan[i + dNext][i + colum + dNext].stone == 1 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 1) {
					//pan[i][i + colum] = 3;
					pan[i][i + colum].priority += TWO_CON;
					if (i < count - 3) {
						pan[i + dNext + dPrev + 1][i + dPrev + dNext + colum + 1].priority += TWO_CON;
					}
					black--;
				}
				if (pan[i][i + colum].stone == 1 && pan[i + dNext][i + colum + dNext].stone == 0 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 1 ||
					pan[i][i + colum].stone == 1 && pan[i + dNext][i + colum + dNext].stone == 3 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 1) {
					//pan[i + dNext][i + colum + dNext] = 3;
					pan[i + dNext][i + colum + dNext].priority += TWO_CON;
					if (i > 0 && i < count - 3) {
						pan[i - 1][i + colum - 1].priority += TWO_CON;
						pan[i + dNext + dPrev + 1][i + dPrev + dNext + colum + 1].priority += TWO_CON;
					}
					else if (i == 0) {
						pan[i + dNext + dPrev + 1][i + dPrev + dNext + colum + 1].priority += TWO_CON;
					}
					else if (i == count - 3) {
						pan[i - 1][i + colum - 1].priority += TWO_CON;
					}
					black--;
				}
				if (pan[i][i + colum].stone == 1 && pan[i + dNext][i + colum + dNext].stone == 1 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 0 ||
					pan[i][i + colum].stone == 1 && pan[i + dNext][i + colum + dNext].stone == 1 && pan[i + dNext + dPrev][i + dPrev + dNext + colum].stone == 3) {
					//pan[i + dNext + dPrev][i + dPrev + dNext + colum] = 3;
					pan[i + dNext + dPrev][i + dPrev + dNext + colum].priority += TWO_CON;
					if (i > 0) {
						pan[i - 1][i + colum - 1].priority += TWO_CON;
					}
					black--;
				}
			}
			if (pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 1 ||
				pan[i + colum][i].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 1 ||
				pan[i + colum][i].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 1 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 1 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 1 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 0 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 3) {
				if (black < 3) {
					black = 3;
				}
				if (pan[i + colum][i].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 1 ||
					pan[i + colum][i].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 1) {
					//pan[i + colum][i] = 3;
					pan[i + colum][i].priority += TWO_CON;
					if (i < count - 3) {
						pan[i + colum + dNext + dPrev + 1][i + dNext + dPrev + 1].priority += TWO_CON;
					}
					black = 2;
				}
				if (pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 1 ||
					pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 1) {
					//pan[i + colum + dNext][i + dNext] = 3;
					pan[i + colum + dNext][i + dNext].priority += TWO_CON;
					if (i > 0 && i < count - 3) {
						pan[i + colum - 1][i - 1].priority += TWO_CON;
						pan[i + colum + 1 + dNext + dPrev][i + 1 + dNext + dPrev].priority += TWO_CON;
					}
					else if (i == 0) {
						pan[i + colum + 1 + dNext + dPrev][i + 1 + dNext + dPrev].priority += TWO_CON;
					}
					else if (i == count - 3) {
						pan[i + colum - 1][i - 1].priority += TWO_CON;
					}
					black = 2;
				}
				if (pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 0 ||
					pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 3) {
					//pan[i + colum + dNext + dPrev][i + dNext + dPrev] = 3;
					pan[i + colum + dNext + dPrev][i + dNext + dPrev].priority += TWO_CON;
					if (i > 0) {
						pan[i + colum - 1][i - 1].priority += TWO_CON;
					}
					black = 2;
				}

			}
			if (pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1
				&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
				pan[i][i + colum].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 1
				&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
				pan[i][i + colum].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 1
				&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
				pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 0
				&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
				pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 3
				&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
				pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1
				&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 0 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
				pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1
				&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 3 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
				pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1
				&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 0 ||
				pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1
				&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 3) {
				if (black < 4) {
					black = 4;
				}
				if (pan[i][i + colum].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 1
					&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
					pan[i][i + colum].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 1
					&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1) {
					pan[i][i + colum].stone = 3;
					pan[i][i + colum].priority += THREE_CON;
					if (i < count - 4) {
						pan[i + colum + dPprev + dNext + dPrev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					black = 3;
				}
				if (pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 0
					&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
					pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 3
					&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1) {
					pan[i + colum + dNext][i + dNext].stone = 3;
					pan[i + colum + dNext][i + dNext].priority += THREE_CON;
					if (i > 0 && i < count - 4) {
						pan[i - 1][i + colum - 1].priority += THREE_CON;
						pan[i + colum + dPprev + dNext + dPrev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					black = 3;
				}
				if (pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1
					&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 0 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1 ||
					pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1
					&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 3 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 1) {
					pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone = 3;
					pan[i + colum + dPrev + dNext][i + dPrev + dNext].priority += THREE_CON;
					if (i > 0 && i < count - 4) {
						pan[i - 1][i + colum - 1].priority += THREE_CON;
						pan[i + colum + dPprev + dNext + dPrev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + colum + dPprev + dNext + dPrev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == count - 4) {
						pan[i + colum + dPprev + dNext + dPrev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					black = 3;
				}
				if (pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1
					&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 0 ||
					pan[i][i + colum].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1
					&& pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone == 3) {
					pan[i + colum + dPprev + dNext + dPrev][i + dPrev + dPprev].stone = 3;
					pan[i + colum + dPrev + dNext + dPrev][i + dPrev + dPprev].priority += THREE_CON;
					if (i > 0) {
						pan[i - 1][i + colum - 1].priority += THREE_CON;
					}
					black = 3;
				}
			}
			if (pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
				&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
				pan[i + colum][i].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
				&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
				pan[i + colum][i].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
				&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
				&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
				&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 0
				&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 3
				&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
				&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 0 ||
				pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
				&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 3) {
				if (black < 4) {
					black = 4;
				}
				if (pan[i + colum][i].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
					&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
					pan[i + colum][i].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
					&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1) {
					//pan[i + colum][i].stone = 3;
					pan[i + colum][i].priority += THREE_CON;
					if (i < count - 4) {
						pan[i + colum + dPprev + dNext + 1 + 1][i + dNext + dPrev + dPprev + 1].priority += THREE_CON;
					}
					black = 3;
				}
				if (pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
					&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
					pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
					&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1) {
					pan[i + colum + dNext][i + dNext].stone = 3;
					pan[i + colum + dNext][i + dNext].priority += THREE_CON;
					if (i > 0 && i < count - 4) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
						pan[i + colum + dPprev + dNext + 1 + 1][i + dNext + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + colum + dPprev + dNext + 1 + 1][i + dNext + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == count - 4) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
					}
					black = 3;
				}
				if (pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 0
					&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1 ||
					pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 3
					&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 1) {
					pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone = 3;
					pan[i + colum + dPrev + dNext][i + dPrev + dNext].priority += THREE_CON;
					if (i > 0 && i < count - 4) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
						pan[i + colum + dPprev + dNext + 1 + 1][i + dNext + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + colum + dPprev + dNext + 1 + 1][i + dNext + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == count - 4) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
					}
					black = 3;
				}
				if (pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
					&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 0 ||
					pan[i + colum][i].stone == 1 && pan[i + colum + dNext][i + dNext].stone == 1 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 1
					&& pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone == 3) {
					pan[i + colum + dPprev + dNext + 1][i + dNext + dPrev + dPprev].stone = 3;
					pan[i + colum + dPrev + dNext + 1][i + dNext + dPrev + dPprev].priority += THREE_CON;
					if (i > 0) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
					}
					black = 3;
				}
			}
			if (pan[i + colum][i].stone == 2) {
				if (i > 0 && i < count) {
					pan[i + colum - 1][i - 1].priority += ONE_CON;
					pan[i + colum + 1][i + 1].priority += ONE_CON;
				}
				else if (i == 0) {
					pan[i + colum + 1][i + 1].priority += ONE_CON;
				}
				else if (i == count) {
					pan[i + colum - 1][i - 1].priority += ONE_CON;
				}
				if (white < 1) {
					white = 1;
				}
			}
			if (pan[i][i + colum].stone == 2) {
				if (i > 0 && i < count - 1) {
					pan[i - 1][i + colum - 1].priority += ONE_CON;
					pan[i + 1][i + colum + 1].priority += ONE_CON;
				}
				else if (i == 0) {
					pan[i + 1][i + colum + 1].priority += ONE_CON;
				}
				else if (i == count - 1) {
					pan[i - 1][i + colum - 1].priority += ONE_CON;
				}
				if (white < 1) {
					white = 1;
				}
			}
			if (pan[i + dNext][i + colum + dNext].stone == 2 && pan[i][i + colum].stone == 2) {
				if (i > 0 && i < count - 2) {
					pan[i + dNext + 1][i + colum + dNext + 1].priority += TWO_CON;
					pan[i - 1][i + colum - 1].priority += TWO_CON;
				}
				else if (i == 0) {
					pan[i + dNext + 1][i + colum + dNext + 1].priority += TWO_CON;
				}
				else if (i == count - 2) {
					pan[i - 1][i + colum - 1].priority += TWO_CON;
				}
				if (white < 2) {
					white = 2;
				}
			}
			if (pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2) {
				if (i > 0 && i < count - 2) {
					pan[i + colum + dNext + 1][i + dNext + 1].priority += TWO_CON;
					pan[i + colum - 1][i - 1].priority += TWO_CON;
				}
				if (white < 2) {
					white = 2;
				}
			}
			if (pan[i][i + colum].stone == 2 && pan[i + dNext][i + colum + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 2 ||
				pan[i][i + colum].stone == 0 && pan[i + dNext][i + colum + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 2 ||
				pan[i][i + colum].stone == 3 && pan[i + dNext][i + colum + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 2 ||
				pan[i][i + colum].stone == 2 && pan[i + dNext][i + colum + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 2 ||
				pan[i][i + colum].stone == 2 && pan[i + dNext][i + colum + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 2 ||
				pan[i][i + colum].stone == 2 && pan[i + dNext][i + colum + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 0 ||
				pan[i][i + colum].stone == 2 && pan[i + dNext][i + colum + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 3) {
				if (white < 3) {
					white = 3;
				}
				if (pan[i][i + colum].stone == 0 && pan[i + dNext][i + colum + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 2 ||
					pan[i][i + colum].stone == 3 && pan[i + dNext][i + colum + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 2) {
					//pan[i][i + colum] = 3;
					pan[i][i + colum].priority += TWO_CON;
					if (i < count - 3) {
						pan[i + dPrev + dNext + 1][i + dPrev + colum + dNext + 1].priority += TWO_CON;
					}
					white = 2;
				}
				if (pan[i][i + colum].stone == 2 && pan[i + dNext][i + colum + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 2 ||
					pan[i][i + colum].stone == 2 && pan[i + dNext][i + colum + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 2) {
					//pan[i + dNext][i + colum + dNext] = 3;
					pan[i + dNext][i + colum + dNext].priority += TWO_CON;
					if (i > 0 && i < count - 3) {
						pan[i - 1][i + colum - 1].priority += TWO_CON;
						pan[i + dPrev + dNext + 1][i + dPrev + colum + dNext + 1].priority = TWO_CON;
					}
					else if (i == 0) {
						pan[i + dPrev + dNext + 1][i + dPrev + colum + dNext + 1].priority = TWO_CON;
					}
					else if (i == count - 3) {
						pan[i - 1][i + colum - 1].priority += TWO_CON;
					}
					white = 2;
				}
				if (pan[i][i + colum].stone == 2 && pan[i + dNext][i + colum + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 0 ||
					pan[i][i + colum].stone == 2 && pan[i + dNext][i + colum + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + colum + dNext].stone == 3) {
					//pan[i + dPrev + dNext][i + dPrev + colum + dNext] = 3;
					pan[i + dPrev + dNext][i + dPrev + colum + dNext].priority += TWO_CON;
					if (i > 0) {
						pan[i - 1][i + colum - 1].priority += TWO_CON;
					}
					white = 2;
				}
			}
			if (pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
				pan[i + colum][i].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
				pan[i + colum][i].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 0 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 3) {
				if (white < 3) {
					white = 3;
				}
				if (pan[i + colum][i].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
					pan[i + colum][i].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 2) {
					//pan[i + colum][i] = 3;
					pan[i + colum][i].priority += TWO_CON;
					if (i < count - 3) {
						pan[i + colum + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += TWO_CON;
					}
					white = 2;
				}
				if (pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
					pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 2) {
					//pan[i + colum + dNext][i + dNext] = 3;
					pan[i + colum + dNext][i + dNext].priority += TWO_CON;
					if (i > 0 && i < count - 3) {
						pan[i + colum - 1][i - 1].priority += TWO_CON;
						pan[i + colum + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += TWO_CON;
					}
					else if (i == 0) {
						pan[i + colum + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += TWO_CON;
					}
					else if (i == count - 3) {
						pan[i + colum - 1][i - 1].priority += TWO_CON;
					}
					white = 2;
				}
				if (pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 0 ||
					pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dPrev + dNext][i + dPrev + dNext].stone == 3) {
					//pan[i + colum + dPrev + dNext][i + dPrev + dNext] = 3;
					pan[i + colum + dPrev + dNext][i + dPrev + dNext].priority += TWO_CON;
					if (i > 0) {
						pan[i + colum - 1][i - 1].priority += TWO_CON;
					}
					white = 2;
				}
			}
			if (pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
				pan[i][i + colum].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
				pan[i][i + colum].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
				pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
				pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
				pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 0
				&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
				pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 3
				&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
				pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 0 ||
				pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 3) {
				if (white < 4) {
					white = 4;
				}
				if (pan[i][i + colum].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
					pan[i][i + colum].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2) {
					pan[i][i + colum].stone = 3;
					pan[i][i + colum].priority += THREE_CON;
					if (i < count - 3) {
						pan[i + colum + dPrev + dPprev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					white = 3;
				}
				if (pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
					pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2) {
					pan[i + colum + dNext][i + dNext].stone = 3;
					pan[i + colum + dNext][i + dNext].priority += THREE_CON;
					if (i > 0 && i < count - 3) {
						pan[i - 1][i + colum - 1].priority += THREE_CON;
						pan[i + colum + dPrev + dPprev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + colum + dPrev + dPprev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == count - 3) {
						pan[i - 1][i + colum - 1].priority += THREE_CON;
					}
					white = 3;
				}
				if (pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 0
					&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2 ||
					pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 3
					&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 2) {
					pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone = 3;
					pan[i + colum + dNext + dPrev][i + dNext + dPrev].priority += THREE_CON;
					if (i > 0 && i < count - 3) {
						pan[i - 1][i + colum - 1].priority += THREE_CON;
						pan[i + colum + dPrev + dPprev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + colum + dPrev + dPprev + 1][i + dPrev + dPprev + 1].priority += THREE_CON;
					}
					else if (i == count - 3) {
						pan[i - 1][i + colum - 1].priority += THREE_CON;
					}
					white = 3;
				}
				if (pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 0 ||
					pan[i][i + colum].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone == 3) {
					pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].stone = 3;
					pan[i + colum + dPrev + dPprev][i + dPrev + dPprev].priority += THREE_CON;
					if (i > 0) {
						pan[i - 1][i + colum - 1].priority += THREE_CON;
					}
					white = 3;
				}

			}
			if (pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
				pan[i + colum][i].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
				pan[i + colum][i].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 0
				&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 3
				&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 0 ||
				pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
				&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 3) {
				if (white < 4) {
					white = 4;
				}
				if (pan[i + colum][i].stone == 0 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
					pan[i + colum][i].stone == 3 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2) {
					pan[i + colum][i].stone = 3;
					pan[i + colum][i].priority += THREE_CON;
					if (i < count - 4) {
						pan[i + colum + dPrev + dNext + dPprev + 1][i + dPrev + dNext + dPprev + 1].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 0 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
					pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 3 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2) {
					pan[i + colum + dNext][i + dNext].stone = 3;
					pan[i + colum + dNext][i + dNext].priority += THREE_CON;
					if (i > 0 && i < count - 4) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
						pan[i + colum + dPrev + dNext + dPprev + 1][i + dPrev + dNext + dPprev + 1].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + colum + dPrev + dNext + dPprev + 1][i + dPrev + dNext + dPprev + 1].priority += THREE_CON;
					}
					else if (i == count - 4) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 0
					&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2 ||
					pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 3
					&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 2) {
					pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone = 3;
					pan[i + colum + dNext + dPrev][i + dNext + dPrev].priority += THREE_CON;
					if (i > 0 && i < count - 4) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
						pan[i + colum + dPrev + dNext + dPprev + 1][i + dPrev + dNext + dPprev + 1].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + colum + dPrev + dNext + dPprev + 1][i + dPrev + dNext + dPprev + 1].priority += THREE_CON;
					}
					else if (i == count - 4) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 0 ||
					pan[i + colum][i].stone == 2 && pan[i + colum + dNext][i + dNext].stone == 2 && pan[i + colum + dNext + dPrev][i + dNext + dPrev].stone == 2
					&& pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone == 3) {
					pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].stone = 3;
					pan[i + colum + dPrev + dNext + dPprev][i + dPrev + dNext + dPprev].priority += THREE_CON;
					if (i > 0) {
						pan[i + colum - 1][i - 1].priority += THREE_CON;
					}

					if (white < 3) {
						white = 3;
					}
				}
			}

		}

		/*if (black > white) {
		printf("우대각선%d줄에 흑돌이 %d개 연속됩니다. \n", colum + 1, black);
		}
		else if (black < white) {
		printf("우대각선 %d줄에 백돌이 %d개 연속됩니다.\n", colum + 1, white);
		}*/
		black = 0;
		white = 0;

		count--;
		colum++;

	}


}
void findOneDiagonal(PAN pan[SIZE_2013180016][SIZE_2013180016]) {

	int i = 0;
	int j = 0;
	int k = 0;
	int dNext = 1;
	int dPrev = 1;
	int dPprev = 1;
	int diagonal = 0;
	int black = 0;
	int white = 0;
	int count = 17;
	int colum = 1;
	for (i = 0; i < 19; i++) {

		if (pan[i][i].stone == 1) {
			if (i > 0 && i < 19) {
				pan[i - 1][i - 1].priority += ONE_CON;
				pan[i + 1][i + 1].priority += ONE_CON;
			}
			else if (i == 0) {
				pan[i + 1][i + 1].priority += ONE_CON;
			}
			else if (i == 19) {
				pan[i - 1][i - 1].priority += ONE_CON;
			}
			if (black < 1) {
				black = 1;
			}
		}
		if (pan[i][i].stone == 2) {
			if (i > 0 && i < 19) {
				pan[i - 1][i - 1].priority += ONE_CON;
				pan[i + 1][i + 1].priority += ONE_CON;
			}
			else if (i == 0) {
				pan[i + 1][i + 1].priority += ONE_CON;
			}
			else if (i == 19) {
				pan[i - 1][i - 1].priority += ONE_CON;
			}
			if (white < 1) {
				white = 1;
			}
		}
		if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1) {
			if (i > 0 && i < 18) {
				pan[i - 1][i - 1].priority += TWO_CON;
				pan[i + dNext + 1][i + dNext + 1].priority += TWO_CON;
			}
			else if (i == 0) {
				pan[i + dNext + 1][i + dNext + 1].priority += TWO_CON;
			}
			else if (i == 18) {
				pan[i - 1][i - 1].priority += TWO_CON;
			}
			if (black < 2) {
				black = 2;
			}
		}
		if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2) {
			if (i > 0 && i < 18) {
				pan[i - 1][i - 1].priority += TWO_CON;
				pan[i + dNext + 1][i + dNext + 1].priority += TWO_CON;
			}
			else if (i == 0) {
				pan[i + dNext + 1][i + dNext + 1].priority += TWO_CON;
			}
			else if (i == 18) {
				pan[i - 1][i - 1].priority += TWO_CON;
			}
			if (white< 2) {
				white = 2;
			}
		}
		if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 ||
			pan[i][i].stone == 0 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 ||
			pan[i][i].stone == 3 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 0 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 3) {
			if (black < 3) {
				black = 3;
			}
			if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1) {
				if (i > 0 && i < 17) {
					pan[i - 1][i - 1].priority += THREE_CON;
					pan[i + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += THREE_CON;
				}
				else if (i == 0) {
					pan[i + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += THREE_CON;
				}
				else if (i == 17) {
					pan[i - 1][i - 1].priority = THREE_CON;
				}
			}
			if (pan[i][i].stone == 0 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 ||
				pan[i][i].stone == 3 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1) {
				//pan[i][i] = 3;
				pan[i][i].priority += TWO_CON;
				if (i < 17) {
					pan[i + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += TWO_CON;
				}
				black = 2;
			}
			if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 ||
				pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1) {
				if (i <= 16) {
					//pan[i + dNext][i + dNext] = 3;
					pan[i + dNext][i + dNext].priority += TWO_CON;
				}
				if (i > 0 && i < 16) {
					pan[i - 1][i - 1].priority += TWO_CON;
					pan[i + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += TWO_CON;
				}
				else if (i == 0) {
					pan[i + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += TWO_CON;
				}
				else if (i == 16) {
					pan[i - 1][i - 1].priority += TWO_CON;
				}
				black = 2;
			}
			if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 0 ||
				pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 3) {
				if (i <= 16) {
					//pan[i + dPrev + dNext][i + dPrev + dNext] = 3;
					pan[i + dPrev + dNext][i + dPrev + dNext].priority += TWO_CON;
				}
				if (i > 0) {
					pan[i - 1][i - 1].priority += TWO_CON;
				}
				black = 2;
			}
		}
		if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
			pan[i][i].stone == 0 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
			pan[i][i].stone == 3 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 0 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 3) {
			if (white < 3) {
				white = 3;
			}
			if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2) {
				if (i > 0 && i < 17) {
					pan[i - 1][i - 1].priority += THREE_CON;
					pan[i + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += THREE_CON;
				}
				else if (i == 0) {
					pan[i + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += THREE_CON;
				}
				else if (i == 16) {
					pan[i - 1][i - 1].priority = THREE_CON;
				}
			}
			if (pan[i][i].stone == 0 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
				pan[i][i].stone == 3 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2) {
				if (i <= 16) {
					//pan[i][i] = 3;
					pan[i][i].priority += TWO_CON;
				}
				if (i < 16) {
					pan[i + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += TWO_CON;
				}
				if (white < 2) {
					white = 2;
				}
			}
			if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2 ||
				pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2) {

				if (i <= 16) {
					//pan[i + dNext][i + dNext] = 3;
					pan[i + dNext][i + dNext].priority += TWO_CON;
				}
				if (i > 0 && i < 17) {
					pan[i - 1][i - 1].priority += TWO_CON;
				}
				else if (i == 0) {
					pan[i + dPrev + dNext + 1][i + dPrev + dNext + 1].priority += TWO_CON;
				}
				else if (i == 16) {
					pan[i - 1][i - 1].priority += TWO_CON;
				}
				if (white < 2) {
					white = 2;
				}
			}
			if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 0 ||
				pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 3) {
				//pan[i + dPrev + dNext][i + dPrev + dNext] = 3;
				if (i <= 16) {
					pan[i + dPrev + dNext][i + dPrev + dNext].priority += TWO_CON;
				}
				if (i > 0) {
					pan[i - 1][i - 1].priority += TWO_CON;
				}
				if (white < 2) {
					white = 2;
				}
			}
		}
		if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
			dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
			pan[i][i].stone == 0 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
			dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
			pan[i][i].stone == 3 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
			dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
			dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
			dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 0 && pan[i + dNext +
			dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 3 && pan[i + dNext +
			dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
			dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 0 ||
			pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
			dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 3) {
			if (black < 4) {
				black = 4;
			}
			if (pan[i][i].stone == 0 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
				dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
				pan[i][i].stone == 3 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
				dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1) {
				if (i <= 15) {
					pan[i][i].stone = 3;
					pan[i][i].priority += THREE_CON;
				}
				if (i < 15) {
					pan[i + dNext + dPprev + dPrev + 1][i + dPrev + dPprev + dNext + 1].priority += THREE_CON;
				}
				if (black < 3) {
					black = 3;
				}
			}
			if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
				dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
				pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
				dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1) {
				if (i <= 15) {
					pan[i + dNext][i + dNext].stone = 3;
					pan[i + dNext][i + dNext].priority += THREE_CON;
				}
				if (i > 0 && i < 15) {
					pan[i - 1][i - 1].priority += THREE_CON;
					pan[i + dNext + dPprev + dPrev + 1][i + dPrev + dPprev + dNext + 1].priority += THREE_CON;
				}
				else if (i == 0) {
					pan[i + dNext + dPprev + dPrev][i + dPrev + dPprev + dNext].priority += THREE_CON;
				}
				else if (i == 15) {
					pan[i - 1][i - 1].priority += THREE_CON;
				}
				if (black < 3) {
					black = 3;
				}
			}
			if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 0 && pan[i + dNext +
				dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1 ||
				pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 3 && pan[i + dNext +
				dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1) {
				if (i <= 15) {
					pan[i + dPrev + dNext][i + dPrev + dNext].stone = 3;
					pan[i + dPrev + dNext][i + dPrev + dNext].priority += THREE_CON;
				}
				if (i > 0 && i < 15) {
					pan[i - 1][i - 1].priority += THREE_CON;
					pan[i + dNext + dPprev + dPrev + 1][i + dPrev + dPprev + dNext + 1].priority += THREE_CON;
				}
				else if (i == 0) {
					pan[i + dNext + dPprev + dPrev + 1][i + dPrev + dPprev + dNext + 1].priority += THREE_CON;
				}
				else if (i == 15) {
					pan[i - 1][i - 1].priority += THREE_CON;
				}
				if (black < 3) {
					black = 3;
				}
			}
			if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
				dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 0 ||
				pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
				dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 3) {
				if (i <= 15) {
					pan[i + dNext + dPprev + dPrev][i + dPrev + dPprev + dNext].stone = 3;
					pan[i + dNext + dPprev + dPrev][i + dPrev + dNext].priority += THREE_CON;
				}
				if (i > 0) {
					pan[i - 1][i - 1].priority += THREE_CON;
				}
				if (black < 3) {
					black = 3;
				}
			}
			if (pan[i][i].stone == 1 && pan[i + dNext][i + dNext].stone == 1 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 1 && pan[i + dNext +
				dPprev + dPrev][i + dPrev + dPprev + dNext].stone == 1) {
				if (i > 0 && i<15) {
					pan[i - 1][i - 1].priority += FOUR_CON;
					pan[i + 4][i + 4].priority += FOUR_CON;
				}
				else if (i == 0) {
					pan[i + 4][i + 4].priority += FOUR_CON;
				}
				else if (i == 15) {
					pan[i - 1][i - 1].priority += FOUR_CON;
				}
			}
		}
		if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
			&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
			pan[i][i].stone == 0 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
			&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
			pan[i][i].stone == 3 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
			&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
			&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
			&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 0
			&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 3
			&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
			&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 0 ||
			pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
			&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 3) {
			if (white < 4) {
				white = 4;
			}
			if (pan[i][i].stone == 0 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
				&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
				pan[i][i].stone == 3 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
				&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2) {
				if (i <= 15) {
					pan[i][i].stone = 3;
					pan[i][i].priority += THREE_CON;
				}
				if (i < 15) {
					pan[i + dNext + dPprev + dPrev + 1][i + dNext + dPprev + dPrev + 1].priority += THREE_CON;
				}
				if (white < 3) {
					white = 3;
				}
			}
			if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 0 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
				&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
				pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 3 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
				&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2) {
				if (i <= 15) {
					pan[i + dNext][i + dNext].stone = 3;
					pan[i + dNext][i + dNext].priority += THREE_CON;
				}
				if (i > 0 && i < 15) {
					pan[i - 1][i - 1].priority += THREE_CON;
					pan[i + dPrev + dPprev + dNext + 1][i + dNext + dPprev + dPrev + 1].priority += THREE_CON;
				}
				else if (i == 0) {
					pan[i + dPrev + dPprev + dNext + 1][i + dNext + dPprev + dPrev + 1].priority += THREE_CON;
				}
				else if (i == 15) {
					pan[i - 1][i - 1].priority += THREE_CON;
				}
				if (white < 3) {
					white = 3;
				}
			}
			if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 0
				&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2 ||
				pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 3
				&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2) {
				if (i <= 15) {
					pan[i + dPrev + dNext][i + dPrev + dNext].stone = 3;
					pan[i + dPrev + dNext][i + dPrev + dNext].priority += THREE_CON;
				}
				if (i > 0 && i < 15) {
					pan[i - 1][i - 1].priority += THREE_CON;
					pan[i + dPrev + dPprev + dNext + 1][i + dNext + dPprev + dPrev + 1].priority += THREE_CON;
				}
				else if (i == 0) {
					pan[i + dPrev + dPprev + dNext + 1][i + dNext + dPprev + dPrev + 1].priority += THREE_CON;
				}
				else if (i == 15) {
					pan[i - 1][i - 1].priority += THREE_CON;
				}
				if (white < 3) {
					white = 3;
				}
			}
			if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
				&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 0 ||
				pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
				&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 3) {
				if (i <= 15) {
					pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone = 3;
					pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].priority += THREE_CON;
				}
				if (i > 0) {
					pan[i - 1][i - 1].priority += THREE_CON;
				}
				if (white < 3) {
					white = 3;
				}
			}
			if (pan[i][i].stone == 2 && pan[i + dNext][i + dNext].stone == 2 && pan[i + dPrev + dNext][i + dPrev + dNext].stone == 2
				&& pan[i + dPrev + dPprev + dNext][i + dNext + dPprev + dPrev].stone == 2) {
				if (i > 0 && i<15) {
					pan[i - 1][i - 1].priority += FOUR_CON;
					pan[i + 4][i + 4].priority += FOUR_CON;
				}
				else if (i == 0) {
					pan[i + 4][i + 4].priority += FOUR_CON;
				}
				else if (i == 15) {
					pan[i - 1][i - 1].priority += FOUR_CON;
				}
			}
		}
	}
	/*if (black > white) {
	printf("우대각선%d줄에 흑돌이 %d개 연속됩니다. \n", 1, black);
	}
	else if (black < white) {
	printf("우대각선 %d줄에 백돌이 %d개 연속됩니다.\n", 1, white);
	}*/
}
void findLeftDiagonal(PAN pan[SIZE_2013180016][SIZE_2013180016]) {														//좌 주대각선 기준 위
	int black = 0;
	int white = 0;
	int count = 18;
	int colum = 18;
	int diagonal = 19;
	int i = 0;
	int dNext = 0;
	int dPrev = 0;
	int dPprev = 0;


	while (diagonal > 0) {
		diagonal = colum + 1;
		for (i = 0; i <= count; i++) {
			if (i<18 && i > 0) {
				dNext = 1;
			}
			if (i > 1) {
				dPrev = 1;
			}
			if (i > 2) {
				dPprev = 1;
			}
			if (pan[i][colum - i].stone == 1) {
				if (i > 0 && colum - i < 17) {
					pan[i + 1][colum - i - 1].priority += ONE_CON;
					pan[i - 1][colum - i + 1].priority += ONE_CON;
				}
				else if (i == 0) {
					pan[i + 1][colum - i - 1].priority += ONE_CON;
				}
				else if (i == 17) {
					pan[i - 1][colum - i + 1].priority += ONE_CON;
				}
				if (black < 1) {
					black = 1;
				}
			}
			if (pan[i][colum - i].stone == 2) {
				if (i > 0 && colum - i < 17) {
					pan[i + 1][colum - i - 1].priority += ONE_CON;
					pan[i - 1][colum - i + 1].priority += ONE_CON;
				}
				else if (i == 0) {
					pan[i + 1][colum - i - 1].priority += ONE_CON;
				}
				else if (i == 17) {
					pan[i - 1][colum - i + 1].priority += ONE_CON;
				}
				if (white < 1) {
					white = 1;
				}
			}
			if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1) {
				if (i > 1 && colum - i < 16) {
					pan[i - 1][colum - i + 1].priority += TWO_CON;
					pan[i + 2][colum - i - 2].priority += TWO_CON;
				}
				else if (i == 1) {
					pan[i + 2][colum - i - 2].priority += TWO_CON;
				}
				else if (i == 16) {
					pan[i - 1][colum - i + 1].priority += TWO_CON;
				}
				if (black < 2) {
					black = 2;
				}
			}
			if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2) {
				if (i > 1 && colum - i < 16) {
					pan[i - 1][colum - i + 1].priority += TWO_CON;
					pan[i + 2][colum - i - 2].priority += TWO_CON;
				}
				else if (i == 1) {
					pan[i + 2][colum - i - 2].priority += TWO_CON;
				}
				else if (i == 16) {
					pan[i - 1][colum - i + 1].priority += TWO_CON;
				}
				if (white < 2) {
					white = 2;
				}
			}
			if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1 ||
				pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1 ||
				pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3 ||
				pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0 ||
				pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3) {
				if (black < 3) {
					black = 3;
				}
				if (pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1 ||
					pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1) {
					//pan[i][colum - i] = 3;
					if (i >= 0 && colum - i - dNext - dPrev > 0) {
						pan[i][colum - i].priority += TWO_CON;
						pan[i + dNext + dPrev + 1][colum - i - dNext - dPrev - 1].priority += TWO_CON;
					}
					else if (colum - i - dNext - dPrev == 0) {
						pan[i][colum - i].priority += TWO_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}
				if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1 ||
					pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1) {
					// pan[i + dNext][colum - i - dNext] = 3;
					if (i > 0 && colum - i - dNext - dPrev > 0) {
						pan[i - 1][colum - i + 1].priority += TWO_CON;
						pan[i + dNext][colum - i - dNext].priority += TWO_CON;
						pan[i + 3][colum - i - 3].priority += TWO_CON;
					}
					else if (colum - i - dNext - dPrev == 0) {
						pan[i - 1][colum - i + 1].priority += TWO_CON;
						pan[i + dNext][colum - i - dNext].priority += TWO_CON;
					}
					else if (i > 0) {
						pan[i + 3][colum - i - 3].priority += TWO_CON;
						pan[i + dNext][colum - i - dNext].priority += TWO_CON;
					}

					if (black < 2) {
						black = 2;
					}
				}
				if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0 ||
					pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3) {
					//pan[i + dNext + dPrev][colum - i - dNext - dPrev] = 3;
					if (i > 0 && colum - i - dNext - dPrev >= 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += TWO_CON;
						pan[i - 1][colum - i + 1].priority += TWO_CON;
					}
					else if (i == 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += TWO_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}
				if (pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0 ||
					pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3) {
					if (i >= 0 && colum - i - dNext - dPrev >= 0) {
						pan[i][colum - i].priority += ONE_CON;
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += ONE_CON;
					}
				}
				if (black < 1) {
					black = 1;

				}
			}
			if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2 ||
				pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2 ||
				pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3 ||
				pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0) {
				if (white < 3) {
					white = 3;
				}
				if (pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2 ||
					pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2) {
					//pan[i][colum - i] = 3;
					if (i >= 0 && colum - i - dNext - dPrev > 0) {
						pan[i][colum - i].priority += TWO_CON;
						pan[i + dNext + dPrev + 1][colum - i - dNext - dPrev - 1].priority += TWO_CON;
					}
					else if (colum - i - dNext - dPrev == 0) {
						pan[i][colum - i].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
				if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2 ||
					pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2) {
					// pan[i + dNext][colum - i - dNext] = 3;
					if (i > 0 && colum - i - dNext - dPrev > 0) {
						pan[i - 1][colum - i + 1].priority += TWO_CON;
						pan[i + dNext][colum - i - dNext].priority += TWO_CON;
						pan[i + 3][colum - i - 3].priority += TWO_CON;
					}
					else if (colum - i - dNext - dPrev == 0) {
						pan[i - 1][colum - i + 1].priority += TWO_CON;
						pan[i + dNext][colum - i - dNext].priority += TWO_CON;
					}
					else if (i > 0) {
						pan[i + 3][colum - i - 3].priority += TWO_CON;
						pan[i + dNext][colum - i - dNext].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
				if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0 ||
					pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3) {
					//pan[i + dNext + dPrev][colum - i - dNext - dPrev] = 3;
					if (i > 0 && colum - i - dNext - dPrev >= 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += TWO_CON;
						pan[i - 1][colum - i + 1].priority += TWO_CON;
					}
					else if (i == 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
				if (pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0 ||
					pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3) {
					if (i >= 0 && colum - i - dNext - dPrev >= 0) {
						pan[i][colum - i].priority += ONE_CON;
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += ONE_CON;
					}
				}
			}
			if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
				pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
				pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 0 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 3) {
				if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev > 0) {
						pan[i - 1][colum - i - 1].priority += FOUR_CON;
						pan[i + 4][colum - i - 4].priority += FOUR_CON;
					}
					else if (i == 0) {
						pan[i + 4][colum - i - 4].priority += FOUR_CON;
					}
					else if (colum - i - dNext - dPrev - dPprev == 0) {
						pan[i - 1][colum - i - 1].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
					pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1) {
					// pan[i][colum - i].stone = 3;
					if (i >= 0 && colum - i - dNext - dPrev - dPprev > 0) {
						pan[i][colum - i].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (colum - i - dNext - dPrev - dPprev == 0) {
						pan[i][colum - i].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
					pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1) {
					//pan[i + dNext][colum - i - dNext].stone = 3;
					if (i>0 && colum - i - dNext - dPrev - dPprev>0) {
						pan[i + dNext][colum - i - dNext].priority += THREE_CON;
						pan[i - 1][colum - i + 1].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + dNext][colum - i - dNext].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (colum - i - dNext - dPrev - dPprev == 0) {
						pan[i + dNext][colum - i - dNext].priority += THREE_CON;
						pan[i - 1][colum - i + 1].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 ||
					pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev > 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += THREE_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (colum - i - dNext - dPrev - dPprev == 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += THREE_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
					}
					//pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone = 3;
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 0 ||
					pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 3) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev <= 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += THREE_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += THREE_CON;
					}
					//pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone = 3;
					if (black < 3) {
						black = 3;
					}
				}
			}
			if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
				pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
				pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 0 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 3) {
				if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev > 0) {
						pan[i - 1][colum - i - 1].priority += FOUR_CON;
						pan[i + 4][colum - i - 4].priority += FOUR_CON;
					}
					else if (i == 0) {
						pan[i + 4][colum - i - 4].priority += FOUR_CON;
					}
					else if (colum - i - dNext - dPrev - dPprev == 0) {
						pan[i - 1][colum - i - 1].priority += FOUR_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[i][colum - i].stone == 0 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
					pan[i][colum - i].stone == 3 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2) {
					if (i >= 0 && colum - i - dNext - dPrev - dPprev > 0) {
						pan[i][colum - i].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (colum - i - dNext - dPrev - dPprev == 0) {
						pan[i][colum - i].priority += THREE_CON;
					}
					//pan[i][colum - i].stone = 3;
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
					pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2) {
					if (i>0 && colum - i - dNext - dPrev - dPprev>0) {
						pan[i + dNext][colum - i - dNext].priority += THREE_CON;
						pan[i - 1][colum - i + 1].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + dNext][colum - i - dNext].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (colum - i - dNext - dPrev - dPprev == 0) {
						pan[i + dNext][colum - i - dNext].priority += THREE_CON;
						pan[i - 1][colum - i + 1].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 ||
					pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev > 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += THREE_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += THREE_CON;
						pan[i + 4][colum - i - 4].priority += THREE_CON;
					}
					else if (colum - i - dNext - dPrev - dPprev == 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += THREE_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 0 ||
					pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 3) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev <= 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += THREE_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
					}
					else if (i == 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
			}
			if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 0 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 3 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 0 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 3 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1) {
				/* if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 || pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 0 ||
				pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 || pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 3) {
				pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].priority += FOUR_CON;
				}*/
				if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 0 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1 ||
					pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 3 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev - 1 > 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += FOUR_CON;
						pan[i - 1][colum - i + 1].priority += THREE_CON;
						pan[i + dNext + dPrev + dPprev + 1 + 1][colum - i - dNext - dPrev - dPprev - 1 - 1].priority += THREE_CON;
						if (black < 4) {
							black = 4;
						}
					}
					else if (i == 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += FOUR_CON;
						pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].priority += THREE_CON;
						if (black < 3) {
							black = 3;
						}
					}
					else if (colum - i - dNext - dPrev - dPprev - 1 == 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += FOUR_CON;
						pan[i - 1][colum - i + 1].priority += THREE_CON;
						if (black < 3) {
							black = 3;
						}
					}

				}
				if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1 ||
					pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 1 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev - 1 > 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += FOUR_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
						pan[i + dNext + dPrev + dPprev + 1 + 1][colum - i - dNext - dPrev - dPprev - 1 - 1].priority += THREE_CON;
						if (black < 4) {
							black = 4;
						}
					}
					else if (i == 0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += FOUR_CON;
						pan[i + dNext + dPrev + dPprev + 1 + 1][colum - i - dNext - dPrev - dPprev - 1 - 1].priority += THREE_CON;
						if (black < 3) {
							black = 3;
						}
					}
					else if (colum - i - dNext - dPrev - dPprev - 1>0) {
						pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += FOUR_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
						if (black < 3) {
							black = 3;
						}
					}
				}
				if (pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1 ||
					pan[i][colum - i].stone == 1 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 1
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 1 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 1) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev - 1 > 0) {
						pan[i + dNext][colum - i - dNext].priority += FOUR_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
						pan[i + dNext + dPrev + 1][colum - i - dNext - dPrev - 1].priority += THREE_CON;
						if (black < 4) {
							black = 4;
						}
					}
					else if (i == 0) {
						pan[i + dNext][colum - i - dNext].priority += FOUR_CON;
						pan[i + dNext + dPrev + 1][colum - i - dNext - dPrev - 1].priority += THREE_CON;
						if (black < 3) {
							black = 3;
						}
					}
					else if (colum - i - dNext - dPrev - dPprev - 1 == 0) {
						pan[i + dNext][colum - i - dNext].priority += FOUR_CON;
						pan[i - 1][colum - i - 1].priority += THREE_CON;
						if (black < 3) {
							black = 3;
						}
					}

				}
			}
			if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 0 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 3 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 0 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 3 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2) {
				/* if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 0 ||
				pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
				&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 3) {
				pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].priority += FOUR_CON;
				}*/
				if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 0 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2 ||
					pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
					&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 3 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2) {
					if (i > 0 && colum - i - dNext - dPrev - dPprev - 1 > 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += FOUR_CON;
						pan[i - 1][colum - i + 1].priority += THREE_CON;
						pan[i + dNext + dPrev + dPprev + 1 + 1][colum - i - dNext - dPrev - dPprev - 1 - 1].priority += THREE_CON;
						if (white < 4) {
							white = 4;
						}
					}
					else if (i == 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += FOUR_CON;
						pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].priority += THREE_CON;
						if (white < 3) {
							white = 3;
						}
					}
					else if (colum - i - dNext - dPrev - dPprev - 1 == 0) {
						pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].priority += FOUR_CON;
						pan[i - 1][colum - i + 1].priority += THREE_CON;
						if (white < 3) {
							white = 3;
						}
					}
					if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 0
						&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2 ||
						pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 2 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 3
						&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2) {
						if (i > 0 && colum - i - dNext - dPrev - dPprev - 1 > 0) {
							pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += FOUR_CON;
							pan[i - 1][colum - i - 1].priority += THREE_CON;
							pan[i + dNext + dPrev + dPprev + 1 + 1][colum - i - dNext - dPrev - dPprev - 1 - 1].priority += THREE_CON;
							if (white < 4) {
								white = 4;
							}
						}
						else if (i == 0) {
							pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += FOUR_CON;
							pan[i + dNext + dPrev + dPprev + 1 + 1][colum - i - dNext - dPrev - dPprev - 1 - 1].priority += THREE_CON;
							if (white < 3) {
								white = 3;
							}
						}
						else if (colum - i - dNext - dPrev - dPprev - 1>0) {
							pan[i + dNext + dPrev][colum - i - dNext - dPrev].priority += FOUR_CON;
							pan[i - 1][colum - i - 1].priority += THREE_CON;
							if (white < 3) {
								white = 3;
							}
						}
						if (pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 0 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
							&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2 ||
							pan[i][colum - i].stone == 2 && pan[i + dNext][colum - i - dNext].stone == 3 && pan[i + dNext + dPrev][colum - i - dNext - dPrev].stone == 2
							&& pan[i + dNext + dPrev + dPprev][colum - i - dNext - dPrev - dPprev].stone == 2 && pan[i + dNext + dPrev + dPprev + 1][colum - i - dNext - dPrev - dPprev - 1].stone == 2) {
							if (i > 0 && colum - i - dNext - dPrev - dPprev - 1 > 0) {
								pan[i + dNext][colum - i - dNext].priority += FOUR_CON;
								pan[i - 1][colum - i - 1].priority += THREE_CON;
								pan[i + dNext + dPrev + 1][colum - i - dNext - dPrev - 1].priority += THREE_CON;
								if (white < 4) {
									white = 4;
								}
							}
							else if (i == 0) {
								pan[i + dNext][colum - i - dNext].priority += FOUR_CON;
								pan[i + dNext + dPrev + 1][colum - i - dNext - dPrev - 1].priority += THREE_CON;
								if (white < 3) {
									white = 3;
								}
							}
							else if (colum - i - dNext - dPrev - dPprev - 1 == 0) {
								pan[i + dNext][colum - i - dNext].priority += FOUR_CON;
								pan[i - 1][colum - i - 1].priority += THREE_CON;
								if (white < 3) {
									white = 3;
								}
							}
						}
					}
				}
			}
		}
		/*if (black > white) {
		printf("좌대각선%d줄에 흑돌이 %d개 연속됩니다. \n", colum -1, black);
		}
		else if (black < white) {
		printf("좌대각선 %d줄에 백돌이 %d개 연속됩니다.\n", colum -1, white);
		}*/
		black = 0;
		white = 0;
		count--;
		colum--;
	}
}
void findLDiagonal(PAN pan[SIZE_2013180016][SIZE_2013180016]) {											//좌 주대각선기준 아래
	int black = 0;
	int white = 0;
	int count = 18;
	int colum = 18;
	int diagonal = 19;
	int ver = 0;
	int i = 0;
	while (diagonal > 0) {
		diagonal = colum + 1;
		for (i = 0; i <= count; i++) {

			if (pan[i + ver][colum + 1 - i].stone == 1) {
				if (colum + 1 - i < 18 && i + ver < 18) {
					pan[i + ver - 1][colum + 1 - i + 1].priority += ONE_CON;
					pan[i + ver + 1][colum + 1 - i - 1].priority += ONE_CON;
				}
				else if (colum + 1 - i == 18) {
					pan[i + ver + 1][colum + 1 - i - 1].priority += ONE_CON;
				}
				else if (i + ver == 18) {
					pan[i + ver - 1][colum + 1 - i + 1].priority += ONE_CON;
				}
				if (black < 1) {
					black = 1;
				}
			}
			if (pan[i + ver][colum + 1 - i].stone == 2) {
				if (white < 1) {
					white = 1;
				}
				if (colum + 1 - i < 18 && i + ver < 18) {
					pan[i + ver - 1][colum + 1 - i + 1].priority += ONE_CON;
					pan[i + ver + 1][colum + 1 - i - 1].priority += ONE_CON;
				}
				else if (colum + 1 - i == 18) {
					pan[i + ver + 1][colum + 1 - i - 1].priority += ONE_CON;
				}
				else if (i + ver == 18) {
					pan[i + ver - 1][colum + 1 - i + 1].priority += ONE_CON;
				}
			}
			if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1) {
				if (i + ver + 1<18 && colum + 1 - i<18) {
					pan[i + ver - 1][colum + 1 - i + 1].priority += TWO_CON;
					pan[i + ver + 2][colum + 1 - i - 2].priority += TWO_CON;
				}
				else if (i + ver + 1 == 18) {
					pan[i + ver - 1][colum + 1 - i + 1].priority += TWO_CON;
				}
				else if (i + ver == 16) {
					pan[i + ver + 2][colum + 1 - i - 2].priority += TWO_CON;
				}
				if (black < 2) {
					black = 2;
				}
			}
			if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2) {
				if (i + ver + 1<18 && colum + 1 - i < 18) {
					pan[i + ver - 1][colum + 1 - i + 1].priority += TWO_CON;
					pan[i + ver + 2][colum + 1 - i - 2].priority += TWO_CON;
				}
				else if (i + ver + 1 == 18) {
					pan[i + ver - 1][colum + 1 - i + 1].priority += TWO_CON;
				}
				else if (colum + 1 - i == 18) {
					pan[i + ver + 2][colum + 1 - i - 2].priority += TWO_CON;
				}
				if (white < 2) {
					white = 2;
				}
			}
			if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 0 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 3 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 0 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 3 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 0 ||
				pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 3) {
				if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1) {
					if (i + ver + 2 < 18 && colum + 1 - i < 18) {
						pan[i + ver + 3][colum + 1 - i - 3].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (i + ver + 2 == 18) {
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 3][colum + 1 - i - 3].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 0 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1 ||
					pan[i + ver][colum + 1 - i].stone == 3 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1) {
					//pan[i + ver][colum + 1 - i] = 3;
					if (colum + 1 - i <= 18 && i + ver + 2<18) {
						pan[i + ver][colum + 1 - i].priority += TWO_CON;
						pan[i + ver + 3][colum + 1 - i - 3].priority += TWO_CON;
					}
					else if (colum + 1 - i <= 18 && i + ver + 2 == 18) {
						pan[i + ver][colum + 1 - i].priority += TWO_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 0 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1 ||
					pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 3 && pan[i + ver + 2][colum + 1 - i - 2].stone == 1) {
					//pan[i + ver + 1][colum + 1 - i - 1] = 3;
					if (colum + 1 - i < 18 && i + ver + 2 < 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += TWO_CON;
						pan[i + ver + 3][colum + 1 - i - 3].priority += ONE_CON;
						pan[i + ver - 1][colum + 1 - i - 1].priority += ONE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += TWO_CON;
						pan[i + ver + 3][colum + 1 - i - 3].priority += ONE_CON;
					}
					else if (i + ver + 2 == 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += TWO_CON;
						pan[i + ver - 1][colum + 1 - i - 1].priority += ONE_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 0 ||
					pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1 && pan[i + ver + 2][colum + 1 - i - 2].stone == 3) {
					//pan[i + ver + 2][colum + 1 - i - 2] = 3;
					if (colum + 1 - i<18 && i + ver + 2 <= 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += TWO_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += TWO_CON;
					}
					else if (colum + 1 - i == 18 && i + ver + 2 <= 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += TWO_CON;
					}
					if (black < 2) {
						black = 2;
					}
				}
			}
			if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 0 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 3 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 0 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 3 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 0 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 3) {
				if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2) {
					if (i + ver + 2 < 18 && colum + 1 - i < 18) {
						pan[i + ver + 3][colum + 1 - i - 3].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (i + ver + 2 == 18) {
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 3][colum + 1 - i - 3].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 0 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2 ||
					pan[i + ver][colum + 1 - i].stone == 3 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2) {
					//pan[i + ver][colum + 1 - i] = 3;
					if (colum + 1 - i <= 18 && i + ver + 2<18) {
						pan[i + ver][colum + 1 - i].priority += TWO_CON;
						pan[i + ver + 3][colum + 1 - i - 3].priority += TWO_CON;
					}
					else if (colum + 1 - i <= 18 && i + ver + 2 == 18) {
						pan[i + ver][colum + 1 - i].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 0 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2 ||
					pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 3 && pan[i + ver + 2][colum + 1 - i - 2].stone == 2) {
					//pan[i + ver + 1][colum + 1 - i - 1] = 3;
					if (colum + 1 - i < 18 && i + ver + 2 < 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += TWO_CON;
						pan[i + ver + 3][colum + 1 - i - 3].priority += ONE_CON;
						pan[i + ver - 1][colum + 1 - i - 1].priority += ONE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += TWO_CON;
						pan[i + ver + 3][colum + 1 - i - 3].priority += ONE_CON;
					}
					else if (i + ver + 2 == 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += TWO_CON;
						pan[i + ver - 1][colum + 1 - i - 1].priority += ONE_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 0 ||
					pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2 && pan[i + ver + 2][colum + 1 - i - 2].stone == 3) {
					//pan[i + ver + 2][colum + 1 - i - 2] = 3;

					if (colum + 1 - i<18 && i + ver + 2 <= 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += TWO_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += TWO_CON;
					}
					else if (colum + 1 - i == 18 && i + ver + 2 <= 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += TWO_CON;
					}
					if (white < 2) {
						white = 2;
					}
				}
			}
			if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 0 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 3 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 0
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 3
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 0 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1 ||
				pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 0 ||
				pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 3) {
				if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1) {
					if (i + ver + 3 < 18 && colum + 1 - i < 18) {
						pan[i + ver - 1][colum + 1 - i - 1].priority += FOUR_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += FOUR_CON;
					}
					else if (i + ver + 3 == 18) {
						pan[i + ver - 1][colum + 1 - i - 1].priority += FOUR_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 4][colum + 1 - i - 4].priority += FOUR_CON;
					}
					if (black < 4) {
						black = 4;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 0 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1) {
					if (colum + 1 - i <= 18 && i + ver + 3 < 18) {
						pan[i + ver][colum + 1 - i].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
					}
					else if (i + ver + 3 == 18) {
						pan[i + ver][colum + 1 - i].priority += THREE_CON;
					}

					//pan[i + ver][colum + 1 - i].stone = 3;
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 0
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1) {
					//pan[i + ver + 1][colum + 1 - i - 1].stone = 3;
					if (i + ver + 3 < 18 && colum + 1 - i < 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (i + ver + 3 == 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 0 && pan[i + ver + 3][colum + 1 - i - 3].stone == 1) {
					if (i + ver + 3 < 18 && colum + 1 - i < 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
					}
					else if (i + ver + 3 == 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
					}

					//pan[i + ver + 2][colum + 1 - i - 2].stone = 3;
					if (black < 3) {
						black = 3;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 1 && pan[i + ver + 1][colum + 1 - i - 1].stone == 1
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 1 && pan[i + ver + 3][colum + 1 - i - 3].stone == 0) {
					//pan[i + ver + 3][colum + 1 - i - 3].stone = 3;
					if (i + ver + 3 <= 18 && colum + 1 - i<18) {
						pan[i + ver + 3][colum + 1 - i - 3].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 3][colum + 1 - i - 3].priority += THREE_CON;
					}
					if (black < 3) {
						black = 3;
					}
				}
			}
			if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 0 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 3 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 0
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 3
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 0 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 3 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 0 ||
				pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
				&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 3) {
				if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2) {
					if (i + ver + 3 < 18 && colum + 1 - i < 18) {
						pan[i + ver - 1][colum + 1 - i + 1].priority += FOUR_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += FOUR_CON;
					}
					else if (i + ver + 3 == 18) {
						pan[i + ver - 1][colum + 1 - i + 1].priority += FOUR_CON;
					}
					else if (colum + 1 - i == 19) {
						pan[i + ver + 4][colum + 1 - i - 4].priority += FOUR_CON;
					}
					if (white < 4) {
						white = 4;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 0 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2) {
					if (colum + 1 - i <= 18 && i + ver + 3 < 18) {
						pan[i + ver][colum + 1 - i].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
					}
					else if (i + ver + 3 == 18) {
						pan[i + ver][colum + 1 - i].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 0
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2) {
					if (i + ver + 3 < 18 && colum + 1 - i < 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (i + ver + 3 == 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 1][colum + 1 - i - 1].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 0 && pan[i + ver + 3][colum + 1 - i - 3].stone == 2) {
					if (i + ver + 3 < 18 && colum + 1 - i < 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
					}
					else if (i + ver + 3 == 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 2][colum + 1 - i - 2].priority += THREE_CON;
						pan[i + ver + 4][colum + 1 - i - 4].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
				if (pan[i + ver][colum + 1 - i].stone == 2 && pan[i + ver + 1][colum + 1 - i - 1].stone == 2
					&& pan[i + ver + 2][colum + 1 - i - 2].stone == 2 && pan[i + ver + 3][colum + 1 - i - 3].stone == 0) {
					if (i + ver + 3 <= 18 && colum + 1 - i<18) {
						pan[i + ver + 3][colum + 1 - i - 3].priority += THREE_CON;
						pan[i + ver - 1][colum + 1 - i + 1].priority += THREE_CON;
					}
					else if (colum + 1 - i == 18) {
						pan[i + ver + 3][colum + 1 - i - 3].priority += THREE_CON;
					}
					if (white < 3) {
						white = 3;
					}
				}
			}

		}
		/*if (black > white) {
		printf("좌대각선%d줄에 흑돌이 %d개 연속됩니다. \n", ver + 1, black);
		}
		else if (black < white) {
		printf("좌대각선%d줄에 백돌이 %d개 연속됩니다. \n", ver + 1, white);
		}*/
		black = 0;
		white = 0;
		ver++;
		count--;

		if (count < 0) {
			break;
		}
	}
}
void findLOneDiagonal(PAN pan[SIZE_2013180016][SIZE_2013180016]) {														//좌 주대각선
	int black = 0;
	int white = 0;
	int i = 0;
	for (i = 0; i <= 18; i++) {
		if (pan[i][19 - i].stone == 1) {
			if (i > 0 && 19 - i < 18) {
				pan[i - 1][19 - i + 1].priority += ONE_CON;
				pan[i + 1][19 - i - 1].priority += ONE_CON;
			}
			else if (i == 0) {
				pan[i + 1][19 - i - 1].priority += ONE_CON;
			}
			else if (19 - i == 18) {
				pan[i - 1][19 - i + 1].priority += ONE_CON;
			}
			if (black < 1) {
				black = 1;
			}
		}
		if (pan[i][19 - i].stone == 2) {
			if (i > 0 && 19 - i < 18) {
				pan[i - 1][19 - i - 1].priority += ONE_CON;
				pan[i + 1][19 - i + 1].priority += ONE_CON;
			}
			else if (i == 0) {
				pan[i + 1][19 - i + 1].priority += ONE_CON;
			}
			else if (19 - i == 18) {
				pan[i - 1][19 - i - 1].priority += ONE_CON;
			}
			if (white < 1) {
				white = 1;
			}
		}
		if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1) {
			if (i + 1 < 18 && 19 - i < 18) {
				pan[i + 2][19 - i - 2].priority += TWO_CON;
				pan[i - 1][19 - i + 1].priority += TWO_CON;
			}
			else if (i + 1 == 18) {
				pan[i - 1][19 - i + 1].priority += TWO_CON;
			}
			else if (19 - i == 18) {
				pan[i + 2][19 - i - 2].priority += TWO_CON;
			}
			if (black < 2) {
				black = 2;
			}
		}
		if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2) {
			if (i + 1 < 18 && 19 - i < 18) {
				pan[i + 2][19 - i - 2].priority += TWO_CON;
				pan[i - 1][19 - i + 1].priority += TWO_CON;
			}
			else if (i + 1 == 18) {
				pan[i - 1][19 - i + 1].priority += TWO_CON;
			}
			else if (19 - i == 18) {
				pan[i + 2][19 - i - 2].priority += TWO_CON;
			}
			if (white < 2) {
				white = 2;
			}
		}
		if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 ||
			pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 ||
			pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 0 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 3) {
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1) {
				if (i + 2<18 && 19 - i<18) {
					pan[i + 3][19 - i - 3].priority += THREE_CON;
					pan[i - 1][19 - i - 1].priority += THREE_CON;
				}
				else if (i + 2 == 18) {
					pan[i - 1][19 - i - 1].priority += THREE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 3][19 - i - 3].priority += THREE_CON;
				}
				if (black < 3) {
					black = 3;
				}
			}
			if (pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 ||
				pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1) {
				//pan[i][20 - i] = 3;
				if (i + 2 <= 18 && 19 - i<18) {
					pan[i + 3][19 - i - 3].priority += TWO_CON;
					pan[i][19 - i].priority += TWO_CON;
				}
				else if (19 - i == 18) {
					pan[i][19 - i].priority += TWO_CON;
				}
				if (black < 2) {
					black = 2;
				}
			}
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 1 ||
				pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 1) {
				//pan[i + 1][20 - i - 1] = 3;
				if (i + 2>18 && 19 - i<18) {
					pan[i - 1][19 - i - 1].priority += ONE_CON;
					pan[i + 3][19 - i - 3].priority += ONE_CON;
					pan[i + 1][19 - i - 1].priority += TWO_CON;
				}
				else if (i + 2 == 18) {
					pan[i + 1][19 - i - 1].priority += TWO_CON;
					pan[i - 1][19 - i - 1].priority += ONE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 1][19 - i - 1].priority += TWO_CON;
					pan[i + 3][19 - i - 3].priority += ONE_CON;
				}
				if (black < 2) {
					black = 2;
				}
			}
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 0 ||
				pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 3) {
				//pan[i + 2][20 - i - 2] = 3;
				if (i + 2 <= 18 && 19 - i<18) {
					pan[i + 2][19 - i - 2].priority += TWO_CON;
					pan[i - 1][19 - i - 1].priority += ONE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 2][19 - i - 2].priority += TWO_CON;
				}
				if (black<2) {
					black = 2;
				}
			}
		}
		if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 ||
			pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 ||
			pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 0 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 3) {

			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2) {
				if (i + 2<18 && 19 - i<18) {
					pan[i + 3][19 - i - 3].priority += THREE_CON;
					pan[i - 1][19 - i - 1].priority += THREE_CON;
				}
				else if (i + 2 == 18) {
					pan[i - 1][19 - i - 1].priority += THREE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 3][19 - i - 3].priority += THREE_CON;
				}
				if (white < 3) {
					white = 3;
				}
			}
			if (pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 ||
				pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2) {
				//pan[i][20 - i] = 3;
				if (i + 2 <= 18 && 19 - i<18) {
					pan[i + 3][19 - i - 3].priority += TWO_CON;
					pan[i][19 - i].priority += TWO_CON;
				}
				else if (19 - i == 18) {
					pan[i][19 - i].priority += TWO_CON;
				}
				if (white<2) {
					white = 2;
				}
			}
			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 2 ||
				pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 2) {
				//pan[i + 1][20 - i - 1] = 3;
				if (i + 2>18 && 19 - i<18) {
					pan[i - 1][19 - i - 1].priority += ONE_CON;
					pan[i + 3][19 - i - 3].priority += ONE_CON;
					pan[i + 1][19 - i - 1].priority += TWO_CON;
				}
				else if (i + 2 == 18) {
					pan[i + 1][19 - i - 1].priority += TWO_CON;
					pan[i - 1][19 - i - 1].priority += ONE_CON;
				}
				else if (19- i == 18) {
					pan[i + 1][19 - i - 1].priority += TWO_CON;
					pan[i + 3][19 - i - 3].priority += ONE_CON;
				}
				if (white<2) {
					white = 2;
				}
			}
			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 0 ||
				pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 3) {
				//pan[i + 2][20 - i - 2] = 3;
				if (i + 2 <= 18 && 19 - i<18) {
					pan[i + 2][19 - i - 2].priority += TWO_CON;
					pan[i - 1][19 - i - 1].priority += ONE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 2][19 - i - 2].priority += TWO_CON;
				}
				if (white<2) {
					white = 2;
				}
			}
		}
		if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
			&& pan[i + 3][19 - i - 3].stone == 1 ||
			pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
			&& pan[i + 3][19 - i - 3].stone == 1 ||
			pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
			&& pan[i + 3][19 - i - 3].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 1
			&& pan[i + 3][19 - i - 3].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 1
			&& pan[i + 3][19 - i - 3].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 0
			&& pan[i + 3][19 - i - 3].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 3
			&& pan[i + 3][19 - i - 3].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
			&& pan[i + 3][19 - i - 3].stone == 0 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
			&& pan[i + 3][19 - i - 3].stone == 3) {
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
				&& pan[i + 3][19 - i - 3].stone == 1) {
				if (i + 3 < 18 && 19 - i < 18) {
					pan[i - 1][19 - i - 1].priority += FOUR_CON;
					pan[i + 4][19 - i - 4].priority += FOUR_CON;
				}
				else if (i + 3 == 18) {
					pan[i - 1][19 - i - 1].priority += FOUR_CON;
				}
				else if (19 - i == 18) {
					pan[i + 4][19 - i - 4].priority += FOUR_CON;
				}
				if (black < 4) {
					black = 4;
				}
			}
			if (pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
				&& pan[i + 3][19 - i - 3].stone == 1 ||
				pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
				&& pan[i + 3][19 - i - 3].stone == 1) {
				if (i + 3 < 18 && 19 - i <= 18) {
					pan[i][19 - i].priority += THREE_CON;
					pan[i + 4][19 - i - 4].priority += THREE_CON;
				}
				else if (i + 3 == 18) {
					pan[i][19 - i].priority += THREE_CON;
				}
				//pan[i][20 - i].stone = 3;
				if (black<3) {
					black = 3;
				}
			}
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 1
				&& pan[i + 3][19 - i - 3].stone == 1 ||
				pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 1
				&& pan[i + 3][19 - i - 3].stone == 1) {
				if (i + 3 < 18 && 19 - i < 18) {
					pan[i + 1][19 - i - 1].priority += THREE_CON;
					pan[i - 1][19 - i + 1].priority += TWO_CON;
					pan[i + 4][19 - i - 4].priority += TWO_CON;
				}
				else if (i + 3 == 18) {
					pan[i + 1][19 - i - 1].priority += THREE_CON;
					pan[i - 1][19 - i - 1].priority += TWO_CON;
				}
				else if (19 - i == 18) {
					pan[i + 1][19 - i - 1].priority += THREE_CON;
					pan[i + 4][19 - i - 4].priority += TWO_CON;
				}
				//pan[i + 1][20 - i - 1].stone = 3;
				if (black<3) {
					black = 3;
				}
			}
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 0
				&& pan[i + 3][19 - i - 3].stone == 1 ||
				pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 3
				&& pan[i + 3][19 - i - 3].stone == 1) {
				if (i + 3<18 && 19 - i<18) {
					pan[i + 2][19 - i - 2].priority += THREE_CON;
					pan[i - 1][19 - i + 1].priority += TWO_CON;
					pan[i + 4][19 - i - 4].priority += TWO_CON;
				}
				else if (i + 3 == 18) {
					pan[i + 2][19 - i - 2].priority += THREE_CON;
					pan[i - 1][19 - i + 1].priority += TWO_CON;
				}
				else if (19 - i == 18) {
					pan[i + 2][19 - i - 2].priority += THREE_CON;
					pan[i + 4][19 - i - 4].priority += TWO_CON;
				}
				//pan[i + 2][20 - i - 2].stone = 3;
				if (black<3) {
					black = 3;
				}
			}
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
				&& pan[i + 3][19 - i - 3].stone == 0 ||
				pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1
				&& pan[i + 3][19 - i - 3].stone == 3) {
				if (19 - i<18 && i + 3 <= 18) {
					pan[i + 3][19 - i - 3].priority += THREE_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 3][19 - i - 3].priority += THREE_CON;
				}
				//pan[i + 3][20 - i - 3].stone = 3;
				if (black<3) {
					black = 3;
				}
			}
		}
		if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
			&& pan[i + 3][19 - i - 3].stone == 2 ||
			pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
			&& pan[i + 3][19 - i - 3].stone == 2 ||
			pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
			&& pan[i + 3][19 - i - 3].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 2
			&& pan[i + 3][19 - i - 3].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 2
			&& pan[i + 3][19 - i - 3].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 0
			&& pan[i + 3][19 - i - 3].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 3
			&& pan[i + 3][19 - i - 3].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
			&& pan[i + 3][19 - i - 3].stone == 0 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
			&& pan[i + 3][19 - i - 3].stone == 3) {
			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
				&& pan[i + 3][19 - i - 3].stone == 2) {
				if (i + 3 < 18 && 19 - i < 18) {
					pan[i - 1][19 - i - 1].priority += FOUR_CON;
					pan[i + 4][19 - i - 4].priority += FOUR_CON;
				}
				else if (i + 3 == 18) {
					pan[i - 1][19 - i - 1].priority += FOUR_CON;
				}
				else if (19 - i == 18) {
					pan[i + 4][19 - i - 4].priority += FOUR_CON;
				}
				if (white < 4) {
					white = 4;
				}
			}
			if (pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
				&& pan[i + 3][19 - i - 3].stone == 2 ||
				pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
				&& pan[i + 3][19 - i - 3].stone == 2) {
				//pan[i][20 - i].stone = 3;
				if (i + 3 < 18 && 19 - i <= 18) {
					pan[i][19 - i].priority += THREE_CON;
					pan[i + 4][19 - i - 4].priority += THREE_CON;
				}
				else if (i + 3 == 18) {
					pan[i][19 - i].priority += THREE_CON;
				}
				if (white < 3) {
					white = 3;
				}
			}
			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 2
				&& pan[i + 3][19 - i - 3].stone == 2 ||
				pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 2
				&& pan[i + 3][19 - i - 3].stone == 2) {
				if (i + 3 < 18 && 19 - i < 18) {
					pan[i + 1][19 - i - 1].priority += THREE_CON;
					pan[i - 1][19 - i + 1].priority += TWO_CON;
					pan[i + 4][19 - i - 4].priority += TWO_CON;
				}
				else if (i + 3 == 18) {
					pan[i + 1][19 - i - 1].priority += THREE_CON;
					pan[i - 1][19 - i - 1].priority += TWO_CON;
				}
				else if (19 - i == 18) {
					pan[i + 1][19 - i - 1].priority += THREE_CON;
					pan[i + 4][19 - i - 4].priority += TWO_CON;
				}
				if (white < 3) {
					white = 3;
				}
			}
			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 0
				&& pan[i + 3][19 - i - 3].stone == 2 ||
				pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 3
				&& pan[i + 3][19 - i - 3].stone == 2) {
				if (i + 3 < 18 && 19 - i < 18) {
					pan[i + 2][19 - i - 2].priority += THREE_CON;
					pan[i - 1][19 - i + 1].priority += TWO_CON;
					pan[i + 4][19 - i - 4].priority += TWO_CON;
				}
				else if (i + 3 == 18) {
					pan[i + 2][19 - i - 2].priority += THREE_CON;
					pan[i - 1][19 - i + 1].priority += TWO_CON;
				}
				else if (19 - i == 18) {
					pan[i + 2][19 - i - 2].priority += THREE_CON;
					pan[i + 4][19 - i - 4].priority += TWO_CON;
				}
				if (white < 3) {
					white = 3;
				}
			}
			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
				&& pan[i + 3][19 - i - 3].stone == 0 ||
				pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2
				&& pan[i + 3][19 - i - 3].stone == 3) {
				if (19 - i < 18 && i + 3 <= 18) {
					pan[i + 3][19 - i - 3].priority += THREE_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 3][19 - i - 3].priority += THREE_CON;
				}
				if (white < 3) {
					white = 3;
				}
			}

		}
		if (pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
			pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1 ||
			pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
			pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 1 &&
			pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 1 &&
			pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 0 &&
			pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 3 &&
			pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
			pan[i + 3][19 - i - 3].stone == 0 && pan[i + 4][19 - i - 4].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
			pan[i + 3][20 - i - 3].stone == 3 && pan[i + 4][20 - i - 4].stone == 1 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
			pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 0 ||
			pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
			pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 3) {
			if (pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
				pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1 ||
				pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
				pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1) {
				if (i + 4 < 18 && 19 - i <= 18) {
					pan[i + 5][19 - i - 5].priority += FOUR_CON;
					pan[i][19 - i].priority += FOUR_CON;
				}
				else if (i + 4 == 18) {
					pan[i][19 - i].priority += FOUR_CON;
				}
				if (black<4) {
					black = 4;
				}
			}
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 1 &&
				pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1 ||
				pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 1 &&
				pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1) {
				if (i + 4 < 18 && 19 - i < 18) {
					pan[i + 1][19 - i - 1].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				else if (i + 4 == 18) {
					pan[i + 1][19 - i - 1].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
				}
				else if (19 - i < 18) {
					pan[i + 1][19 - i - 1].priority += FOUR_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				if (black < 4) {
					black = 4;
				}
			}
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 0 &&
				pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1 ||
				pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 3 &&
				pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 1) {
				if (i + 4 < 18 && 19 - i < 18) {
					pan[i + 2][19 - i - 2].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				else if (i + 4 == 18) {
					pan[i + 2][19 - i - 2].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 2][19 - i - 2].priority += FOUR_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				if (black<4) {
					black = 4;
				}
			}
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
				pan[i + 3][19 - i - 3].stone == 0 && pan[i + 4][19 - i - 4].stone == 1 ||
				pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
				pan[i + 3][19 - i - 3].stone == 3 && pan[i + 4][19 - i - 4].stone == 1) {
				if (i + 4 < 18 && 19 - i < 18) {
					pan[i - 1][19 - i + 1].priority += THREE_CON;
					pan[i + 3][19 - i - 3].priority += FOUR_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				else if (i + 4 == 18) {
					pan[i + 3][19 - i - 3].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 3][19 - i - 3].priority += FOUR_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				if (black<4) {
					black = 4;
				}
			}
			if (pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
				pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 0 ||
				pan[i][19 - i].stone == 1 && pan[i + 1][19 - i - 1].stone == 1 && pan[i + 2][19 - i - 2].stone == 1 &&
				pan[i + 3][19 - i - 3].stone == 1 && pan[i + 4][19 - i - 4].stone == 3) {
				if (i + 4 <= 18 && 19 - i < 18) {
					pan[i + 4][19 - i - 4].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += FOUR_CON;
				}
				else if (19 - i == 18) {
					pan[i + 4][19 - i - 4].priority += FOUR_CON;
				}
				if (black<4) {
					black = 4;
				}
			}
		}
		if (pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
			pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2 ||
			pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
			pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 2 &&
			pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 2 &&
			pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 0 &&
			pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 3 &&
			pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
			pan[i + 3][19 - i - 3].stone == 0 && pan[i + 4][19 - i - 4].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
			pan[i + 3][19 - i - 3].stone == 3 && pan[i + 4][19 - i - 4].stone == 2 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
			pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 0 ||
			pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
			pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 3) {
			if (pan[i][19 - i].stone == 0 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
				pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2 ||
				pan[i][19 - i].stone == 3 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
				pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2) {
				if (i + 4 < 18 && 19 - i <= 18) {
					pan[i + 5][19 - i - 5].priority += FOUR_CON;
					pan[i][19 - i].priority += FOUR_CON;
				}
				else if (i + 4 == 18) {
					pan[i][19 - i].priority += FOUR_CON;
				}
				if (white<4) {
					white = 4;
				}
			}
			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 0 && pan[i + 2][19 - i - 2].stone == 2 &&
				pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2 ||
				pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 3 && pan[i + 2][19 - i - 2].stone == 2 &&
				pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2) {
				if (i + 4 < 18 && 19 - i < 18) {
					pan[i + 1][19 - i - 1].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				else if (i + 4 == 18) {
					pan[i + 1][19 - i - 1].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
				}
				else if (19 - i < 18) {
					pan[i + 1][19 - i - 1].priority += FOUR_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				if (white<4) {
					white = 4;
				}
			}
			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 0 &&
				pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2 ||
				pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 3 &&
				pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 2) {
				if (i + 4 < 18 && 19 - i < 18) {
					pan[i + 2][19 - i - 2].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				else if (i + 4 == 18) {
					pan[i + 2][19 - i - 2].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 2][19 - i - 2].priority += FOUR_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				if (white<4) {
					white = 4;
				}
			}
			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
				pan[i + 3][19 - i - 3].stone == 0 && pan[i + 4][19 - i - 4].stone == 2 ||
				pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
				pan[i + 3][19 - i - 3].stone == 3 && pan[i + 4][19 - i - 4].stone == 2) {
				if (i + 4 < 18 && 19 - i < 18) {
					pan[i - 1][19 - i + 1].priority += THREE_CON;
					pan[i + 3][19 - i - 3].priority += FOUR_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				else if (i + 4 == 18) {
					pan[i + 3][19 - i - 3].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += THREE_CON;
				}
				else if (19 - i == 18) {
					pan[i + 3][19 - i - 3].priority += FOUR_CON;
					pan[i + 5][19 - i - 5].priority += THREE_CON;
				}
				if (white<4) {
					white = 4;
				}
			}

			if (pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
				pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 0 ||
				pan[i][19 - i].stone == 2 && pan[i + 1][19 - i - 1].stone == 2 && pan[i + 2][19 - i - 2].stone == 2 &&
				pan[i + 3][19 - i - 3].stone == 2 && pan[i + 4][19 - i - 4].stone == 3) {
				if (i + 4 <= 18 && 19 - i < 18) {
					pan[i + 4][19 - i - 4].priority += FOUR_CON;
					pan[i - 1][19 - i + 1].priority += FOUR_CON;
				}
				else if (19 - i == 18) {
					pan[i + 4][19 - i - 4].priority += FOUR_CON;
				}
				if (white<4) {
					white = 4;
				}
			}
		}
	}
	/*if (black > white) {
	printf("좌대각선%d줄에 흑돌이 %d개 연속됩니다. \n",1, black);
	}
	else if (black < white) {
	printf("좌대각선%d줄에 백돌이 %d개 연속됩니다. \n", 1, white);
	}*/

	black = 0;
	white = 0;
}
void checkTrashPriority(PAN pan[SIZE_2013180016][SIZE_2013180016]) {
	int i, j;
	int jNext = 0;
	int jPrev = 0;
	int jPprev = 0;
	int jNnext = 0;

	for (j = 0; j < 19; j++) {
		for (i = 0; i < 19; i++) {

			if (j > 0) {
				jPrev = j - 1;

			}
			if (j > 1) {
				jPprev = j - 2;
			}
			if (j >= 0 && j<18) {
				jNext = j + 1;
			}
			if (j >= 0 && j < 17) {
				jNnext = j + 2;
			}
			if (j == 2) {
				if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 2) {
					if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2 ||
						pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2) {
						pan[jPprev][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2) {
						pan[jPrev][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 2) {
						pan[j][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 2 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 2) {
						pan[jNext][i].priority = 0;
					}
				}
				if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1) {
					if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1) {
						pan[jPprev][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1) {
						pan[jPrev][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1) {
						pan[j][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1) {
						pan[jNext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1) {
						pan[jPprev][i].priority = 0;
						pan[jPrev][i].priority = 0;
						pan[j][i].priority = 0;
						pan[jNnext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1) {
						pan[jPprev][i].priority = 0;
						pan[jPrev][i].priority = 0;
						pan[j][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 0 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 3 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1) {
						pan[jPprev][i].priority = 0;
						pan[jPrev][i].priority = 0;
						pan[j][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 1) {
						pan[jPrev][i].priority = 0;
						pan[j][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1) {
						pan[jPrev][i].priority = 0;
						pan[j][i].priority = 0;
						pan[jNext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1) {
						pan[j][i].priority = 0;
						pan[jNext][i].priority = 0;
					}
				}
			}
			if (j == 16) {
				if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 0 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 3 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 0 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 3 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 0 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 3 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 0 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 3 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 0 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 3 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 2 ||
					pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 2) {

					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 0 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 3) {
						pan[jNnext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 1 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1) {
						pan[jPrev][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 0 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 3 && pan[jNext][i].stone == 1 && pan[jNnext][i].stone == 1) {
						pan[j][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 1 ||
						pan[jPprev][i].stone == 2 && pan[jPrev][i].stone == 1 && pan[j][i].stone == 1 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 1) {
						pan[jNext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 0 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 3) {
						pan[jPrev][i].priority = 0;
						pan[j][i].priority = 0;
						pan[jNext][i].priority = 0;
						pan[jNnext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 0 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 3) {
						pan[j][i].priority = 0;
						pan[jNext][i].priority = 0;
						pan[jNnext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 0 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 3) {
						pan[jNext][i].priority = 0;
						pan[jNnext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 0 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 2 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 3) {
						pan[jNnext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 2 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 2) {
						pan[jPrev][i].priority = 0;
						pan[j][i].priority = 0;
						pan[jNext][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 0 && pan[j][i].stone == 0 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 3 && pan[j][i].stone == 3 && pan[jNext][i].stone == 2 && pan[jNnext][i].stone == 2) {
						pan[jPrev][i].priority = 0;
						pan[j][i].priority = 0;
					}
					if (pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 0 && pan[jNext][i].stone == 0 && pan[jNnext][i].stone == 2 ||
						pan[jPprev][i].stone == 1 && pan[jPrev][i].stone == 2 && pan[j][i].stone == 3 && pan[jNext][i].stone == 3 && pan[jNnext][i].stone == 2) {
						pan[j][i].priority = 0;
						pan[jNext][i].priority = 0;
					}

				}
			}
		}
	}
}
void checkCrossTrashPriority(PAN pan[SIZE_2013180016][SIZE_2013180016]) {
	int i = 0;
	int j = 0;
	int iNext = 0;
	int iPrev = 0;
	int iPprev = 0;
	int iNnext = 0;

	for (j = 0; j < 19; j++) {
		for (i = 0; i < 19; i++) {
			if (i > 0) {
				iPrev = i - 1;

			}
			if (i > 1) {
				iPprev = i - 2;
			}
			if (i >= 0 && i < 18) {
				iNext = i + 1;
			}
			if (i >= 0 && i < 17) {
				iNnext = i + 2;
			}
			if (i == 2) {
				if (pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 0 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 3 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 2 ||
					pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 2) {
					if (pan[j][iPprev].stone == 0 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2 ||
						pan[j][iPprev].stone == 3 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2) {
						pan[j][iPprev].priority = 0;
					}
					if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2 ||
						pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2) {
						pan[j][iPrev].priority = 0;
					}
					if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 0 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2 ||
						pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 3 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 2) {
						pan[j][i].priority = 0;
					}
					if (pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 2 ||
						pan[j][iPprev].stone == 1 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 2) {
						pan[j][iNext].priority = 0;
					}
				}
			}
			if (i == 16) {
				if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 0 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 3 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 0 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 3 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 1 ||
					pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 1) {
					if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 0 ||
						pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 3) {
						pan[j][iNnext].priority = 0;
					}
					if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 0 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
						pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 3 && pan[j][i].stone == 1 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1) {
						pan[j][iPrev].priority = 0;
					}
					if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 0 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1 ||
						pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 3 && pan[j][iNext].stone == 1 && pan[j][iNnext].stone == 1) {
						pan[j][i].priority = 0;
					}
					if (pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 0 && pan[j][iNnext].stone == 1 ||
						pan[j][iPprev].stone == 2 && pan[j][iPrev].stone == 1 && pan[j][i].stone == 1 && pan[j][iNext].stone == 3 && pan[j][iNnext].stone == 1) {
						pan[j][iNext].priority = 0;
					}
				}
			}

		}
	}
}
void printPan(PAN pan[SIZE_2013180016][SIZE_2013180016]) {
	int i = 0;
	int j = 0;

	for (j = 0; j < 19; j++) {
		for (i = 0; i < 19; i++) {
			printf("%d   ", pan[j][i].priority);
		}
		printf("\n");
	}
}
void SetStoneZero(PAN pan[SIZE_2013180016][SIZE_2013180016]) {
	int i = 0;
	int j = 0;

	for (j = 0; j < 19; j++) {
		for (i = 0; i < 19; i++) {
			if (pan[j][i].stone == 1 || pan[j][i].stone == 2) {
				pan[j][i].priority = 0;
			}
		}
		// printf("\n");
	}
}
void Auto_Rand(PAN pan[SIZE_2013180016][SIZE_2013180016]) {
	srand((unsigned int)time(NULL));
	int j = 0;
	int i = 0;

re:
	j = (rand() % 19) + 1;
	i = (rand() % 19) + 1;
	if (pan[j][i].stone == 1) {
		pan[j][i + 1].stone = 2;
	}
	else if (pan[j][i].stone == 2) {
		pan[j][i + 1].stone = 2;
	}
	else {
		if (j < 19 && i < 19) {
			pan[j][i].stone = 2;
		}
		else {
			goto re;
		}
	}
}
void SetPriority_Zero(PAN pan[SIZE_2013180016][SIZE_2013180016]) {
	int i = 0, j = 0;

	for (i = 0; i <19; i++) {
		for (j = 0; j < 19; j++) {
			pan[i][j].priority = 0;
		}
	}
}
void Auto_Thread(PAN pan[SIZE_2013180016][SIZE_2013180016],int *x,int *y) {
	int j = 0, i = 0;
	int blackStone = 0;
	int whiteStone = 0;
	PRIOR temp = { 0 , };
	
	j = 0;
	i = 0;
	temp.maxpriority = pan[j][i].priority;
	temp.indexX = i;
	temp.indexY = j;
	for (j = 0; j < 19; j++) {
		for (i = 0; i < 19; i++) {
			if (temp.maxpriority < pan[j][i].priority) {
				temp.maxpriority = pan[j][i].priority;
				temp.indexX = i;
				temp.indexY = j;
			}
		}
	}

	pan[temp.indexY][temp.indexX].stone = 1;


}
void BlackAttack_2013180016(int *x, int*y) {
	int i = 0;
	int j = 0;
	int count = 0;
	int colum = 0;
	int ver = 0;
	int diagonal = 0;
	PRIOR temp = { 0 , };

	if (turn == 0) {
		pan[6][10].stone = 1;
		*x = 10;
		*y = 6;
	}
	else {
		SetPriority_Zero(pan);
		
		//system("cls");
		findCrossContinueCount(pan);

		findVertexContinueCount(pan);
		
		findDiagonalContinueCount(pan);
		
		findOneDiagonal(pan);

		findLeftDiagonal(pan);
		
		findLDiagonal(pan);
		
		findLOneDiagonal(pan);

		SetStoneZero(pan);
		
		checkTrashPriority(pan);
		checkCrossTrashPriority(pan);
	
		j = 0;
		i = 0;
		temp.maxpriority = pan[j][i].priority;
		temp.indexX = i;
		temp.indexY = j;
		for (j = 0; j < 19; j++) {
			for (i = 0; i < 19; i++) {
				if (temp.maxpriority < pan[j][i].priority) {
					temp.maxpriority = pan[j][i].priority;
					temp.indexX = i;
					temp.indexY = j;
				}
			}
		}

		pan[temp.indexY][temp.indexX].stone = 1;
		*x = temp.indexX;
		*y = temp.indexY;
	
	}
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	//printPan(pan);
	SetPriority_Zero(pan);
	turn++;
}
void BlackDefence_2013180016(int x, int y) {
	pan[y][x].stone = 2;

}
void WhiteAttack_2013180016(int *x, int *y) {
	int i = 0;
	int j = 0;
	int count = 0;
	int colum = 0;
	int ver = 0;
	int diagonal = 0;
	PRIOR temp = { 0 , };
	
	//SetPriority_Zero(pan);

	findCrossContinueCount(pan);

	findVertexContinueCount(pan);

	findDiagonalContinueCount(pan);

	findOneDiagonal(pan);

	findLeftDiagonal(pan);

	findLDiagonal(pan);

	findLOneDiagonal(pan);
	SetStoneZero(pan);
	
	checkTrashPriority(pan);
	checkCrossTrashPriority(pan);
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	///printPan(pan);
	j = 0;
	i = 0;
	temp.maxpriority = pan[j][i].priority;
	temp.indexX = i;
	temp.indexY = j;
	for (j = 0; j < 19; j++) {
		for (i = 0; i < 19; i++) {
			if (temp.maxpriority < pan[j][i].priority) {
				temp.maxpriority = pan[j][i].priority;
				temp.indexX = i;
				temp.indexY = j;
			}
		}
	}

	pan[temp.indexY][temp.indexX].stone = 2;
	*y = temp.indexY;
	*x = temp.indexX;

	/*printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printPan(pan);*/
	turn++;
	SetPriority_Zero(pan);

}
void WhiteDefence_2013180016(int x, int y) {
	pan[y][x].stone = 1;
	//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	//printPan(pan);
}