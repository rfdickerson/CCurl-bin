/**
 * Copyright IBM Corporation 2016
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#ifndef CurlHelpers_h
#define CurlHelpers_h

#import "include/curl/curl.h"

#define CURL_TRUE  1
#define CURL_FALSE 0

extern inline CURLcode curlHelperSetOptBool(CURL *curl, CURLoption option, int yesNo) {
    return curl_easy_setopt(curl, option, yesNo == CURL_TRUE ? 1L : 0L);
}

extern inline CURLcode curlHelperSetOptHeaders(CURL *curl, struct curl_slist *headers) {
    return curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
}

extern inline CURLcode curlHelperSetOptInt(CURL *curl, CURLoption option, long data) {
    return curl_easy_setopt(curl, option, data);
}

extern inline CURLcode curlHelperSetOptString(CURL *curl, CURLoption option, char *data) {
    return curl_easy_setopt(curl, option, data);
}

extern inline CURLcode curlHelperSetOptReadFunc(CURL *curl, void *userData, size_t (*read_cb) (char *buffer, size_t size, size_t nitems, void *userdata)) {
    
    CURLcode rc = curl_easy_setopt(curl, CURLOPT_READDATA, userData);
    if  (rc == CURLE_OK) {
        rc = curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_cb);
    }
    return rc;
    
}

extern inline CURLcode curlHelperSetOptWriteFunc(CURL *curl, void *userData, size_t (*write_cb) (char *ptr, size_t size, size_t nmemb, void *userdata)) {
    
    CURLcode rc = curl_easy_setopt(curl, CURLOPT_HEADER, 1);
    if  (rc == CURLE_OK)  {
        rc = curl_easy_setopt(curl, CURLOPT_WRITEDATA, userData);
        if  (rc == CURLE_OK) {
            rc = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
        }
    }
    return rc;
}

extern inline CURLcode curlHelperGetInfoCString(CURL *curl, CURLINFO info, char **data) {
    return curl_easy_getinfo(curl, info, data);
}


extern inline CURLcode curlHelperGetInfoLong(CURL *curl, CURLINFO info, long *data) {
    return curl_easy_getinfo(curl, info, data);
}


#endif /* CurlHelpers_h */
