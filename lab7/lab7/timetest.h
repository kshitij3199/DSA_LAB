typedef struct {
	double istime;
	double QStime;
}tt ;


extern tt testRun(Record Ls[],int size);
extern int estimateCutoff(Record Ls[],int min,int max);