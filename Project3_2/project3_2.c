#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define LEN 5

typedef struct {
	char name[100];
	int number;
	int score[12];
	double avg;
} student;

void print_student(const student* s);
double get_mean(const student* s[], int len);

int main(void) {
	student students[LEN];
	for (int i = 0; i < LEN; i++) scanf("%s %d", students[i].name, &students[i].number);
	for (int i = 0; i < LEN; i++) {
		int j = 0, total = 0;
		do {
			scanf("%d", &students[i].score[j]);
			total += students[i].score[j];
		} while (students[i].score[j++] != -1);
		students[i].avg = (double)total / (j - 1);
	}
	printf("\n");
	for (int i = 0; i < LEN; i++) print_student(&students[i]);
	printf("\n");

	double mean = get_mean(&students, LEN);
	printf("전체 학생 평균 : %.2lf", mean);

	return 0;
}

void print_student(const student* s) {
	printf("%s %d ", s->name, s->number);
	for (int i = 0; s->score[i] != -1; i++) printf("%d ", s->score[i]);
	printf("%.2lf\n", s->avg);
}

double get_mean(const student* s, int len) {
	double total = 0;
	for (int i = 0; i < len; i++) total += s[i].avg;
	total /= len;
	return total;
}

/*
abc 10
bcd 11
cde 13
def 12
efg 14

100 90 90 95 -1
80 85 90 -1
85 95 100 -1
90 75 -1
95 80 85 75 90 -1
*/