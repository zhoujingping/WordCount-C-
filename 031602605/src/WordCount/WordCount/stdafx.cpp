// stdafx.cpp : 只包括标准包含文件的源文件
// WordCount.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"


// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用
Word::Word()
{
	//初始化
	linesnum = 0;
	characters = 0;
	words = 0;
	mapword.clear();
}
int Word::Countlines(char *argv)
{
	string name;
	long ans, num,i;
	ifstream Fileread;
	Fileread.open(argv, std::ios::in);
	if (Fileread.fail())
	{
		printf("file isn't exist\n");
		return -1;
	}
	while (!Fileread.eof())
	{
		getline(Fileread, name);
		ans = 0;
		num = name.size();
		for (i = 0; i < num; i++)
		{
			//去掉一些特殊项
			if (!ans&&name[i] != 0x9 && name[i] != 0xd && name[i] != 0xa && name[i] != 0x20)
			{
				ans = 1;//标记； 
			}//统计空白行 
		}
		if(ans)linesnum++;
	}
	Fileread.close();
	return linesnum;
}
int Word::Countwords(char *argv)
{
	map<string, int>::iterator iter;
	string name,word;
	long ans, num, i, j, wordpos;
	ifstream Fileread;
	Fileread.open(argv, std::ios::in);
	if (Fileread.fail())
	{
		printf("file isn't exist\n");
		return -1;
	}
	while (!Fileread.eof())
	{
		getline(Fileread, name);
		ans = 0; wordpos = 0;
		num = name.size();
		for (i = 0; i<num; i++)
		{
			if (65 <= name[i] && name[i] <= 90)name[i] += 32;//大小写转化
			if (97 <= name[i] && name[i] <= 122)
			{
				ans++;
				continue;
			}
			if ('0' <= name[i] && name[i] <= '9')
			{
				if (ans >= 4)
				{
					continue;
				}				
				else
				{
					for (j = i+1; j<num; j++)
					{
						if ('0' <= name[j] && name[j] <= '9')
							continue;
						else if (('a' <= name[j] && name[j] <= 'z') || ('A' <= name[j] && name[j] <= 'Z'))
							continue;
						else
						{
							while (j<num)
							{
								if (('a' <= name[j + 1] && name[j + 1] <= 'z') || ('A' <= name[j + 1] && name[j + 1] <= 'Z'))
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
					ans = 0;
				}
			}
			else
			{
				if (ans >= 4)
				{
					//添加单词 
					words++;
				}//获取单词
				while (i<num)
				{
					if (('a' <= name[i + 1] && name[i + 1] <= 'z') || ('A' <= name[i + 1] && name[i + 1] <= 'Z'))
					{
						break;
					}
					else
						i++;
				} //寻找下一个单词的开头 
				ans = 0;
			}
		}
		if (ans >= 4)
		{
			//		cout<<"word:"<<word<<endl;
			words++;
		}
	}
	Fileread.close();
	return words;
}
int Word::Countcharacters(char *argv)
{
	//统计ascll码的数量
	string name;
	long  num, i;
	ifstream Fileread;
	Fileread.open(argv, std::ios::in);
	if (Fileread.fail())
	{
		printf("file isn't exist\n");
		return -1;
	}
	while (!Fileread.eof())
	{
		getline(Fileread, name);
		num = name.size();
		for (i = 0; i < num; i++)
		{
			if (name[i] >= 0 && name[i] <= 127)
			{
				characters++;
			}//统计字符数 
		}
		characters++;
	}
	characters--;
	Fileread.close();
		//	cout<<name<<endl;;	
	return characters;
}
vector<pair<string, int>> Word::Counttop10(char *argv)
{
	//利用多重映射的multimap,将单词按词频字典序排序，之后用vector存储前十的单词
	mapword.clear();
	map<string, int>::iterator iter;
	multimap<int, string> mapint;
	multimap<int, string>::iterator iter2;
	string name, word;
	long ans, num, i, j, wordpos;
	vector<pair<string, int>> top10;
	ifstream Fileread;
	Fileread.open(argv, std::ios::in);
	if (Fileread.fail())
	{
		printf("file isn't exist\n");
		return top10;
	}
	while (!Fileread.eof())
	{
		getline(Fileread, name);
		ans = 0; wordpos = 0;
		num = name.size();
		for (i = 0; i<num; i++)
		{
			if (65 <= name[i] && name[i] <= 90)name[i] += 32;//大小写转化
			if (97 <= name[i] && name[i] <= 122)
			{
				ans++;
				continue;
			}
			if ('0' <= name[i] && name[i] <= '9')
			{
				if (ans >= 4)
				{
					continue;
				}
				else
				{
					for (j = i; j<num; j++)
					{
						if ('0' <= name[j] && name[j] <= '9')
							continue;
						else if (('a' <= name[j] && name[j] <= 'z') || ('A' <= name[j] && name[j] <= 'Z'))
							continue;
						else
						{
							while (j<num)
							{
								if (('a' <= name[j + 1] && name[j + 1] <= 'z') || ('A' <= name[j + 1] && name[j + 1] <= 'Z'))
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
					ans = 0;
				}
			}
			else
			{
				if (ans >= 4)
				{
					//添加单词 
					word = name.substr(wordpos, i - wordpos);
					iter = mapword.find(string(word));
					if (iter != mapword.end())
						iter->second += 1;
					else
						mapword.insert(pair<string, int>(word, 1));
					
					//	cout<<"word:"<<word<<endl;
				}//获取单词
				while (i<num)
				{
					if (('a' <= name[i + 1] && name[i + 1] <= 'z') || ('A' <= name[i + 1] && name[i + 1] <= 'Z'))
					{
						wordpos = i + 1;
						break;
					}
					else
						i++;
				} //寻找下一个单词的开头 
				ans = 0;
			}
		}
		if (ans >= 4)
		{
			word = name.substr(wordpos, i - wordpos);
			iter = mapword.find(string(word));
			if (iter != mapword.end())
				iter->second += 1;
			else
			{
				mapword.insert(pair<string, int>(word, 1));
			}
			//		cout<<"word:"<<word<<endl;
		}
	}
	num = 0;
	iter = mapword.begin();
	for (; iter != mapword.end(); iter++)
	{
		mapint.insert(pair<int, string>(-iter->second, iter->first));
	}
	for (iter2 = mapint.begin(); iter2 != mapint.end(); iter2++)
	{
		num++;
		top10.push_back(make_pair(iter2->second.c_str(), -(iter2->first)));
		if (num == 10)
			break;
	}
	Fileread.close();
	return top10;
}
File::File(){}
int File::FileTest(char *argv[])
{
	int ans = 1;
	if (argv[1] == NULL)
	{
		printf("no file\n");
		ans=0;
	}
	if (argv[2] != NULL)
	{
		printf("too much\n");
		ans = 0;
	}
	fstream Fileread;
	Fileread.open(argv[1], std::ios::in);
	if (Fileread.fail())
	{
		printf("file isn't exist\n");
		ans = 0;
	}
	Fileread.close();
	return ans;
}