/*
 * TestBase.cpp
 *
 * Created on: Nov 18, 2019
 * Author: Erno Pakarinen
 * mail-to: codesmith.fi@gmail.com
 */

#include "TestBase.h"
#include "../util/DebugLogger.h"


namespace codesmith {
	namespace Testing {
		/**
		 * Helper method implementation
		 */

		void TestBase::TestFailure(const std::string& description)
		{
			m_testFailCount++;
			std::string msg("Failure: " + description);
			LOG_ERROR() << msg;
		}

		void TestBase::TestSuccess(const std::string& description)
		{
			m_testSuccessCount++;
			std::string msg("Success: " + description);
			LOG_INFO() << msg;
		}

		void TestBase::AssertCondition(bool condition, const std::string& testMessage)
		{
			if (condition) {
				TestSuccess(testMessage);
			}
			else {
				TestFailure(testMessage);
			}
		}
	} // namespace Testing
} // namespace codesmith