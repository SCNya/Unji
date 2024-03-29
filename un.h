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
	void Find();
private:
    void Go();
    void Fill();
    void Open();
    void Start();
    void Create();
    void Boot();
    void Clear();
    bool err;
	int *len, *size, *k;
	ifstream *in;
	string *str, *mass;
	stringstream *ss;
};

#endif // UN_H
