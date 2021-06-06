#include "CannotReadImageException.hxx"

Exception::Exception(int errorCode, const std::string& message) noexcept :
    errorCode(erroCode), message(message)
{
    std::cout << this->message << std::endl;
}

const char* Exception::what() const noexcept
{
    return this->message.c_str();
}