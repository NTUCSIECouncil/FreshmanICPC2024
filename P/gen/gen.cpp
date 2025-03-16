#include <bits/stdc++.h>
#include <assert.h>
#include <string.h>
#include "testlib.h"
using namespace std;
const int N=1000000;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int rnd_seed=atoi(argv[1]);
	int n=(atoi(argv[2])==0?rnd.next(N/10, N):n);
	cout<<n<<"\n";
}
