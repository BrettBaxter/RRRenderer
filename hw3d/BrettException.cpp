#include "BrettException.h"
#include <sstream>

BrettException::BrettException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* BrettException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* BrettException::GetType() const noexcept
{
	return "Brett Exception";
}

int BrettException::GetLine() const noexcept
{
	return line;
}

const std::string& BrettException::GetFile() const noexcept
{
	return file;
}

std::string BrettException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File]" << file << std::endl
		<< "[Line]" << line;
	return oss.str();
}