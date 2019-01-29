#include <stdio.h>
#include <string.h>

int main()
{	
	char c, color[10];
	int needsPaste, size;
	FILE *file, *file2;
	
	file=fopen("white.srt", "rt");
	file2=fopen("yellow.srt", "wt");
	if (file==NULL || file2==NULL) {
		printf("Failed to open!");
		return 1;
	}
	
	printf("What color should it be? (hexa-ban, # nelkul)\n");
	gets(color); //  warning: the `gets' function is dangerous and should not be used.


	printf("What size? (18 is default)\n");
	scanf("%d", &size);

	needsPaste=0;
	while(fscanf(file, "%c", &c) != EOF)
	{	
		if(c=='>')
			needsPaste=1;
		
		if(c=='\n' && needsPaste)
		{
			//printf("%c", c);
			// original probably : <font color=\"#ffffff\" size=18>");
			fprintf(file2, "\n<font color=\"#%s\" size=%d>", color, size);
			needsPaste=0;
		}
		
		else
			//printf("%c", c);
			fprintf(file2, "%c", c);
	}

	fclose(file);
	fclose(file2);
	printf("\nDone.\n");
    return 0;
}
