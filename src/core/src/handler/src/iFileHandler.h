#ifndef __IFILEHANDLER_H__
#define __IFILEHANDLER_H__

#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

namespace network
{
	class network;
} // namespace network


namespace handler
{
	enum class handler_type
	{
		RAIL,
		TRAIN
	};
	class iFileHandler
	{
		private:
			network::network*	_network;
			handler_type		_type;
		public:
			iFileHandler(network::network* net = nullptr, handler_type a_type = handler_type::RAIL) : _network{net}, _type{a_type}
			{
				if (!net)
					throw std::runtime_error("Network is not set");
			}
			
			inline handler_type type() const
			{
				return _type;
			}

			inline network::network* getNetwork()
			{
				return _network;
			}

			virtual bool load(const std::string& a_filename) const = 0;
	};
	
} // namespace handler


#endif