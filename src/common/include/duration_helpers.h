#ifndef __DURATION_HELPERS_H__
#define __DURATION_HELPERS_H__
#include <chrono>
#include <string>

namespace utils
{
	std::chrono::nanoseconds getDuration(char type, long& number);
	std::chrono::nanoseconds parseDuration(const std::string& durationStr);
} // namespace utils



#endif