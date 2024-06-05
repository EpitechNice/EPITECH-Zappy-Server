/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** signal
*/

#include "zappy_server.h"

static size_t get_nb_subs(const char *str, const char *sub)
{
    bool on_word = false;
    bool chr = false;
    size_t size = 0;

    for (size_t i = 0; str[i]; ++i) {
        chr = strchr(sub, str[i]) == NULL;
        if (!on_word && chr) {
            ++size;
            on_word = true;
        }
        if (on_word && !chr)
            on_word = false;
    }
    return size;
}

static char *m_strndup(const char *str, size_t size)
{
    size_t len = strlen(str);
    char *out;

    len = ((len < size) ? len : size);
    out = (char *)malloc(len + 1);
    strncpy(out, str, len);
    return out;
}

static int find_pos_not_of(const char *str, const char *sub)
{
    for (int i = 0; str[i]; ++i)
        if (!strchr(sub, str[i]))
            return i;
    return -1;
}

static int find_pos_of(const char *str, const char *sub)
{
    for (int i = 0; str[i]; ++i)
        if (strchr(sub, str[i]))
            return i;
    return -1;
}

char **stowa(const char *str, const char *sub)
{
    size_t nb_sub = get_nb_subs(str, sub);
    char **map;
    int pos = 0;
    int size = 0;

    if (!str || !sub || !nb_sub)
        return NULL;
    map = (char **)malloc(sizeof(char *) * (nb_sub + 1));
    map[nb_sub] = NULL;
    for (size_t i = 0; i < nb_sub; i++) {
        pos += find_pos_not_of(&str[pos], sub);
        size = find_pos_of(&str[pos], sub);
        map[i] = m_strndup(&str[pos], size);
        pos += size;
    }
    return map;
}
