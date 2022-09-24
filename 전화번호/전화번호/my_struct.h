typedef struct phonelist {
	char* name;
	char* phone_num;
	struct phonelist* next;
	struct phonelist* prev;
	int value;
}Phonelist;