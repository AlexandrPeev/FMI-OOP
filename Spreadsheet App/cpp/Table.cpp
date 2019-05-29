#include "Table.h"
#include <iostream>
#include <fstream>

Table::Table()
{
	lines = new Line[2];
	size = 0;
	capacity = 2;
	columnrank = 0;
}

void Table::AddRow()
{
	if (size >= capacity)
	{
		Resize();
	}
	size++;
}

void Table::Resize()
{
	try
	{
		Line* newarr = new Line[capacity * 2];
		for (int i = 0; i < size; ++i)
		{
			newarr[i] = lines[i];
		}
		delete[] lines;
		lines = newarr;
		capacity *= 2;
	}
	catch (std::bad_alloc& e)
	{
		std::cout << "Line allocation failed: " << e.what() << '\n';
	}

}

void Table::ReadFromFile(const char* name)
{
	std::ifstream ifs(name);
	if (!ifs.is_open())
	{
		throw std::logic_error("Could not load file!");
	}
	char* arr = new char[4096];
	int count = 0;
	while (!ifs.eof())
	{
		ifs.getline(arr, 4096);
		count = ProcessLine(arr);
		std::cout << std::endl;
		columnrank = count > columnrank ? count : columnrank;
	}
}

int Table::ProcessLine(const char* arr)
{
	AddRow();
	int counter = 0; // used to traverse the string
	int elementcntr = 0; // used to count elements in LINE
	int beg, end;  // indecies for copying words
	int copycounter = 0; // counter for copying data
	char* tmp; // pointer for copying the data
	int dotcount = 0; // counting the number of dots for data determination
	char sign = 'n'; // Used for the number case
	Date* datebuff;
	String* stringbuff;
	Double* doublebuff;
	Integer* integerbuff;
	while (arr[counter] != '\0')
	{
		while (arr[counter] == ' ')
		{
			counter++;
		}
		if (arr[counter] == ',')
		{
			lines[size-1].AddElement(nullptr);
			elementcntr++;
		}
		else if (arr[counter] == '\"') // CASE OF STRING
		{
			beg = counter;
			counter++; // skipping the opening '"'
			while (counter < 4096 && arr[counter] != '\0')
			{
				if (arr[counter] == '\"' && arr[counter - 1] != '\\')
				{
					break;
				}
				else
				counter++;
			}
			end = counter+1;
			tmp = new char[end - beg + 1];
			for (int i = beg; i < end; ++i)
			{
				tmp[copycounter] = arr[i];
				copycounter++;
			}
			tmp[copycounter] = '\0';
			stringbuff = new String(tmp);
			stringbuff->Visualise(std::cout);
			lines[size-1].AddElement(stringbuff);
			copycounter = 0;
			end = 0;
			beg = 0;
			delete[] tmp;
			delete stringbuff;
			elementcntr++;
			counter++;
		}
		else if (arr[counter] == '+' || arr[counter] == '-' || (arr[counter] >= '0' && arr[counter] <= '9')) // CASE OF DATE OR NUMBERS
		{
			if (arr[counter] == '+' || arr[counter] == '-')
			{
				sign = arr[counter];
				counter++;
			}
			beg = counter;
			while ((arr[counter] >= '0' && arr[counter] <= '9') || arr[counter] == '.')
			{
				if (arr[counter] == '.')
				{
					dotcount++;
					counter++;
				}
				else if (arr[counter] >= '0' && arr[counter] <= '9')
				{
					counter++;
				}
			}
			if (arr[counter] == '.') // CASE OF 123.346346. 
			{
				std::cout << "Invalid info at : " << size << " " << elementcntr << std::endl;
				throw std::logic_error("Invalid info");
			}
			end = counter - 1;
			if (dotcount > 2)
			{
				std::cout << "Invalid info at : " << size << " " << elementcntr << std::endl;
				throw std::logic_error("Invalid info");
			}
			else if (dotcount == 0)
			{
				tmp = new char[end - beg + 2];
				for (int i = beg; i <= end; ++i)
				{
					tmp[copycounter] = arr[i];
					copycounter++;
				}
				tmp[copycounter] = '\0';
				if (sign == 'n')
				{
					integerbuff = new Integer(atoi(tmp));
				}
				else
				{
					integerbuff = new Integer(atoi(tmp), sign);
				}
				integerbuff->Visualise(std::cout);
				lines[size - 1].AddElement(integerbuff);
				delete[] tmp;
				delete integerbuff;
				beg = 0;
				end = 0;
				copycounter = 0;
				dotcount = 0;
				sign = 'n';
			}
			else if (dotcount == 1)
			{
				tmp = new char[end - beg + 2];
				for (int i = beg; i <= end; ++i)
				{
					tmp[copycounter] = arr[i];
					copycounter++;
				}
				tmp[copycounter] = '\0';
				if (sign == 'n')
				{
					doublebuff = new Double(atof(tmp), tmp);
				}
				else
				{
					doublebuff = new Double(atof(tmp), sign, tmp);
				}
				doublebuff->Visualise(std::cout);
				lines[size - 1].AddElement(doublebuff);
				delete[] tmp;
				delete doublebuff;
				beg = 0;
				end = 0;
				copycounter = 0;
				dotcount = 0;
				sign = 'n';
			}
			else if (dotcount == 2)
			{
				end = counter - 1;
				tmp = new char[end - beg + 2];
				for (int i = beg; i <= end; ++i)
				{
					tmp[copycounter] = arr[i];
					copycounter++;
				}
				tmp[copycounter] = '\0';
				datebuff = new Date(tmp);
				datebuff->Visualise(std::cout);
				lines[size - 1].AddElement(datebuff);
				copycounter = 0;
				end = 0;
				beg = 0;
				dotcount = 0;
				delete[] tmp;
				delete datebuff;
			}
				elementcntr++;
		}
		while (arr[counter] == ' ' && arr[counter] != '\0')
		{
			counter++;
		}
		if (arr[counter] == ',' && arr[counter] != '\0')
		{
			counter++;
		}
	}
	return elementcntr;
}

void Table::Print()
{
	int* maxlen = new int[columnrank];
	for (int j = 0; j < columnrank; ++j)	// Collecting the widest data in the column
	{
		for (int i = 0; i < size; ++i)
		{
			if (lines[i][j] != nullptr)
			{
				if (j < lines[i].GetSize())
				{
					if (lines[i][j]->GetLen() > maxlen[j])
					{
						maxlen[j] = lines[i][j]->GetLen();
					}
				}
			}
			else
			{

			}
		}
	}
	for (int p = 0; p < columnrank; ++p)
	{
		std::cout << maxlen[p] << "|";
	}
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < columnrank; ++j)
			{
				if (j < lines[i].GetSize())
				{
					if (lines[i][j] != nullptr)
					{
						if (lines[i][j]->GetLen() < maxlen[j])
						{
							if ((maxlen[j] - lines[i][j]->GetLen()) % 2 == 0)
							{
								for (int z = 0; z < (maxlen[j] - lines[i][j]->GetLen()) / 2; ++z)
								{
									std::cout << " ";
								}
								lines[i][j]->Visualise(std::cout);
								for (int z = 0; z < (maxlen[j] - lines[i][j]->GetLen()) / 2; ++z)
								{
									std::cout << " ";
								}
							}
							else
							{
								for (int z = 0; z < (maxlen[j] - lines[i][j]->GetLen()) / 2; ++z)
								{
									std::cout << " ";
								}
								lines[i][j]->Visualise(std::cout);
								for (int z = 0; z <= (maxlen[j] - lines[i][j]->GetLen()) / 2; ++z)
								{
									std::cout << " ";
								}
							}
						}
						else
						{
							lines[i][j]->Visualise(std::cout);
						}
						std::cout << "|";
					}
					else
					{
						for (int z = 0; z < maxlen[j]; ++z)
						{
							std::cout << " ";
						}
						std::cout << "|";
					}
				}
				else
				{
					for (int z = 0; z < maxlen[j]; ++z)
					{
						std::cout << " ";
					}
					std::cout << "|";
				}
			}
		std::cout << std::endl;
	}
	delete[] maxlen;
}


void Table::Sort(const int& columnn) // Simple Bubble Sort
{
	int column = columnn - 1; // -1 because of the interface requirements
	Line tmp;
	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < (size - i); ++j)
		{
			if (lines[j][column] != nullptr && j < lines[j].GetSize() - 1)
			{
				if (lines[j + 1][column] != nullptr && j < lines[j+1].GetSize() - 1)
				{
					if (lines[j][column]->DoubleValue() > lines[j + 1][column]->DoubleValue())
					{
						tmp = lines[j];
						lines[j] = lines[j + 1];
						lines[j + 1] = tmp;
					}
				}
				else
				{
					tmp = lines[j];
					lines[j] = lines[j + 1];
					lines[j + 1] = tmp;
				}
			}
		}
	}
}

Table::~Table()
{
	delete[] lines;
}
