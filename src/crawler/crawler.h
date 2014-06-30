/*
    MAX_PAGES is the maximum number of pages which will be crawled before the crawler exits. You don't want to continue endlessly.
*/
#ifndef MAX_PAGES
#define MAX_PAGES 100
#endif
/*
    SLEEP_TIME_IN_SECONDS is the time for which the crawler will stop in between crawling pages.
*/
#ifndef SLEEP_TIME_IN_SECONDS
#define SLEEP_TIME_IN_SECONDS 5
#endif
/*
    A web page will be fetched only if the difference between its last fetched time and the current time exceeds the specified refresh frequency
    1 minute: 60 seconds
    1 hour: 3600 seconds
    1 day: 86400 seconds
    1 week: 604800 seconds (approximate)
    1 month: 2629743 seconds (approximate)
*/
#ifndef REFRESH_FREQUENCY_IN_SECONDS
#define REFRESH_FREQUENCY_IN_SECONDS 600
#endif
/*
    Make sure you have read and write permissions (6) to the actual path represented by URLS_FILE_PATH
*/
#ifndef URLS_FILE_PATH
#define URLS_FILE_PATH "/home/sp/projects/cppprojects/crawler/urls.txt"
#endif
/*
    The path specified here should not be the same as or within the path specified by WEB_ROOT
    Make sure you have read and write permissions (6) to the actual path represented by CRAWL_STATUS_FILE_PATH
    The file represented by CRAWL_STATUS_FILE_PATH will have the last line number of URLS_FILE_PATH which was crawled
    Before running the program, create the file represented by CRAWL_STATUS_FILE_PATH and enter '0' as the first line (without the single quotes) 
    A sample crawl_status.txt is provided along with this program.
    The value will be overwritten by the program, everytime it runs.
*/
#ifndef CRAWL_STATUS_FILE_PATH
#define CRAWL_STATUS_FILE_PATH "/home/sp/projects/cppprojects/crawler/crawl_status.txt"
#endif
/*
    The path specified here should not be the same as or within the path specified by WEB_ROOT
    Make sure you have read and write permissions (6) to the actual path represented by URL_EXTRACTION_STATUS_FILE_PATH
    The file represented by URL_EXTRACTION_STATUS_FILE_PATH will have the line number of the last url in URLS_FILE_PATH from which urls have been extracted
    Before running the program, create the file represented by URL_EXTRACTION_STATUS_FILE_PATH and enter '0' as the first line (without the single quotes) 
    A sample url_extraction_status.txt is provided along with this program.
    The value will be overwritten by the program, everytime it runs.
*/
#ifndef URL_EXTRACTION_STATUS_FILE_PATH
#define URL_EXTRACTION_STATUS_FILE_PATH "/home/sp/projects/cppprojects/crawler/url_extraction_status.txt"
#endif
/*
    Make sure you have permission to write files (4) within the actual directory represented by WEB_ROOT
*/
#ifndef WEB_ROOT
#define WEB_ROOT "/home/sp/projects/cppprojects/crawler/webroot"
#endif



