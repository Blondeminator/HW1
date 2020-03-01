#include <stdio.h>
#include <stdlib.h>

//Game parameters:
const int deck_number = 1;
const int deck_size = 52;
const int shuffle_number = 28; //how many times 2 random cards from the deck get swapped
const int bet = 100;
const int seed = 0;

//Ingame indicators:
int strategy = 4; //5 strategies 1 to 5
int split = 0;
int doubled = 1; //1 if not doubled, 2 if doubled
int playerwon = 0;
int split_playerwon = 0;
int dealerwon = 0;

//Statistics:
int money = 0;
int playerwon_number = 0; //Split win still counts as one
int dealerwon_number = 0; //Tie counts as 0 for both parties

struct player{
    int hand[11];
    int card_number;
    int hand_value;
};

void deck_setup(int *sdeck){
    for(int i = 0; i < 9; i++){
        sdeck[i] = i + 2;
        sdeck[i+9] = i + 2;
        sdeck[i+18] = i + 2;
        sdeck[i+27] = i + 2;
    }
    for(int i = 0; i < 4; i++){
        sdeck[i+36] = 11;
    }
    for(int i = 0; i < 12; i++){
        sdeck[i+40] = 10;
    }
}

void shuffle(int *sdeck){
    int j,k,container;
    for(int i = 0; i < deck_size*shuffle_number; i++){
        j = rand()%deck_size;
        k = rand()%deck_size;
        container = sdeck[j];
        sdeck[j] = sdeck[k];
        sdeck[k] = container;
    }
}

void new_player(struct player *nplayer){
    nplayer->card_number = 0;
    nplayer->hand_value = 0;
    for (int i = 0; i < 11; ++i) {
        nplayer->hand[i] = 0;
    }
}

void draw_card(struct player *dplayer, int *ddeck){
    int i = rand()%52;
    while(ddeck[i] == -1){
        i = rand()%52;
    }
    int j = 0;
    int k = dplayer->card_number++;
    dplayer->hand[k] = ddeck[i];
    if(ddeck[i] == 11) j++;
    ddeck[i] = -1;
    dplayer->hand_value += dplayer->hand[k];
    if(dplayer->hand_value > 21 && j) dplayer->hand_value-=10;
}

void game_end(struct player *p_dealer, struct player *p, struct player *p_split){
    if(p->hand_value > p_dealer->hand_value ){
        if(p->hand_value <= 21){
            playerwon = 1;
            }
        } else if(p->hand_value == 21 && p->card_number == 2){ //Blackjack check
            playerwon = 1;
    }
    if( split && p_split->hand_value > p_dealer->hand_value && p_split->hand_value <= 21 ){
        split_playerwon = 1;
    }
    if(!playerwon && !split_playerwon && p_dealer->hand_value <= 21){
        dealerwon = 1;
    } else if(p_dealer->hand_value == 21 && p_dealer->card_number == 2){ //Blackjack check
        dealerwon = 1;
    }
    //
    money += doubled * bet * playerwon;
    money += bet * split_playerwon;
    money -= bet * dealerwon;
    if(playerwon || split_playerwon){playerwon_number++;}
    if(dealerwon){dealerwon_number++;}
}

void strategy1(struct player *s1player, int *s1deck){
    doubled = 2;
    draw_card(s1player,s1deck);
}

void strategy2(struct player *s2player, struct player *split_s2player ,int *s2deck){
    if(s2player->hand[0] == s2player->hand[1]){
        split = 1;
        s2player->hand_value -= s2player->hand[1];
        s2player->card_number--;
        split_s2player->hand[0] = s2player->hand[1];
        draw_card(s2player,s2deck);
        draw_card(split_s2player,s2deck);
    } else{
        doubled = 2;
        draw_card(s2player,s2deck);
    }
}

void strategy3(struct player *s3player, struct player *split_s3player ,int *s3deck){
    if(s3player->hand[0] == s3player->hand[1]){
        if(rand()%2){
            split = 1;
            s3player->hand_value -= s3player->hand[1];
            s3player->card_number--;
            split_s3player->hand[0] = s3player->hand[1];
            draw_card(s3player,s3deck);
            draw_card(split_s3player,s3deck);
        } else{
            doubled = 2;
            draw_card(s3player,s3deck);
        }
    } else{
        doubled = 2;
        draw_card(s3player,s3deck);
    }
}

void strategy4(struct player *s4player, struct player *split_s4player ,int *s4deck){
    if(s4player->hand[0] == s4player->hand[1] && s4player->hand[0] >= 10){
        split = 1;
        s4player->hand_value -= s4player->hand[1];
        s4player->card_number--;
        split_s4player->hand[0] = s4player->hand[1];
        draw_card(s4player,s4deck);
        draw_card(split_s4player,s4deck);
    } else{
        doubled = 2;
        draw_card(s4player,s4deck);
    }
}

void strategy5(struct player *s5player, struct player *split_s5player , struct player *s5dealer ,int *s5deck){
    if(s5player->hand[0] == s5player->hand[1] && s5player->hand_value >= s5dealer->hand_value){
        split = 1;
        s5player->hand_value -= s5player->hand[1];
        s5player->card_number--;
        split_s5player->hand[0] = s5player->hand[1];
        draw_card(s5player,s5deck);
        draw_card(split_s5player,s5deck);
    } else{
        doubled = 2;
        draw_card(s5player,s5deck);
    }
}

int main() {
    srand(seed);
    struct player p;
    struct player split_p;
    struct player dealer;
    struct player *ppointer = &p;
    struct player *split_ppointer = &split_p;
    struct player *dpointer = &dealer;
    int *deck = malloc(deck_number*deck_size*sizeof(int));

    for (int i = 0; i < 10000; ++i) {
        deck_setup(deck);
        shuffle(deck);
        new_player(ppointer);
        new_player(split_ppointer);
        new_player(dpointer);
        doubled = 1;
        split = 0;
        playerwon = 0;
        split_playerwon = 0;
        dealerwon = 0;
        for (int i = 0; i < 2 ; ++i) {
            draw_card(ppointer,deck);
            draw_card(dpointer,deck);
        }

        switch (strategy){
            case 1:
                strategy1(ppointer,deck);
                break;
            case 2:
                strategy2(ppointer,split_ppointer,deck);
                break;
            case 3:
                strategy3(ppointer,split_ppointer,deck);
                break;
            case 4:
                strategy4(ppointer,split_ppointer,deck);
                break;
            case 5:
                strategy5(ppointer,split_ppointer,dpointer,deck);
                break;
        }
        if(dpointer->hand_value <= 17){draw_card(dpointer,deck);}
        game_end(dpointer,ppointer,split_ppointer);
    }
    printf("Player money: %d\n Times the player won: %d\n Times the dealer won: %d\n Seed:%d\n",money,playerwon_number,dealerwon_number,seed);
    free(deck);
    return 0;
}
