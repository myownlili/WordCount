#include<stdio.h>
#include<string.h> 
int CharCount(char *Path)
{
	int Ccount =0;
	char txt;
	FILE *file=fopen(Path,"r");
	while((txt=fgetc(file))!=EOF)
	{
		if(txt != ' ' && txt != '\t' && txt != '\n')
		{
			Ccount++;
		}
	}
	fclose(file);
    printf("字符数：%d\n",Ccount);
}

int WordCount(char *Path)
{
	int Wcount =1;
	char word;
	FILE *file=fopen(Path,"r");
	while((word=fgetc(file))!=EOF)
	{
		if(word == ',' || word == ' ' || word == '.')
		{
			Wcount++;
		}
	}
	fclose(file);
    printf("单词数：%d\n",Wcount);
}

int main(int argc, char* argv[])             
{
    FILE *fp;
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("目标文件不存在\n\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(!strcmp(argv[1],"-w")) 
        WordCount(argv[2]);                
        else if(!strcmp(argv[1],"-c"))  
        CharCount(argv[2]);                
        else
            printf("NullPoint\n");
        printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
    }
    return 0;
}
