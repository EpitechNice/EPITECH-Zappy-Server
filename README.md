# 🌐 Zappy Server Submodule 🌐

Welcome to the **Zappy Server** submodule! This submodule provides the server-side infrastructure for the Zappy game, managing the game state, player interactions, and communication between clients.

## 📖 Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## 🌟 Introduction

The Zappy Server is the backbone of the Zappy game, responsible for managing the game world, handling player connections, and ensuring smooth gameplay.

## ✨ Features

- **Robust Game Management**: Handles the game state and player interactions.
- **Scalable**: Supports multiple teams and players.
- **Configurable Logging**: Adjustable log settings for different levels of detail.

## 🛠️ Installation

1. **Clone the Repository**:
   ```bash
   git clone git@github.com:EpitechNice/EPITECH-Zappy-Server.git zappy_server
   cd zappy_server
   ```

2. **Build the Project**:
   ```bash
   make
   ```

## 🚀 Usage

To launch the Zappy Server, use the following command:

```bash
./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq -l log_file -d log_level
```

### DESCRIPTION

- **-p**: Port number.
- **-x**: Width of the world.
- **-y**: Height of the world.
- **-n**: Names of the teams.
- **-c**: Number of authorized clients per team.
- **-f**: Reciprocal of time unit for execution of actions.
- **-l**: Log file (default is no logging).
- **-d**: Log level (debug, info, warning, error, or critical).

### Example

```bash
./zappy_server -p 12345 -x 100 -y 100 -n Team1 Team2 -c 10 -f 100 -l server.log -d info
```

This command will start the server on port `12345` with a world size of `100x100`, two teams (`Team1` and `Team2`), a maximum of `10` clients per team, an action frequency of `100`, logging to `server.log`, and a log level of `info`.

---

Feel free to reach out for any further questions or contributions!
