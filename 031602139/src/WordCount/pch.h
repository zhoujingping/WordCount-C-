// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef PCH_H
#define PCH_H

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<fstream>
#include <cctype>
#include<map> 
#include<vector>
#include <algorithm>
#include<direct.h>
using namespace std;

class counter {
public:
	counter() {
		char_num = 0;
		line_num = 0;
		word_num = 0;
	}
	
	void initInFilename(char tempName[]);
	void countPerLine(string line);
	pair<int, int> countCharLine();

	void splitPerLine(string line);
	void initDic();
	int countWord();

	vector<pair<string, int> > frequency();

	void print(char * outFilename);
	
private:
	int char_num;
	int line_num;
	int word_num;
	char * inFilename;
	map<string, int> dic;   //<word, frequency>
	vector<pair<string, int> > sortedDic; 
};
#endif //PCH_H
