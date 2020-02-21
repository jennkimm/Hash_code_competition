#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

#define MAX 100001

using namespace std;

int n, l, d;
int b_score[MAX];

int main(void) {
	cin >> n >> l >> d;

	for (int i = 0; i < n; i++) {
		cin >> b_score[n];
	}
	
	int* b = new int[l];
	int* signUp = new int[l];
	int* ship = new int[l];

	vector<vector<int>> book;

	for (int i = 0; i < l; i++) {
		vector<int> v1(n);
		book.push_back(v1);
	}

	for (int i = 0; i < l; i++) {
		cin >> b[i] >> signUp[i] >> ship[i];
		for (int j = 0; j < b[i]; j++) {
			int index;
			cin >> index;
			book[i].push_back(index);
		}
		sort(book[i].begin(), book[i].end());
	}

	vector<vector<int>> score;

	for (int i = 0; i<l; i++) {
		vector<int> s(n);
		score.push_back(s);

		for (int j = 0; j < book[i].size(); j++) {
			score[i][j] = b_score[j];
		}

		//점수 내림차순 정렬
		sort(score[i].begin(), score[i].end(), greater<int>());

		for (int j = 0; j < book[i].size(); j++) {
			printf("%d ", score[i][j]);
		}

	}

	//스캔 했는지 체크
	bool check_b[MAX] = { false, };

	//최대로 스캔할 수 있는 책 개수
	int max_book = 0;

	//얻을 수 있는 최대 점수
	int max_score = 0;

	//도서관 순서
	vector<int> v(l);

	//책 스캔 순서
	//vector<int> scanned;

	//최종적으로 스캔 할 도서관의 순서 
	vector<int> order_lib(l);

	for (int i = 0; i < l; i++) {
		v[i] = i;
	}

	do {
		//check_b[MAX] = { false, }; //초기화
		int sum = 0;
		int total = 0;
		int remaining_day = d;

		for (int i = 0; i < l; i++) {
			//printf("lib %d번: ", i);
			int num = (remaining_day - signUp[v[i]]) * ship[v[i]];
			
			/*
			for (int k = 0; k < num; k++) {
				if (k < book[i].size()) {
					if (check_b[book[i][k]] == false) {
						total += score[i][k];
						printf("score= %d ", score[i][k]);
					}
				}
				else
					break;
			}
			printf("\n");
			*/
			sum += num;
			printf("num= %d ", num);
			remaining_day -= signUp[v[i]];
		}

		printf("sum= %d\n", sum);

		
		if (total > max_score) {
			max_book = sum;

			//도서관 사인업 순서 저장
			for (int i = 0; i < l; i++) {
				order_lib.pop_back();
			}
			for (int i = 0; i < l; i++) {
				order_lib.push_back(v[l]);
			}

			max_score = total;
		}

		
		if (sum > max_book) {
			max_book = sum;
			for (int i = 0; i < l; i++) {
				order_lib.pop_back();
			}
			for (int i = 0; i < l; i++) {
				order_lib.push_back(v[l]);
			}
		}
		

	} while (next_permutation(v.begin(), v.end()));






	//ifstream input("a_example.txt");

	//string line1;

	//stringstream ss;


	//ofstream outfile("a_example.out");

	return 0;
}