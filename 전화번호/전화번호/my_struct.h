// 사용할 자료형 구조체
typedef struct phonelist {
	char* name;
	char* phone_num;
	struct phonelist* next;
	struct phonelist* prev;
}Phonelist;