#include"pch.h"
#include<iostream> 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<fstream>
#include"readchars.h"
#include"readlines.h"
#include"readword.h"
#include"sort.h"
#include"structword.h"
using namespace std;

/*****************************主函数****************************/
int main()
{
	char filename[60];
	struct word *head;
	head = new word;
	head->next = NULL;
	int file_lines = 0;
	int file_chars = 0;
	int word_num = 0;
	int i = 0;
	char c;
	for (i = 0;(c = getchar()) != '\n'&&i < 59;i++)
	{
		filename[i] = c;
	}
	filename[i] = '\0';
	FILE *file = _fsopen(filename, "r", _SH_DENYNO);
	if (!file)
	{
		printf( "打开文件错误！" );
		return 0;
	}
	else
	{
		readchars(head, filename, file_chars);
		readword(head, filename, word_num);
		readlines(head, filename, file_lines);
		sort(head);
	}

}
