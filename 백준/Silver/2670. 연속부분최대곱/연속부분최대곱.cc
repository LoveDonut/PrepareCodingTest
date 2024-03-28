#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	double ret = 0.0f;
	cin >> N;
	vector<double> v(N); 
	for(int i=0; i<N; i++)
	{
		cin >> v[i];
	}

	for(int i=0; i<N; i++)
	{
		double mul = 1.0f;
		for(int j=i; j<N; j++)
		{
			mul *= v[j];
			if(mul > ret)
			{
				ret = mul;
			}
		}
	}
	
	ret = floor(ret*1000.0f + 0.5f) / 1000.0f;

	printf("%.3f", ret);	

	return 0;
}