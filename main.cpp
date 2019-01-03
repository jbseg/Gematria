#include <iostream>
#include <string>
#include <fcntl.h>
#include <io.h>
#include <fstream>
using namespace std;

int let_num(wchar_t y);
int word_num(wstring x);
void text_nums();
void text_consec_nums();
void val_occur();
void find_words_with_val();
void find_words_of_mult();
void make_stats();
void find_max_val();
int main() {
	_setmode(_fileno(stdout), _O_U8TEXT);
	_setmode(_fileno(stdin), _O_U8TEXT);
	//text_nums();
	//text_consec_nums();
	//find_words_of_mult();
	//make_stats();
	//find_max_val();
	find_words_with_val();
	return 0;
}

int word_num(wstring x) {
	int sum = 0;
	wchar_t y;
	for (int i = 0; i < x.length(); i++) {
		y = x[i];
		sum += let_num(y);
	}
	return sum;
}

int let_num(wchar_t y) {
	int z = (int)y;
	switch (z) {
	case 1488: z = 1; break;
	case 1489: z = 2; break;
	case 1490: z = 3; break;
	case 1491: z = 4; break;
	case 1492: z = 5; break;
	case 1493: z = 6; break;
	case 1494: z = 7; break;
	case 1495: z = 8; break;
	case 1496: z = 9; break;
	case 1497: z = 10; break;
	case 1498: z = 20; break;
	case 1499: z = 20; break;
	case 1500: z = 30; break;
	case 1501: z = 40; break;
	case 1502: z = 40; break;
	case 1503: z = 50; break;
	case 1504: z = 50; break;
	case 1505: z = 60; break;
	case 1506: z = 70; break;
	case 1507: z = 80; break;
	case 1508: z = 80; break;
	case 1509: z = 90; break;
	case 1510: z = 90; break;
	case 1511: z = 100; break;
	case 1512: z = 200; break;
	case 1513: z = 300; break;
	case 1514: z = 400; break;
	default: z = 0; break;
	}
	return z;
}

void text_nums(){
	wstring x;
	int chapter;
	int verse;
	while (wcin >> x) {
		int z = word_num(x);
		if (z == 0) {//not hebrew
			if (x[0] >=48 && x[0] <= 57) {//the first part is a number
				verse = stoi(x);
				wchar_t colon;
				wcin >> colon;
				wcin >> x;
				chapter = stoi(x);
				wcout << endl << chapter << ":" << verse << " ";
			}
			if (x[1] == 'x') {//this indicates a change in chapters. Print the same heading
				wcout << endl << x;
				getline(wcin, x);
				wcout << x;
			}
		}
		else {
			wcout << z << " ";
		}
	}
}
void text_consec_nums() {
	ofstream consec_nums;
	consec_nums.open("testout.txt");
	wstring x;
	while (wcin >> x) {
		int z = word_num(x);
		if (z != 0) {
			consec_nums << z;
		}
	}
}

void val_occur() {
	ifstream inf;
	inf.open("Torah_numbers.txt");
	wcout << "numbers: ";
	int count = 0;
	int x;
	wcin >> x;
	string word;
	while (inf >> word) {
		if (word.find_first_of(':') != string::npos) continue;
		else if (word.find_first_of('x') != string::npos) {
			getline(cin, word);
		}
		else if (stoi(word) == x) count++;
	}
	wcout << endl << count;
}
void find_words_with_val() {
	wstring word;
	int val = 613;
	while (wcin >> word) {
		int z = word_num(word);
		if (z == val) wcout << word << endl;
	}
}
void find_words_of_mult() {
	wstring word;
	int mult = 18;
	while (wcin >> word) {
		int z = word_num(word);
		if (z!=0 && z%mult == 0) wcout << word << ":" << z << endl;
	}
}

void make_stats() {
	int arr[1501];
	fill(arr, arr + 1501, 0);
	wstring word;
	while (wcin >> word) {
		int z = word_num(word);
		if (z != 0) {
			arr[z]++;
		}
	}
	for (int i = 0; i < 1501; i++) {
		wcout << i << "," << arr[i] << endl;
	}
}

void find_max_val() {
	wstring max_word;
	int max_val = 0;
	wstring word;
	while (wcin >> word) {
		int z = word_num(word);
		if (z > max_val) {
			max_word = word;
			max_val = z;
		}
	}
	wcout << max_word << ":" << max_val << endl;
}