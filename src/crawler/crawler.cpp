#include <cstring>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <curl/curl.h>
#include <openssl/sha.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include "unistd.h"
extern "C" {
#include "cleanurl.h"
}
#include "crawler.h"

class Crawler{
    private:
        size_t static write_callback_func(void *buffer, size_t size, size_t nmemb, void *userdata); 
        std::string slurp(std::ifstream &in);
        std::set<std::string> get_links(std::string web_page);
        
    public:
        enum ProcessType { CRAWL, URL_EXTRACT };
        std::string get_page(std::string absolute_normalized_url);
        std::string get_hash(std::string value_to_hash);
        void process(ProcessType p_type);

};

size_t Crawler::write_callback_func(void *buffer, size_t size, size_t nmemb, void *userdata){
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

std::string Crawler::slurp(std::ifstream &in) {
    std::stringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

std::set<std::string> Crawler::get_links(std::string web_page){
	std::set<std::string> links;
	std::string href_begin = "<a href=\""; //9 chars
    std::string href_end = "\"";
	int pos = web_page.find(href_begin, 0);
	while(pos != std::string::npos){
		int end = web_page.find(href_end, pos+9);
		std::string link_url= web_page.substr( pos+9, (end - (pos+9)));
		//std::cout << "link_url=" << link_url << std::endl;
		bool skip_flag = true;
		std::vector<std::string> starts { "/wiki/" , "//en.wikipedia.org"}; 
		std::vector<std::string> start_substitutes { "http://en.wikipedia.org/wiki/" , "http://en.wikipedia.org"}; 
		std::vector<std::string>::iterator start_substitutes_it = start_substitutes.begin();
		for (std::vector<std::string>::iterator starts_it = starts.begin(); starts_it != starts.end(); ++starts_it){
			if (!(link_url.compare(0, (*starts_it).length(), (*starts_it))==0) ){
				continue;
			}else {
				int index = starts_it - starts.begin(); 
				std::string orig = starts.at(index);
				std::string sub = start_substitutes.at(index);
				link_url = link_url.replace(0, orig.size(), sub);
				//std::cout << "replacedurl:" + link_url << std::endl;
				skip_flag = false;
				break;
			}
		}//end-for 

		if (skip_flag){
			pos = web_page.find(href_begin,pos+1);
			//std::cout << "skipping:" + link_url << std::endl;
			continue; 
		}       
		links.insert(link_url);
		pos = web_page.find(href_begin,pos+1);
    }//end-while
    return links;

}

void Crawler::process(ProcessType p_type){
	std::fstream urls;
	std::fstream crawl_status;
	std::fstream url_extract_status;
    urls.open(URLS_FILE_PATH, std::ios_base::in | std::ios_base::out);
    std::string line;
    int current_line_number = 0;
    crawl_status.open(CRAWL_STATUS_FILE_PATH, std::ios_base::in | std::ios_base::out);
    std::string crawl_number;
    getline(crawl_status, crawl_number);
    //std::cout << "Last crawled line number:" << crawl_number << std::endl;
    int last_crawled_line_number = atoi(crawl_number.c_str());
    crawl_status.clear();
    int last_url_extracted_line_number = 0;
    //std::cout << "Last crawled line number int:" << last_crawled_line_number << std::endl;
    if (p_type == Crawler::URL_EXTRACT){
        url_extract_status.open(URL_EXTRACTION_STATUS_FILE_PATH, std::ios_base::in | std::ios_base::out);
        std::string url_extract_number;
        getline(url_extract_status, url_extract_number);    
        last_url_extracted_line_number = atoi(url_extract_number.c_str());
        url_extract_status.clear();
        crawl_status.close();
    }
    std::set<std::string> all_links;
    while(getline(urls,line)){
        current_line_number++;
        int last_line_number = (p_type == Crawler::CRAWL)? last_crawled_line_number : last_url_extracted_line_number;
        if (current_line_number < last_line_number) continue;
        if (current_line_number > MAX_PAGES) break;
        
        char buf[2048];
        if (p_type == Crawler::CRAWL){
	        sleep(SLEEP_TIME_IN_SECONDS);
            //std::cout << "URL:" << line << std::endl;
            std::string url_to_be_fetched = line;
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
            std::cout << "Current time in seconds is:" << current_time << std::endl;
            int time_difference = current_time - modified_time;
            std::cout << "Time difference:" << time_difference << std::endl; 
            if (current_time - modified_time > REFRESH_FREQUENCY_IN_SECONDS){
                std::string page_content = get_page(absolute_normalized_url);
                //std::cout << "OUTPUT:START:" << std::endl;
                std::cout << page_content << std::endl;
                //std::cout << "OUTPUT:END:" << std::endl;
                std::ofstream url_file(url_file_name.c_str(), std::ios_base::out);
                url_file << page_content;
                url_file.close();
            }//end-if
            crawl_status.seekg(0);
            crawl_status << current_line_number;
            crawl_status.flush();
		}else{
			char buf[2048];
			int return_cu = clean_url(buf, line.c_str(), line.length());
			std::string absolute_normalized_url(buf);
			std::string hash_value = get_hash(absolute_normalized_url);
			std::string url_file_name = std::string(WEB_ROOT) + "/" + hash_value;
			//std::cout << "hash_value of web_page:" << absolute_normalized_url << " is: " << url_file_name << std::endl;
			std::ifstream url_file(url_file_name.c_str());
			std::string web_page = slurp(url_file);
			//std::cout << "length of web_page:" << absolute_normalized_url << " is: " << web_page.size() << std::endl;
			std::set<std::string> links = get_links(web_page);
			all_links.insert(links.begin(), links.end());
            url_extract_status.seekg(0);
            url_extract_status << current_line_number;
            url_extract_status.flush();			
		}//end-if-processtype

    }//end-while
    urls.clear();
    if (p_type == Crawler::URL_EXTRACT){
        for (std::set<std::string>::iterator it = all_links.begin(); it != all_links.end(); ++it){
                std::cout << "extracted url:" << *it << std::endl;
                char buf[2048];
			    int return_cu = clean_url(buf, it->c_str(), it->length());
			    std::string absolute_normalized_url(buf);
		    	std::string hash_value = get_hash(absolute_normalized_url);
	    		std::string url_file_name = std::string(WEB_ROOT) + "/" + hash_value;
	    		//std::cout << "url_file_name:" << url_file_name << std::endl;
	    		struct stat st;
	    		int rc = stat (url_file_name.c_str(), &st);
    			if (rc != 0) {
			        //std::cout << "file doesn't exist:" << url_file_name << ":RC=" << rc << std::endl;
				    urls << *it << std::endl;
			    	urls.flush();
		    	}
        }//end-for
    }
    
    if (p_type == Crawler::CRAWL){
        crawl_status.close();
    }else{
		url_extract_status.close();
	}
	urls.close();

}

int main(){  
    Crawler crawler;
    int crawl_depth = CRAWL_DEPTH;
    while (crawl_depth-- > 0){
	    crawler.process(Crawler::CRAWL);
        crawler.process(Crawler::URL_EXTRACT);
	}
}
