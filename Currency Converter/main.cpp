#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

size_t writeCallback(void* contents, size_t size, size_t nmemb, string* output){
    output->append((char*)contents, size *nmemb);
    return size* nmemb;
}


int main()
{
    string fromCurrency, toCurrency;
    double amount;

    cout << "Enter base currency (e.g. EUR): ";
    cin >> fromCurrency;

    cout << "Enter target currency (e.g. GBP): ";
    cin >> toCurrency;

    cout << "Enter amount: ";
    cin >> amount;

    string apiKey = "51566ba15cd0ce34ccf39099"; //api key

    string url = "https://v6.exchangerate-api.com/v6/" + apiKey +"/pair/" + fromCurrency + "/"
    + toCurrency;

    CURL* curl = curl_easy_init();
    string response;

    if(!curl){
        cout << "Curl initialization failed\n";
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);


    if(res != CURLE_OK){
        cout << "API request failed\n";
        return 1;
    }

    //Parse JSON
    auto data = json::parse(response);

    if(data["result"]!= "success"){
        cout << "API error or invalid currency codes\n";
        return 1;
    }

    double rate = data["conversion_rate"];
    double convertedAmount = amount * rate;

    cout << "\nConversion Result\n";
    cout << amount << " " << fromCurrency
         << " = " << convertedAmount
         << " " << toCurrency << endl;
    return 0;
}