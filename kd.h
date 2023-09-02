/*

    SIGNATURE:
        v0.0.5 - KD Core Library

    INFO:
        Author: Krzysztof "Sejoslaw" Dobrzyński
        Source: https://github.com/Sejoslaw/kdc

    DESCRIPTION:
        - Core library which I use for my personal projects.

    LICENSE:
        'Public License'
        See at the end of the file for more info.

*/

#ifdef KD_IMPLEMENTATION

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
    /////////////////////////////////////////////////////////////////
    //                                                             //
    //                                                             //
    //                         Libraries                           //
    //                                                             //
    //                                                             //
    /////////////////////////////////////////////////////////////////
*/

#ifndef KD_SKIP_C99
    #include <assert.h>         // Contains the assert macro, used to assist with detecting logical errors and other types of bugs in debugging versions of a program.
    #include <complex.h>        // A set of functions for manipulating complex numbers.
    #include <ctype.h>          // Defines set of functions used to classify characters by their types or to convert between upper and lower case in a way that is independent of the used character set (typically ASCII or one of its extensions, although implementations utilizing EBCDIC are also known).
    #include <errno.h>          // For testing error codes reported by library functions.
    #include <fenv.h>           // Defines a set of functions for controlling floating-point environment.
    #include <float.h>          // Defines macro constants specifying the implementation-specific properties of the floating-point library.
    #include <inttypes.h>       // Defines exact-width integer types.
    #include <iso646.h>         // Defines several macros that implement alternative ways to express several standard tokens. For programming in ISO 646 variant character sets.
    #include <limits.h>         // Defines macro constants specifying the implementation-specific properties of the integer types.
    #include <locale.h>         // Defines localization functions.
    #include <math.h>           // Defines common mathematical functions.
    #include <signal.h>         // Defines signal-handling functions.
    #include <stdarg.h>         // For accessing a varying number of arguments passed to functions.
    #include <stdbool.h>        // Defines a boolean data type.
    #include <stddef.h>         // Defines several useful types and macros.
    #include <stdint.h>         // Defines exact-width integer types.
    #include <stdio.h>          // Defines core input and output functions.
    #include <stdlib.h>         // Defines numeric conversion functions, pseudo-random numbers generation functions, memory allocation, process control functions.
    #include <string.h>         // Defines string-handling functions.
    #include <tgmath.h>         // Defines type-generic mathematical functions.
    #include <time.h>           // Defines date- and time-handling functions.
    #include <wchar.h>          // Defines wide-string-handling functions.
    #include <wctype.h>         // Defines set of functions used to classify wide characters by their types or to convert between upper and lower case.
#endif // KD_SKIP_C99

#ifndef KD_SKIP_C11
    #include <stdalign.h>       // For querying and specifying the alignment of objects.
    #include <stdatomic.h>      // For atomic operations on data shared between threads.
    #include <stdnoreturn.h>    // For specifying non-returning functions.
    #include <threads.h>        // Defines functions for managing multiple threads, mutexes and condition variables.
    #include <uchar.h>          // Types and functions for manipulating Unicode characters
#endif // KD_SKIP_C11

#ifndef KD_SKIP_POSIX
    #include <aio.h>            // Asynchronous input and output.
    #include <arpa/inet.h>      // Functions for manipulating numeric IP addresses (part of Berkeley sockets).
    #include <cpio.h>           // Magic numbers for the cpio archive format.
    #include <dirent.h>         // Allows the opening and listing of directories.
    #include <dlfcn.h>          // Dynamic linking.
    #include <fcntl.h>          // File opening, locking and other operations.
    #include <fmtmsg.h>         // Message display structures.
    #include <fnmatch.h>        // Filename matching.
    #include <ftw.h>            // File tree traversal.
    #include <glob.h>           // Pathname "globbing" (pattern-matching).
    #include <grp.h>            // User group information and control.
    #include <iconv.h>          // Codeset conversion facility.
    #include <langinfo.h>       // Language information constants – builds on C localization functions.
    #include <libgen.h>         // Pathname manipulation.
    #include <monetary.h>       // String formatting of monetary units.
    #include <mqueue.h>         // Message queue.
    #include <net/if.h>         // Listing of local network interfaces.
    #include <netdb.h>          // Translating protocol and host names into numeric addresses (part of Berkeley sockets).
    #include <netinet/in.h>     // Defines Internet protocol and address family (part of Berkeley sockets).
    #include <netinet/tcp.h>    // Additional TCP control options (part of Berkeley sockets).
    #include <nl_types.h>       // Localization message catalog functions.
    #include <poll.h>           // Asynchronous file descriptor multiplexing.
    #include <pthread.h>        // Defines an API for creating and manipulating POSIX threads.
    #include <pwd.h>            // passwd (user information) access and control.
    #include <regex.h>          // Regular expression matching.
    #include <sched.h>          // Execution scheduling.
    #include <search.h>         // Search tables.
    #include <semaphore.h>      // POSIX semaphores.
    #include <spawn.h>          // Process spawning.
    #include <strings.h>        // Case-insensitive string comparisons.
    #include <sys/ipc.h>        // Inter-process communication (IPC).
    #include <sys/mman.h>       // Memory management, including POSIX shared memory and memory mapped files.
    #include <sys/msg.h>        // POSIX message queues.
    #include <sys/resource.h>   // Resource usage, priorities, and limiting.
    #include <sys/select.h>     // Synchronous I/O multiplexing.
    #include <sys/sem.h>        // XSI (SysV style) semaphores.
    #include <sys/shm.h>        // XSI (SysV style) shared memory.
    #include <sys/socket.h>     // Main Berkeley sockets header.
    #include <sys/stat.h>       // File information (stat et al.).
    #include <sys/statvfs.h>    // File System information.
    #include <sys/time.h>       // Time and date functions and structures.
    #include <sys/times.h>      // File access and modification times.
    #include <sys/types.h>      // Various data types used elsewhere.
    #include <sys/uio.h>        // Vectored I/O operations.
    #include <sys/un.h>         // Unix domain sockets.
    #include <sys/utsname.h>    // Operating system information, including uname.
    #include <sys/wait.h>       // Status of terminated child processes.
    #include <syslog.h>         // System error logging.
    #include <tar.h>            // Magic numbers for the tar archive format.
    #include <termios.h>        // Allows terminal I/O interfaces.
    #include <unistd.h>         // Various essential POSIX functions and constants.
    #include <utime.h>          // inode access and modification times.
    #include <utmpx.h>          // User accounting database functions.
    #include <wordexp.h>        // Word-expansion like the shell would perform.
#endif // KD_SKIP_POSIX

/*
    /////////////////////////////////////////////////////////////////
    //                                                             //
    //                                                             //
    //                            Color                            //
    //                                                             //
    //                                                             //
    /////////////////////////////////////////////////////////////////
*/

#define KD_COLOR_RED       "\x1B[31m"
#define KD_COLOR_GREEN     "\x1B[32m"
#define KD_COLOR_YELLOW    "\x1B[33m"
#define KD_COLOR_BLUE      "\x1B[34m"
#define KD_COLOR_MAGENTA   "\x1B[35m"
#define KD_COLOR_CYAN      "\x1B[36m"
#define KD_COLOR_WHITE     "\x1B[37m"
#define KD_COLOR_RESET     "\x1B[0m"

#define KD_PRINT_COLOR_CHAR(text, KD_COLOR)    printf(KD_COLOR "%c" KD_COLOR_RESET, text);
#define KD_PRINT_COLOR_TEXT(text, KD_COLOR)    printf(KD_COLOR "%s" KD_COLOR_RESET, text);

/*
    /////////////////////////////////////////////////////////////////
    //                                                             //
    //                                                             //
    //                            Files                            //
    //                                                             //
    //                                                             //
    /////////////////////////////////////////////////////////////////
*/

#define KD_FILE_READ                                "r"
#define KD_FILE_READ_BINARY                         "rb"
#define KD_FILE_WRITE                               "w"
#define KD_FILE_WRITE_BINARY                        "wb"
#define KD_FILE_APPEND                              "a"
#define KD_FILE_APPEND_BINARY                       "ab"
#define KD_FILE_READ_WRITE                          "r+"
#define KD_FILE_READ_WRITE_BINARY                   "r+b"
#define KD_FILE_READ_WRITE_CREATE                   "w+"
#define KD_FILE_READ_WRITE_CREATE_BINARY            "w+b"
#define KD_FILE_READ_WRITE_CREATE_APPEND            "a+"
#define KD_FILE_READ_WRITE_CREATE_APPEND_BINARY     "a+b"

/*
    Opens file in KD_FILE_READ mode.
*/
FILE *kd_file_open_read(const char *path) {
    FILE *file = fopen(path, KD_FILE_READ);
    return file;
}

/*
    Returns file size in bytes.
*/
long kd_file_size(FILE *file) {
    long current_position = ftell(file);
    fseek(file, 0L, SEEK_END);
    long last_position = ftell(file);
    fseek(file, current_position, SEEK_SET);
    return last_position;
}

/*
    Reads file content and stores it in given buffer.
*/
void kd_file_read_text(FILE *file, char *buffer) {
    int index = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        buffer[index] = ch;
        index++;
    }
}

/*
    Reads a content of a file in a given path.
*/
char *kd_file_read_content(const char *path) {
    FILE *file = kd_file_open_read(path);
    long file_size = kd_file_size(file);

    char *buf = (char *) malloc(sizeof(char) * file_size);
    
    kd_file_read_text(file, buf);

    fclose(file);

    return buf;
}

/*
    /////////////////////////////////////////////////////////////////
    //                                                             //
    //                                                             //
    //                         Collections                         //
    //                                                             //
    //                                                             //
    /////////////////////////////////////////////////////////////////
*/

/*
    /////////////////////////////////////////////////////////////////
    //                                                             //
    //                                                             //
    //                            LINQ                             //
    //                                                             //
    //                                                             //
    /////////////////////////////////////////////////////////////////
*/

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // KD_IMPLEMENTATION

/*

    This software is dual-licensed to the public domain and under the following
    license: you are granted a perpetual, irrevocable license to copy, modify,
    publish, and distribute this file as you see fit.

*/