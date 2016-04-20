////////////////////////////////////////////////
// logger_module.cpp
//
////////////////////////////////////////////////
#include "logger_module.h"

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

namespace logutil{
	
	// The object of log4cplus
	static log4cpp::Category& g_logger = log4cpp::Category::getRoot();

	logger_module::logger_module()
	{
		this->loadconf();
	}

	logger_module::~logger_module()
	{
		//release handles of logger
		log4cpp::Category::shutdown();
	}

	// load logger configuration file
	void logger_module::loadconf()
	{
		try
		{
			log4cpp::PropertyConfigurator::configure("log.properties");
		}
		catch (log4cpp::ConfigureFailure& f)
		{
			std::cerr << "configure problem " << f.what() << std::endl;
		}
	}

	// output log
	void logger_module::macro_to_log(std::string logevent, logutil::LogLevel loglevel)
	{
		switch (loglevel)
		{
			case EMERG_LOG_LEVEL:
				LOG4CPP_EMERG(g_logger, logevent);
				break;

			case FATAL_LOG_LEVEL:
				LOG4CPP_FATAL(g_logger, logevent);
				break;

			case ALERT_LOG_LEVEL:
				LOG4CPP_ALERT(g_logger, logevent);
				break;

			case CRIT_LOG_LEVEL:
				LOG4CPP_CRIT(g_logger, logevent);
				break;

			case ERROR_LOG_LEVEL:
				LOG4CPP_ERROR(g_logger, logevent);
				break;

			case WARN_LOG_LEVEL:
				LOG4CPP_WARN(g_logger, logevent);
				break;

			case NOTICE_LOG_LEVEL:
				LOG4CPP_NOTICE(g_logger, logevent);
				break;

			case INFO_LOG_LEVEL:
				LOG4CPP_INFO(g_logger, logevent);
				break;

			case DEBUG_LOG_LEVEL:
				LOG4CPP_DEBUG(g_logger, logevent);
				break;

			case OFF_LOG_LEVEL:
			case NOT_SET_LOG_LEVEL:
				break;

			default:
				break;
		}
	}
} // namespace

