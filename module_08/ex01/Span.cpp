#include "Span.hpp"

Span::Span() : N(0){}
Span::Span(Span const &other){*this = other;}
Span::Span(unsigned int N) : N(N){}
Span::~Span(){}

Span &Span::operator=(Span const &other)
{
	if (this == &other)
		return (*this);
	this->N = other.getN();
	this->storage = other.getStorage();
	return (*this);
}

unsigned int Span::getN() const{return (this->N);}
std::vector<int> Span::getStorage() const{return (this->storage);}

void Span::addNumber(int number)
{
	if (this->storage.size() >= this->N)
		throw Span::FullStorageException();
	this->storage.push_back(number);
}

int Span::shortestSpan()
{
	if (this->storage.size() <= 1)
	{
		throw Span::NotEnoughNumbersException();
		return (-1);
	}

	std::vector<int> tmp = this->storage;
	std::sort(tmp.begin(), tmp.end());

	int shortest = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < shortest)
			shortest = tmp[i] - tmp[i - 1];
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (this->storage.size() <= 1)
	{
		throw Span::NotEnoughNumbersException();
		return (-1);
	}
	std::vector<int>::iterator min = std::min_element(this->storage.begin(), this->storage.end());
    std::vector<int>::iterator max = std::max_element(this->storage.begin(), this->storage.end());

    return (*max - *min);
}
int getRandomeNumber()
{
	return (rand() % 100000);
}

void Span::autoFill()
{
	this->storage.resize(this->N);
	std::generate(this->storage.begin(), this->storage.end(), &getRandomeNumber);
	std::sort(this->storage.begin(), this->storage.end());
}

const char* Span::FullStorageException::what() const throw()
{
	return ("Storage is full");
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers to calculate span");
}

std::ostream &operator<<(std::ostream &out, Span const &span)
{
	out << std::endl << "<< content >> ";
	for (unsigned int i = 0; i < span.getStorage().size(); i++)
	{
		out << span.getStorage()[i];
		if (i < span.getStorage().size() - 1)
			out << " ";
	}
	out << std::endl << std::endl << "<<  size   >> " << span.getN() << std::endl;
	return (out);
}
