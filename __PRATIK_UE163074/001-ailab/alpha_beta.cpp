#include <iostream>
#include <algorithm>
#include "tct_lib.cpp"
using namespace std;
#define INF 1000000

int max_depth;

int mv;

int heuristic(int p1, int p2, int depth){
	int val;
	if(g_check(p1)) return 1000;
	if(g_check(p2)) return -1000;

	int d, grid[9] = {0};
	while(p1 > 0){
		d = p1 % 10;
		p1 /= 10;
		grid[d-1] = 1; 
	}

	while(p2 > 0){
		d = p2 % 10;
		p2 /= 10;
		grid[d-1] = 2; 
	}

	int v1, v2;
	v1 = (grid[4] == 1)*20  
		  + (grid[0] == 1 + grid[2] == 1 + grid[3] == 1 + grid[5] == 1 + grid[6] == 1 + grid[8] == 1)*3
	      + (grid[1] = 1 + grid[7] == 1)*1;

	v2 = (grid[4] == 2)*20  
	      + (grid[0] == 2 + grid[2] == 2 + grid[3] == 2 + grid[5] == 2 + grid[6] == 2 + grid[8] == 2)*3
	      + (grid[1] = 2 + grid[7] == 2)*1; 
	
	return v1-v2-depth;
}

int alpha_beta(int p1, int p2, int depth, bool isMax, int alpha, int beta){
	int val;
	if(g_check(p1) || g_check(p2) || depth == max_depth){
		val = heuristic(p1, p2, depth);
		return val;
	}

	int bestval, mvs, d;
	bool grid[9] = {false};
	mvs = movegen(p1, p2);
	while(mvs > 0){
		d = mvs % 10;
		mvs /= 10;
		grid[d-1] = true;
	}

	if(isMax){
		bestval = -INF;
		for(int i = 0; i < 9; i++){
			if(grid[i]){
				val = alpha_beta(p1*10 + i+1, p2, depth+1, !isMax, alpha, beta);
				bestval = max(bestval, val);
				if(alpha < bestval){
					alpha = bestval;
					mv = i+1;
				}
				if(beta >= alpha) break;
			}
		}
		return bestval;
	}
	else{
		bestval = INF;
		for(int i = 0; i < 9; i++){
			if(grid[i]){
				val = alpha_beta(p1, p2*10 + i+1, depth+1, !isMax, alpha, beta);
				bestval = min(bestval, val);
				if(beta > bestval){
					beta = bestval;
					mv = i+1;
				}
				if(beta >= alpha) break;
			}
		}
		return bestval;
	}
}

int ai_wrapper(int p1, int p2){
	mv = -1;
	alpha_beta(p1, p2, 0, false, -INF, INF);
	return mv;
}

int main(){
	cout<<"Enter maximum depth for search ";	cin>>max_depth;
	int (*ai)(int, int) = ai_wrapper;
	game(ai);
	return 0;
}