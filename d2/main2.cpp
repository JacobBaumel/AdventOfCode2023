#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main() {
	std::ifstream file("data.txt");
	std::string line;
	int sum = 0;

	while(getline(file, line)) {
		int lred = 0;
		int lblue = 0;
		int lgreen = 0;

		for(size_t i = line.find_first_of(':') + 2; i < line.length(); ) {
			std::string numstr(1, line[i]);
			if(std::isdigit(line[i + 1])) numstr += line[i++ + 1]; 
			int num = std::stoi(numstr);
			i += 2;
			char color = line[i];
			int* colorInt = nullptr;

			switch(color) {
				case 'r':
					i += 5;
					colorInt = &lred;
					break;

				case 'g':
					i += 7;
					colorInt = &lgreen;
					break;

				case 'b':
					i += 6;
					colorInt = &lblue;
					break;

				default:
					std::cout << "AAAAAAAAAH GOT CHARACTER " << color << std::endl;
					return 0;
			}

			if(num > *colorInt) *colorInt = num;
		}
		sum += (lred * lblue * lgreen);
	}

	std::cout << "Sum: " << sum << std::endl;
}
