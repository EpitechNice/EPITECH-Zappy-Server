/*
** EPITECH PROJECT, 2024
** server
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include "includes.h"

/**
 * @brief Check is a char is a digit
 *
 * @param c the character to check
 *
 * @return True if the character is a digit, false otherwise
*/
bool is_digit(char c);

/**
 * @brief Check is a string is made of digit
 *
 * @param str the string to check
 *
 * @return True if the string is made of digits, false otherwise
*/
bool is_digits(char *str);

/**
 * @brief Read a file
 *
 * @param filepath the path to the file
*/
void read_file(char *filepath);

/**
 * @brief Get the content of a file
 *
 * @param filepath the path to the file
 *
 * @return the content of the file as a string
*/
char *get_file_content(char *filepath);

/**
 * @brief Signal handler
 *
 * @param int the signal status
*/
void sig_handler(int);

/**
 * @brief Free a tab
 *
 * @param tab the tab to free
*/
void free_tab(char **);

/**
 * @brief str to word array
 *
 * @param str the string
 * @param sub the substring
 *
 * @return the word array
*/
char **stowa(const char *, const char *);

/**
 * @brief Get the length of a tab
 *
 * @param tab the tab
 *
 * @return the length of the tab
*/
int tab_len(char **);

/**
 * @brief Get the time
 *
 * @return the time in milliseconds
*/
size_t get_time(void);

#endif /* !UTILS_H_ */
