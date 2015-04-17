#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <sstream>

void display(int);
void findcombinations(int);

using namespace std;

int main()
{
	int length = 0;
	double totalcomb;
	string Y_N;
	cout << "Please enter the password length you would like to generate" << endl << endl;
	cin >> length;
	cout << endl;
	totalcomb = pow(26, length);
	cout << "This will generate a total of " << totalcomb << " words. " << endl << endl;
	cout << "Would you like to continue....." << endl << "Type Yes or No and then press enter." << endl << endl;
	cin >> Y_N;
	cout << endl;
	if (Y_N == "yes" | Y_N == "YES" | Y_N == "Yes")
	{
		Y_N.clear();
		clock_t begin = clock();
		findcombinations(length);
		clock_t end = clock();
		int elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "It took " << elapsed_secs << " seconds to generate " << totalcomb << " possible combinations" << endl << endl;
		cout << "All possible combinations have been saved in a Text file." << endl << endl;
		cout << "Would you like for all the possible combinations to be displayed on the screen." << endl << "Type Yes or No and then press enter." << endl << endl;
		cin >> Y_N;
		cout << endl;
		if (Y_N == "yes" | Y_N == "YES" | Y_N == "Yes")
		{
			display(length);
		}


		system("pause");
		return 0;
	}
	else
		return 0;
}

void findcombinations(int length)
{
	ostringstream convert;
	ifstream infile, infile2;
	string Result, Result2;
	string str, str_old;
	ofstream out_data;
	double totalcomb;
	char chars[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	char output[256];
	int nextlength, count = 0, count2 = 0;
	if (length == 0)
	{
		return;
	}
	if (length == 1)
	{
		infile.open("output1.txt", ifstream::in);
		if (infile.is_open())
		{
			return;
		}
		else
		{
			convert.str("");
			convert.clear();
			convert << length;
			Result = convert.str();
			str = "output";
			str += Result;
			str += ".txt";
			out_data.open(str.c_str(), ios::out);
			count = 0;
			while (count <= 25)
			{
				if (count < 25)
				{
					out_data << chars[count] << ",";
				}
				else
				{
					out_data << chars[count];
				}
				count++;
			}
			return;
		}
	}
	if (length > 1)
	{
		convert.str("");
		convert.clear();
		Result = "";
		convert << length;
		Result = convert.str();
		str = "output";
		str += Result;
		str += ".txt";
		infile.open(str.c_str(), ios::in);
		if (infile.is_open())
		{
			return;
		}
		else
		{
			convert.str("");
			convert.clear();
			nextlength = length - 1;
			totalcomb = pow(26, nextlength);
			Result = "";
			convert << nextlength;
			Result = convert.str();
			str_old = "output";
			str_old += Result;
			str_old += ".txt";
			infile.open(str_old.c_str(), ios::in);
			if (infile.is_open())
			{
				convert.str("");
				convert.clear();
				Result = "";
				convert << length;
				Result = convert.str();
				str = "output";
				str += Result;
				str += ".txt";
				out_data.open(str.c_str(), ios::out);
				count = 0;
				while (count <= 25)
				{
					count2 = 1;
					while (infile.good())
					{
						convert.str("");
						convert.clear();
						Result.clear();
						Result2.clear();
						convert << chars[count];
						Result = convert.str();
						infile.getline(output, 256, ',');
						convert.str("");
						convert.clear();
						convert << output;
						Result2 = convert.str();
						Result2.insert(0, Result);
						if (count2 < totalcomb)
						{
							out_data << Result2 << ",";
						}
						else
						{
							out_data << Result2;
						}
						count2++;
					}
					if (count < 25)
					{
						out_data << ",";
					}
					infile.close();
					count++;
					infile.open(str_old.c_str(), ios::in);
				}
				infile.close();
				return;
			}
			else
			{
				findcombinations(nextlength);
				convert.str("");
				convert.clear();
				Result = "";
				convert << length;
				Result = convert.str();
				str = "output";
				str += Result;
				str += ".txt";
				out_data.open(str.c_str(), ios::out);
				count = 0;
				while (count <= 25)
				{
					count2 = 1;
					while (infile.good())
					{
						convert.str("");
						convert.clear();
						Result.clear();
						Result2.clear();
						convert << chars[count];
						Result = convert.str();
						infile.getline(output, 256, ',');
						convert.str("");
						convert.clear();
						convert << output;
						Result2 = convert.str();
						Result2.insert(0, Result);
						if (count2 < totalcomb)
						{
							out_data << Result2 << ",";
						}
						else
						{
							out_data << Result2;
						}
						count2++;
					}
					if (count < 25)
					{
						out_data << ",";
					}
					infile.close();
					count++;
					infile.open(str_old.c_str(), ios::in);
				}
				infile.close();
				return;
			}
		}

	}
	return;
}

void display(int length)
{
	ostringstream convert;
	ifstream infile;
	string Result;
	string str;
	char output[256];
	convert.str("");
	convert.clear();
	Result = "";
	convert << length;
	Result = convert.str();
	str = "output";
	str += Result;
	str += ".txt";
	infile.open(str.c_str(), ios::in);
	if (infile.is_open())
	{
		while (infile.good())
		{
			infile.getline(output, 256, ',');
			cout << output << endl;
		}
		infile.close();
	}
	return;
}

