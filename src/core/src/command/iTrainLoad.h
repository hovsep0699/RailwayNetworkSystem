#include "iFileOpen.h"

namespace command
{
	class iTrainLoad : public iFileOpen
	{
		public:
			iTrainLoad() : iFileOpen("Train", "Load") {}
			bool validate(ArgumentList&& args) override;
			bool execute(ArgumentList&& args) override;
	};
} // namespace command