#include <iostream>
#include <stack>
#include <string>
using namespace std;

enum Mode
{
    simple,
    complex
};

int precendence(char op)
{
    return 0;
}
void simple_calculator();
void complex_calculator();
double perform_operation(stack<double> &numbers, stack<char> &operations);
bool isOperator(char c);

int main()
{
    cout << "Calculator\n";
    cout << "Mode: simple (s) or complex (c)? ";
    char mode;
    cin >> mode;
    Mode m = (mode == 's') ? simple : complex;
    switch (m)
    {
    case simple:
        simple_calculator();
        break;
    case complex:
        complex_calculator();
        break;
    }
    return 0;
}

void simple_calculator()
{
    cout << "Simple calculator\n";
    cout << "Enter two numbers: ";
    double a, b;
    cin >> a >> b;
    cout << "Enter operation: ";
    char op;
    cin >> op;
    double result = 0;
    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }
    cout << "Result: " << result << endl;
}
void complex_calculator()
{
    stack<double> numbers;
    stack<char> operations;
    string expression;
    cout << "Complex calculator (enter expression, e.g. 1+2*3): ";
    cin >> expression;
    for (int i = 0; i < expression.length(); i++)
    {

        // read number till operator
        if (isdigit(expression[i]))
        {
            string number;
            while (isdigit(expression[i]))
            {
                number += expression[i];
                i++;
            }
            numbers.push(stod(number));
        }
        else
        {
            if (expression[i] == '(')
                operations.push(expression[i]);
            else if (expression[i] == ')')
            {
                while (operations.top() != '(')
                {
                    double output = perform_operation(numbers, operations);
                    numbers.push(output);
                }
            }
            else if (isOperator(expression[i]))
            {
                while (!operations.empty() && precendence(expression[i]) <= precendence(operations.top()))
                {
                    double output = perform_operation(numbers, operations);
                    numbers.push(output);
                }
                operations.push(expression[i]);
            }
        }
    }

    while (!operations.empty())
    {
        double output = perform_operation(numbers, operations);
        numbers.push(output);
    }
    cout << numbers.top();
}

double perform_operation(stack<double> &numbers, stack<char> &operations)
{
    double a = numbers.top();
    numbers.pop();
    double b = numbers.top();
    numbers.pop();
    char op = operations.top();
    operations.pop();
    double result = 0;
    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }
    return result;
}
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}