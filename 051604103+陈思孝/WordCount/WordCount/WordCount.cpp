// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include"WordCount.h"


int main(int argc,char *argv[])
{
	vector<Word> words;
	
	char *filename = argv[1];
	//char asd[70] = "D:/SE/PersonProject-C/051604103+陈思孝/WordCount/Debug/in1.txt";
	//char *filename = asd;
	//cout << filename << endl;
	vector<string> lines;
	
	int Count_Char = CountChar(filename);
	int Line_Count = LineCount(filename, lines);
	int Word_Number = WordNumber(filename);
	WordFCount(filename, words);
	SortResult(words);
	ResultOut(words, Count_Char, Word_Number, Line_Count);
	
	
	return 0;
}

