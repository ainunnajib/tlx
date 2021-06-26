#include "dna.h"
#include <algorithm>
#include <cstring>
using namespace std;

string ga, gb;
int n;
int cumA[2][100000], cumT[2][100000], cumC[2][100000];

void init(std::string a, std::string b) {
	ga = a;
	gb = b;
	n = a.size();
	
	if(a[0]!=b[0]) {
		if(a[0] == 'A') cumA[0][0] = 1;
		if(b[0] == 'A') cumA[1][0] = 1;
		if(a[0] == 'T') cumT[0][0] = 1;
		if(b[0] == 'T') cumT[1][0] = 1;
		if(a[0] == 'C') cumC[0][0] = 1;
		if(b[0] == 'C') cumC[1][0] = 1;
	}
	for(int i=1; i<n; i++){
		char p = a[i];
		char q = b[i];

		cumA[0][i] = cumA[0][i-1];
		cumA[1][i] = cumA[1][i-1];
		cumT[0][i] = cumT[0][i-1];
		cumT[1][i] = cumT[1][i-1];
		cumC[0][i] = cumC[0][i-1];
		cumC[1][i] = cumC[1][i-1];
		if(p!=q){
			switch(p){
				case 'A': cumA[0][i]++; break;
				case 'T': cumT[0][i]++; break;
				case 'C': cumC[0][i]++; break; 
				default: break;
			}
			switch(q){
				case 'A': cumA[1][i]++; break;
				case 'T': cumT[1][i]++; break;
				case 'C': cumC[1][i]++; break; 
				default: break;
			}
		}
	}
}

int get_distance(int x, int y) {
	int numA1, numA2, numT1, numT2, numC1, numC2;
	numA1 = cumA[0][y];
	numA2 = cumA[1][y];
	numT1 = cumT[0][y];
	numT2 = cumT[1][y];
	numC1 = cumC[0][y];
	numC2 = cumC[1][y];
	if(x > 0){
		numA1 -= cumA[0][x-1];
		numA2 -= cumA[1][x-1];
		numT1 -= cumT[0][x-1];
		numT2 -= cumT[1][x-1];
		numC1 -= cumC[0][x-1];
		numC2 -= cumC[1][x-1];
	}
	if(numA1==numA2 && numT1==numT2 && numC1==numC2){
		int minletter = min(numA1, numT1);
		minletter = min(minletter, numC1);
		return minletter * 2 + (numA1+numT1+numC1-3*minletter)/2;
	} else {
		return -1;
	}
}