// fopen, fclose, fprintf, fscanf
#include<stdio.h>
// 사용할 자료형
#include"my_struct.h"
//fopen 보안 경고로 인한 컴파일 에러 방지
#define _CRT_SECURE_NO_WARINGS

// 함수 end를 void형으로 선언하고 매개변수(파라미터)로 전달된 인자를 받는다.
void end(Phonelist* head) {

	// 포인터변수 선언 및 초기화
	Phonelist* file_p = NULL;
	file_p = head->next;
	FILE* fp = NULL;

	// PHONE_BOOK.txt 파일을 w(쓰기) 모드로 열기
	fp = fopen("PHONE_BOOK.txt", "w");

	// file_p->next가 NULL이 아니면 반복문을 돌리고 NULL이 되면 반복문을 종료한다.
	while (file_p->next != NULL) {

		/*
		fprintf: 문자열을 파일에 저장
		file_p->next->next가 NULL이면 fprintf 아니면 else로 이동하고 fprintf
		파일 끝에 공백을 두지 않기 위함.
		*/
		if (file_p->next->next == NULL) {
			fprintf(fp, "%s %s", file_p->name, file_p->phone_num);
		}
		else {
			fprintf(fp, "%s %s\n", file_p->name, file_p->phone_num);
		}

		// 포인터변수 file_p는 file_p->next를 가리킨다.
		file_p = file_p->next;
	}
	// 파일 포인터 닫기
	fclose(fp);

	return 0;
}