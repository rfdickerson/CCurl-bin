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

import Glibc

system("mkdir -p .build/debug")

// search for existing library
var fp: UnsafeMutablePointer<FILE>
var path: UnsafeMutablePointer<CChar> = UnsafeMutablePointer<CChar>.alloc(1024);

fp = popen("find /usr/lib -name \"libcurl*\"", "r")
var count=0

while (fgets(path, 1024, fp) != nil) {
        count += 1
}

if count > 2 {
        // found system library skip copying
} else {

#if os(Linux)
    system("cp `find Packages/ -type d -name CCurl*`/lib/linux-64/* .build/debug")
    
#else
    system("cp `find Packages/ -type d -name CCurl*`/lib/darwin/* .build/debug")
    
#endif
}
