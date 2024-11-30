#include <iostream>
#include <string>
using namespace std;

class ArraySizeException 
{
public:

    const char* what() const
    {
        return "Array must be 4x4";
    }
};

class ArrayDataException
{
    int row, col;
    string value;

public:

    ArrayDataException(int r, int c, const string& val) : row(r), col(c), value(val) {}
    void printError() const 
    {
        cout << "Invalid data at [" << row << "][" << col << "]: " << value << endl;
    }
};

class ArrayValueCalculator
{
public:

    int doCalc(string array[4][4])
    {
        int sum = 0;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (!isNumber(array[i][j]))
                {
                    throw ArrayDataException(i, j, array[i][j]);
                }
                sum += stoi(array[i][j]);
            }
        }
        return sum;
    }

private:

    bool isNumber(const string& str)
    {
        for (char c : str)
        {
            if (!isdigit(c)) return false;
        }
        return true;
    }
};

int main()
{
    string validArray[4][4] = 
    {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    string invalidDataArray[4][4] = 
    {
        {"1", "2", "X", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    ArrayValueCalculator calculator;

    try
    {
        cout << "Sum: " << calculator.doCalc(validArray) << endl;
    }
    catch (const ArraySizeException& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const ArrayDataException& e)
    {
        e.printError();
    }
    try
    {
        cout << "Sum: " << calculator.doCalc(invalidDataArray) << endl;
    }
    catch (const ArraySizeException& e) 
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const ArrayDataException& e)
    {
        e.printError();
    }

    return 0;
}