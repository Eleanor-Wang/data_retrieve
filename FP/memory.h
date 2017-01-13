//
//  memory.hpp
//  FP
//
//  Created by 汪念怡 on 4/23/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#ifndef memory_hpp
#define memory_hpp


#include <sstream>

struct MemoryStruct {
    char *memory;
    size_t size;  //dynamic allocation
};

void *myrealloc(void *ptr, size_t size);

int write_data2(void *ptr, size_t size, size_t nmemb, void *data);

#endif /* memory_hpp */
