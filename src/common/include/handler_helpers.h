#ifndef __HANDLER_HELPERS_H__
#define __HANDLER_HELPERS_H__

#include <stddef>
#include <string>

namespace handler_helpers
{
	void strip(std::string& token) const;
	
	std::size_t indexOfCloseQuote(const std::string& str, std::size_t openQuotePos) const;\

	bool isBalancedQuotes(const std::string& str) const;

} // namespace handler_helpers


#endif