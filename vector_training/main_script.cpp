#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isAlphabet(char character) {
	if (((character > 64) && (character < 91)) || ((character > 96) && (character < 123))) {
		return true;
	}
	else {
		return false;
	}
};

void word_separator(string line, vector<string> &vec) {
	char character_i,character_f;
	string word;
	int line_char_len = line.length();
	int start_ind = 0, end_ind = 0;
	character_i = line[start_ind];

	while (end_ind < line_char_len) {
		character_i = line[start_ind];
		character_f = line[end_ind];
		
		if (!isAlphabet(character_i)) {
			start_ind++;
			end_ind = start_ind;
			continue;
		}
		else if (!isAlphabet(character_f)) {
			word = line.substr(start_ind, (end_ind-start_ind));
			vec.push_back(word);
			start_ind = end_ind + 1;
		}
		else if ((end_ind == line_char_len - 1) && (isAlphabet(character_i))) {
			word = line.substr(start_ind, (end_ind - start_ind)+1);
			vec.push_back(word);
			start_ind = end_ind + 1;
		}
		end_ind++;
	}
};

void main() {
	string sentence;
	vector<string> words;
	cout << "Welcome to the word separator program";
	while (true) {
		
		cout << "\nPlease enter text, then press enter: \n";
		getline(cin, sentence);
		word_separator(sentence, words);
		cout << "Total number of words: "<<words.size() << endl;
		cout << "The words in the sentence are:\n";
		for (int i = 0;i < words.size();i++) {
			cout << "\"" << words[i] << "\"" << endl;
		}
		words.clear();
	}
}
