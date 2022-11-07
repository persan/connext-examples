/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>

/*****************************************************************************/
/* Unify some common functions and types between Unix and Windows            */
/*****************************************************************************/
#ifdef RTI_WIN32
#include <string>
#define RTI_SNPRINTF(src, srcSize, format, ...) \
	_snprintf_s(src, srcSize, _TRUNCATE, format, __VA_ARGS__)
#define RTI_STRCASECMP      _stricmp
#define RTI_STRNCASECMP     _strnicmp
#define RTI_STRTOULL        _strtoui64
#define RTI_STRTOUL         strtoul
#define RTI_STRNCMP         strncmp
#else
#include <strings.h>
#define RTI_SNPRINTF        snprintf
#define RTI_STRCASECMP      strcasecmp
#define RTI_STRNCASECMP     strncasecmp
#define RTI_STRTOULL        strtoull
#define RTI_STRTOUL         strtoul
#define RTI_STRNCMP         strncmp
#endif

extern "C" int subscriberMain(int sampleCount);
extern "C" int publisherMain(int sampleCount);

using namespace std;

int main(int argc, char *argv[]) {

    int sampleCount = 0; /* infinite loop */
    bool isPub = false;

    if (argc >= 2) {
        if (RTI_STRCASECMP(argv[1], "pub") == 0) {
            isPub = true;
        }
        else if (RTI_STRCASECMP(argv[1], "sub") == 0) {
            isPub = false;
        }
        else {
            fprintf(stderr, "Parameter 1 must be 'pub' or 'sub'\n");
            return(-1);
        }
    }

    if (argc >= 3) {
        sampleCount = atoi(argv[2]);
    }

	/* Uncomment this to turn on additional logging
	NDDSConfigLogger::get_instance()->
	set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API,
	NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
	*/

    if (isPub == true) {
        return publisherMain(sampleCount);
    }
    return subscriberMain(sampleCount);
}
