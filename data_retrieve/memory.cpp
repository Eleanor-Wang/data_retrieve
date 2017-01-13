//
//  memory.cpp
//  FP
//
//  Created by 汪念怡 on 4/23/16.
//  Copyright © 2016 汪念怡. All rights reserved.
//

#include "memory.h"

void *myrealloc(void *ptr, size_t size)
{
    /* There might be a realloc() out there that doesn't like reallocing
     NULL pointers, so we take care of it here */
    if(ptr)
        return realloc(ptr, size);
    else
        return malloc(size);
}

int write_data2(void *ptr, size_t size, size_t nmemb, void *data)
{
    size_t realsize = size * nmemb;  //the total size
    struct MemoryStruct *mem = (struct MemoryStruct *)data;
    
    mem->memory = (char *)myrealloc(mem->memory, mem->size + realsize + 1); //end by num
    if (mem->memory) {
        memcpy(&(mem->memory[mem->size]), ptr, realsize); //for the space
        mem->size += realsize;
        mem->memory[mem->size] = 0;
    }
    return int(realsize);
}

get data from ecel