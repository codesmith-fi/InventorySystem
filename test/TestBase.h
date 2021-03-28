/*
 * A simple base class for unit tests
 *
 *  Created on: Nov 18, 2019
 *      Author: erno
 */

#ifndef __TEST_BASE_H_DEFINED__
#define __TEST_BASE_H_DEFINED__

#include <string>
#include <memory>

namespace codesmith {
	namespace Testing {
		/**
		 * Simple base class for unit testing
		 */
		class TestBase {
			TestBase() : m_testFailCount(0), m_testSuccessCount(0) { };

		public: // helpers
			int FailCount() { return m_testFailCount; };
			int SuccessCount() { return m_testSuccessCount; };
			void TestFailure(const std::string& description);
			void TestSuccess(const std::string& description);
			void AssertCondition(bool condition, const std::string& testMessage);

		private: // Data
			int m_testFailCount;
			int m_testSuccessCount;
		};
	}  // namespace Testing
} // namespace codesmith

#endif // __TEST_BASE_H_DEFINED__
