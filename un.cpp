#include "un.h"

Un::Un (string n)
{
	str=n;
	Start();
}

Un::~Un()
{}

void Un::Start()
{
	Open();
	Boot();
}

void Un::Open()
{
	in.open(str.c_str());
	if (Good_in()!=0) cout << "Error: 1" << endl;
}

int Un::Good_in()
{
	if (!in.good()) return (-1);
	else return (0);
}

void Un::Create()
{}

void Un::Boot()
{
	ss << in.rdbuf();
	str=ss.str();
	ss.str("");
	ss.clear();
	in.close();
}
int Un::Find()
{
	int k (0);
	string temp (str), cut;
	bool y (true);
	while (y==true)
		{
			cut=Go (temp);
			y=Clear (cut, temp, k);
		}
	cout << endl;
	return (k);
}

string Un::Go (string & temp)
{
	int i (0);
	string cut;
	do
		{
			if ((((temp [i]<='&') || (temp [i]>'/'))) && (((temp [i]<' ') || (temp [i]>='&'))) && (temp [i]!='\n') && (temp [i]!=0) && (temp [i]!='\\') && (temp [i]!='~') && (temp [i]!='?') && (temp [i]!='<') && (temp [i]!='>'))
				{
					ss << temp [i];
					if (((temp [(i+1)]>=' ') && (temp [(i+1)]<'&')) || (temp [(i+1)]==0) || (temp [(i+1)]=='\\') || (temp [(i+1)]=='~') || (temp [(i+1)]=='?') || (temp [(i+1)]=='<') || (temp [(i+1)]=='>'))
						{
							cut=Doll (ss.str(), temp);
							ss.str("");
							ss.clear();
							break;
						}
				}
			i++;
		}
	while (i<temp.size());
	return (cut);
}

string Un::Doll (string t, string & temp)
{
	int i (0);
	string cut;
	ss.str("");
	ss.clear();
	do
		{
			if ((((temp [i]<='&') || (temp [i]>'/'))) && (((temp [i]<' ') || (temp [i]>='&'))) && (temp [i]!='\n') && (temp [i]!=0) && (temp [i]!='\\') && (temp [i]!='~') && (temp [i]!='?') && (temp [i]!='<') && (temp [i]!='>'))
				{
					ss << temp [i];
					if (((temp [(i+1)]>=' ') && (temp [(i+1)]<'&')) || (temp [(i+1)]==0) || (temp [(i+1)]=='\\') || (temp [(i+1)]=='~') || (temp [(i+1)]=='?') || (temp [(i+1)]=='<') || (temp [(i+1)]=='>'))
						{
							if (ss.str()==t)
								{
									cut=ss.str();
									break;
								}
							ss.str("");
							ss.clear();
						}
				}
			i++;
		}
	while (i<temp.size());
	return (cut);
}

bool Un::Clear (string cut, string &temp, int &k)
{
	int i (0), h (0);
	bool y (false);
	stringstream tss;
	ss.str("");
	ss.clear();
	do
		{
			if ((((temp [i]<='&') || (temp [i]>'/'))) && (((temp [i]<' ') || (temp [i]>='&'))) && (temp [i]!='\n') && (temp [i]!=0) && (temp [i]!='\\') && (temp [i]!='~') && (temp [i]!='?') && (temp [i]!='<') && (temp [i]!='>'))
				{
					ss << temp [i];
					if (((temp [(i+1)]>=' ') && (temp [(i+1)]<'&')) || (temp [(i+1)]==0) || (temp [(i+1)]=='\\') || (temp [(i+1)]=='~') || (temp [(i+1)]=='?') || (temp [(i+1)]=='<') || (temp [(i+1)]=='>'))
						{
							if (ss.str()!=cut)
								{
									y=true;
									tss << ss.str();
								}
							else h++;
							ss.str("");
							ss.clear();
						}
				}
			else tss << temp [i];
			i++;
		}
	while (i<temp.size());
	temp=tss.str();
	if (h>1)
		{
			k++;
			cout << "\nWord " << k << ": " << cut << endl;
		}
	return (y);
}
