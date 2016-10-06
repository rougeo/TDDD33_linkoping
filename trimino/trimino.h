#ifndef TRIMINO_H
#define TRIMINO_H

struct Trimino {
	int number1;
	int number2;
	int number3;
	std::string optionalURL;
};

bool isCorrect(std::string);
bool clock_increasing(int a, int b, int c);
#endif
