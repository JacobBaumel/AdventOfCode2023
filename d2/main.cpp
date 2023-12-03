#include <cctype>
#include <iostream>
#include <string>
#include <fstream>
#include <map>

std::map<char, int> maxPerColor;

int main() {
	maxPerColor.insert({'r', 12});
	maxPerColor.insert({'g', 13});
	maxPerColor.insert({'b', 14});

	std::ifstream file("data.txt");
	std::string line;
	int sum = 0;
	int id = 0;

	while(getline(file, line)) {
		id++;
		bool valid = true;

		for(size_t i = line.find_first_of(':') + 2; i < line.length(); ) {
			std::string numstr(1, line[i]);
			if(std::isdigit(line[i + 1])) numstr += line[i++ + 1]; 
			int num = std::stoi(numstr);
			i += 2;
			char color = line[i];

			switch(color) {
				case 'r':
					i += 5;
					break;

				case 'g':
					i += 7;
					break;

				case 'b':
					i += 6;
					break;

				default:
					std::cout << "AAAAAAAAAH GOT CHARACTER " << color << std::endl;
					return 0;
			}

			if(num > maxPerColor[color]) {
				valid = false;
				break;
			}

		}
		if(valid) sum += id;
	}

	std::cout << "Sum: " << sum << std::endl;
}
