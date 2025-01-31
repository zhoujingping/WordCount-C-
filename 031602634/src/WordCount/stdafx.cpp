#include "stdafx.h"

w s;
w str[20000];

bool isnum(char c)
{
	if (c >= '0' && c <= '9') return true;
	else return false;
}

bool ischar(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
	else return false;
}

int mycmpstruct(w a, w b)
{
	if (a.count != b.count) return a.count > b.count;
	if (a.count = b.count)
	{
		string aa = a.word;
		string bb = b.word;
		return aa < bb;
	}
}

myfile::myfile()
{
	chars = 0;
	lines = 1;
	words = 0;
}

void myfile::countchar(FILE *f)
{
	char ch;
	while (!feof(f))
	{
		ch = getc(f);
		if (ch >= 0 && ch <= 255) chars++;
	}
}

void myfile::countline(FILE *f)
{
	char ch;
	while (!feof(f))											//统计行数
	{
		ch = getc(f);
		if (ch == '\n') lines++;
	}
}

void myfile::countword(FILE  *f)
{
	char ch;
	int flag = 1;
	int x;
	int i, j;
	while (!feof(f))											//读单词写入结构体，并统计单词个数
	{
		ch = getc(f);
		if (ch == ' ' || ch == 10)								//出现空格或换行的情况跳过
		{
			flag = 1;
			continue;
		}
		if (isnum(ch))											//flag用于出现“7english”情况的错误判断
		{
			flag = 0;
			continue;
		}
		if ((ischar(ch)) && flag == 1)
		{														//当出现一个字母，并且前一个相邻的不是数字时进入
			int k = 0;
			x = 0;
			s.count = 1;
			while ((ischar(ch)) || (isnum(ch)))
			{
				if (x <= 3 && (isnum(ch)))						//没有符合至少以四个英文单词开头
				{
					k = k - x;
					flag = 0;
					break;
				}
				s.word[k++] = tolower(ch);						//将大写转换为小写
				ch = getc(f);
				x++;
			}
			if (flag == 0) continue;
			if (x <= 3)											//如果出现字符数小于4个的情况，不算单词
			{
				k = k - x;
				continue;
			}
			s.word[k++] = '\0';
			j = words;
			for (i = 0; i < j; i++)								//与结构体中比较，如果存在，则改单词次数+1
			{
				if (strcmp(s.word, str[i].word) == 0)
				{
					str[i].count++;
					break;
				}
			}
			if (words == 0 || i == j)							//不存在将单词写入结构体中
			{
				str[words++] = s;
			}
		}
	}
}

void myfile::px()
{
	sort(str, str + words, mycmpstruct);						//结构体排序，按出现次数从大到小排序
}


void myfile::fileoutput()
{
	fstream file("result.txt", ios::out);						//先清空输出文本
	fstream File("result.txt", ios::in | ios::out);
	File << "characters: " << chars << endl;
	File << "lines: " << lines << endl;
	File << "words: " << words << endl;
	int n = words;
	if (n > 10) n = 10;
	for (int i = 0; i < n; i++)
	{
		File <<"<"<< str[i].word << ">: " << str[i].count << endl;
	}
}

myfile::~myfile()
{

}
