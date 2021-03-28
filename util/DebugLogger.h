/*
 * DebugLogger.h
 *
 * Simple console/terminal logger
 * Usage:
 * Include this header in your project 
 * 		#include "debuglogger.h"
 *  Usage:
 *  	using namespace codesmith;
 *		LOG_INFO() "You have a minor problem";
 *		LOG_WARN() "Warning, this happened " << warncount << " times";
 *		LOG_ERROR() "Fata error happened, your code sucks";
 *
 * Created on: Nov 18, 2019
 * Author: Erno Pakarinen
 * mail-to: codesmith.fi@gmail.com
 */

#ifndef __DEBUGLOGGER_H_DEFINED__
#define __DEBUGLOGGER_H_DEFINED__

#include <iostream>
#include <sstream>

namespace codesmith
{
	namespace Debug
	{
		enum class DebugLogLevel : int
		{
			INFO = 0,
			WARN = 1,
			ERROR = 2
		};

		class DebugLogger
		{
		public:
			DebugLogger(DebugLogLevel severity = DebugLogLevel::ERROR) : m_buffer()
			{
				std::string sevStr;
				if (severity == DebugLogLevel::ERROR) {
					sevStr = "ERROR";
				}
				else if (severity == DebugLogLevel::WARN) {
					sevStr = "WARN";
				}
				else {
					sevStr = "INFO";
				}
				m_buffer << sevStr << ": ";
			}

			// Destructor, causes the debug info to be outputted
			virtual ~DebugLogger() {
				m_buffer << std::endl;
				std::cerr << m_buffer.str();
			}

			/**
			 * Stream output operator, appends a value to the debug output stream
			 */
			template <typename T>
			DebugLogger& operator<<(T const& value) {
				m_buffer << value;
				return *this;
			}

		private:
			std::ostringstream m_buffer;
		};
	}
}

using namespace codesmith::Debug;

/**
 * Helper macros/defines for using the DebugLogger
 */
#define LOG_INFO() DebugLogger(DebugLogLevel::INFO)
#define LOG_WARN() DebugLogger(DebugLogLevel::WARN)
#define LOG_ERROR() DebugLogger(DebugLogLevel::ERROR)

#endif // __DEBUGLOGGER_H_DEFINED__
