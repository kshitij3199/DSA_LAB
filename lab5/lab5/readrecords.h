typedef struct{
	long card_no;
	char bank_code[6];
	char exp_date[8];
	char f_name[6];
	char l_name[6];
} ccinfo;

extern ccinfo* readfile(ccinfo* ptr,long long int *cur_loc );