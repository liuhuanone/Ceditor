#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
char path[100] = "c:\\users\\liuxi_001\\desktop\\";
FILE *fp;
char fname[50];
char a[200];
char *lineNo[5];

//打开文件
void open(char fname[])
{


    int text;
    int i = 0;
    int j = 0;
    strcat(path, fname);
    fp=fopen(path, "r");
    //打开文件不存在新建
    if(fp==NULL)
    {
        fp = fopen(path, "w+");
        fclose(fp);
        fp = fopen(path, "r+");
    }

     //显示文件一行30个汉字
     text = fgetc(fp);
     while(text !=  EOF)
    {
        lineNo[j] = (char*)malloc(2*300);
        lineNo[j][i] = text;
        printf("%c", lineNo[j][i]);
        text = fgetc(fp);
//        i++;
//        if(i%60 == 0)
//        {
//            puts("\n");
//            j++;
//            lineNo[j] = (char*)malloc(2*30);
//        }

    }
    fclose(fp);
    free(lineNo[j]);

}

//写入文件
void write(char path[200])
{

    char *text = (char*)malloc(20000);
    fp=fopen(path, "a+");
    gets(text);
//    fputs(text, fp);
    int countline = 0;
    while(countline<5)
    {
        fwrite(text, 2, 30, fp);
        fputs("\n", fp);
        countline++;
    }
    fclose(fp);
    free(text);
}

//编辑文件
void edit(char path[200])
{
    int del;
    int i;
    fp = fopen(path, "w");
    del = getch();
    if(del = 8)
    {
        int len = strlen(a) -1;

        for(i=0; i<len; i++)
        {
            fprintf(fp, "%c", a[i]);
        }
        for(i=0; i<len; i++)
        {
            printf("%c", a[i]);
        }
    }
    getch();

}
int main(void)
{
    puts("请输入文件名：");
    gets(fname);
    open(fname);
    write(path);
//    edit(path);

}
