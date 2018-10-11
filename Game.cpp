#include "Game.h"


void playGame(unsigned long long int& currentScore){
    SDL_Plotter g(600,300);

    //variables
    bool musicPlaying = false;

    //Sets board
    Box Board[20][10];
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            Board[i][j].setRow(i);
            Board[i][j].setCol(j);
        }
    }

    //Sets grid
    Line verticalRule[11];
    Line horizontalRule[20];
    for(int i = 0; i < 11; i++)
    {
        verticalRule[i].setP1(Point(i*30,0));
        verticalRule[i].setP2(Point(i*30,599));
    }
    for(int i = 0; i < 20; i++)
    {
        horizontalRule[i].setP1(Point(0,i*30));
        horizontalRule[i].setP2(Point(300,i*30));
    }


    //Increase randomness
    srand(time(NULL));


    //Initialize Sound
    g.initSound("Left.ogg");
    g.initSound("clearRow.wav");
    g.initSound("drop.wav");
    g.initSound("Rotate.ogg");
    g.initSound("Tetris.ogg");



    //Draw board & grid
    for(int i = 0; i < 11; i++)
    {
        verticalRule[i].draw(g);
    }

    for(int i = 0; i < 20; i++)
    {
        horizontalRule[i].draw(g);
    }

    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            Board[i][j].draw(g);
        }
    }


    // Set first spawn shape
    Spawn currentShape = Spawn();

    // clock ticks
    clock_t lastDrop = clock();

    // Draws Spawn block
    drawBlock(currentShape, Board, g);

    int collision = 0;
    char key;

    while(!g.getQuit())
    {
        //Input key hits
        if(g.kbhit())
        {
            key = g.getKey();
        }
        switch(key)
        {

            case RIGHT_ARROW:
            {
                collision = check_right_collision(currentShape, Board);
                if(collision != 3)
                {
                    g.playSound("Left.ogg");
                    eraseBlock(currentShape, Board, g);
                    currentShape.moveRight();
                    drawBlock(currentShape, Board, g);
                    key = '\0';
                }
                break;
            }

            case LEFT_ARROW:
            {
                collision = check_left_collision(currentShape, Board);
                if(collision != 2)
                {
                    g.playSound("Left.ogg");
                    eraseBlock(currentShape, Board, g);
                    currentShape.moveLeft();
                    drawBlock(currentShape, Board, g);
                    key = '\0';
                }
                break;
            }

            case UP_ARROW:
            {
                Spawn rotated = currentShape.rotateBlock();
                bool canRotate = allowRotation(rotated, Board);
                if(canRotate)
                {
                    g.playSound("Rotate.ogg");
                    eraseBlock(currentShape, Board, g);
                    currentShape = rotated;
                    drawBlock(currentShape, Board, g);
                    key = '\0';
                }
                break;
            }

            case DOWN_ARROW:
            {
                collision = check_bot_collision(currentShape, Board);
                while (collision != 1)
                {
                    g.playSound("drop.wav");
                    eraseBlock(currentShape, Board, g);
                    currentShape.fall();
                    drawBlock(currentShape, Board, g);

                    collision = check_bot_collision(currentShape, Board);
                }
                key = '\0';
                break;
            }

             case 'P':
                if(musicPlaying == false)
                {
                    g.playSound("Tetris.ogg");
                    musicPlaying = true;
                }

                key = '\0';
                break;

            case 'M':
                g.quitSound("Tetris.ogg");
                g.initSound("Tetris.ogg");
                musicPlaying = false;

                key = '\0';
                break;
        }

        //Check if block hit the bottom to then spawn new shape
        collision = check_bot_collision(currentShape, Board);
        if(collision == 1)
        {
            removeControl(currentShape, Board);
            lineDetection(Board, g);

            if(topDetection(Board, g))
            {
                g.setQuit(true);

            }

            currentShape = Spawn();
            currentScore += 50;
            cout << "Score: " << currentScore << endl;

            drawBlock(currentShape, Board, g);

        }
        //Make block fall automatically every 0.3 second
        else
        {
            clock_t currentDrop = clock();
            float timeDiff = (float)(currentDrop-lastDrop)/CLOCKS_PER_SEC;

            if(timeDiff >= 0.3)
            {
                lastDrop = currentDrop;
                eraseBlock(currentShape, Board, g);
                currentShape.fall();
                drawBlock(currentShape, Board, g);
            }
        }
        // Update Screen
        g.update();
        g.Sleep(10);
    }
}


void displaySplash(){
    SDL_Window* window = SDL_CreateWindow("splashscreen", 200, 200, 1066, 600, 0);

    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface * image = SDL_LoadBMP("BackSplashIMG.bmp");

    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);


    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);


    SDL_Delay(2000);


    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}


void displayHighScore(unsigned long long int& currentScore, string name)
{
    //Initialize HighScore
    HighScores score[5], gameScore;

    ifstream inFile;
    inFile.open("HighScore.txt");

    string nameFromFile;
    int scoreFromFile;

    inFile.ignore(100 , '\n');
    inFile.ignore(100, '\n' );

    for( int i = 0; i < 5; i++ )
    {
        inFile >> nameFromFile >> scoreFromFile;

        score[i].setName( nameFromFile);
        score[i].setScore( scoreFromFile);
    }

    inFile.close();

    ofstream outFile;
    outFile.open("HighScore.txt");

    cout << endl << "Your score: " << currentScore << endl << endl;

    gameScore.setName(name);
    gameScore.setScore(currentScore);

    if(score[4].getScore() < gameScore.getScore())
    {
        score[4] = gameScore;
    }

    sortScores(score);

    outFile << "\t===HIGHSCORES===\n";
    outFile << "Name\t\t\t\tScore\n";

    cout << "\t===HIGHSCORES===\n";
    cout << "Name\t\t\t\tScore\n";

    for(int i = 0; i < 5; i++)
    {
        cout << setw(30) << left;
        cout << score[i].getName() << "\t" <<  score[i].getScore() << "\n";

        outFile << setw(30) << left;
        outFile << score[i].getName() << "\t" << score[i].getScore() << "\n";
    }
    outFile.close();
}


void drawBlock(Spawn shape, Box board[20][10], SDL_Plotter& g)
{
    for(int i = 0; i < 4; i++)
    {
        Box temp = shape.getBox(i);
        int row = temp.getRow();
        int col = temp.getCol();
        board[row][col] = temp;
        board[row][col].draw(g);
    }
}


void eraseBlock(Spawn shape, Box board[20][10], SDL_Plotter& g)
{
    for(int i = 0; i < 4; i++)
    {
        Box temp = shape.getBox(i);
        int row = temp.getRow();
        int col = temp.getCol();
        board[row][col].deactivate();
        board[row][col].draw(g);
    }
}


void removeControl(Spawn shape, Box board[20][10])
{
    for(int i = 0; i < 4; i++){
        Box temp = shape.getBox(i);
        int row = temp.getRow();
        int col = temp.getCol();
        board[row][col].notSpawn();
    }
}


int check_bot_collision(Spawn shape, Box board[20][10])
{
    /*
    ret 1 = bottom collision
    ret 2 = left collision
    ret 3 = right collision
    */
    int ret = 0;
    int rowmax = 19;

    //Check if a box is on boundary or contacts another box
    for(int i = 0; i < 4; i++){
        Box currentBox = shape.getBox(i);
        int row = currentBox.getRow();
        int col = currentBox.getCol();

        if(row == rowmax)
        {
            ret = 1;
            break;
        }
        else
        {
            Box nextBox = board[row+1][col];
            bool activated = nextBox.checkActivation();
            bool isSpawn = nextBox.checkSpawn();
            if(activated && !isSpawn){
                ret = 1;
                break;
            }
        }
    }

    return ret;
}


int check_left_collision(Spawn shape, Box board[20][10])
{
    int ret = 0;
    int colmin = 0;

    //Check if a box is on boundary or contacts another box
    for(int i = 0; i < 4; i++)
    {
        Box currentBox = shape.getBox(i);
        int row = currentBox.getRow();
        int col = currentBox.getCol();

        if(col == colmin)
        {
            ret = 2;
            break;
        }
        else
        {
            Box nextBox = board[row][col-1];
            bool activated = nextBox.checkActivation();
            bool isSpawn = nextBox.checkSpawn();
            if(activated && !isSpawn)
            {
                ret = 2;
                break;
            }
        }
    }

    return ret;
}


int check_right_collision(Spawn shape, Box board[20][10])
{
    int ret = 0;
    int colmax = 9;

    //Check if a box is on boundary or contacts another box
    for(int i = 0; i < 4; i++)
    {
        Box currentBox = shape.getBox(i);
        int row = currentBox.getRow();
        int col = currentBox.getCol();

        if(col == colmax)
        {
            ret = 3;
            break;
        }
        else
        {
            Box nextBox = board[row][col+1];
            bool activated = nextBox.checkActivation();
            bool isSpawn = nextBox.checkSpawn();
            if(activated && !isSpawn)
            {
                ret = 3;
                break;
            }
        }
    }

    return ret;
}


bool allowRotation(Spawn shape, Box board[20][10])
{
    bool canRotate = true;
    int colmin = 0;
    int colmax = 9;
    int minrow = 0;

    //Check if a box is on boundary or contacts another box
    for(int i = 0; i < 4; i++)
    {
        Box rotatedBox = shape.getBox(i);
        int row = rotatedBox.getRow();
        int col = rotatedBox.getCol();

        if(col < colmin)
        {
            canRotate = false;
            break;
        }

        if(col > colmax)
        {
            canRotate = false;
            break;
        }

        if(row < minrow)
        {
            canRotate = false;
            break;
        }

        Box boardBox = board[row][col];
        bool activated = boardBox.checkActivation();
        bool isSpawn = boardBox.checkSpawn();

        if(activated && !isSpawn)
        {
            canRotate = false;
            break;
        }
    }
    return canRotate;
}


void lineDetection(Box board[20][10], SDL_Plotter& g)
{
    int count = 0;

    for(int i = 0; i < 20; i++)
    {
        count = 0;
        for(int p = 0; p < 10; p++)
        {
            if (board[i][p].checkActivation())
            {
                count++;
            }
        }
        if (count == 10)
        {
            for(int y = 0; y < 10; y++)
            {
                board[i][y].deactivate();
                board[i][y].draw(g);
            }

            for(int y = i; y >= 0; y--)
            {
                for(int x = 0; x < 10; x++)
                {
                    Box checkedBox = board[y][x];
                    if(checkedBox.checkActivation())
                    {
                        board[y][x].deactivate();
                        board[y][x].draw(g);
                        checkedBox.setRow(y+1);
                        board[y+1][x] = checkedBox;
                        board[y+1][x].draw(g);
                        g.playSound("clearRow.wav");
                    }
                }
            }
        }
    }
}


bool topDetection(Box board[20][10], SDL_Plotter& g)
{
    bool topped = false;
    for(int col = 0; col < 10; col++)
    {
        if (board[0][col].checkActivation() && !board[0][col].checkSpawn())
        {
            topped = true;
        }
    }

    return topped;
}


void sortScores( HighScores data[5] )
{
    HighScores temp;

    for(int pass = 0; pass < 5-1; pass++)
    {
        for(int i = 0; i < 5-1-pass; i++)
        {
            if(data[i].getScore() < data[i+1].getScore())
            {
              swap(data[i], data[i+1]);
            }
        }
    }
}
