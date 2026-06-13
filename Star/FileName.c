/*#include <stdio.h>
int main(void)
{
	for (int i = 0; i < 5; i++) // 삼각형 높이 5칸
	{
			for (int j = 0; j <= i; j++) // 별 갯수 아래로 갈수록 한 개씩 증가
			{
				printf("*");
			}
			printf("\n"); // 출력 후 줄 바꿈
	}

	return 0;
}*/

/*#include <stdio.h>
int main(void)
{
	for (int i = 5; i > 0; i--) // 역삼각형 높이 5칸
	{
		for (int j = 1; j <= i; j++) // 별 갯수 아래로 갈수록 한 개씩 감소
		{
			printf("*");
		}
		printf("\n"); // 별이 출력되고 줄 바꿈
	}

	return 0;
}*/

/*#include <stdio.h>
int main(void)
{
	for (int i = 0; i < 5; i++) // 높이 5칸
	{
		for (int j = 4; j > i; j--) // 첫 시작은 4칸 띄우기 아래로 갈수록 한 칸씩 감소
		{
			printf(" ");
		}
		for (int k = 0; k <= i; k++) // 별 갯수 아래로 갈수록 한 개씩 증가
		{
			printf("*");
		}
		printf("\n"); // 별이 출력되고 줄 바꿈
	}
	return 0;
}*/

/*#include <stdio.h>
int main(void)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 4; j >= i; j--)
		{
			printf(" ");
		}
		for (int k = 0; k <= 2 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}*/

/*#include <stdio.h>
int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = - 1; j >= - i; j--)
		{
			printf(" ");
		}
		for (int k = 10; k >= 2 * i; k--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}*/

/*#include <stdio.h>
int main(void)
{
	for (int i = 0; i < 5; i++) // 삼각형 높이 6칸
	{
		for (int j = 4; j >= i; j--) // 첫 시작은 5칸 띄우기 아래로 갈수록 감소
		{
			printf(" ");
		}
		for (int k = 0; k <= 2 * i; k++) // 별 갯수 아래로 갈수록 두 개씩 증가
		{
			printf("*");
		}
		printf("\n"); // 별이 출력되고 줄 바꿈
	}
	for (int i = 0; i < 6; i++) // 역삼각형 높이 6칸
	{
		for (int j = -1; j >= -i; j--) // 첫 시작은 0칸 띄우기 아래로 갈수록 증가
		{
			printf(" ");
		}
		for (int k = 10; k >= 2 * i; k--) // 별 갯수 아래로 갈수록 두 개씩 감소
		{
			printf("*");
		}
		printf("\n"); // 별이 출력되고 줄 바꿈
	}
	return 0;
}*/

/*#include <stdio.h>
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", i);
		for (int j = 0; j <= 5; j++)
		{
			printf("%d", j);
		};
	}

	return 0;
}*/

/*#include <stdio.h>
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d", i);
	}

	return 0;
}*/

#include <stdio.h> 
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
			printf(" ");

		for (int k = 1; k <= 2 * i + 1; k++)
			printf("*");

		printf("\n");
	}

	for (int i = 3; i >= 0; i--)
	{
		for (int j = 4; j > i; j--)
			printf(" ");
		for (int k = 1; k <= 2 * i + 1; k++)
			printf("*");
		printf("\n");
	}
	return 0;
}
