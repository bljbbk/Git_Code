#include "log_helper.h"
#include <boost/program_options.hpp>
#include <log4cpp/PropertyConfigurator.hh>
#include <iostream>
#include <string>


int main(int argc, char const *argv[])
{
	boost::program_options::options_description desc("options");
	desc.add_options()
		("help, h", "help message")
		("config, c", boost::program_options::value<std::string>(), "set config file name")
		("logproperties, l", boost::program_options::value<std::string>(), "set log properties file name")
	;

	boost::program_options::variables_map vm;
	boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
	boost::program_options::notify(vm); 

	std::string configFile;
	if(vm.count("config"))
	{
		configFile = vm["config"].as<std::string>().c_str();
	}
	else
	{
		std::cout << desc << std::endl;
		return -1;
	}

	std::string logPropertyFile;
	if(vm.count("logproperties"))
	{
		logPropertyFile = vm["logproperties"].as<std::string>().c_str();
	}
	else
	{
		std::cout << desc << std::endl;
		return -1;
	}

	log4cpp::PropertyConfigurator::configure(logPropertyFile);
	LOG_PRINT(g_log, LOG_LEVEL_DEBUG, "done");

	return 0;
}


