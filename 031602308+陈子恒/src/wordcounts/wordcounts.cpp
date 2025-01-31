#include "pch.h"
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;
bool cmp(const pair<string, int> &p1, const pair<string, int> &p2)
{
	return p1.second > p2.second;
}//定义一个sort的比较模式，从大到小排序 
int CountLines(char *filename)
{
	ifstream ReadFile;
	int n = 0;
	char line[512];
	string temp;
	ReadFile.open(filename, ios::in);
	if (ReadFile.fail())
	{
		return 0;
	}
	else
	{
		while (getline(ReadFile, temp))
		{
			if (temp.empty()) continue;
			n++;
		}
		return n;
	}
	ReadFile.close();
}//统计文本行数 

int Countcharacters(char *filename)
{
	ifstream ReadFile;
	int m = 0;
	char characters;
	ReadFile.open(filename);
	ReadFile >> noskipws;
	if (ReadFile.fail())
	{
		return 0;
	}
	else
	{
		while (!ReadFile.eof())
		{
			ReadFile >> characters;
			m++;
		}
		return m;
	}
	ReadFile.close();
}//统计文本字数 
int main(int argc, char *argv[]) {
	int sum = 0;
	int i = 0;
	int j = 0;
	cout << "characters:" << Countcharacters(argv[1]) << endl;
	cout << "lines:" << CountLines(argv[1]) << endl;
	ifstream in(argv[1]);
	map<string, int> words;//用map存储单词及其数量 
	string temp;
	while (in >> temp)
	{
		for (j = 0; temp[j]; j++)
		{
			if (temp[j]<'0' || (temp[j] > '9'&&temp[j] < 'A') || (temp[j] > 'Z'&&temp[j] < 'a') || temp[j]>'z')
			{
				break;
			}
			if (temp[j] >= 'A'&&temp[j] <= 'Z')
			{
				temp[j] += 32;
			}//大写字母转小写               
		}
		istringstream istrm(temp);
		double d;
		if (!(istrm >> d)) ++words[temp];
	}
	vector<pair<string, int> > arr;
	for (map<string, int>::iterator it = words.begin(); it != words.end(); ++it)
	{
		arr.push_back(make_pair(it->first, it->second));
	}//将map的单个单词及数目存入vector容器并进行字典排序 
	ofstream out("result.txt");
	for (vector<pair<string, int> >::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		out << it->first << " ";
	}//输出到result文本 
	sort(arr.begin(), arr.end(), cmp);//value排序 
	for (map<string, int>::iterator it = words.begin(); it != words.end(); ++it)
	{
		sum = sum + it->second;
	}
	cout << "words:" << sum << endl;
	for (vector<pair<string, int> >::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		cout << "<" << it->first << ">" << ":" << it->second << endl;
		i++;
		if (i == 10)
		{
			break;
		}
	}
	i = 0;

	return 0;
}