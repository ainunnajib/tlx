#include "dna.h"
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int cum[2][3][100000];
int diff[3][3][100000];

int f(char c){
	if(c=='A') return 0;
	if(c=='T') return 1;
	if(c=='C') return 2;
	return 0;
}

void init(std::string a, std::string b) {
	n = a.size();
	
	if(a[0]!=b[0]) {
		cum[0][f(a[0])][0]++;
		cum[1][f(b[0])][0]++;

		diff[f(a[0])][f(b[0])][0]++;
	}
	for(int i=1; i<n; i++){
		char p = a[i];
		char q = b[i];

		for(int k=0;k<3;k++){
			for(int j=0;j<2;j++){
				cum[j][k][i] = cum[j][k][i-1];
			}
			for(int l=0;l<3;l++){
				diff[k][l][i] = diff[k][l][i-1];
			}
		}

		if(p!=q){
			cum[0][f(p)][i]++;
			cum[1][f(q)][i]++;

			diff[f(p)][f(q)][i]++;
		}
	}
}

int get_distance(int x, int y) {
	int numAT = diff[0][1][y], numTA = diff[1][0][y];
	int numAC = diff[0][2][y], numCA = diff[2][0][y]; 
	int numTC = diff[1][2][y], numCT = diff[2][1][y];
	int numA1, numA2, numT1, numT2, numC1, numC2;
	numA1 = cum[0][0][y];
	numA2 = cum[1][0][y];
	numT1 = cum[0][1][y];
	numT2 = cum[1][1][y];
	numC1 = cum[0][2][y];
	numC2 = cum[1][2][y];

	if(x > 0){
		numA1 -= cum[0][0][x-1];
		numA2 -= cum[1][0][x-1];
		numT1 -= cum[0][1][x-1];
		numT2 -= cum[1][1][x-1];
		numC1 -= cum[0][2][x-1];
		numC2 -= cum[1][2][x-1];

		numAT -= diff[0][1][x-1];
		numTA -= diff[1][0][x-1];
		numAC -= diff[0][2][x-1];
		numCA -= diff[2][0][x-1];
		numTC -= diff[1][2][x-1];
		numCT -= diff[2][1][x-1];
	}
	if(numA1==numA2 && numT1==numT2 && numC1==numC2){
		int pairs = 0;
		pairs += min(numAT, numTA);
		pairs += min(numAC, numCA);
		pairs += min(numTC, numCT);

		int triples = numA1 + numT1 + numC1 - 2*pairs;

		return pairs + 2*triples/3;
	} else {
		return -1;
	}
}
