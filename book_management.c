#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* menu[6] = { "파일 읽기", "추가", "출력", "검색", "파일 쓰기", "종료"};
	char book[30], author[30], publisher[30], book_pub[30];
	int num;
	char ch;
	FILE* fp;

	while (1) {
		printf("========================\n");
		for (int i = 0; i < 6; i++) {
			printf("%d. %s\n", i + 1, menu[i]);
		}
		printf("========================\n");

		printf("정수 값을 입력하시오: ");
		scanf("%d", &num);

		if (num == 1) {
			fp = fopen("book.txt", "r");
			if (fp == NULL) {
				printf("파일 오픈 성공\n");
				exit(1);
			}
			else {
				printf("파일 오픈 성공!\n");
			}
		}
		else if (num == 2) {
			fp = fopen("book.txt", "a");
			printf("도서의 이름: ");
			scanf("%s", book);
			printf("저자: ");
			scanf("%s", author);
			printf("출판사: ");
			scanf("%s", publisher);

			fprintf(fp, "\n%s %s %s", book, author, publisher);
			fclose(fp);
		}
		else if (num == 3) {
			if ((fp = fopen("book.txt", "r")) == NULL) {
				fprintf(stderr, "도서 파일을 열 수 없습니다.\n");
				exit(1);
			}
			else {
				while (!feof(fp)) {
					fscanf(fp, "%s %s %s", book, author, publisher);
					printf("제목: %s\n", book);
					printf("저자: %s\n", author);
					printf("출판사: %s\n", publisher);
				}
			}
		}
		else if (num == 4) {
			printf("제목: ");
			scanf("%s", book_pub);
			if ((fp = fopen("book.txt", "r")) == NULL) {
				fprintf(stderr, "도서 파일을 열 수 없습니다.\n");
				exit(1);
			}
			else {
				while (!feof(fp)) {
					fscanf(fp, "%s %s %s", book, author, publisher);
					if (strcmp(book, book_pub) == 0) {
						printf("출판사는 %s\n", publisher);
					}
				}
				fclose(fp);
			}
		}
		else if (num == 5) {
			fp = fopen("book.txt", "a");
			if (fp == NULL) {
				printf("파일 오픈 실패\n");
			}
			else {
				printf("파일 오픈 성공!(2)\n");
			}
		}
		else if (num == 6) {
			break;
		}
	}
	return 0;
}