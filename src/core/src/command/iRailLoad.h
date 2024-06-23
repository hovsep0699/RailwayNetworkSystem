#include "iFileOpen.h"

namespace command
{
	class iRailLoad : public iFileOpen
	{
		public:
			iRailLoad() : iFileOpen("Rail", "Load") {}
			bool validate(ArgumentList&& args) override;
			bool execute(ArgumentList&& args) override;
	};
} // namespace command


