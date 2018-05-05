#pragma once

#ifndef LOG_LEVEL_EMERG 				/* system is unusable */
	#define LOG_LEVEL_EMERG 	(0)
#endif

#ifndef LOG_LEVEL_FATAL 				/* system is unusable */
	#define LOG_LEVEL_FATAL 	(0)
#endif

#ifndef LOG_LEVEL_ALERT 				/* action must be taken immediately */
	#define LOG_LEVEL_ALERT   	(1)
#endif

#ifndef LOG_LEVEL_CRIT 					/* critical conditions */
	#define LOG_LEVEL_CRIT    	(2)
#endif

#ifndef LOG_LEVEL_ERROR 				/* error conditions */
	#define LOG_LEVEL_ERROR   	(3)
#endif

#ifndef LOG_LEVEL_WARN 					/* warning conditions */
	#define LOG_LEVEL_WARN    	(4)
#endif

#ifndef LOG_LEVEL_NOTICE 				/* normal but significant conditions */
	#define LOG_LEVEL_NOTICE  	(5)
#endif

#ifndef LOG_LEVEL_INFO					/* informational */
	#define LOG_LEVEL_INFO    	(6)
#endif

#ifndef LOG_LEVEL_DEBUG					/* debug-level messages */
	#define LOG_LEVEL_DEBUG    	(7)
#endif


#ifndef LOG4CPP_OFF
#include <log4cpp/Category.hh>
extern log4cpp::Category& g_log;

#ifdef WIN32
	#define LOG_PRINT(category, level, msg, ...)\
		do\
		{\
			if(LOG_LEVEL_EMERG == level)\
			{\
				category.emerg(msg, __VA_ARGS__);\
			}\
			else if(LOG_LEVEL_FATAL == level)\
			{\
				category.fatal(msg, __VA_ARGS__);\
			}\
			else if(LOG_LEVEL_ALERT == level)\
			{\
				category.alert(msg, __VA_ARGS__);\
			}\
			else if(LOG_LEVEL_CRIT == level)\
			{\
				category.crit(msg, __VA_ARGS__);\
			}\
			else if(LOG_LEVEL_ERROR == level)\
			{\
				category.error(msg, __VA_ARGS__);\
			}\
			else if(LOG_LEVEL_WARN == level)\
			{\
				category.warn(msg, __VA_ARGS__);\
			}\
			else if(LOG_LEVEL_NOTICE == level)\
			{\
				category.notice(msg, __VA_ARGS__);\
			}\
			else if(LOG_LEVEL_INFO == level)\
			{\
				category.info(msg, __VA_ARGS__);\
			}\
			else if(LOG_LEVEL_DEBUG == level)\
			{\
				category.debug(msg, __VA_ARGS__);\
			}\
			else\
			{\
				category.debug(msg, __VA_ARGS__);\
			}\
		}while(0)


#else
	#define LOG_PRINT(category, level, msg, args...)\
		do\
		{\
			if(LOG_LEVEL_EMERG == level)\
			{\
				category.emerg(msg, ##args);\
			}\
			else if(LOG_LEVEL_FATAL == level)\
			{\
				category.fatal(msg, ##args);\
			}\
			else if(LOG_LEVEL_ALERT == level)\
			{\
				category.alert(msg, ##args);\
			}\
			else if(LOG_LEVEL_CRIT == level)\
			{\
				category.crit(msg, ##args);\
			}\
			else if(LOG_LEVEL_ERROR == level)\
			{\
				category.error(msg, ##args);\
			}\
			else if(LOG_LEVEL_WARN == level)\
			{\
				category.warn(msg, ##args);\
			}\
			else if(LOG_LEVEL_NOTICE == level)\
			{\
				category.notice(msg, ##args);\
			}\
			else if(LOG_LEVEL_INFO == level)\
			{\
				category.info(msg, ##args);\
			}\
			else if(LOG_LEVEL_DEBUG == level)\
			{\
				category.debug(msg, ##args);\
			}\
			else\
			{\
				category.debug(msg, ##args);\
			}\
		}while(0)
#endif


#else
#include <stdio.h>

#ifdef WIN32
	#define LOG_PRINT(category, level, msg, ...)\
			printf("[%s : %d]" "msg\r\n", __FUNCTION__, __LINE__, __VA_ARGS__)
#else
	#define LOG_PRINT(category, level, msg, args...)\
			printf("[%s : %d]" "msg\r\n", __FUNCTION__, __LINE__, ##args)	
#endif

#endif