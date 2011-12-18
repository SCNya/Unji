//Unji by AEffect 18.12.2011 21:43 ver. alpha 0.1 (ASCII)
#include <un.h>

int main()
{
	Un*one=new Un("f.txt");
	cout << "Words that occur more than once: " << one->Find();
	delete one;
	return (0);
}
