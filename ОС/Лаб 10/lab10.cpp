#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>


int counter = 1;
FILE *file1, *file2, *file3;
struct stat buff;

void table(){
	printf("NAME\t\tMODE\tUSER\tSIZE\n");
	
	for (int i = 1; i < counter; ++i)
	{
		char ch[4];
		char str[32] = "file";
		sprintf(ch, "%d", i);
		strcat(str, ch);
		strcat(str, ".txt");
		stat(str, &buff);
		printf("\t\n%s\t%d\t%d\t%ld\n", str, buff.st_mode,buff.st_uid,buff.st_size);
		
	}
}
int main()
{
	
	
	if(file1 = fopen("file1.txt", "r"))
	{
		printf("file1:\n");
		counter++;
		table();
	}
	if(file2 = fopen("file2.txt", "r"))
	{
		printf("\nfile2:\n");
		counter++;
		table();
	}
	if(file3 = fopen("file3.txt", "r"))
	{
		printf("\nfile3:\n");
		counter++;
		table();
	}
	if(file3 = freopen("file3.txt", "w", file3)) table();
	
	printf("\n\nfile1 => file3:\n");
	char a;
	while( (a = fgetc(file1) ) != EOF )
	{
		fputc(a, file3);
	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
	table();
	return 0;
}