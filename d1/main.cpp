#include <cctype>
#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <string>

void fixString(std::string& str);

std::string stringNums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::string replaceNums[] = {"z0o", "o1e", "t2o", "t3e", "f4r", "f5e", "s6x", "s7n", "e8t", "n9e"};

int main() {
	std::ifstream file("data.txt");
	std::string line;
	int sum = 0;

	while(getline(file, line)) {
		fixString(line);

		size_t firstDig = 0;
		for(; firstDig < line.length(); firstDig++)
			if(isdigit(line[firstDig])) break;

		size_t lastDig = line.length() - 1;
		for(; lastDig >= 0; lastDig--) 
			if(isdigit(line[lastDig])) break;
		sum += std::stoi(std::string(1, line[firstDig]) + line[lastDig]);
	}

	std::cout << "Sum: " << sum << std::endl;
}

void fixString(std::string& str) {
	for(int i = 0; i < 10; i++) {
		str = std::regex_replace(str, std::regex(stringNums[i]), replaceNums[i]);
	}
}
