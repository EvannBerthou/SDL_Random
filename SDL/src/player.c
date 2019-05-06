#include <SDL2/SDL.h>
#include "math.h"
#include "player.h"

Player initPlayer(Vec2 position, Vec2 scale){
    
    Player result = {
        position,
        scale
    };
    return result;
}

void player_draw(SDL_Renderer* renderer, Player* player){
    

    SDL_Rect r = {
        player->position.x,
        player->position.y,
        player->scale.x,
        player->scale.y
    };


    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderFillRect(renderer, &r);

}
