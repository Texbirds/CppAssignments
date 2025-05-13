#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath> 
#include "ImprovedStack.h"

// Split an expression into numbers, operators, and parenthese
std::vector<std::string> split(const std::string& expression);

// Evaluate an expression and return the result
int evaluateExpression(const std::string& expression);

// Perform an operation
void processAnOperator(
	Stack<int>& operandStack, Stack<char>& operatorStack);

int main()
{
	std::string expression;
	std::cout << "Enter an expression: ";
	std::getline(std::cin, expression);

	std::cout << expression << " = "
		<< evaluateExpression(expression) << std::endl;

	return 0;
}

std::vector<std::string> split(const std::string& expression)
{
	std::vector<std::string> v; // A vector to store split items as strings
	std::string numberString; // A numeric string

	for (unsigned int i = 0; i < expression.length(); i++)
	{
		if (isdigit(expression[i]))
			numberString.append(1, expression[i]); // Append a digit
		else
		{
			if (numberString.size() > 0)
			{
				v.push_back(numberString); // Store the numeric string
				numberString.erase(); // Empty the numeric string
			}

			if (!isspace(expression[i]))
			{
				std::string s;
				s.append(1, expression[i]);
				v.push_back(s); // Store an operator and parenthesis
			}
		}
	}

	// Store the last numeric string
	if (numberString.size() > 0)
		v.push_back(numberString);

	return v;
}

// Evaluate an expression 
int evaluateExpression(const std::string& expression) {
	Stack<int> operandStack;
	Stack<char> operatorStack;
	std::vector<std::string> tokens = split(expression);

	for (unsigned int i = 0; i < tokens.size(); i++) {
		std::string token = tokens[i];

		if (isdigit(token[0])) {
			operandStack.push(atoi(token.c_str()));
		}
		else if (token[0] == '+' || token[0] == '-') {
			while (!operatorStack.empty() &&
				(operatorStack.peek() == '+' || operatorStack.peek() == '-' ||
					operatorStack.peek() == '*' || operatorStack.peek() == '/' ||
					operatorStack.peek() == '%')) {
				processAnOperator(operandStack, operatorStack);
			}
			operatorStack.push(token[0]);
		}
		else if (token[0] == '*' || token[0] == '/' || token[0] == '%') {
			while (!operatorStack.empty() &&
				(operatorStack.peek() == '*' || operatorStack.peek() == '/' ||
					operatorStack.peek() == '%' || operatorStack.peek() == '^')) {
				processAnOperator(operandStack, operatorStack);
			}
			operatorStack.push(token[0]);
		}
		else if (token[0] == '^') {
			while (!operatorStack.empty() && operatorStack.peek() == '^') {
				processAnOperator(operandStack, operatorStack);
			}
			operatorStack.push(token[0]);
		}
		else if (token[0] == '(') {
			operatorStack.push('(');
		}
		else if (token[0] == ')') {
			while (!operatorStack.empty() && operatorStack.peek() != '(') {
				processAnOperator(operandStack, operatorStack);
			}
			operatorStack.pop(); 
		}
	}

	while (!operatorStack.empty()) {
		processAnOperator(operandStack, operatorStack);
	}

	return operandStack.pop();
}

// Process one opeator: Take an operator from operatorStack and 
// apply it on the operands in the operandStack 
void processAnOperator(Stack<int>& operandStack, Stack<char>& operatorStack) {
	char op = operatorStack.pop();
	int op1 = operandStack.pop();
	int op2 = operandStack.pop();

	if (op == '+')
		operandStack.push(op2 + op1);
	else if (op == '-')
		operandStack.push(op2 - op1);
	else if (op == '*')
		operandStack.push(op2 * op1);
	else if (op == '/')
		operandStack.push(op2 / op1);
	else if (op == '%')
		operandStack.push(op2 % op1);
	else if (op == '^')
		operandStack.push(static_cast<int>(std::pow(op2, op1)));
}
