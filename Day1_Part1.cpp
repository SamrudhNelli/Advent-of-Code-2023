#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;
#pragma disable(warning::4966)

int main()
{
	ifstream Fdata;
	Fdata.open("input.txt", ios::in);
	string line[1001];
	int first_num[1001], second_num[1001], sum = 0;
	for (int i = 1; i < 1001; i++)
	{
		getline(Fdata, line[i]);
		for (int j = 0; j < size(line[i]); j++)
		{
			char ch = line[i][j];
			if (int(ch) >= 48 && int(ch) <= 57)
			{
				first_num[i] = int(ch) - 48;
				break;
			}
		}
		for (int j = size(line[i]) - 1; j >= 0; j--)
		{
			char ch = line[i][j];
			if (int(ch) >= 48 && int(ch) <= 57)
			{
				second_num[i] = int(ch) - 48;
				break;
			}
		}
		sum += (first_num[i] * 10 + second_num[i]);
	}
	printf("%d\n\n", sum);
	return 0;

}