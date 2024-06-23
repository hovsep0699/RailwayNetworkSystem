#include "iObjectCreate.h"

namespace command
{
	class iTrain : public iObjectCreate<object::container_type::TRAIN>
	{
		using duration_type = object::event::duration_type;
		std::string		_train_name;
		std::string 	_from;
		std::string 	_to;
		double			_max_acc_force;
		double			_max_br_force;
		duration_type	_start_time;
		public:
			iTrain()
				: Base("Train", command_type::TRAIN) {}
			bool validate(ArgumentList&& args) override;
			bool execute(ArgumentList&& args) override;
	};
} // namespace command


