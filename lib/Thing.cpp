

#define OBJECT_NUM 0
#define CHARACTER_NUM 1

enum typeOfThing
{
    OBJECT = 0,
    CHARACTER
};


class Thing 
{
    private:
        typeOfThing TYPE;

    protected:
        char RENDER;
        char RENDER_DEFAULT;

    public:
        int row;
        int col;

        Thing(int t = 0)
        {
            this->TYPE = (typeOfThing)t;

            this->row = -1;
            this->col = -1;

            this->RENDER_DEFAULT = '?';
            this->RENDER = this->RENDER_DEFAULT;
        }

        char getRender() { return this->RENDER; }

        void overrideRender(char NEW_RENDER) { this->RENDER = NEW_RENDER; }

        void restoreRender() { this->RENDER = this->RENDER_DEFAULT; }
};