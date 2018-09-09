// WordCount.cpp: 定义控制台应用程序的入口点。
#include "stdafx.h"
#include<iostream>
#include<fstream>	//实现文本输入输出流的头文件 
#include<string> 
#include<cstring>
#include<map>
using namespace std;
int main(int argc, char *argv[])//argc是命令行参数，*argv[]
{
	map<string, int> mapstr;
	multimap<int, string> mapint;
	map<string, int>::iterator iter;
	multimap<int, string>::iterator iter2;
	long snum = 0, j, i, num, rownum = 0, wordnum = 0;
	int ans, ans2, ansname, wordpos;
	string name, word;
	//读出文件
	ifstream rf;
	rf.open(argv[1]);
	while (!rf.eof())
	{
		getline(rf, name);
		ans = 0, ans2 = 0; ansname = 0; wordpos = 0;
		num = name.size();
		for (i = 0; i<num; i++)
		{
			if (name[i] >= 0 && name[i] <= 127)
			{
				snum++;
			}//统计字符数 
			if (!ans&&name[i] != 0x9 && name[i] != 0xd && name[i] != 0xa && name[i] != 0x20)
			{
				ans = 1;//标记； 
			}//统计空白行 
			if (65 <= name[i] && name[i] <= 90)name[i] += 32;//大小写转化
			if (97 <= name[i] && name[i] <= 122)
			{
				ans2++;
				continue;
			}
			if ('0' <= name[i] && name[i] <= '9')
			{
				if (ans2 >= 4)
					continue;
				else
				{
					for (j = i; j<num; j++)
					{
						if ('0' <= name[j] && name[j] <= '9')
							continue;
						else if ('a' <= name[j] && name[j] <= 'z')
							continue;
						else
						{
							while (j<num)
							{
								if ('a' <= name[j + 1] && name[j + 1] <= 'z')
								{
									wordpos = j + 1;
									break;
								}
								else
									j++;
							} //寻找下一个单词的开头 
							i = j;
							break;
						}
					}	//寻找下一个分隔符 
					if (j == num)
					{
						break;
					}	//寻找不到下一个分隔符 
					ans2 = 0;
				}
			}
			else
			{
				if (ans2 >= 4)
				{
					word = name.substr(wordpos, i - wordpos);
					//添加单词 

					iter = mapstr.find(string(word));
					if (iter != mapstr.end())
						iter->second += 1;
					else
					{
						mapstr.insert(pair<string, int>(word, 1));
					}
					//	cout<<"word:"<<word<<endl;
					wordnum++;
				}//获取单词
				while (i<num)
				{
					if ('a' <= name[i + 1] && name[i + 1] <= 'z')
					{
						wordpos = i + 1;
						break;
					}
					else
						i++;
				} //寻找下一个单词的开头 
				ans2 = 0;
			}
		}
		if (ans2 >= 4)
		{
			word = name.substr(wordpos, i - wordpos);
			iter = mapstr.find(string(word));
			if (iter != mapstr.end())
				iter->second += 1;
			else
			{
				mapstr.insert(pair<string, int>(word, 1));
			}
			//		cout<<"word:"<<word<<endl;
			wordnum++;
		}
		if (ans)
		{
			rownum++;
		}
		snum++;
		//	cout<<name<<endl;;	
	}
	iter = mapstr.begin();
	for (; iter != mapstr.end(); iter++)
	{
		mapint.insert(pair<int, string>(-iter->second, iter->first));
	}
	snum--;
	iter = mapstr.begin();
	/*
	//按字典序输出
	for(;iter!=mapstr.end();iter++)
	{
	cout<<iter->first<<" "<<iter->second<<endl;
	}
	*/
	cout << "characters: " << snum << endl;
	cout << "words: " << wordnum << endl;
	cout << "lines: " << rownum << endl;
	num = 0;
	for (iter2 = mapint.begin(); iter2 != mapint.end(); iter2++)
	{
		num++;
		printf("<%s>: %ld\n", iter2->second.c_str(), -(iter2->first));
		if (num == 10)
			break;
	}
	ofstream fout("result.txt");
	//按字典序输出 
	for (; iter != mapstr.end(); iter++)
	{
		fout << iter->first << endl;
	}
	fout.close();
	return 0;
}

