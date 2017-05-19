
// A place in the world
#define INVALID_POS -1

class Place
{
    private:
    // Dimensions of this place
    int width, height;
    Spot **spots;

    public:
    static int maxWidth, maxHeight;
    static int minWidth, minHeight;

    Place(int w = maxWidth, int h = maxHeight)
    {
        this->width = validWidth(w);
        this->height = validHeight(h);
        
        spots = new Spot*[this->height];
        
        for(int i = 0; i < this->height; i++)
            spots[i] = new Spot[this->width];
    }

    int validWidth(int val)
    {
        if(val < minWidth) return minWidth;

        if(val > maxWidth) return maxWidth;

        return val;
    }


    int validHeight(int val)
    {
        if(val < minHeight) return minHeight;

        if(val > maxHeight) return maxHeight;

        return val;
    }

    int getW() { return this->width; }
    int getH() { return this->height; }

    // void setThing(int row, int col, Thing * newThing)
    // {
    //     //if(newThing == NULL) return;

    //     Thing * aThing = &this->things[row][col];
    //     //delete(aThing);

    //     *aThing = *newThing;

    //     //aThing = newThing;
    // }

    void placeInSpot(int row, int col, Thing * t)
    {
        this->spots[row][col].placeThing(t, row, col);
    }

    char getSpotRender(int row, int col)
    {
        return this->spots[row][col].renderHere();
    }

    bool moveThing (inputDirection dir, Thing * t)
    {
        if(t == NULL) return false;

        int row_pos = t->row;
        int col_pos = t->col;

        int new_row;
        int new_col;

        if(row_pos == INVALID_POS || col_pos == INVALID_POS)
        return false;


        switch (dir)
        {
            case NO_INPUT:
            return false;
            break;

            case UP:
                if(row_pos == 0) return false;

                new_row = row_pos-1;

                this->spots[row_pos][col_pos].removeThing();
                this->spots[new_row][col_pos].placeThing(t, new_row, col_pos);
            break;

            case DOWN:
                if(row_pos == this->height-1) return false;

                new_row = row_pos+1;

                this->spots[row_pos][col_pos].removeThing();
                this->spots[new_row][col_pos].placeThing(t, new_row, col_pos);
            break;

            case LEFT:
                if(col_pos == 0) return false;

                new_col = col_pos-1;

                this->spots[row_pos][col_pos].removeThing();
                this->spots[row_pos][new_col].placeThing(t, row_pos, new_col);
            break;


            case RIGHT:
                if(col_pos == this->width-1) return false;

                new_col = col_pos+1;

                this->spots[row_pos][col_pos].removeThing();
                this->spots[row_pos][new_col].placeThing(t, row_pos, new_col);
            break;

            case UP_LEFT:
                if(col_pos == 0 || row_pos == 0) return false;

                new_row = row_pos-1;
                new_col = col_pos-1;

                this->spots[row_pos][col_pos].removeThing();
                this->spots[new_row][new_col].placeThing(t, new_row, new_col);
            break;

            default:
                return false;
            break;
        }

        return true;
    }

    // Thing * getThing(int row, int col) 
    // { 
    //     Thing * aThing = &this->things[row][col];
    //     return aThing; 
    // }

    void setW(int w) { this->width = validWidth(w); }
    void setH(int h) { this->height = validHeight(h); }
};