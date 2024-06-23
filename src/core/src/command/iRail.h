#include "iObjectCreate.h"

namespace command
{
	class iRail : public iObjectCreate<object::container_type::RAIL>
	{
		std::string	_from;
		std::string	_to;
		double		_distance;
		public:
			iRail() : Base("Rail", command_type::RAIL) {}
			bool validate(ArgumentList&& args) override;
			bool execute(ArgumentList&& args) override;
	};
} // namespace command



