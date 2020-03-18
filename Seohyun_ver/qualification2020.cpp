#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

#define MAX 100001

using namespace std;

int num_of_books, num_of_libs, total_days;
int max_score = 0;

void init(vector<int>& check, int t) {
	for (int i = 0; i < num_of_books; i++) {
		check[i] = t;
	}
}

int main(void) {
	ifstream in("a_example.txt");
	
	string line1;
	getline(in, line1); // 각각 책 수, 도서관 수, 주어진 날 수
	stringstream ss;
	ss << line1;
	ss >> num_of_books >> num_of_libs >> total_days;

	string line2;
	getline(in, line2);
	stringstream ss2;
	ss2 << line2;
	vector<int> b(num_of_books + 1); // 책의 점수

	for (int i = 0; i < num_of_books; i++) {
		ss2 >> b[i];
	}

	vector<int> book(num_of_libs + 1); //각 도서관이 갖고있는 책 갯수
	vector<int> signup(num_of_libs + 1); //각 도서관이 등록하는데 걸리는 날짜
	vector<int> scanning(num_of_libs + 1); //각 도서관이 하루에 스캔할 수 있는 날의 갯수

	vector<int> check(num_of_books + 1); //전체 책 중에서, 스캔을 했는지 안했는지를 검사.
	init(check ,-1); //-1 로 초기화
	vector<vector<int>> have_book(num_of_libs + 1); //각 도서관이 갖고있는 책들 저장

	vector<vector<pair<int, int>>> desc_v(num_of_libs + 1); //(책 점수, 책 번호) 내림차순대로 각 도서관에 저장.

	for (int i = 0; i < num_of_libs; i++) {
		string s1, s2;
		getline(in, s1);
		getline(in, s2);

		stringstream ss3, ss4;

		ss3 << s1;
		ss4 << s2;

		ss3 >> book[i] >> signup[i] >> scanning[i];

		vector<int> v1(book[i] + 1);
		have_book.push_back(v1);

		vector<pair<int, int>> v2(book[i] + 1);
		desc_v.push_back(v2);

		for (int j = 0; j < book[i]; j++) {
			int tmp;
			ss4 >> tmp;

			have_book[i].push_back(tmp);
			check[have_book[i][j]] = 1; //각 도서관이 갖고 있는 책을 표시. 1 이면 어떤 도서관엔 있다는 뜻임.
			desc_v[i].push_back(make_pair(b[have_book[i][j]], have_book[i][j]));
		}
	}

	//순열을 통해 어떤 순서로 도서관을 스캔해야 가장 많은 책을 스캔 가능한지를 검사한다.
	int* lib = new int[num_of_libs+1];

	for (int i = 0; i < num_of_libs; i++) {
		lib[i] = i; // 오름차순 저장.
	}

	vector<int> order_of_libs; //스캔할 도서관 순서 저장
	int max_num = 0;

	int max_score = 0;

	do {
		int score = 0; //도서관의 스코어 비교
		int deadline = total_days;
		int remaining = total_days;

		int* num = new int[num_of_libs + 1];
		for (int i = 0; i < num_of_libs; i++) {
			num[i] = (remaining - signup[lib[i]]) * scanning[lib[i]];
			remaining = remaining - signup[lib[i]];
			cout << num[i] << "\n";
		}



	} while (next_permutation(lib, lib + num_of_libs));

	return 0;
}