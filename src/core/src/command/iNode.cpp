#include "iNode.h"

namespace command
{
	bool iNode::validate(ArgumentList&& args)
	{
		_opCity = false;
		_opRailNode = false;
		_node_name = "";

		if (args.size() > 1 || args[_cmd].size() > 1)
			throw std::runtime_error(message::NodeUsage);
		_node_name = args[_cmd][0];
		if (_node_name.empty())
			throw std::runtime_error(message::EmptyNodeName);
		if (_node_name.find("City") == 0)
			_opCity = true;
		else if (_node_name.find("RailNode") == 0)
			_opRailNode = true;
		if (!_opCity && !_opRailNode)
			throw std::runtime_error(message::InvalidNodeName);
		return true;
		
	}

	bool iNode::execute(ArgumentList&& args)
	{
		if (_opCity)
		{
			if (!_net->insert(_node_name, object::node_type::CITY))
				std::runtime_error("Cannot create Node " + _node_name);
		}
		else if (_opRailNode)
		{
			if (!_net->insert(_node_name, object::node_type::RAIL))
				std::runtime_error("Cannot create Node " + _node_name);
		}
		auto find_node = [&](const std::string& a_name) -> void
		{
			auto* node_ptr = _cont->get(
			[&](object::node* node) -> bool
			{
				return node->name() == a_name;
			});
			if (!node_ptr)
				throw std::runtime_error(_node_name + " " + message::NonExistsNode);
		};
		find_node(_node_name);
		return true;
	}
}