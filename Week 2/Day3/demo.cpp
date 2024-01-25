#include <curl/curl.h>
#include <iostream>



size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}



int main()
{
    char end_point []= "https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD,JPY,EUR\0";
    /*
    Initialize the curl session object
    
    */
    auto curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, end_point);

        std::string response_string;
        std::string header_string;

        /*
            we need a function that can read response receive and write it (byte by byte) into response_string variable.
            this function(writeFunction is defined above)

        
        */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        /*
            specify where data has to be written(address of response string)
        
        
        */
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        /*
            specify where header data comes from(location of header_string)
        
        
        */
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

        char *url;
        /*
            store response code after execution of api call in this variable
        */
        long response_code;
        /*
            time taken for api call to complete
        */
        double elapsed;

        /*
        
            after all setting above ,finally execute curl
            with on all options provided
        
        */


        /*
            gather info on response code,store it in response_code variable location
            similarly we store elapsed time in its respective variable location
        
        */

        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
        curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &elapsed);
        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
        /*
        clean up session.reset everything before next request is to be made
        
        */
  
        curl_easy_cleanup(curl);
        // session can be terminated by setting curl session object to NULL
        curl = nullptr;
        std::cout<<response_string<<"\n";
        std::cout<<response_code<<"\n";
    }
    
}