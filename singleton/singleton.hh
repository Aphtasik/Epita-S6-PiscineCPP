#pragma once

#include <iostream>
#include <string>

template <class T>
class Singleton
{
public:
    Singleton(Singleton const&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static T* instance()
    {
        static T* instance;
        return instance;
    }

protected:
    Singleton<T>()
    {}
};

class Logger : public Singleton<Logger>
{
    friend class Singleton<Logger>;

public:
    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();

protected:
    Logger()
    {}
};
