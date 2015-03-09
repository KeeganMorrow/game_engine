#ifndef COMPONENTS_POSITION_H
#define COMPONENTS_POSITION_H

#include <assert.h>
#include <SDL2/SDL.h>

namespace basic{
    struct compPosition : entityx::Component<compPosition> {
    public:
        compPosition(float posX, float posY) : posX(posX), posY(posY) {}

        ~compPosition(){}

        float getPosX(){
            return posX;
        }

        float getPosY(){
            return posY;

        }

        void setPosX(float newx){
            posX=newx;
        }

        void setPosY(float newy){
            posY=newy;
        }

        float modPosX(float modx){
            posX += modx;
            return posX;
        }

        float modPosY(float mody){
            posY += mody;
            return posY;
        }

    private:
        float posX;
        float posY;

    };
};

#endif /* COMPONENTS_POSITION_H */
