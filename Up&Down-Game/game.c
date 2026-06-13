#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 랜덤한 숫자를 만드는 도구함
#include <time.h> // 현재 시간을 알아내는 도구함 랜덤 쓰려면 필수

int main()
{
	srand(time(NULL)); // 랜덤으로 숫자를 설정하게 함

	int num1 = rand() % 100 + 1; // 1~100 까지 범위 설정
	int num2;
	int chances = 5; // 횟수 제한 (예: 5번)

	printf("1~100 사이의 랜덤한 숫자를 정했습니다.\n");
	printf("총 %d번의 기회가 주어집니다!\n\n", chances);

	// 기회가 0보다 클 때 반복
	while (chances > 0)
	{
		printf("남은 기회: %d번\n", chances);
		printf("숫자를 맞춰보세요: ");
		scanf("%d", &num2);

		if (num1 == num2) // 정한 숫자랑 입력한 숫자가 같으면 멈춤
		{
			printf("정답!\n");
			break;
		}
		else if (num1 > num2) // 정한 숫자가 크면 Up 출력
		{
			printf("Up!\n\n");
		}
		else // 정한 숫자가 작으면 Down 출력
		{
			printf("Down!\n\n");
		}

		chances--; // 틀리면 1회 감소
	}

	// 횟수를 다 차감하면 출력
	if (chances == 0)
	{
		printf("기회를 모두 소진했습니다. 정답은 %d였습니다!\n", num1);
	}

	return 0;
}
