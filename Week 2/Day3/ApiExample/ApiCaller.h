#ifndef APICALLER_H
#define APICALLER_H

#include<curl/curl.h>
#include<iostream>
#include"Response.h"
#include<memory>


class ApiCaller
{
private:
    CURL* _curl_session_object_handle{nullptr};
    const char* _end_point{nullptr};
    std::shared_ptr<Response> _response{nullptr};
    std::string _request_header{""};

public:
    ApiCaller(std::string url);
    ApiCaller(std::string url,std::string header);
    bool InitializeSessions();
    void ExecuteApiCall();
    ApiCaller() = default;
    ApiCaller(const ApiCaller&) = delete;
    ApiCaller(ApiCaller&&) = delete;
    ApiCaller& operator =(const ApiCaller&) = delete;
    ApiCaller& operator = (ApiCaller&&) = delete;
    ~ApiCaller() = default;


    friend std::ostream &operator<<(std::ostream &os, const ApiCaller &rhs);
};

#endif // APICALLER_H
