#ifndef TRIMINO_H
#define TRIMINO_H

struct Trimino {
	int number1;
	int number2;
	int number3;
	std::string optionalURL;
};

bool isCorrect(std::string set, int min, int max);
bool clock_increasing(int a, int b, int c);
int max_find(int a, int b);
int min_find(int a, int b);

#endif
