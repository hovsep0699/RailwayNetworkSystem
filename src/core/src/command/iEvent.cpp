#include "iEvent.h"


namespace command
{
	bool iEvent::validate(ArgumentList&& args)
	{
		_name = "";
		_prob = 0;
		_duration = duration_type();
		_loc = "";
		if (args.size() > 1 || args[_cmd].size() > 4)
			throw std::runtime_error(message::EventUsage);
		_name = args[_cmd][0];
		if (_name.empty())
			throw std::runtime_error("Event name is empty");
		try
		{
			_prob = std::stod(args[_cmd][1]);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("Event probability should be a number");
		}
		_duration = utils::parseDuration(args[_cmd][2]);
		_loc = args[_cmd][3];
		if (_loc.empty())
			std::runtime_error(message::EmptyNodeName);
		auto loc = _net->Manager()->get<object::container_type::NODE>()->get(
		[&](object::node* n)
		{
			return n->name() == _loc;
		});
		if (!loc)
			throw std::runtime_error(message::NonExistsNode);
		return true;
	}

	bool iEvent::execute(ArgumentList&& args)
	{
		if(!_net->insert(_name, _prob, _duration, _loc))
			throw std::runtime_error("Cannot create event");
		return true;
	}
} // namespace command

