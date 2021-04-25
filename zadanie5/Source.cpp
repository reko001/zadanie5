#include <iostream>
#include <fstream>

class Dziennik {
private:
	enum LogLevel { FINEST, FINER, FINE, CONFIG, INFO, WARNING, SEVERE };
	bool toFile;
	std::fstream file;
	LogLevel level;

	void logFinest(std::string message) {
		if (toFile) {
			file << "[ FINEST ] " << message << std::endl;
		}
		else {
			std::cout << "[ FINEST ] " << message << std::endl;
		}
	}

	void logFiner(std::string message) {
		if (toFile) {
			file << "[ FINER ] " << message << std::endl;
		}
		else {
			std::cout << "[ FINER ] " << message << std::endl;
		}
	}
	void logFine(std::string message) {
		if (toFile) {
			file << "[ FINE ] " << message << std::endl;
		}
		else {
			std::cout << "[ FINE ] " << message << std::endl;
		}
	}
	void logConfig(std::string message) {
		if (toFile) {
			file << "[ CONFIG ] " << message << std::endl;
		}
		else {
			std::cout << "[ CONFIG ] " << message << std::endl;
		}
	}
	void logInfo(std::string message) {
		if (toFile) {
			file << "[ INFO ] " << message << std::endl;
		}
		else {
			std::cout << "[ INFO ] " << message << std::endl;
		}
	}
	void logWarning(std::string message) {
		if (toFile) {
			file << "[ WARNING ] " << message << std::endl;
		}
		else {
			std::cout << "[ WARNING ] " << message << std::endl;
		}
	}
	void logSevere(std::string message) {
		if (toFile) {
			file << "[ SEVERE ] " << message << std::endl;
		}
		else {
			std::cout << "[ SEVERE ] " << message << std::endl;
		}
	}

	void log() {

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
		log();
		file.close();
	}

	void printToConsole(std::string message) {
		toFile = false;
		log();
	}


};

int main() {

}