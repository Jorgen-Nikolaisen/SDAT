#include "TemperatureSensor.h"
#include <iostream>
#include <random>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


TemperatureSensor::TemperatureSensor() {}

    double TemperatureSensor::getTemperature(double latitude, double longitude) {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;
        std::string apiKey = "API_KEY"; // Replace with your API key
        std::string url = "https://api.weatherapi.com/v1/current.json?key=" + apiKey +
                          "&q=" + std::to_string(latitude) + "," + std::to_string(longitude);

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                return 0;
            }

            auto json = nlohmann::json::parse(readBuffer);
            return json["current"]["temp_c"].get<double>(); // Access the temperature field based on your API's response structure
        }
        return 0;
    }


