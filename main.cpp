//Unji by Alexeenko Vsevolod 21.12.2011 20:00 ver. alpha 0.2.1 (ASCII)
#include <un.h>

int main()
{
    Un*one = new Un("bbe.txt");
	one->Find();
	delete one;
	return (0);
}
