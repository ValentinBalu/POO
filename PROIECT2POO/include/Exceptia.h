#include <exception>

class Exceptia: public std::exception {
    const char* what_arg;
public:
  Exceptia(const char* what_arg) throw() {
    this->what_arg = what_arg;
  };
  ~Exceptia() throw() {};

  const char* what() const throw() {
    return this->what_arg;
  }
};

