#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* menu[6] = { "���� �б�", "�߰�", "���", "�˻�", "���� ����", "����"};
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

		printf("���� ���� �Է��Ͻÿ�: ");
		scanf("%d", &num);

		if (num == 1) {
			fp = fopen("book.txt", "r");
			if (fp == NULL) {
				printf("���� ���� ����\n");
				exit(1);
			}
			else {
				printf("���� ���� ����!\n");
			}
		}
		else if (num == 2) {
			fp = fopen("book.txt", "a");
			printf("������ �̸�: ");
			scanf("%s", book);
			printf("����: ");
			scanf("%s", author);
			printf("���ǻ�: ");
			scanf("%s", publisher);

			fprintf(fp, "\n%s %s %s", book, author, publisher);
			fclose(fp);
		}
		else if (num == 3) {
			if ((fp = fopen("book.txt", "r")) == NULL) {
				fprintf(stderr, "���� ������ �� �� �����ϴ�.\n");
				exit(1);
			}
			else {
				while (!feof(fp)) {
					fscanf(fp, "%s %s %s", book, author, publisher);
					printf("����: %s\n", book);
					printf("����: %s\n", author);
					printf("���ǻ�: %s\n", publisher);
				}
			}
		}
		else if (num == 4) {
			printf("����: ");
			scanf("%s", book_pub);
			if ((fp = fopen("book.txt", "r")) == NULL) {
				fprintf(stderr, "���� ������ �� �� �����ϴ�.\n");
				exit(1);
			}
			else {
				while (!feof(fp)) {
					fscanf(fp, "%s %s %s", book, author, publisher);
					if (strcmp(book, book_pub) == 0) {
						printf("���ǻ�� %s\n", publisher);
					}
				}
				fclose(fp);
			}
		}
		else if (num == 5) {
			fp = fopen("book.txt", "a");
			if (fp == NULL) {
				printf("���� ���� ����\n");
			}
			else {
				printf("���� ���� ����!(2)\n");
			}
		}
		else if (num == 6) {
			break;
		}
	}
	return 0;
}