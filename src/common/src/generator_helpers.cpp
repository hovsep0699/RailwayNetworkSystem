#include "generator.h"
#include <chrono>
#include <unistd.h>

namespace generator
{
	size_t generateID()
	{
		static size_t counter;
		unsigned long pid = static_cast<unsigned long>(getpid());
		auto now = std::chrono::system_clock::now();
		auto duration = now.time_since_epoch();
		auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
		size_t id = (millis << 16) | (pid << 8) | (counter);
		++counter;
		return id;
	}
} // namespace generator


