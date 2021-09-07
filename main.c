#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>

static char const* gRowPattern = "|%-20.20s|%-25.25s|%-30.30s|%-40.40s|\n";

void generateRow(char const* comment, char const* fmt, char const* values, ...)
{
    char output[50];
    va_list args;
    va_start(args, values);
    char armoredFmt[50];
    sprintf(armoredFmt, "`%s`", fmt);
    vsprintf(output, armoredFmt, args);
    va_end(args);
    printf(gRowPattern,
            armoredFmt,
            values,
            output,
            comment);
}

void generateHeader() {
    printf(gRowPattern,
            "Format",
            "Values",
            "Display",
            "Comments");
    char const* line = "-------------------------------------------------------";
    printf(gRowPattern,
            line,
            line,
            line,
            line);
}

void generateTitle(char const* title) {
    printf("\n### %s\n\n", title);
}

int main(int, char *[])
{
    generateTitle("Strings/Characters");
    generateHeader();
    generateRow("", "%c%c%c%c%c","'H', 'e', 'l', 'l', 'o'", 'H', 'e', 'l', 'l', 'o');
    generateRow("", "%s %s","\"Hello\", \"World\"", "Hello", "World");
    generateRow("Right justification by default", "%10s %s","\"Hello\", \"World\"", "Hello", "World");
    generateRow("Left justification on-demand", "%-10s %s","\"Hello\", \"World\"", "Hello", "World");
    generateRow("Minimal width", "%10s","\"LongLongWord\"", "LongLongWord");
    generateRow("Limit the output", "%10.5s","\"LongLongWord\"", "LongLongWord");
    generateRow("Limit the output left justified", "%-10.5s","\"LongLongWord\"", "LongLongWord");

    generateTitle("Integers");
    generateHeader();
    generateRow("%d and %i are aliases", "%d","0xDEADBEEF", 0xDEADBEEF);
    generateRow("Prefix with '+' for positive numbers", "%+d","42", 42);
    generateRow("Unsigned representation", "%u","0xDEADBEEF", 0xDEADBEEF);
    generateRow("Octal representation", "%o","0xDEADBEEF", 0xDEADBEEF);
    generateRow("Hexadecimal representation", "%x","0xDEADBEEF", 0xDEADBEEF);
    generateRow("Hexadecimal upper case", "%X","0xDEADBEEF", 0xDEADBEEF);

    generateTitle("Floats");
    generateHeader();
    double faraday = 96485.3321233;
    generateRow("Precision is the number of digits after point", "%.3f","double faraday", faraday);
    generateRow("Precision is 6 by default", "%f","double faraday", faraday);
    generateRow("Precision is the total number of digits", "%.9g","double faraday", faraday);
    generateRow("Precision is still 6 by default", "%g","double faraday", faraday);
    generateRow("", "%.3g","double faraday", faraday);
    generateRow("More decimals", "%+.9f","double faraday", faraday);
    generateRow("Exponent notation", "%e","double faraday", faraday);
    generateRow("Exponent upper case", "%E","double faraday", faraday);
    generateRow("Padding with 0", "%015.2f","double faraday", faraday);
    generateRow("Padding with spaces (default)", "% 15.2f","double faraday", faraday);
    generateRow("Some flags combinations", "%0+15.2f","double faraday", faraday);
    generateRow("Hexadecimal notation", "%a","double faraday", faraday);

    generateTitle("Pointers");
    generateHeader();
    generateRow("", "%p","&someFunction", &generateHeader);
    generateRow("", "%p","&someVariable", &gRowPattern);

    generateTitle("Glibc extensions");
    generateHeader();
    generateRow("Display errno", "%m", "nothing");
    int fd = open("/toto", O_APPEND);
    if (fd == -1) {}
    generateRow("Display errno after an error", "%m", "nothing");
    return 0;
}
