#ifndef CLOGGER_HPP
#define CLOGGER_HPP

#include <iostream>
#include <string>
#include <unordered_map>

namespace clog {

class {
	class named_logger;

public:
	std::string name;

	named_logger& operator [] (std::string str) {
		return named_loggers[str];
	}

private:
	class named_logger {
	public:
	
		void operator () (std::ostream& os) {
			this->os = &os;
		}

		named_logger* operator << (std::string str) {
			*os << str;
			*os << std::endl;
			return this;
		}

		std::ostream* os = &std::cout;
	};

	std::unordered_map<std::string, named_logger> named_loggers;
} logger;

} // namespace clog

#endif
