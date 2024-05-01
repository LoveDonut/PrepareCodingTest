#include <bits/stdc++.h>

using namespace std;

int table[101][101];
int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(!table[a][b] || table[a][b] > c)
		{
			table[a][b] = c;		
		}
	}

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i != j && !table[i][j])
			{
				table[i][j] = 1e9;
			}
		}
	}
	
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(table[i][j] > table[i][k] + table[k][j])
				{
					table[i][j] = table[i][k] + table[k][j];
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(table[i][j] >= 1e9)
			{
				cout << "0 ";
			}
			else
			{
				cout << table[i][j] << ' ';			
			}
		}
		cout << '\n';
	}
	
	return 0;
}