#include "duration_helpers.h"
#include <stdexcept>
#include <unordered_map>

namespace utils
{
	std::chrono::nanoseconds getDuration(char type, long& number)
	{
		std::chrono::nanoseconds duration{0};
		switch (type)
		{
			case 'Y':
				duration += std::chrono::hours(number * 365 * 24);
				number = 0;
				break;
			case 'M':
				duration += std::chrono::hours(number * 24);
				number = 0;
				break;
			case 'd':
				duration += std::chrono::hours(number * 30 * 24);
				number = 0;
				break;
			case 'h':
				duration += std::chrono::hours(number);
				number = 0;
				break;
			case 'm':
				duration += std::chrono::minutes(number);
				number = 0;
				break;
			case 's':
				duration += std::chrono::seconds(number);
				number = 0;
				break;
			default:
				throw std::runtime_error("Invalid Date format");
		}
		return duration;
	}
	std::chrono::nanoseconds parseDuration(const std::string& durationStr)
	{
		std::chrono::nanoseconds duration(0);

		std::unordered_map<char, char> map = {
			{'Y', 'M'},
			{'M', 'd'},
			{'d', 'h'},
			{'h', 'm'},
			{'m', 's'},
			{'s', 's'},
			{ 0 , 'm'}
		};
		long number = 0;
		char type = 0;
		for (size_t i = 0; i < durationStr.size(); ++i)
		{
			if (!isdigit(durationStr[i]))
			{
				type = durationStr[i];
				duration += getDuration(type, number);
			}
			else
				number = number * 10 + durationStr[i] - '0';
		}
		duration += getDuration(map[type], number);
		return duration;
	}
} // namespace utils


