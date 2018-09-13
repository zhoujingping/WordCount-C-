// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#include <string>
#include<cstring>
#include <stdio.h>
#include <tchar.h>
#include<map>
#include<iostream>
#include<fstream>	//实现文本输入输出流的头文件 
#include<vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Word
{
//单词类：统计单词的词频
private:
	int linesnum;
	int words;
	int characters;
	map<string, int> mapword;
	ifstream Fileread;
public:
	Word();//初始化
	int Countcharacters(char *argv);//统计字符数
	int Countlines(char *argv);//统计空白行
	int Countwords(char *argv);//统计单词数
	vector<pair<string,int>> Counttop10(char *argv);//统计前十个词
};
class File
{
//文本类：异常测试
public:
	File();
	int FileTest(char *argv[]);//异常测试
};

// TODO: 在此处引用程序需要的其他头文件
