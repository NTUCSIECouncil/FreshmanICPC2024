#include <bits/stdc++.h>
#include <assert.h>
#include <string.h>
#include "testlib.h"
using namespace std;
int N=10000000;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int rnd_seed=atoi(argv[1]);
	int n=atoi(argv[2]);
	if(n==0) n=rnd.next(N/2, N);
	cout<<n<<"\n";
}
