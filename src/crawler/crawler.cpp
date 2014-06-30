#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
//#include <sys/types.h>
#include <sys/stat.h> 
#include <curl/curl.h>
#include <openssl/sha.h>
#include "unistd.h"
extern "C" {
#include "cleanurl.h"
}
#include "crawler.h"

class Crawler{
    private:
        //size_t static write_callback_func(void *buffer, size_t size, size_t nmemb, void *userdata); //n00b meets C++ :-)

    public:
        std::string get_page(std::string absolute_normalized_url);
        std::string get_hash(std::string value_to_hash);
        void crawl();
        void extract_urls();


};

size_t static write_callback_func(void *buffer, size_t size, size_t nmemb, void *userdata){
    ((std::string*)userdata)->append((char*)buffer, size * nmemb);
    return size * nmemb;
}

std::string Crawler::get_hash(std::string value_to_hash){
    char str[2048];
    strncpy(str, value_to_hash.c_str(), sizeof(str));
    unsigned char hash[SHA_DIGEST_LENGTH]; 
    char hash_value[SHA_DIGEST_LENGTH*2];
    memset(hash, 0x0, SHA_DIGEST_LENGTH);
    memset(hash_value, 0x0, SHA_DIGEST_LENGTH*2);
    SHA1((unsigned char*) &str, strlen(str), (unsigned char*) &hash);
    int i = 0;
    for (i=0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf((char*)&(hash_value[i*2]), "%02x", hash[i]);
    }
    return hash_value;
}

std::string Crawler::get_page(std::string absolute_normalized_url){
    CURL *curl;
    CURLcode res;
    std::string page_content; 

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, absolute_normalized_url.c_str());
        //follow one level of redirection 
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback_func);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &page_content);
        res = curl_easy_perform(curl);
    
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
 
        curl_easy_cleanup(curl);
        return page_content;
    }
}

void Crawler::crawl(){
    std::fstream urls(URLS_FILE_PATH, std::ios_base::in | std::ios_base::out);
    std::string line;
    int current_line_number = 0;
    std::fstream crawl_status(CRAWL_STATUS_FILE_PATH, std::ios_base::in | std::ios_base::out);
    std::string crawl_number;
    getline(crawl_status, crawl_number);
    //std::cout << "Last crawled line number:" << crawl_number << std::endl;
    int last_crawled_line_number = atoi(crawl_number.c_str());
    crawl_status.clear();
 
    while(getline(urls,line)){
        current_line_number++;
        if (current_line_number < last_crawled_line_number) continue;
        if (current_line_number > MAX_PAGES) break;
        sleep(SLEEP_TIME_IN_SECONDS);
        //std::cout << "URL:" << line << std::endl;
        std::string url_to_be_fetched = line;
        char buf[2048];
        int return_cu = clean_url(buf, url_to_be_fetched.c_str(), url_to_be_fetched.length());
        std::string absolute_normalized_url(buf);
        //std::cout << "RETURNED:" << return_cu << "NORMALIZED:" << absolute_normalized_url << ":" << std::endl;
        std::string hash_value = get_hash(absolute_normalized_url);
        //std::cout << "SHA1:" << hash_value << std::endl;
        std::string url_file_name = std::string(WEB_ROOT) + "/" + hash_value;
        struct stat st;
        int modified_time = 0;
        int rc = stat (url_file_name.c_str(), &st);
        if (rc != 0) {
            //std::cout << "Error while checking statistics of: " << url_file_name <<  ":return code is:" << rc << std::endl;
        }else{
            modified_time = st.st_mtime;
        }
        //std::cout << "Time of modification in seconds is:" << modified_time << std::endl;
        int current_time = time(0);
        //std::cout << "Current time in seconds is:" << current_time << std::endl;
        int time_difference = current_time - modified_time;
        //std::cout << "Time difference:" << time_difference << std::endl; 
        if (current_time - modified_time > REFRESH_FREQUENCY_IN_SECONDS){
            std::string page_content = get_page(absolute_normalized_url);
            //std::cout << "OUTPUT:START:" << std::endl;
            //std::cout << page_content << std::endl;
            //std::cout << "OUTPUT:END:" << std::endl;
            std::ofstream url_file(url_file_name.c_str(), std::ios_base::out);
            url_file << page_content;
            url_file.close();
        }//end-if
        crawl_status.seekg(0);
        crawl_status << current_line_number;
        crawl_status.flush();
    }//end-while

    crawl_status.close();

}

/*
    TO BE DONE
    This should read the file containing urls. For each line, go and get the corresponding page from web root, and extract links from it.
    Then append those links to the file containing urls.
*/
void Crawler::extract_urls(){

}

int main(){
    Crawler crawler;
    //Use either crawl() or extract_urls(): one at a time. 
    crawler.crawl();
    //crawler.extract_urls();
}









