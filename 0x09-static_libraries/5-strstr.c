char *_strstr(char *haystack, char *needle)
{
    int i;

    if (!*needle)
        return (haystack);
    while (*haystack)
    {
        i = 0;
        while (needle[i] && haystack[i] == needle[i])
            i++;
        if (!needle[i])
            return (haystack);
        haystack++;
    }
    return (0);
}
