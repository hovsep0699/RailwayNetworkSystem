#include "iRail.h"

namespace command
{
	bool iRail::validate(ArgumentList&& args)
	{
		_from = "";
		_to = "";
		_distance = 0;
		if (args.size() > 1 || args[_cmd].size() > 3)
			throw std::runtime_error(message::RailUsage);
		auto* manager = _net->Manager()->get<object::container_type::NODE>();
		auto find_node = [&](const std::string& a_name) -> void
		{
			auto* node_ptr = manager->get(
			[&](object::node* node) -> bool
			{
				return node->name() == a_name;
			});
			if (!node_ptr)
				throw std::runtime_error(message::NonExistsNode);
		};
		_from = args[_cmd][0];
		if (_from.empty())
			throw std::runtime_error(message::EmptyNodeName);
		find_node(_from);
		_to = args[_cmd][1];
		if (_from.empty())
			throw std::runtime_error(message::EmptyNodeName);
		find_node(_to);
		if (_from == _to)
			throw std::runtime_error(message::SameRailStartEnd);
		try
		{
			_distance = std::stod(args[_cmd][2]);
		}
		catch(...)
		{
			throw std::runtime_error("Invalid distance");
		}
		return true;
	}
	
	bool iRail::execute(ArgumentList&& args)
	{
		if(!_net->insert(_from, _to, _distance))
			throw std::runtime_error("Cannot create Rail");

		return true;
	}
} // namespace command
