#ifndef __UNIQUEIDGENERATOR_H__
#define __UNIQUEIDGENERATOR_H__


#include <stddef.h>

namespace generator
{

	// Generate a unique ID based on timestamp, process ID, and a counter
	size_t generateID();

} // namespace generator


#endif