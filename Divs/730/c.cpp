#include <bits/stdc++.h>
using namespace std;

const double NOT0 = 1e-9;


int t;
double c, m, p, v;


double calc(double c, double m, double p){
	if(c>NOT0){
		if(m>NOT0){
			return c*calc(c-v, m+min(v/2, c/2), p+min(v/2, c/2)) + m*calc(c+min(m/2, v/2), m-v, p+min(m/2, v/2)) + 1;
		}
		else {
			return c*calc(c-v, 0, p+min(c, v)) + 1;
		}
	}
	else if(m>NOT0){
		return m*calc(0, m-v, p+min(m, v)) + 1;
	}
	return 1;
		
	
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lf%lf%lf%lf", &c, &m, &p, &v);
		printf("%.12lf\n", calc(c, m, p));
	}
	return 0;
}
