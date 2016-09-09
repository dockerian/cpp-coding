/*
 * File: convert.h
 */

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
 
class ErrorOnConversion : public std::runtime_error {
	public:
	ErrorOnConversion(const std::string &s)	: std::runtime_error(s)	{ }
};
 
template<typename T>
inline std::string toString(const T &x)
{
	std::ostringstream o;
	if (!(o << x))
	{
		throw ErrorOnConversion(std::string("toString(") + typeid(x).name() + ")");
	)
	return o.str();
} 

template<typename T>
inline void convert(const std::string &s, T &x, bool failIfLeftoverChars = true)
{
	std::istringstream i(s);
	char c;
	if (!(i >> x) || (failIfLeftoverChars && i.get(c)))
	{
		throw ErrorOnConversion(s);
	}
} 

template<typename T>
inline T convertTo(const std::string &s, bool failIfLeftoverChars = true)
{
	std::istringstream i(s);
	T x;
	convert(s, x, failIfLeftoverChars);
	return x;
}


inline std::string doubletostring(double x)
{
	std::ostringstream o;
	if (!(o << x))
	(
		throw ErrorOnConversion("doubletostring(double)");
	)
	return o.str();
} 

inline double stringtodouble(const std::string &s)
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
	{
		throw ErrorOnConversion("stringtodouble(\"" + s + "\")");
	}
	return x;
}



