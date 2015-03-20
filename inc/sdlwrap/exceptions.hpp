#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <stdexcept>

namespace sdlwrap{
    class exMissingFile : public std::runtime_error {
    public:
        exMissingFile(std::string path) : std::runtime_error("failure to locate file" + path ) {}
    };
};


#endif /* EXCEPTIONS_HPP */
