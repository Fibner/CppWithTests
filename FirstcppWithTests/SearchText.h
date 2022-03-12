#pragma once
#include <string>
#include <vector>
class SearchText {
private:
	std::string text;
public:
	SearchText(std::string text) {
		this->text = text;
	}
	int CountChar() {
		return text.length();
	}
	int CountNumbers() {
		int count =  0;
		for (size_t i = 0; i < text.length(); i++)
		{
			if (isdigit(text[i])) count++;
		}
		return count;
	}
	int CountLetters() {
		int count = 0;
		for (size_t i = 0; i < text.length(); i++)
		{
			if (isalpha(text[i])) count++;
		}
		return count;
	}
	int CountVowels() {
		int count = 0;
		for (size_t i = 0; i < text.length(); i++)
		{
			if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u') count++;
		}
		return count;
	}
	int CountWords(int wordLength) {
		int count = 0;
		std::string word = "";
		std::vector<std::string> words;
		for (size_t i = 0; i < text.length(); i++)
		{
			if(isalpha(text[i])) word += text[i];
			if (iswspace(text[i])) {
				words.push_back(word);
				word = "";
			}
			if(i == text.length()-1) words.push_back(word);
		}
		for (size_t i = 0; i < words.size(); i++)
		{
			if (words.at(i).length() >= wordLength) count++;
		}
		return count;
	}
	int CountTags() {
		int count = 0;
		bool isOpen = false;
		for (size_t i = 0; i < text.length(); i++)
		{
			if (text[i] == '<')
			{
				if (text[i+1] != ' ') isOpen = true;
			}
			else if (text[i] == '>')
			{
				if (isOpen && text[i-1] != ' ') count++;
			}
			else if (text[i] == ' ') isOpen = false;
		}
		return count;
	}
};