#define STD_INPUT_HANDLE ((unsigned long)-10)
#define STD_OUTPUT_HANDLE ((unsigned long)-11)
#define STD_ERROR_HANDLE ((unsigned long)-12)

#define WIN32(r) __declspec(dllimport) r __stdcall

WIN32(void *) GetStdHandle(unsigned long n_std_handle);
WIN32(int) WriteFile(void *file, void *buffer, int nbytes_to_write, int *nbytes_written, void *overlapped);
WIN32(int) SetConsoleOutputCP(unsigned int code_page_id);

#define WIN32_CP_UTF8 65001

#if defined(WIN32_CONSOLE_APP)
    #define nocrt_main() int mainCRTStartup()
#elif defined(WIN32_WINDOWS_APP)
    #define nocrt_main() int WinMainCRTStartup()
#else
    #error No entry function for build config
#endif

// NOTE: You won't get the console output when building /subsystem:windows :')
nocrt_main()
{
    SetConsoleOutputCP(WIN32_CP_UTF8);
    void *stdout = GetStdHandle(STD_OUTPUT_HANDLE);
    char msg[] = "Hello world! \xf0\x9f\x98\x8a\n";
    WriteFile(stdout, msg, sizeof(msg) - 1, (int[]){0}, 0);
    return 0;
}
