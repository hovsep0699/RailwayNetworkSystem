#include "iObjectCreate.h"

namespace command
{
	class iNode : public iObjectCreate<object::container_type::NODE>
	{
		std::string	_node_name;
		bool		_opCity;
		bool		_opRailNode;
		public:
			iNode()
				: Base("Node",command_type::NODE), _opCity{false}, _opRailNode{false}
			{}
			bool validate(ArgumentList&& args) override;
			bool execute(ArgumentList&& args) override;
	};
} // namespace command
