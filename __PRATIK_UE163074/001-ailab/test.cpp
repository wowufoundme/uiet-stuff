#include <iostream>
#include "tct_lib.cpp"
using namespace std;

int alpha_beta(int p1, int p2){
	int d, mv, mvs = movegen(p1, p2);
	while(mvs > 0){
		d = mvs % 10;
		if(d == 5)	{
			mv = 5;
			break;
		}
		else if ((d == 1 || d == 2 || d == 6 || d == 9) && mv != 5)
		{
			mv = d;
		}
		else{
			mv = d;
		}
		mvs /= 10;
	}
	return mv;
}

int main(){
	int (*ai)(int, int) = alpha_beta;
	game(ai);
	return 0;
}