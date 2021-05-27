
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"

Text::Text ( const char *charSeq )
{
	bufferSize = strlen(charSeq) + 1; // ('\0')
	buffer = new char[bufferSize];
	strcpy(buffer, charSeq);
}

Text::Text ( const Text &other )
{
	bufferSize = other.bufferSize;
	this->buffer = new char[bufferSize];
	strcpy(buffer, other.buffer);
}

void Text::operator = ( const Text &other )
{
	if (other.bufferSize > bufferSize) // if other will not fit then release and allocate larger
	{
		delete[] this->buffer;
		this->buffer = new char[other.bufferSize];
	}
	strcpy(this->buffer, other.buffer);
}

Text::~Text ()
{
	delete[] buffer;
}

int Text::getLength () const
{
	int length;
	length = strlen(this->buffer);
	return length;
}

char Text::operator [] ( int n ) const
{
	if (n > this->bufferSize)
	{
		return '\0';
	}
	else
	{
		return this->buffer[n]; 
	}
}

void Text::clear ()
{
	memset(&this->buffer[0], 0, sizeof(this->buffer));
}

void Text::showStructure() const

// Outputs the characters in a string. This operation is intended for
// testing/debugging purposes only.

{
	int j;   // Loop counter

	for (j = 0; j < bufferSize; j++)
		cout << j << "\t";
	cout << endl;
	for (j = 0; buffer[j] != '\0'; j++)
		cout << buffer[j] << "\t";
	cout << "\\0" << endl;
}

Text Text::toUpper( ) const
{
	Text temp(buffer);

	for (int i = 0; i < temp.bufferSize; i++)
	{
		if (int(this->buffer[i]) > 96 && int(this->buffer[i]) < 123)
		{
			temp.buffer[i] = int(this->buffer[i]) - 32;
		}
	}
	return temp;
}

Text Text::toLower( ) const
{
	Text temp(buffer);

	for (int i = 0; i < temp.bufferSize; i++)
	{
		if (int(this->buffer[i]) > 64 && int(this->buffer[i]) < 90)
		{
			temp.buffer[i] = int(this->buffer[i]) + 32;
		}
	}
	return temp;
}

bool Text::operator == ( const Text& other ) const
{
	if (strcmp(this->buffer, other.buffer) == 0)
	{
		return true;
	}
	return false;
}

bool Text::operator <  ( const Text& other ) const
{
	if (strcmp(this->buffer, other.buffer) < 0)
	{
		return true;
	}
	return false;
}

bool Text::operator >  ( const Text& other ) const
{
	if (strcmp(this->buffer, other.buffer) > 0)
	{
		return true;
	}
	return false;
}
