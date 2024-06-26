/*
 *  ofxMemoryUsage.h
 *  FlyCapture
 *
 *  Created by Vincent R. on 07.11.11.
 *  Copyright 2011 www.say-nono.com. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "ofConstants.h"

#ifdef TARGET_WIN32
	#include "windows.h"
	#include "psapi.h"
#endif

#ifdef TARGET_LINUX
	#include <sys/types.h>
	//#include <sys/sysctl.h>
	#include <sys/sysinfo.h>
	#include "stdlib.h"
	#include "stdio.h"
	#include "string.h"
	#include "sys/times.h"
	//#include "sys/vtimes.h"
#endif

#if defined(TARGET_OSX) || defined(TARGET_OF_IPHONE)

	#include <sys/types.h>
	#include <sys/sysctl.h>

	#include <mach/vm_statistics.h>
	#include <mach/mach_types.h> 
	#include <mach/mach_init.h>
	#include <mach/mach_host.h>
	#include <mach/mach.h>

#endif


class ofxMemoryUsage{
	
public:	
	void setup();
	void update();
	void draw();
	
	int getTotalMemory();
	int getUsedMemory();
	int getProcessMemory();
	
private:
	int updateSecs;
	int memory_total;
	int memory_used_total;
	int memory_used_process;		
	
#ifdef TARGET_LINUX
    int parseLine(char* line) {
        int i = strlen(line);
        while (*line < '0' || *line > '9') line++;
        line[i-3] = '\0';
        i = atoi(line);
        return i;
    }
#endif

};


