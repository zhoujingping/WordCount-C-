// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include"WordCount.h"
using namespace std;

int main(int argc,char *argv[])
{
	//string filename = argv[1];
	//cout << "文件名为： " << filename << endl;
	int k = 0;
	Word words[100];
	for (int i = 0; i < 100; i++)
	{
		words[i].cnt = 0;
	}
	vector<string> lines;
	GetFile(lines);
	int Line_count = LineCount(lines);
	//cout << Line_count << endl;
	int Count_char=CountChar(lines, Line_count);
	//cout << Count_char << endl;
	int Word_num=WordNumber(lines);
	//cout << Word_num << endl;

	Lower(lines);
	WordFCount(lines, words, k);
	SortResult(words, k);
	ResultOut(words, Count_char, Word_num, Line_count);
	
	
	
    return 0;
}

