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
	getline(in, line1); // ���� å ��, ������ ��, �־��� �� ��
	stringstream ss;
	ss << line1;
	ss >> num_of_books >> num_of_libs >> total_days;

	string line2;
	getline(in, line2);
	stringstream ss2;
	ss2 << line2;
	vector<int> b(num_of_books + 1); // å�� ����

	for (int i = 0; i < num_of_books; i++) {
		ss2 >> b[i];
	}

	vector<int> book(num_of_libs + 1); //�� �������� �����ִ� å ����
	vector<int> signup(num_of_libs + 1); //�� �������� ����ϴµ� �ɸ��� ��¥
	vector<int> scanning(num_of_libs + 1); //�� �������� �Ϸ翡 ��ĵ�� �� �ִ� ���� ����

	vector<int> check(num_of_books + 1); //��ü å �߿���, ��ĵ�� �ߴ��� ���ߴ����� �˻�.
	init(check ,-1); //-1 �� �ʱ�ȭ
	vector<vector<int>> have_book(num_of_libs + 1); //�� �������� �����ִ� å�� ����

	vector<vector<pair<int, int>>> desc_v(num_of_libs + 1); //(å ����, å ��ȣ) ����������� �� �������� ����.

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
			check[have_book[i][j]] = 1; //�� �������� ���� �ִ� å�� ǥ��. 1 �̸� � �������� �ִٴ� ����.
			desc_v[i].push_back(make_pair(b[have_book[i][j]], have_book[i][j]));
		}
	}

	//������ ���� � ������ �������� ��ĵ�ؾ� ���� ���� å�� ��ĵ ���������� �˻��Ѵ�.
	int* lib = new int[num_of_libs+1];

	for (int i = 0; i < num_of_libs; i++) {
		lib[i] = i; // �������� ����.
	}

	vector<int> order_of_libs; //��ĵ�� ������ ���� ����
	int max_num = 0;

	int max_score = 0;

	do {
		int score = 0; //�������� ���ھ� ��
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