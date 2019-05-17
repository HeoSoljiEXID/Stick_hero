#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
using namespace sf;

int main()
{
    sf::Sound game_sound;
    sf::SoundBuffer game_sound_buffer;
    game_sound_buffer.loadFromFile("Audio/gamesound.wav");
    game_sound.setBuffer(game_sound_buffer);
    game_sound.setVolume(30);
    game_sound.play();
    game_sound.setLoop(true);
    //khai bao bien:
    bool press=false,startgame=false,endgame=false,pausegame=false;
    int c=0;
    int high_score=0;
    int m_score=0;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(456, 700), "Stick Hero Go");
    window.setFramerateLimit(60);
    sf::Sound m_character_drop,m_score_sound,m_bridge_drop;
    sf::SoundBuffer m_character_drop_buffer,m_score_sound_buffer,m_bridge_drop_buffer;
    sf::Sound m_sound_bridge_rise;
    sf::SoundBuffer m_sound_bridge_rise_buffer;
    sf:: Sprite m_again_press_sprite;
    sf::Texture m_again_press_texture1;
    sf::Texture m_again_press_texture2;
    sf:: Sprite m_game_over_sprite;
    sf:: Texture m_game_over_texture;
    sf::Sprite m_score_bonus_sprite;
    sf::Texture m_score_bonus_texture;
    sf::Image m_score_bonus_image;
    sf:: Font m_font;
    sf::Text m_text,m_high_score;
    sf::Text m_game_over;
    sf:: RectangleShape m_bonus_point;
    sf:: Sprite m_cherry_sprite;
    sf:: Texture m_cherry_texture;
    sf:: Image m_cherry_image;
    sf:: Sprite m_background_sprite;
    sf:: Texture m_background_texture;
    sf:: Image m_background_image;
    sf::RectangleShape m_bright;
    sf::Sprite m_character_sprite;
    sf::Texture m_character_texture;
    sf::Image m_character_image;
    sf::RectangleShape m_column1;
    sf::RectangleShape m_column2;
    sf::Sprite m_start_game_sprite;
    sf:: Sprite m_press_start_sprite;
    sf::Texture m_press_start_texture1;
    sf::Texture m_press_start_texture2;
    sf::Texture m_start_game_texture;

    //khoi tao size
    sf::Vector2f m_bonus_point_size={7,4};
    sf::Vector2f m_column_size={50,200};
    sf::Vector2f m_bright_size={3,0};

    //khoi tao vi tri
    sf::Vector2f op={0,500};
    sf::Vector2f ed={456,500};
    sf::Vector2f m_character_pos={0,472};
    sf::Vector2f m_column1_pos={0,500};
    sf::Vector2f m_column2_pos={456,500};
    sf::Vector2f m_bright_pos={48,500};
    sf:: Vector2f m_bonus_point_pos={456+50/2 - 3,500};//dua vao vi ri cua column: m_column2_pos.x+m_column_size.x/2-3
    int m_rand_pos_X=rand()%(400-50+1)+50;

    //set Size:
    m_bonus_point.setSize(m_bonus_point_size);
    m_bright.setSize(m_bright_size);
    m_column1.setSize(m_column_size);
    m_column2.setSize(m_column_size);
    m_column2.setOrigin(0,0);

    //set vi tri:
    m_bonus_point.setPosition(m_bonus_point_pos);
    m_character_sprite.setPosition(m_character_pos);
    m_column1.setPosition(m_column1_pos);
    m_column2.setPosition(m_column2_pos);
    m_bright.setPosition(m_bright_pos);
    m_press_start_sprite.setPosition(Vector2f(172,450));
    m_again_press_sprite.setPosition(Vector2f(115,500));

    //khoi tao mau sac
    m_bonus_point.setFillColor(sf::Color::Red);
    m_column1.setFillColor(sf::Color::Black);
    m_column2.setFillColor(sf::Color::Black);
    m_bright.setFillColor(sf::Color::Yellow);

    //chinh phong nen nhan vat va lay anh cua nhan vat
    m_bridge_drop_buffer.loadFromFile("Audio/bridgedrop.wav");
    m_score_sound_buffer.loadFromFile("Audio/score.wav");
    m_character_drop_buffer.loadFromFile("Audio/characterdrop.wav");
    m_sound_bridge_rise_buffer.loadFromFile("Audio/bridge.wav");
    m_again_press_texture1.loadFromFile("Picture/tryagain1.png");
    m_again_press_texture2.loadFromFile("Picture/tryagain2.png");
    m_game_over_texture.loadFromFile("Picture/gameover.png");
    m_score_bonus_image.loadFromFile("Picture/bonus_score.png");
    m_character_image.loadFromFile("Picture/character.png");
    m_start_game_texture.loadFromFile("Picture/startgame.jpg");
    m_press_start_texture1.loadFromFile("Picture/pressstart.png");
    m_press_start_texture2.loadFromFile("Picture/pressstart - Copy.png");
    m_sound_bridge_rise.setLoop(1);
        for (int a=0; a<m_score_bonus_image.getSize().x; a++)
    {
        for (int b=0; b<m_score_bonus_image.getSize().y; b++)
        {
                if (m_score_bonus_image.getPixel(a,b) == sf::Color(0,255,0))
                m_score_bonus_image.setPixel(a,b,sf::Color::Transparent);
        }
    }

    for (int a=0; a<m_character_image.getSize().x; a++)
    {
        for (int b=0; b<m_character_image.getSize().y; b++)
        {
                if (m_character_image.getPixel(a,b) == sf::Color(0,255,0))
                m_character_image.setPixel(a,b,sf::Color::Transparent);
        }
    }
    m_bridge_drop.setBuffer(m_bridge_drop_buffer);
    m_score_sound.setBuffer(m_score_sound_buffer);
    m_character_drop.setBuffer(m_character_drop_buffer);
    m_sound_bridge_rise.setBuffer(m_sound_bridge_rise_buffer);
    m_character_texture.loadFromImage(m_character_image);
    m_score_bonus_texture.loadFromImage(m_score_bonus_image);
    m_score_bonus_texture.setSmooth(true);
    m_character_texture.setSmooth(true);
    m_game_over_sprite.setTexture(m_game_over_texture);
    m_character_sprite.setTexture(m_character_texture);
    m_score_bonus_sprite.setTexture(m_score_bonus_texture);
    m_start_game_sprite.setTexture(m_start_game_texture);
    m_press_start_sprite.setTexture(m_press_start_texture1);
    m_again_press_sprite.setTexture(m_again_press_texture1);
    m_background_image.loadFromFile("Picture/fond.png");
    m_background_texture.loadFromImage(m_background_image);
    m_background_sprite.setTexture(m_background_texture);
    m_font.loadFromFile("Font/MarkerFelt.ttf");
    m_text.setFont(m_font);
    m_text.setString("Score: "+std::to_string(m_score));
    m_text.setCharacterSize(20);
    m_text.setPosition(200,0);
    m_high_score.setFont(m_font);
    m_game_over.setFont(m_font);
    m_high_score.setString(std::to_string(high_score));
    m_game_over.setString(std::to_string(m_score));
    m_high_score.setCharacterSize(72);
    m_game_over.setCharacterSize(72);
    m_game_over.setPosition(Vector2f(200,275));
    m_high_score.setPosition(Vector2f(200,385));
    m_game_over.setFillColor(Color::Black);
    m_high_score.setFillColor(Color::Black);

    while (window.isOpen())
    {
        if(m_score>=high_score)
        {
            high_score=m_score;
            cout<<high_score<<"    ";
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        int x=Mouse::getPosition(window).x;
        int y=Mouse::getPosition(window).y;
        if(Mouse::isButtonPressed(Mouse::Left)&&x<=(140+172)&&x>=172&&y>=450&&y<=(450+140))
        {
            startgame=true;
        }
        if(startgame==false)
        {
        if(x<=(140+172)&&x>=172&&y>=450&&y<=(450+140))
        {
            m_press_start_sprite.setTexture(m_press_start_texture2);
        }else{
            m_press_start_sprite.setTexture(m_press_start_texture1);
        }
        window.clear(sf::Color::Green);
        window.draw(m_start_game_sprite);
        window.draw(m_press_start_sprite);
        window.display();
        }else
        {

            if(endgame==false)
            {
                        m_text.setString("Score: "+std::to_string(m_score));
                if(Keyboard::isKeyPressed(Keyboard::Space)&&m_bright.getRotation()==0)
        {
            m_bright_size.y+=2;
//            BrightsetP.y-=0.1;
            m_bright.setSize(m_bright_size);
            m_bright.setPosition(m_bright_pos);
            c+=2;
            press=true;
            if(c%8==0)
            {
                m_sound_bridge_rise.play();
            }
//            m_sound_bridge_rise.setLoop(true);

//            window.draw(Bright);
        }else{
            m_sound_bridge_rise.stop();
        }
        m_bright.setOrigin(3,c);
        if(Event::KeyReleased && event.key.code == Keyboard::Space&&press==true)
        {
            if(m_bright.getRotation()<90)
            {
                m_bright.rotate(3);
                window.draw(m_bright);
            }
            if(m_bright.getRotation()>=90)
            {
                press=false;
                m_bridge_drop.play();
            }
        }
        if(m_character_pos.x<=m_column2_pos.x&& m_bright.getRotation()>=90&&m_column2.getPosition().x<=m_rand_pos_X&&  m_bright.getSize().y>=(m_rand_pos_X-50)&&m_bright.getSize().y<=(m_rand_pos_X))
        {
            m_score_sound.play();
            m_character_pos.x+=1;
            m_character_sprite.setPosition(m_character_pos.x,m_character_pos.y);
        }
        if(m_column2.getPosition().x!=m_rand_pos_X&&m_column1.getPosition().x>=0)
        {
            m_column2_pos.x-=1;
            m_column2.setPosition(m_column2_pos);
            m_bonus_point_pos.x-=1;
            m_bonus_point.setPosition(m_bonus_point_pos);//bonus_point thay doi theo column;
            window.draw(m_column2);
            window.draw(m_bonus_point);

        }else {
            if(m_column1.getPosition().x>=-50&&m_character_sprite.getPosition().x>=m_column2.getPosition().x&& m_bright.getRotation()>=90&&  m_bright.getSize().y>=(m_rand_pos_X-50)&&m_bright.getSize().y<=(m_rand_pos_X))
            {
                m_column1_pos.x-=1;
                m_column1.setPosition(m_column1_pos);
                m_bright.setPosition(Vector2f(m_bright.getPosition().x-1,m_bright.getPosition().y));
                window.draw(m_column1);
            }
            if(m_column2.getPosition().x>=0&&m_column1.getPosition().x<=-50&&m_character_sprite.getPosition().x>=m_column2.getPosition().x&& m_bright.getRotation()>=90&&  m_bright.getSize().y>=(m_rand_pos_X-50)&&m_bright.getSize().y<=(m_rand_pos_X))
            {
                m_column2_pos.x-=1;
                m_column2.setPosition(m_column2_pos);
                m_background_sprite.setTextureRect(IntRect(m_background_sprite.getTextureRect().left+1,0,456,700));
                m_background_sprite.setPosition(0,0);
                if(m_bonus_point_pos.x>=22)
                {
                    m_bonus_point_pos.x-=1;
                    m_bonus_point.setPosition(m_bonus_point_pos);
                    window.draw(m_bonus_point);
                }
                if(m_character_sprite.getPosition().x>0)
                {
                    m_character_pos=m_character_sprite.getPosition();
                    m_character_pos.x-=1;
                    m_character_sprite.setPosition(m_character_pos);
                    window.draw(m_character_sprite);

                    m_bright_pos=m_bright.getPosition();
                    m_bright_pos.x-=1;
                    m_bright.setPosition(m_bright_pos);
                    window.draw(m_bright);
                }
//                window.draw(m_column2);
//                window.draw(m_bonus_point);
            }
            if(m_column2.getPosition().x<=0&&m_column1.getPosition().x<=-50&&m_character_sprite.getPosition().x>m_column2.getPosition().x&& m_bright.getRotation()>=90)
            {
                m_column1.setPosition(op);
                m_column2.setPosition(ed);
                m_column2_pos=ed;
                m_rand_pos_X=rand()%(400-50+1)+50;
                m_column1_pos={0,500};
                m_score+=10;
                m_text.setString("Score: "+std::to_string(m_score));
                m_bonus_point.setPosition(Vector2f(456+50/2-3,500));
                m_bonus_point_pos=Vector2f(456+50/2-3,500);
                m_bright.setRotation(0);
                m_bright.setSize(Vector2f(3,0));
                m_bright_size=Vector2f(3,0);
                m_bright.setPosition(m_bright_pos);
                m_bright_pos=Vector2f(48,500);
                c=0;
            }
        }
        if((m_bright.getSize().y<=(m_rand_pos_X-50)||m_bright.getSize().y>=(m_rand_pos_X))&& m_bright.getRotation()>=90)
                {
                    if(m_character_sprite.getPosition().x>=(m_bright.getSize().y+50))
                    {
                        if(m_character_sprite.getPosition().y<700)
                        {
                            m_character_pos.y+=3;
                            m_character_sprite.setPosition(m_character_pos.x,m_character_pos.y);
                            m_character_drop.play();
                        }
                        if(m_bright.getRotation()<180)
                        {
                            m_bright.rotate(5);
                        }
                    }
                    if(m_character_sprite.getPosition().x<(m_bright.getSize().y+50))
                    {
                        m_character_pos.x+=1;
                        m_character_sprite.setPosition(m_character_pos.x,m_character_pos.y);
                    }
                    if(m_character_sprite.getPosition().x>=(m_bright.getSize().y+50)&&m_character_sprite.getPosition().y>=700&&m_bright.getRotation()>=180)
                {
                    endgame=true;
                m_column1.setPosition(op);
                m_column2.setPosition(ed);
                m_column2_pos=ed;
                m_rand_pos_X=rand()%(400-50+1)+50;
                m_column1_pos={0,500};
                m_text.setString("Score: "+std::to_string(m_score));
                m_bonus_point.setPosition(Vector2f(456+50/2-3,500));
                m_bonus_point_pos=Vector2f(456+50/2-3,500);
                m_bright.setRotation(0);
                m_bright.setSize(Vector2f(3,0));
                m_bright_size=Vector2f(3,0);
                m_bright.setPosition(m_bright_pos);
                m_bright_pos=Vector2f(48,500);
                c=0;
                m_character_sprite.setPosition(Vector2f(0,472));
                m_character_pos.x=0;
                m_character_pos.y=472;
                cout<<"LOL";
                }
                }
        window.clear(sf::Color::Green);
            window.draw(m_background_sprite);
            window.draw(m_column1);
            window.draw(m_column2);
            window.draw(m_character_sprite);
            window.draw(m_bright);
            window.draw(m_text);
            window.draw(m_bonus_point);
            window.draw(m_score_bonus_sprite);
        window.display();
        }else
        {
            if(Mouse::isButtonPressed(Mouse::Left)&&x<=(240+115)&&x>=115&&y>=500&&y<=(500+150))
            {
                endgame=false;
                m_score=0;
            }
            if(x<=(240+115)&&x>=115&&y>=500&&y<=(500+150))
        {
            m_again_press_sprite.setTexture(m_again_press_texture2);
        }else{
            m_again_press_sprite.setTexture(m_again_press_texture1);
        }
            m_game_over.setString(std::to_string(m_score));
            m_high_score.setString(std::to_string(high_score));
            window.clear(sf::Color::Green);
            window.draw(m_game_over_sprite);
            window.draw(m_game_over);
            window.draw(m_high_score);
            window.draw(m_again_press_sprite);
            window.display();
//            if(Keyboard::isKeyPressed(Keyboard::A))
//            {
//                endgame=false;
//                m_score=0;
//            }
        }
            }

    }
    return 0;
}
