#include "iCommand.h"

namespace command
{
	class iFileOpen : public iCommand
	{
		protected:
			std::string _filename;
		public:
			iFileOpen(const std::string& a_name = "file", const std::string& a_name_prefix = "open")
				: iCommand(a_name, a_name_prefix, command_type::FILEOPEN)
			{}
			virtual bool validate(ArgumentList&& args) override;
			virtual bool execute(ArgumentList&& args) override;
	};
} // namespace command


	