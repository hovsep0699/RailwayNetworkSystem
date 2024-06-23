#ifndef __IOBJECTCREATE_H__
#define __IOBJECTCREATE_H__
#include "iCommand.h"

namespace command
{
	template<object::container_type Type>
	class iObjectCreate : public iCommand
	{
		protected:
			using Base = iObjectCreate<Type>;
			network::network* _net;
			object::iContainer<Type>* _cont;
		public:
			iObjectCreate(const std::string& a_objname, command_type type)
				: iCommand("object", a_objname, type)
			{
				_net = config::config::Config().Network();
				_cont = _net->Manager()->get<Type>();
			}
	};

} // namespace command


#endif