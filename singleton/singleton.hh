#pragma once

#include <iostream>
#include <string>

template <class T>
class Singleton
{
protected:
    Singleton<T>()
    {}

public:
    Singleton(Singleton const&) = delete; // copy ctor
    Singleton(Singleton&&) = delete; // move ctor
    Singleton& operator=(Singleton const&) = delete; // copy assignment
    Singleton& operator=(Singleton&&) = delete;
    static T* instance()
    {
        static T instance;
        return &instance;
    }
};

class Logger : public Singleton<Logger>
{
    friend class Singleton<Logger>;

public:
    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();

private:
    Logger()
    {}
};
