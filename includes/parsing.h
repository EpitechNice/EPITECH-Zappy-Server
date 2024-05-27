/*
** EPITECH PROJECT, 2024
** server
** File description:
** parsing
*/

#ifndef PARSING_H_
    #define PARSING_H_

    #include "includes.h"
    #include "linked_list.h"

typedef struct parsing_structure {
    int port;
    int width;
    int height;
    lnode_t *names;
    int clients_nb;
    int freq;
    bool ok;
    bool help;
} parsing_t;

/**
 * @brief Final check for the parsing
 *
 * @param p the parsing structure
*/
parsing_t *parsing_check(parsing_t *p);


/**
 * @brief Destroy the parsing structure.
 *
 * @param parsing A pointer to the parsing structure.
*/
void destroy_parsing(parsing_t *parsing);

/**
 * @brief Init an empty parsing structure
 *
 * @return the new structure
*/
parsing_t *init_parsing(void);


/**
 * @brief Parse the arguments and return a parsing structure.
 *
 * @param argc The number of arguments.
 * @param argv The arguments.
 *
 * @return A pointer to the parsing structure.
*/
parsing_t *parse(int argc, char **argv);

#endif /* !PARSING_H_ */
