#include "iTrain.h"

namespace command
{
	bool iTrain::validate(ArgumentList&& args)
	{
		if (args.size() > 1 || args[_cmd].size() > 6)
			throw std::range_error(message::TrainUsage);
		_train_name = args[_cmd][0];
		try
		{
			_max_acc_force = std::stod(args[_cmd][1]);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("invalid argument");
		}
		try
		{
			_max_br_force = std::stod(args[_cmd][2]);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("invalid argument");
		}
		_from = args[_cmd][3];
		if (_from.empty())
			throw std::runtime_error(message::EmptyNodeName);
		
		_to = args[_cmd][4];
		if (_to.empty())
			throw std::runtime_error(message::EmptyNodeName);
		_start_time = utils::parseDuration(args[_cmd][5]);
		return true;
	}
	
	
	bool iTrain::execute(ArgumentList&& args)
	{
		if (!_net->insert(_train_name, _max_acc_force, _max_br_force, _from, _to, _start_time))
			throw std::runtime_error("Cannot create Train");
		return true;
	}
} // namespace command
