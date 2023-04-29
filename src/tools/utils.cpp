#include "../stdaxf.h"
using namespace std;

void read();

int main()
{
    vector<string> _vecInput;
    read(_vecInput);

    return 0;
}

void read(OUT  vector<string>& vecInput_)
{
    // 第一行读取数据的行数
    string _strNum;
    getline(cin, _strNum);

    // 读取数据
    for(int _nRow = 0; _nRow < atoi(_strNum.c_str()); _nRow++)
    {
        string _str;
        getline(cin, _str);
        vecInput_.emplace_back(_str);
    }
}