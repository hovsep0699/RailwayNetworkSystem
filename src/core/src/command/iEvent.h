#include "iObjectCreate.h"

namespace command
{
	class iEvent : public iObjectCreate<object::container_type::EVENT>
	{
		using duration_type = object::event::duration_type;
		std::string		_name;
		double			_prob;
		duration_type	_duration;
		std::string		_loc;
		public:
			iEvent() : Base("Event", command_type::EVENT) {}
			bool validate(ArgumentList&& args) override;
			bool execute(ArgumentList&& args) override;
	};
} // namespace command



