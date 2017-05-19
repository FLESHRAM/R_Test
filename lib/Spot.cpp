



class Spot
{
    private:
        Thing * here;

    public:
        Spot()
        {
            this->here = NULL;
        }

        Thing * getThing() { return this->here; }

        void placeThing(Thing * t, int row, int col) 
        {
            if(this->here != NULL) return;

            this->here = t;
            this->here->row = row;
            this->here->col = col; 
        }

        void removeThing() 
        { 
            this->here->row = -1;
            this->here->col = -1;
            this->here = NULL; 
        }

        bool isEmpty()
        {
            if(here == NULL) return true;

            return false;
        }

        char renderHere()
        {
            if(this->here == NULL) return ' ';

            return this->here->getRender();
        }
};