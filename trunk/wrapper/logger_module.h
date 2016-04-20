// logger_module.h
//////////////////////////////////////////////////
#ifndef _LOGGER_MODULE_H_
#define _LOGGER_MODULE_H_

#include "singleton.h"
#include "loglevel.h"
#include <iostream>
#include <string>
#include <sstream>


// type define output string stream
typedef std::basic_ostringstream<char> tostringstream;
#define LOG_MACRO_INSTANTIATE(var) \
	tostringstream var

#define LOG_MACRO_BODY(logevent, loglevel)                      \
	do {                                                        \
        LOG_MACRO_INSTANTIATE(log_buf);                         \
        log_buf << logevent;                                    \	
        logutil::obj().macro_to_log(log_buf.str(), loglevel);   \ 
	} while(0)


#define LOG_EMERG(p)   LOG_MACRO_BODY(p, logutil::EMERG_LOG_LEVEL)
#define LOG_FATAL(p)   LOG_MACRO_BODY(p, logutil::FATAL_LOG_LEVEL)
#define LOG_ALERT(p)   LOG_MACRO_BODY(p, logutil::ALERT_LOG_LEVEL)
#define LOG_CRIT(p)    LOG_MACRO_BODY(p, logutil::CRIT_LOG_LEVEL)
#define LOG_ERROR(p)   LOG_MACRO_BODY(p, logutil::ERROR_LOG_LEVEL)
#define LOG_WARN(p)    LOG_MACRO_BODY(p, logutil::WARN_LOG_LEVEL)
#define LOG_NOTICE(p)  LOG_MACRO_BODY(p, logutil::NOTICE_LOG_LEVEL)
#define LOG_INFO(p)    LOG_MACRO_BODY(p, logutil::INFO_LOG_LEVEL)
#define LOG_DEBUG(p)   LOG_MACRO_BODY(p, logutil::DEBUG_LOG_LEVEL)

namespace logutil{


	class logger_module:public singleton<logger_module>
	{
	public:
		~logger_module();
	
		// log function
		void macro_to_log(std::string logevent, logutil::LogLevel loglevel);

	public:

	private:
		logger_module();
		// load logger configuration file
		void loadconf();

	private:
		friend class singleton<logger_module>;
	};

	inline logger_module& obj() {return logger_module::instance();}
}
#endif



