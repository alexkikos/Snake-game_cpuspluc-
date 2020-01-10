#include "Menu.h"
#include <time.h>
int main(){
	system("mode con cols=180 lines=50");
	setlocale(LC_ALL, "");
	srand(time(0));
	Menu a;
	while(a.StartGame()==true);
	return 0;
}