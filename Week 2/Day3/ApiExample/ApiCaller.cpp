#include "ApiCaller.h"



/*
    constructor mapping for various attributes


*/
ApiCaller::ApiCaller(std::string url):_end_point(url.c_str())
{
}
/*
takes url and header parameters from user
Uses delegation to call the constructor above and assign the header to _request_header
*/

ApiCaller::ApiCaller(std::string url, std::string header):ApiCaller(url)
{
    _request_header = header;
}

/*
    initialize curl session objects
*/
bool ApiCaller::InitializeSessions()
{
    _curl_session_object_handle = curl_easy_init;
    return _curl_session_object_handle;
}

void ApiCaller::ExecuteApiCall()
{
    curl_easy_perform(_curl_session_object_handle);
}

std::ostream &operator<<(std::ostream &os, const ApiCaller &rhs) {
    os << "_end_point: " << rhs._end_point
       << " _response: " << rhs._response;
   return os;
}




