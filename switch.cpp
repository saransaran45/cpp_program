#include <iostream>
#include <string>
#include <bits/stdc++.h>

int main()
{
    int x = 5;
    int y = 3;
    char op = '+';
    int result = 0;

    switch (op)
    {
    case '+':
        result = x + y;
        break;
    case '-':
        result = x - y;
        break;
    case '*':
        result = x * y;
        break;
    case '/':
        if (y != 0)
        {
            result = x / y;
        }
        else
        {
            std::cerr << "Error: Division by zero" << std::endl;
            return 1;
        }
        break;
    default:
        std::cerr << "Unsupported operation" << std::endl;
        return 1;
    }

    cout << x << " " << op << " " << y << " = " << result << std::endl;

    return 0;
}
