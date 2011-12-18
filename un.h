#ifndef UN_H
#define UN_H
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Un
{

public:
	Un (string);
	~Un();
	string Doll (string, string &);
	string Go (string &);
	int Good_in();
	int Find();
	void Open();
	void Start();
	void Create();
	void Boot();
	void Word (string, int);
	bool Clear (string, string &, int &);

private:
	ifstream in;
	string str;
	stringstream ss;
};

#endif // UN_H
