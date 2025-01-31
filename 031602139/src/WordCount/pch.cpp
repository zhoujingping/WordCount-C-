// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"

// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
void counter::initInFilename(char tempName[])
{
	inFilename = (char*)malloc(strlen(tempName) * sizeof(char));
	strcpy(inFilename, tempName);
}

void counter::countPerLine(string line)
{
	int i = 0;
	// empty line
	while (i < line.length() && isspace(line[i]))
	{
		char_num++;
		i++;
	}
	if (i != line.length())
	{
		line_num++;
		while (i < line.length())
		{
			if (line[i] > 0)
				char_num++;
			i++;
		}
	}
}

pair<int,int> counter::countCharLine()
{
	ifstream inFile(inFilename, ios::in);
	if (inFile.fail())cout << "fail to open input file\n";
	while (inFile)
	{
		string line;
		getline(inFile, line);
		if (inFile.fail() && line == "")
			break;
		if (!inFile.eof())
			line += '\n';
		countPerLine(line);
	}
	inFile.close();
	return pair<int, int>(char_num, line_num);
}

void counter::splitPerLine(string line)
{
	int i = 0;
	while (i < line.length())
	{
		// handle characters before a word
		while (i < line.length() && !isalpha(line[i]))
		{
			if (isdigit(line[i]))  // handle 123file
			{
				while (isalnum(line[i]) && i < line.length())
				{
					i++;
				}
			}
			i++;
		}
		// handle a word
		string tempWord;
		while (i < line.length())
		{
			if (isalpha(line[i]))
			{
				tempWord += tolower(line[i]);
			}
			if (isdigit(line[i]))
			{
				if (tempWord.length() < 4)
				{
					i++;
					break;
				}
				else
				{
					tempWord += line[i];
				}
			}
			if (!isalnum(line[i]) || i == line.length() - 1)
			{
				if (tempWord.length() >= 4)
				{
					map<string, int>::iterator iter;
					iter = dic.find(tempWord);
					if (iter != dic.end())
						iter->second++;
					else
						dic.insert(pair<string, int>(tempWord, 1));
				}
				i++;
				break;
			}
			i++;
		}
	}
}

void counter::initDic()
{
	ifstream inFile(inFilename, ios::in);
	if (inFile.fail())cout << "fail to open input file\n";
	while (inFile)
	{
		string line;
		getline(inFile, line);
		if (inFile.fail() && line == "")
			break;
		splitPerLine(line);
	}
	inFile.close();
}

int counter::countWord()
{
	initDic();
	map<string, int>::iterator iter;
	for (iter = dic.begin(); iter != dic.end(); iter++)
		word_num += iter->second;
	return word_num;
}

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.second != b.second)
		return a.second > b.second;
	else if (a.first != b.first)
		return a.first < b.first;
}

vector<pair<string,int> > counter::frequency()
{
	sortedDic.assign(dic.begin(), dic.end());
	sort(sortedDic.begin(), sortedDic.end(), cmp);
	return sortedDic;
}

/////////////////////////////////////////////


void counter::print(char * outFilename)   
{
	
	ofstream outFile(outFilename,ios::out);
	if (outFile.fail())cout << "fail to open output file\n";
	outFile<<"characters: "<<char_num<<endl;
	outFile<<"words: "<<word_num<<endl;
	outFile<<"lines: "<<line_num<<endl;

	for(int i=0;i<sortedDic.size() && i<10 ;i++)
		outFile<<"<"<<sortedDic[i].first<<">"<<": "<<sortedDic[i].second<<endl;

	outFile.close();

	/*
	cout << "characters: " << char_num << endl;
	cout << "words: " << word_num << endl;
	cout << "lines: " << line_num << endl;

	for (int i = 0; i < sortedDic.size(); i++)
		cout << "<"<<sortedDic[i].first << ">"<<": " << sortedDic[i].second << endl;
	*/
}