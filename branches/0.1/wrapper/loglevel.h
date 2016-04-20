// File:    loglevel.h
////////////////////////////////////////////////////////////////
#ifndef _LOGLEVEL_H_
#define _LOGLEVEL_HR_

namespace logutil{

	/**
	 * \typedef int LogLevel
	 * Defines the minimum set of priorities recognized by the system,
	 * that is {@link #FATAL_LOG_LEVEL}, {@link #ERROR_LOG_LEVEL}, {@link
	 * #WARN_LOG_LEVEL}, {@link #INFO_LOG_LEVEL}, {@link #DEBUG_LOG_LEVEL},
	 * and {@link #TRACE_LOG_LEVEL}.
	 */
	typedef int LogLevel;

	/** \var const LogLevel OFF_LOG_LEVEL
	 * The <code>OFF_LOG_LEVEL</code> LogLevel is used during configuration to
	 * turn off logging. */
	const LogLevel OFF_LOG_LEVEL     = 100000;

	/** \var const LogLevel EMERG_LOG_LEVEL  */
	const LogLevel EMERG_LOG_LEVEL   = 90000;

	/** \var const LogLevel FATAL_LOG_LEVEL
	 * The <code>FATAL_LOG_LEVEL</code> LogLevel designates very severe error
	 * events that will presumably lead the application to abort.  */
	const LogLevel FATAL_LOG_LEVEL   = 80000;

	/** \var const LogLevel ALERT_LOG_LEVEL */
	const LogLevel ALERT_LOG_LEVEL   = 70000;

	/** \var const LogLevel CRIT_LOG_LEVEL */
	const LogLevel CRIT_LOG_LEVEL    = 60000;

	/** \var const LogLevel ERROR_LOG_LEVEL
	 * The <code>ERROR_LOG_LEVEL</code> LogLevel designates error events that
	 * might still allow the application to continue running. */
	const LogLevel ERROR_LOG_LEVEL   = 50000;

	/** \var const LogLevel WARN_LOG_LEVEL
	 * The <code>WARN_LOG_LEVEL</code> LogLevel designates potentially harmful
	 * situations. */
	const LogLevel WARN_LOG_LEVEL    = 40000;

	/** \var const LogLevel NOTICE_LOG_LEVEL
	 * The <code>NOTICE_LOG_LEVEL</code> LogLevel designates potentially harmful
	 * situations. */
	const LogLevel NOTICE_LOG_LEVEL  = 30000;

	/** \var const LogLevel INFO_LOG_LEVEL
	 * The <code>INFO_LOG_LEVEL</code> LogLevel designates informational
	 * messages  that highlight the progress of the application at
	 * coarse-grained  level. */
	const LogLevel INFO_LOG_LEVEL    = 20000;

	/** \var const LogLevel DEBUG_LOG_LEVEL
	 * The <code>DEBUG_LOG_LEVEL</code> LogLevel designates fine-grained
	 * informational events that are most useful to debug an application. */
	const LogLevel DEBUG_LOG_LEVEL   = 10000;

	/** \var const LogLevel NOT_SET_LOG_LEVEL
	 * The <code>NOT_SET_LOG_LEVEL</code> LogLevel is used to indicated that
	 * no particular LogLevel is desired and that the default should be used.
	 */
	const LogLevel NOT_SET_LOG_LEVEL = -1;

}
#endif
