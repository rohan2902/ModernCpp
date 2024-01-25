#ifndef RESPONSE_H
#define RESPONSE_H
#include<iostream>


class Response
{
private:
    std::string _response_string{""};
    long _response_status_code{0L};
    double _elapsed_time_since_execution{0.0};
public:    
    Response() = default;
    Response(const Response&) = delete;
    Response(Response&&) = delete;
    Response& operator =(const Response&) = delete;
    Response& operator = (Response&&) = delete;
    ~Response() = default;

    std::string responseString() const { return _response_string; }

    long responseStatusCode() const { return _response_status_code; }

    double elapsedTimeSinceExecution() const { return _elapsed_time_since_execution; }

};

#endif // RESPONSE_H
