#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;


class LongValue
{
    public:
        string value;

        LongValue() 
        {
            value = "";
        }

        LongValue(int intValue) 
        {
            value = to_string(intValue);
        }

        LongValue(string strValue) 
        {
            value = strValue;
        }
};

ostream& operator << (ostream &os, const LongValue &longValue) 
{
    return os << longValue.value;
}

istream& operator >> (istream &in, LongValue &longValue)
{
    return in >> longValue.value;
}

LongValue operator + (LongValue longValue1, LongValue longValue2)
{
    string result;

    string temp_val1 = longValue1.value;
    string temp_val2 = longValue2.value;

    string val1 = temp_val1;
    string val2 = temp_val2;
    if (temp_val1.size() < temp_val2.size())
    {
        for (int i = 0; i < temp_val2.size() - temp_val1.size(); i++)
        {
            val1 = '0' + val1;
        }
    }
    else if (temp_val2.size() < temp_val1.size())
    {
        for (int i = 0; i < temp_val1.size() - temp_val2.size(); i++)
        {
            val2 = '0' + val2;
        }
    }
    bool flag = false;
    for(int i = 0; i < val1.size(); i++)
    {
        short sum = (val1[val1.size() - i - 1] - '0') + (val2[val2.size() - i - 1] - '0');
        if(flag)
        {
            sum += 1;
        }
        result = to_string(sum % 10) + result;
        if(sum / 10 == 1)
        {
            flag = true;
        }
        else 
        {
            flag = false;
        }
    }
    if (flag)
    {
        result = '1' + result;
    }
    return LongValue(result);
}

LongValue operator + (LongValue longValue1, int intValue2)
{
    return LongValue(stoi(longValue1.value) + intValue2);
}

LongValue operator - (LongValue longValue1, int intValue2)
{
    return LongValue(stoi(longValue1.value) - intValue2);
}

LongValue operator * (LongValue longValue1, int intValue2)
{
    return LongValue(stoi(longValue1.value) * intValue2);
}

LongValue operator / (LongValue longValue1, int intValue2)
{
    return LongValue(stoi(longValue1.value) / intValue2);
}

int main()
{
    LongValue val1;
    LongValue val2;
    cin >> val1 >> val2;
    cout << val1 + val2 << endl;
    return 0;
}