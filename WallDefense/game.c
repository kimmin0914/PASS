#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 3     // 화면에 동시에 나오는 단어 개수
#define MAX_LENGTH 15     // 단어 최대 길이
#define SCREEN_HEIGHT 20  // 세로 20칸
#define SCREEN_WIDTH 40   // 가로 40칸

int main(void)
{

	srand(time(NULL));

	char word_dict[10][MAX_LENGTH] = {
		"MUSH", "SLIME", "RIBBONPIG", "YETI", "PEPE",
		"ZAKUM", "MESO", "HEAL", "SLASH", "BALROG"
	};

	// 스타트

	char enemy_words[MAX_ENEMIES][MAX_LENGTH] = { "MUSH", "SLIME", "RIBBONPIG" };
	int enemy_x[MAX_ENEMIES] = { 15, 25, 5 };
	int enemy_y[MAX_ENEMIES] = { 3, 0, -2 };
	int is_alive[MAX_ENEMIES] = { 1, 1, 1 };

	char player_input[20] = { 0, };
	int input_index = 0;

	char game_screen[SCREEN_HEIGHT][SCREEN_WIDTH];

	int wall_health = 5; // 성벽 체력
	int game_score = 0;  // 내 점수
	int drop_timer = 0;  // 떨어지는 속도 조절

	int game_over = 0;


	// 시작

	while (game_over == 0)
	{
		if (_kbhit() != 0)
		{
			char key = _getch();

			if (key == 13) // 엔터를 쳤을 때
			{
				for (int i = 0; i < MAX_ENEMIES; i++)
				{
					if (is_alive[i] == 1)
					{
						if (strcmp(enemy_words[i], player_input) == 0)
						{
							is_alive[i] = 0;
							game_score += 10;
							break;
						}
					}
				}

				// 입력창 비우기
				for (int i = 0; i < 20; i++) player_input[i] = 0;
				input_index = 0;
			}
			else if (key == 8) // 백스페이스 처리
			{
				if (input_index > 0)
				{
					input_index--;
					player_input[input_index] = 0;
				}
			}
			else // 일반 알파벳 입력
			{
				if (input_index < 19)
				{
					player_input[input_index] = key;
					input_index++;
				}
			}
		}


		// 단어 내려오기

		drop_timer++;
		if (drop_timer == 10) // 0.5초마다 실행
		{
			for (int i = 0; i < MAX_ENEMIES; i++)
			{
				if (is_alive[i] == 1)
				{
					enemy_y[i]++; // 밑으로 한 칸 내린다

					if (enemy_y[i] == SCREEN_HEIGHT - 1) // 성벽(바닥)에 닿았는가?
					{
						is_alive[i] = 0; // 닿았으면 터짐
						wall_health--;   // 성벽 체력 깎임

						if (wall_health <= 0) // 체력이 0이 되면
						{
							game_over = 1; // 게임 오버
						}
					}
				}
			}
			drop_timer = 0; // 타이머 리셋
		}

		//무한 루프

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (is_alive[i] == 0)
			{
				int random_word = rand() % 10;
				strcpy(enemy_words[i], word_dict[random_word]);

				enemy_x[i] = rand() % (SCREEN_WIDTH - MAX_LENGTH);
				enemy_y[i] = -(rand() % 5);
				is_alive[i] = 1;
			}
		}


		// 렌더링

		system("cls");

		// 배경 및 성벽 세팅
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			for (int x = 0; x < SCREEN_WIDTH; x++)
			{
				if (y == SCREEN_HEIGHT - 1) game_screen[y][x] = '=';
				else game_screen[y][x] = ' ';
			}
		}

		// 살아있는 단어를 도화지에 덮어쓰기
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (is_alive[i] == 1 && enemy_y[i] >= 0 && enemy_y[i] < SCREEN_HEIGHT - 1)
			{
				int word_length = strlen(enemy_words[i]);
				for (int j = 0; j < word_length; j++)
				{
					game_screen[enemy_y[i]][enemy_x[i] + j] = enemy_words[i][j];
				}
			}
		}

		// 화면 출력
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			for (int x = 0; x < SCREEN_WIDTH; x++)
			{
				printf("%c", game_screen[y][x]);
			}
			printf("\n");
		}

		// 상태창 출력
		printf(" 현재 점수 : %d | 남은 체력 : %d \n", game_score, wall_health);
		printf(" [입력창] : %s \n", player_input);


		Sleep(50); // 0.05초 대기
	}

	// 게임 종료

	system("cls");
	printf("\n\n ===================================== \n");
	printf("             G A M E   O V E R         \n");
	printf(" ===================================== \n\n");
	printf(" 방어를 실패했습니다... 성벽이 무너졌습니다.\n");
	printf(" 최종 점수 : %d 점 \n\n", game_score);
	printf(" 아무 키나 누르면 종료됩니다...\n");

	_getch();
	return 0;
}