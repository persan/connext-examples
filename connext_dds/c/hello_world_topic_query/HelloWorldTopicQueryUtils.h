
/*****************************************************************************/
/* Unify some common functions and types between Unix and Windows            */
/*****************************************************************************/
#ifdef RTI_WIN32

#define RTI_SNPRINTF(src, srcSize, format, ...) \
	_snprintf_s(src, srcSize, _TRUNCATE, format, __VA_ARGS__)
#define RTI_STRCASECMP      _stricmp
#define RTI_STRNCASECMP     _strnicmp
#define RTI_STRTOULL        _strtoui64
#define RTI_STRTOUL         strtoul
#define RTI_STRNCMP         strncmp
				
#else

#define RTI_SNPRINTF        snprintf
#define RTI_STRCASECMP      strcasecmp
#define RTI_STRNCASECMP     strncasecmp
#define RTI_STRTOULL        strtoull
#define RTI_STRTOUL         strtoul
#define RTI_STRNCMP         strncmp

#endif

#define DEFAULT_DOMAIN_ID           0
#define DOMAIN_ID_MAX               232

void HelloWorldTopicQuery_print_usage();
/*****************************************************************************/
/* HelloWorldTopicQuery_ensure_one_more_argument                             */
/*                                                                           */
/* A simple function used to check if there are enough command line args     */
/*****************************************************************************/
int HelloWorldTopicQuery_ensure_one_more_argument(
    int argc, int i, const char* argName)
{
    if (i+1 >= argc) {
        HelloWorldTopicQuery_print_usage();
        printf("! Error: missing value for %s argument\n", argName);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}


