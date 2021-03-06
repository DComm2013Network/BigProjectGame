/*------------------------------------------------------------------------------------------
 * SOURCE FILE: Packets.h
 *
 * PROGRAM:     [BIG_GAME]
 *
 * FUNCTIONS:   [NONE]
 *                            
 *
 * DATE:        January 27, 2014
 *
 * REVISIONS:   (Date and Description)
 *
 * DESIGNER:    Andrew Burian
 *
 * PROGRAMMER:  Andrew Burian
 *
 * NOTES:
 * 
 * This file contains the all the network communication related definitions and structure
 * declarations that will be used between the client and the server.
 *
 * This file must be consistent between the client and the server.
 *
 *----------------------------------------------------------------------------------------*/

// Limits
#define MAX_PLAYERS         32
#define MAX_FLOORS          8
#define MAX_NAME            80
#define MAX_MESSAGE         180
#define MAX_OBJECTIVES      16

// Definitions for various game data types
#define bool                int
#define floorNo_t           int
#define playerNo_t          uint
#define teamNo_t            uint
#define status_t            int
#define pos_t               uint

// Connect code Definitions
#define CONNECT_CODE_ACCEPTED   0x001
#define CONNECT_CODE_DENIED     0x000

// Game Status Definitions
#define GAME_STATE_WAITING      0x001
#define GAME_STATE_ACTIVE       0x002
#define GAME_STATE_OVER         0x003
#define PLAYER_STATE_READY      0x004
#define PLAYER_STATE_WAITING    0x005

// Special floor Definitions
#define FLOOR_LOBBY             0x000

// Packet Definitions
typedef struct pkt01 {
    int         packet_id;
    char        client_player_name[MAX_NAME_SIZE];
};

typedef struct pkt02 {
    int         packet_id;    
    uint        connect_code;
    playerNo_t  clients_player_number;
    teamNo_t    clients_team_number;
};

typedef struct pkt03 {
    int         packet_id;
    bool        player_valid[MAX_PLAYER];
    char        otherPlayers_name[MAX_PLAYERS][MAX_NAME];
    teamNo_t    otherPlayers_teams[MAX_PLAYERS];
    status_t    readystatus[MAX_PLAYERS];
};

typedef struct pkt04 {
    int         packet_id;
    playerNo_t  sendingPlayer_number;
    char        message[MAX_MESSAGE_SIZE];
};

typedef struct pkt05 {
    int         packet_id;
    playerNo_t  player_number;
    status_t    ready_status;
    teamNo_t    team_number;
    char        player_name[MAX_NAME_SIZE];
};

typedef struct pkt06 {
    int         packet_id;
    floorNo_t   map_data[MAX_FLOORS];
    int         objective_locations[MAX_OBJECTIVES]
};

//Packet 7: 0x0007
// << UNPURPOSED >>

typedef struct pkt08 {
    int         packet_id;
    bool        objectives_captured[MAX_OBJECTIVES]
    status_t    game_status;
};

//Packet 9: 0x0009
// << UNPURPOSED >>

typedef struct pkt10 {
    int         packet_id;
    floorNo_t   floor;
    playerNo_t  player_number;
    pos_t       xPos;
    pos_t       yPos;
    pos_t       xVel;
    pos_t       yVel;
} PKT_POS_UPDATE;

typedef struct pkt11 {
    int         packet_id;
    floorNo_t   floor;
    bool        players_on_floor[MAX_PLAYERS];
    pos_t       xPos[MAX_PLAYERS];
    pos_t       yPos[MAX_PLAYERS];
    pos_t       xVel[MAX_PLAYERS];
    pos_t       yVel[MAX_PLAYERS];
} PKT_ALL_POS_UPDATE;

typedef struct pkt12 {
    int         packet_id;
    playerNo_t  player_number;
    floorNo_t   current_floor;
    floorNo_t   desired_floor;
} PKT_FLOOR_MOVE_REQUEST;

typedef struct pkt13 {
    int         packet_id;
    floor_t     new_floor;
    pos_t       xPos;
    pos_t       yPos;
} PKT_FLOOR_MOVE;