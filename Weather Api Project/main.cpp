#include <iostream>
#include <string>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

// Callback function for libcurl
size_t writeCallback(void* contents, size_t size, size_t nmemb, string* output){
    size_t totalSize = size* nmemb;
    output->append((char*)contents,totalSize);
    return totalSize;
}


string getWeatherDescription(int code) {
    switch (code) {
        case 0:  return "Clear Sky";
        case 1:  return "Mainly Clear";
        case 2:  return "Partly Cloudy";
        case 3:  return "Overcast";

        case 45: return "Fog";
        case 48: return "Rime Fog";

        case 51: return "Light Drizzle";
        case 53: return "Moderate Drizzle";
        case 55: return "Dense Drizzle";
        case 56: return "Freezing Drizzle (Light)";
        case 57: return "Freezing Drizzle (Dense)";

        case 61: return "Slight Rain";
        case 63: return "Moderate Rain";
        case 65: return "Heavy Rain";
        case 66: return "Freezing Rain (Light)";
        case 67: return "Freezing Rain (Heavy)";

        case 71: return "Slight Snow";
        case 73: return "Moderate Snow";
        case 75: return "Heavy Snow";
        case 77: return "Snow Grains";

        case 80: return "Slight Rain Showers";
        case 81: return "Moderate Rain Showers";
        case 82: return "Violent Rain Showers";

        case 85: return "Slight Snow Showers";
        case 86: return "Heavy Snow Showers";

        case 95: return "Thunderstorm";
        case 96: return "Thunderstorm with Slight Hail";
        case 99: return "Thunderstorm with Heavy Hail";

        default: return "Unknown Weather Condition";
    }
}

int main()
{
    double latitude, longitude;

    cout << "Enter latitude: ";
    cin >> latitude;
    cout << "Enter longitude: ";
    cin >> longitude;


    string url = "https://api.open-meteo.com/v1/forecast?latitude=" + to_string(latitude) + "&longitude=" + to_string(longitude) + "&current_weather=true";

    CURL* curl = curl_easy_init();
    string response;

    if(!curl){
        cout << "Curl initialization failed\n";
        return 1;
    }


    curl_easy_setopt(curl,CURLOPT_URL,url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,&response);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if(res != CURLE_OK){
        cout << "Failed to fetch weather data\n";
        return 1;
    }


    //Parse JSON
    auto data = json::parse(response);
    auto weather = data["current_weather"];

    cout << "\n Current Weather Report\n";
    cout << "Temperature : " << weather["temperature"] << " C\n";
    cout << "Wind Speed  : " << weather["windspeed"] << " km/h\n";
    int code = weather["weathercode"];


    cout << "Condition : " << getWeatherDescription(code) << endl;
    return 0;
}