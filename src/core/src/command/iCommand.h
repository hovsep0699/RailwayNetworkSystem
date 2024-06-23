#ifndef __ICOMMAND_H__
#define __ICOMMAND_H__

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include "iContainer.h"
#include "network.h"
#include "include/event.h"
#include "config.h"
#ifndef CONFDIR
	#define CONFDIR "."
#endif

namespace command
{
	enum class command_type
	{
		FILEOPEN,
		RAILLOAD,
		TRAINLOAD,
		NODE,
		RAIL,
		EVENT,
		TRAIN
	};

	using ArgumentList = std::unordered_map<std::string, std::vector<std::string>>;

	class iCommand
	{
		private:
			command_type _type;
		protected:
			std::string	 _cmd;
		public:
			command_type type() const
			{
				return _type;
			}
			const std::string& name() const
			{
				return _cmd;
			}
			iCommand(const std::string& a_name, const std::string& a_extension, command_type a_type) : _type(a_type)
			{
				_cmd = a_name + a_extension;
			};
			virtual ~iCommand() = default;
			virtual bool validate(ArgumentList&& args) = 0;
			virtual bool execute(ArgumentList&& args) = 0;
	};
	
	using iCommand_ptr = std::unique_ptr<iCommand>;
	
} // namespace command




#endif