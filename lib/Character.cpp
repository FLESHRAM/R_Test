

// A character in the world

enum CharType 
{ 
    PLAYER = 0,
    NPC,
    MONSTER
};



class Character : public Thing
{
    char * name;

    protected: 
        int life;
        int maxLife; 

    public:
        Character (int maxLife = 10) : Thing(CHARACTER_NUM)
        {
            this->maxLife = maxLife;
            this->life = maxLife;
            this->RENDER_DEFAULT = 'C';
            this->RENDER = this->RENDER_DEFAULT;
        }


        int getLife() { return this->life; }

        void hurt(int damage = 1) 
        { if(this->life != 0) this->life -= damage; }

        void heal(int h = 1) 
        { if(this->life != this->maxLife) this->life += h; }
};


