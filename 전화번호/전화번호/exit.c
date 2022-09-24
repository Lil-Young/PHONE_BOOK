#include<stdio.h> //printf, scanf 사용을 위해 헤더파일 선언
#include"my_struct.h"
//#include<string>
//test2
void end(Phonelist* head, Phonelist* tail) {
	Phonelist* file_p = NULL;
	file_p = head->next;
	FILE* fp = NULL;
	fp = fopen("c.txt", "w");
	while (file_p->next != NULL) {
		if (file_p->next->next == NULL) {
			fprintf(fp, "%s %s", file_p->name, file_p->phone_num);
		}
		else {
			fprintf(fp, "%s %s\n", file_p->name, file_p->phone_num);
		}
		file_p = file_p->next;
	}
	fclose(fp);
	return 0;
}