#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

// Curl callback
size_t writeCallback(void* contents, size_t size, size_t nmemb, string* output){
    output->append((char*)contents, size*nmemb);
    return size * nmemb;
}


int main()
{
    string place;
    cout << "Enter place name: ";
    getline(cin,place);

    string url = "https://geocoding-api.open-meteo.com/v1/search?name=" + place + "&count=1&country=IN";

    CURL* curl = curl_easy_init();
    string response;

    if(!curl){
        cout << "Curl init failed\n";
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,&response);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if(res != CURLE_OK){
        cout << "API request failed\n";
        return 1;
    }

    auto data = json::parse(response);

    if(!data.contains("results") || data["results"].is_null()){
        cout << "Place not found!\n";
        return 0;
    }
    auto location = data["results"][0];

    double lat = location["latitude"];
    double lon = location["longitude"];
    string name = location["name"];
    string state = location.value("admin1","Unknown");
    string country = location["country"];

    cout << "\n Place Found!\n";
    cout << "Name           : " << name << endl;
    cout << "State          : " << state << endl;
    cout << "Country        : " << country << endl;
    cout << "Latitude       : " << lat << endl;
    cout << "Longitude      : " << lon << endl;

    return 0;
}