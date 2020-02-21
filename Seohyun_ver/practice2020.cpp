#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

int m, n;
int s[MAX];

vector< vector<int> > p;

vector< vector<int> > check;

int main(void) {
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i <= n; i++) {
		vector<int> v1(m+1);
		p.push_back(v1);
	}

	for (int i = 0; i <= m; i++) {
		vector<int> v2(n + 1);
		check.push_back(v2);
	}

	for (int i = 1; i <= m; i++) {
		p[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		p[i][0] = 0;
		for (int j = 1; j  <= m; j++) {
			if (s[i] > j) {
				p[i][j] = p[i - 1][j];
				check[p[i][j]] = check[p[i - 1][j]];
			}
			else {
				p[i][j] = max(s[i] + p[i - 1][j - s[i]], p[i - 1][j]);
				if (s[i] + p[i - 1][j - s[i]] > p[i - 1][j]) {
					check[p[i][j]] = check[p[i - 1][j - s[i]]];
					check[p[i][j]].push_back(i);
				}
				else {
					check[p[i][j]] = check[p[i - 1][j]];
				}
			}
			//printf("%d ", p[i][j]);
		}
		//printf("\n");
	}
	
	printf("%d\n", p[n][m]);

	//for (int i = 0; i <= m; i++) {
		for (int j = 0; j < check[m-1].size(); j++) {
			if(check[m - 1][j] - 1!=-1)
				printf("%d ", check[m-1][j]-1);
		}
		printf("\n");
	//}
	return 0;
}