#include <iostream>
using namespace std;

void display_grid(int p1, int p2){
	int d, grid[9] = {0};
	while(p1 > 0){
		d = p1 % 10;
		grid[d-1] = 1;
		p1 /= 10;
	}
	while(p2 > 0){
		d = p2 % 10;
		grid[d-1] = 2;
		p2 /= 10;
	}
	char c;
	cout<<endl;
	for(int i = 0; i < 9; i++){
		if(grid[i] == 1) c = 'X';
		else if(grid[i] == 2) 	c = 'O';
		else c = ' ';
		cout<<" "<<c<<"  ";
		if(i % 3 == 2 && i != 8) std::cout<<"\n---+---+---\n";
	}
	cout<<endl;
}

int playmove(){
	int val;
	cout<<"Enter the move you want to play ";
	cin>>val;
	return val;
}

int g_check(int x){
	bool flag = false, mvs[9] = {false};
	int d;
	while(x > 0){
		d = x % 10;
		x /= 10;
		mvs[d-1] = true;
	}
	for(int i = 0; i < 3; i++){
		if(mvs[i*3] && mvs[i*3 + 1] && mvs[i*3 + 2]) flag = true;
		if(mvs[i] && mvs[i + 3] && mvs[i + 6]) flag = true; 
	}
	if(mvs[0] && mvs[4] && mvs[8]) flag = true;
	if(mvs[2] && mvs[4] && mvs[6]) flag = true;
	return flag;
}

int movegen(int p1, int p2){
	int d;
	bool grid[9] = {0};
	while(p1 > 0){
		d = p1 % 10;
		grid[d-1] = 1;
		p1 /= 10;
	}
	while(p2 > 0){
		d = p2 % 10;
		grid[d-1] = 1;
		p2 /= 10;
	}
	d = 0;
	for(int i = 0; i < 9; i++){
		if(!grid[i]) d = d*10 + (i+1);
	}
	return d;
}

void game(int (*ai)(int, int)){
	int mv, p1 = 0, p2 = 0, turn = 0;
	bool res = false, flag = false;
	cout<<"Do you want to play first "; cin>>flag;
	while(!res && turn < 9){
		display_grid(p1, p2);
		if((turn + flag) % 2 == 1){
		   mv = playmove();
		   p1 = p1*10 + mv;
		   res = g_check(p1);
		}
		else{
			mv = ai(p1, p2);
			p2 = p2*10 + mv;
			res = g_check(p2);
		}
		turn++;
	}
	cout<<"\nGame Ends\n";
	display_grid(p1, p2);		
}
