#include "core/clist.h"

void va_list_log_test(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    clogfv(format, args);
    va_end(args);
}

int main(void)
{
    clog("basic log test: hello world!");
    clogf("formatted log test: %s %s", "hello", "world!");
    va_list_log_test("va_list log test: %s %s", "hello", "world!");

    const char* hello_world_data = "hello world!";

    cstring(16) hello_str;
    cstring_init(&hello_str);
    cstring_set(&hello_str, hello_world_data);
    clogf("cstring test: %s", (char*)hello_str.data);

    cassertf(0, "cassertf test: %s", hello_world_data);

    return 0;
}
