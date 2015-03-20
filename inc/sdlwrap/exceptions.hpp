#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP
#include <stdexcept>

namespace sdlwrap{
    class exMissingFile : public std::runtime_error {
    public:
        exMissingFile(std::string path) : std::runtime_error("failure to locate file" + path ) {}
    };

    class exInitFailure : public std::runtime_error {
    public:
        exInitFailure() : std::runtime_error("failure to initialize") {}
    };
};


#endif /* EXCEPTIONS_HPP */
