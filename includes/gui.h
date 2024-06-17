/*
** EPITECH PROJECT, 2024
** Zappy
** File description:
** gui
*/

#ifndef GUI_H_
    #define GUI_H_

    #include "zappy_server.h"
    #include "clients.h"

/**
  * @brief Sends a message to the GUI
  *
  * @param args Arguments of the command
*/
void command_smg(char **args);

/**
  * @brief Sends a new AI connection to the GUI
  *
  * @param data Data of the new AI
*/
void command_pnw(const char *data);

/**
 * @brief Sends a endgame message to the GUI
 *
 * @param data Name of the winning team
*/
void command_seg(const char *data);

/**
  * @brief Sends a death message to the GUI
  *
  * @param id ID of the dead player
*/
void command_pdi(int id);

/**
  * @brief Sends an expulsion of an AI to the GUI
  *
  * @param id ID of the player
*/
void command_pex(int id);

/**
  * @brief Sends a new egg was layed by a player to the GUI
  *
  * @param id ID of the player
*/
void command_pfk(int id);

/**
  * @brief Sends a player connection to a new egg to the GUI
  *
  * @param id ID of the egg
*/
void command_ebo(int id);

/**
  * @brief Sends a death of an egg to the GUI
  *
  * @param id ID of the egg
*/
void command_edi(int id);

/**
  * @brief Sends ressource dropping to the GUI
  *
  * @param id ID of the player
  * @param ressource ID of the ressource
*/
void command_pdr(int id, int ressource);

/**
  * @brief Sends ressource collecting to the GUI
  *
  * @param id ID of the player
  * @param ressource ID of the ressource
*/
void command_pgt(int id, int ressource);

/**
 * @brief Sends an end of incantation to the GUI
 *
 * @param x X position of the incantation
 * @param y Y position of the incantation
 * @param success If the incantation was successful
*/
void command_pie(int x, int y, bool success);

/**
  * @brief Sends a new Broadcast to the GUI
  *
  * @param id ID of the player
  * @param message Message of the broadcast
*/
void command_pbc(int id, const char *message);

/**
  * @brief Sends a new player connection on egg to the GUI
  *
  * @param id ID of the egg
  * @param client Client that connected
*/
void command_enw(int id, client_t *client);

/**
  * @brief Sends a new incantation to the GUI
  *
  * @param client Client that started the incantation
  * @param ai Array of the players in the incantation
  * @param size Size of the array
*/
void command_pic(client_t *client, int *ai, int size);

/**
  * @brief Sends the map dimensions to the GUI
  *
  * @param cmd Command sent by the client
  * @param client GUI client
*/
void command_msz(char **cmd, client_t *client);

/**
  * @brief Sends the tile content to the GUI
  *
  * @param cmd Command sent by the client
  * @param client GUI client
*/
void command_bct(char **cmd, client_t *client);

/**
  * @brief Sends the content of all tiles to the GUI
  *
  * @param cmd Command sent by the client
  * @param client GUI client
*/
void command_mct(char **cmd, client_t *client);

/**
  * @brief Sends the team names to the GUI
  *
  * @param cmd Command sent by the client
  * @param client GUI client
*/
void command_tna(char **cmd, client_t *client);

/**
  * @brief Sends the player infos to the GUI
  *
  * @param cmd Command sent by the client
  * @param client Client that connected
*/
void command_ppo(char **cmd, client_t *client);

/**
  * @brief Sends the player level to the GUI
  *
  * @param cmd Command sent by the client
  * @param client Client that connected
*/
void command_plv(char **cmd, client_t *client);

/**
  * @brief Sends the player inventory to the GUI
  *
  * @param cmd Command sent by the client
  * @param client Client that connected
*/
void command_pin(char **cmd, client_t *client);

/**
  * @brief Sends the server frequency  to the GUI
  *
  * @param cmd Command sent by the client
  * @param client Client that connected
*/
void command_sgt(char **cmd, client_t *client);

/**
  * @brief modify the server frequency
  *
  * @param cmd Command sent by the client
  * @param client Client that connected
*/
void command_sst(char **cmd, client_t *client);

/**
  * @brief Sends unknown command to the GUI
  *
  * @param client Client that connected
*/
void command_suc(client_t *);

/**
  * @brief Periodically sends data to the GUI
  *
  * @param client Client that connected
*/
void send_to_gui(client_t *client);

#endif /* !GUI_H_ */
