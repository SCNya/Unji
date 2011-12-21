#include "un.h"

Un::Un (string n)
{
	str=new string;
	ss=new stringstream;
	len=new int (0);
	k=new int (0);
	size=new int (0);
	*str=n;
	Start();
}

Un::~Un()
{
	delete ss, len, k, size, str, in;
	delete [] mass;
}

void Un::Start()
{
	Open();
	Boot();
}

void Un::Open()
{
	in=new ifstream;
	(*in).open((*str).c_str());
	if (!(*in).good()) cout << "Error: 1" << endl;
}

void Un::Create()
{
	Go();
	mass=new string [*len];
	Fill();
}

void Un::Boot()
{
	*ss << (*in).rdbuf();
	*str=(*ss).str();
	*size=(*str).size();
	(*in).close();
}

void Un::Find()
{
	Create();
	Clear();
}

void Un::Go()
{
	int i (0);
	(*ss).str("");
	(*ss).clear();
	do
		{
			if (((((*str) [i]<' ') || ((*str) [i]>='&'))) && ((((*str) [i]<='&') || ((*str) [i]>'/'))) && ((*str) [i]!='\n') && ((*str) [i]!=0) && (((*str) [i]<'[') || ((*str) [i]>'^')) && ((*str) [i]!='~') && (((*str) [i]<':') || ((*str) [i]>'?')) && (((*str) [i]<'{') || ((*str) [i]>'~')))
				{
					if ((((*str) [(i+1)]>'&') && ((*str) [(i+1)]<='/')) || (((*str) [(i+1)]>=' ') && ((*str) [(i+1)]<'&')) || ((*str) [(i+1)]==0) || (((*str) [(i+1)]>='[') && ((*str) [(i+1)]<='^')) || ((*str) [(i+1)]=='~') || (((*str) [(i+1)]>=':') && ((*str) [(i+1)]<='?')) || (((*str) [(i+1)]>='{') && ((*str) [(i+1)]<='~')))
						{
							(*len)++;
						}
				}
			i++;
		}
	while (i<*size);
}

void Un::Fill()
{
	int i (0), j (0);
	(*ss).str("");
	(*ss).clear();
	do
		{
			if (((((*str) [i]<' ') || ((*str) [i]>='&'))) && ((((*str) [i]<='&') || ((*str) [i]>'/'))) && ((*str) [i]!='\n') && ((*str) [i]!=0) && (((*str) [i]<'[') || ((*str) [i]>'^')) && ((*str) [i]!='~') && (((*str) [i]<':') || ((*str) [i]>'?')) && (((*str) [i]<'{') || ((*str) [i]>'~')))
				{
					*ss << (*str) [i];
					if ((((*str) [(i+1)]>'&') && ((*str) [(i+1)]<='/')) || (((*str) [(i+1)]>=' ') && ((*str) [(i+1)]<'&')) || ((*str) [(i+1)]==0) || (((*str) [(i+1)]>='[') && ((*str) [(i+1)]<='^')) || ((*str) [(i+1)]=='~') || (((*str) [(i+1)]>=':') && ((*str) [(i+1)]<='?')) || (((*str) [(i+1)]>='{') && ((*str) [(i+1)]<='~')))
						{
							mass [j]=(*ss).str();
							(*ss).str("");
							(*ss).clear();
							j++;
						}
				}
			i++;
		}
	while (i<*size);
}

void Un::Clear()
{
	int i (0), j, h (0);
	string cut (mass [i]);
	do
		{
			if (mass [i]!="")
				{
					cut=mass [i];
					j=0;
					h=0;
					do
						{
							if (mass [j]==cut)
								{
									h++;
									mass [j]="";
								}
							j++;
						}
					while (j<*len);
					if (h>1)
						{
							(*k)++;
							cout << "\nWord " << *k << ": " << cut << endl;
						}
				}
			i++;
		}
	while (i<*len);
	cout << "\nWords that occur more than once: " << *k << endl;
}
