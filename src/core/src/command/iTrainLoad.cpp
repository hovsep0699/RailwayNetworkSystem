#include "iTrainLoad.h"

namespace command
{
	bool iTrainLoad::validate(ArgumentList&& args)
	{
		ArgumentList lst{args};
		if(!iFileOpen::validate(std::move(lst))) return false;
		if (args.size() > 2)
			throw std::runtime_error("Invalid options");
		if (args.find("--train") == args.end() || args["--train"].size() < 1)
			throw std::runtime_error("Invalid options");
		_filename = args["--train"].at(0);
		return true;
	}

	bool iTrainLoad::execute(ArgumentList&& args)
	{
		if(!iFileOpen::execute(std::move(args))) return false;
	
		auto& conf = config::config::Config();
		auto* manager = conf.Manager()->get( handler::handler_type::TRAIN);
		manager->load(_filename);
		return true;
	}
} // namespace command
