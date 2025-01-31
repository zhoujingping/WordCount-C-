// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<fstream>	//实现文本输入输出流的头文件 
using namespace std;
int main(int argc, char *argv[])//argc是命令行参数，*argv[]
{
	File f;
	if (!f.FileTest(argv))
	{
		return 0;//文件异常
	}
	Word w;
	fstream fout;
	fout.open("./result.txt", ios::out);
	fout << "characters: " << w.Countcharacters(argv[1]) << endl;
	fout << "words: " << w.Countwords(argv[1]) << endl;
	fout << "lines: " << w.Countlines(argv[1]) << endl;
	vector<pair<string, int>> v = w.Counttop10(argv[1]);
	vector<pair<string, int>>::iterator iter = v.begin();
	for (; iter != v.end(); iter++)
	{
		fout << "<"<< iter->first << ">: " << iter->second << endl;
	}
	fout.close();
    return 0;
}

