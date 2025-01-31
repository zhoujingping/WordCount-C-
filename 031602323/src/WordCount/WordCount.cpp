// WordCount.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void File::CharCount()
{
	string fname = this->name;
	this->Char = charCount(fname);
}

void File::WordCount()
{
	string fname = this->name;
	this->Word = wordCount(fname);
}

void File::WordSeq()
{
	string fname = this->name;
	wordSeq(fname, this->str);
}

void File::LineCount()
{
	string s;
	string fname = this->name;
	ifstream infile;
	infile.open(fname, ifstream::in);

	if (!infile.is_open())
		cout << "open error!" << endl;
	infile >> noskipws; 

	infile.clear();
	infile.seekg(0);

	while (infile)
	{
		getline(infile, s);
		Delete(s, " ");
		Delete(s, "\t");
		if (!s.empty()) Line++;
	}
}

void File::writeTxt()
{
	ofstream outfile;
	outfile.open("output.txt", std::ios::out | std::ios::app);
	if (!outfile.is_open())
		cout << "open error!" << endl;

	outfile << "characters:" << Char << endl;
	outfile << "words:" << Word << endl;
	outfile << "lines:" << Line << endl;
	for (int i = 0;!str[i].first.empty();i++)
	{
		outfile << '<' << str[i].first << '>' << ':' << str[i].second << endl;
	}
	outfile.close();
}

void File::print()
{
	cout <<"characters:" << Char << endl;
	cout <<"words:"<< Word << endl;
	cout <<"lines:"<< Line << endl;
	for (int i = 0;!str[i].first.empty();i++)
	{
		cout << '<' << str[i].first << '>' << ':' << str[i].second << endl;
	}
}


int main(int argc,const char* argv[])
{
	for (int i = 1;i < argc;i++)
	{
		string fname = argv[i];
		File fi(fname);
		
		fi.CharCount();
		fi.WordCount();
		fi.WordSeq();
		fi.LineCount();
	//	fi.print();
		fi.writeTxt();
	}
    return 0;
}

