#include <iostream>
#include <fstream>

enum LogLevel { FINEST, FINER, FINE, CONFIG, INFO, WARNING, SEVERE };

class Dziennik {
private:
	bool toFile;
	std::fstream file;
	LogLevel level;

	void logFinest(std::string message) {
		if (toFile) {
			file << "[ FINEST ] " << "   " << message << std::endl;
		}
		else {
			std::cout << "[ FINEST ] " << "   " << message << std::endl;
		}
	}

	void logFiner(std::string message) {
		if (toFile) {
			file << "[ FINER ] " << "    " << message << std::endl;
		}
		else {
			std::cout << "[ FINER ] " << "    " << message << std::endl;
		}
	}
	void logFine(std::string message) {
		if (toFile) {
			file << "[ FINE ] " << "     " << message << std::endl;
		}
		else {
			std::cout << "[ FINE ] " << "     " << message << std::endl;
		}
	}
	void logConfig(std::string message) {
		if (toFile) {
			file << "[ CONFIG ] " << "   " << message << std::endl;
		}
		else {
			std::cout << "[ CONFIG ] " << "   " << message << std::endl;
		}
	}
	void logInfo(std::string message) {
		if (toFile) {
			file << "[ INFO ] " << "     " << message << std::endl;
		}
		else {
			std::cout << "[ INFO ] " << "     " << message << std::endl;
		}
	}
	void logWarning(std::string message) {
		if (toFile) {
			file << "[ WARNING ] " << "  " << message << std::endl;
		}
		else {
			std::cout << "[ WARNING ] " << "  " << message << std::endl;
		}
	}
	void logSevere(std::string message) {
		if (toFile) {
			file << "[ SEVERE ] " << "   " << message << std::endl;
		}
		else {
			std::cout << "[ SEVERE ] " << "   " << message << std::endl;
		}
	}

	void log(std::string message) {
		if (level <= FINEST)
			logFinest(message);
		if (level <= FINER)
			logFiner(message);
		if (level <= FINE)
			logFine(message);
		if (level <= CONFIG)
			logConfig(message);
		if (level <= INFO)
			logInfo(message);
		if (level <= WARNING)
			logWarning(message);
		if (level <= SEVERE)
			logSevere(message);
	}

public:

	Dziennik() {
		level = FINEST;
		toFile = false;
	}

	void setLevel(LogLevel level) {
		this->level = level;
	}

	void logToFile(std::string message, std::string fileName) {
		toFile = true;
		file.open(fileName, std::fstream::app);
		log(message);
		file.close();
	}

	void logToConsole(std::string message) {
		toFile = false;
		log(message);
	}
};

int main() {
	Dziennik* dziennik = new Dziennik();
	dziennik->logToConsole("Message 1");
	dziennik->setLevel(INFO);
	dziennik->logToConsole("Message 2");
	dziennik->logToFile("Message 1", "file.txt");
	dziennik->setLevel(SEVERE);
	dziennik->logToFile("Message 2", "file.txt");
}