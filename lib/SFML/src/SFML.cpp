/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SFML
*/

#include "../include/SFML.hpp"

Sfml::Sfml()
{
    _tileSize = 16;
    _score = 0;
    font.loadFromFile("epitech.ttf");
    text.setFont(font);
    text.setCharacterSize(80);
    text.setPosition(sf::Vector2f(1100, 200));
}

Sfml::~Sfml()
{
    _player.clear();
    _bonus.clear();
    _enemies.clear();
    _map.clear();
    for (sf::Texture *t : _textures)
    {
        delete t;
    }
    _textures.clear();
    _window.close();
}

std::string Sfml::menu(std::vector<std::string> list_games)
{
    int idx = 0;

    if (list_games.empty())
        return ("");

    std::vector<sf::Text> games;
    for (int i = 0; i < 3; ++i)
    {
        games.push_back(*new sf::Text);
        games[i].setFont(font);
        games[i].setCharacterSize(20);
        games[i].setPosition(sf::Vector2f(25, 25 + i * 50));
        games[i].setFillColor(sf::Color(255, 255, 255, 125));
    }
    games[1].setCharacterSize(25);
    games[1].setFillColor(sf::Color(255, 255, 255, 255));

    _window.create(sf::VideoMode(600, 400), "SFML", sf::Style::Titlebar | sf::Style::Close);
    _window.setFramerateLimit(20);

    while (_window.isOpen())
    {
        while (_window.pollEvent(_evt))
        {
            if (_evt.type == sf::Event::Closed) {
                _window.close();
                return ("");
            }
            if (_evt.type == sf::Event::EventType::KeyPressed)
            {
                if (_evt.key.code == sf::Keyboard::Enter)
                {
                    _window.close();
                    return (list_games[idx]);
                }
                if (_evt.key.code == sf::Keyboard::Up)
                {
                    idx -= 1;
                    if (idx < 0)
                        idx = list_games.size() - 1;
                    break;
                }
                if (_evt.key.code == sf::Keyboard::Down)
                {
                    idx += 1;
                    if (idx > (int)list_games.size() - 1)
                        idx = 0;
                    break;
                }
            }
        }
        if (idx - 1 < 0)
            games[0].setString("");
        else
            games[0].setString(list_games[idx - 1]);
        games[1].setString(list_games[idx]);
        if (idx + 1 >= (int)list_games.size())
            games[2].setString("");
        else
            games[2].setString(list_games[idx + 1]);
        _window.clear();
        for (sf::Text tx : games)
            _window.draw(tx);
        _window.display();
    }
    return (list_games[idx]);
}

void Sfml::InitWindow()
{
    _window.create(sf::VideoMode(_tileSize * 90, _tileSize * 35), "SFML", sf::Style::Titlebar | sf::Style::Close);
//    _window.setFramerateLimit(20);
}

void Sfml::init_map()
{
    _mapStartX = 1;
    _mapStartY = 2;
}

void Sfml::getevent(Event &evt)
{
    evt._evtType = Event::NONE;
    while (_window.pollEvent(_evt))
    {
        if (_evt.type == sf::Event::Closed)
            evt._evtType = Event::EXIT;
        if (_evt.type == sf::Event::EventType::KeyPressed)
        {
            switch (_evt.key.code)
            {
            case sf::Keyboard::Z:
                evt._evtType = Event::Z;
                break;
            case sf::Keyboard::Q:
                evt._evtType = Event::Q;
                break;
            case sf::Keyboard::S:
                evt._evtType = Event::S;
                break;
            case sf::Keyboard::D:
                evt._evtType = Event::D;
                break;
            case sf::Keyboard::O:
                evt._evtType = Event::O;
                break;
            case sf::Keyboard::K:
                evt._evtType = Event::K;
                break;
            case sf::Keyboard::L:
                evt._evtType = Event::L;
                break;
            case sf::Keyboard::M:
                evt._evtType = Event::M;
                break;
            case sf::Keyboard::R:
                evt._evtType = Event::R;
                break;
            case sf::Keyboard::Escape:
                evt._evtType = Event::EXIT;
                break;
            case sf::Keyboard::Space:
                evt._evtType = Event::SPACE;
                break;
            case sf::Keyboard::Enter:
                evt._evtType = Event::ENTER;
                break;
            default:
                evt._evtType = evt._evtType;
                break;
            }
        }
    }
}

sf::Sprite Sfml::set_sprite(int x, int y, std::string src_path)
{
    _textures.push_back(new sf::Texture);
    int ix = _textures.size() - 1;
    sf::Sprite sp;

    if (_textures[ix]->loadFromFile(src_path))
    {
        sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
        scale.x = (float)_tileSize / (float)_textures[ix]->getSize().x;
        scale.y = (float)_tileSize / (float)_textures[ix]->getSize().y;
        sp.setTexture(*_textures[ix]);
        sp.scale(scale);
        sp.setPosition((_mapStartX + x) * _tileSize, (_mapStartY + y) * _tileSize);
    }
    return sp;
}

int Sfml::getScore() const
{
    return (_score);
}

void Sfml::create_map(std::vector<std::string> src_map)
{
}

void Sfml::move(Event &evt)
{
    _map_carac = _player.back()->move(evt, _map_carac, _bonus);
    text.setString(std::to_string(_player.front()->getScore()));
}

void Sfml::set_map(std::vector<IObject *> &map)
{
    for (size_t i = 0; i < map.size(); i++)
    {
        if (!map[i]->getSpriteSFML().getTexture())
        {
            _textures.push_back(new sf::Texture);
            int ix = _textures.size() - 1;
            sf::Sprite sp;

            if (_textures[ix]->loadFromFile(map[i]->getNameSprite()))
            {
                sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
                scale.x = (float)_tileSize / (float)_textures[ix]->getSize().x;
                scale.y = (float)_tileSize / (float)_textures[ix]->getSize().y;
                sp.setTexture(*_textures[ix]);
                sp.scale(scale);
            }
            sp.setPosition((_mapStartX + map[i]->getPos()[0]) * _tileSize, (_mapStartY + map[i]->getPos()[1]) * _tileSize);
            map[i]->setSpriteSFML(sp);
        }
    }
    _map = map;
}

void Sfml::set_player(std::vector<IEntity *> &player)
{
    text.setString(std::to_string(player[0]->getScore()));
    for (size_t i = 0; i < player.size(); i++)
    {
        if (!player[i]->getSpriteSFML().getTexture())
        {
            _textures.push_back(new sf::Texture);
            int ix = _textures.size() - 1;
            sf::Sprite sp;

            if (_textures[ix]->loadFromFile(player[i]->getNameSprite()))
            {
                sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
                scale.x = (float)_tileSize / (float)_textures[ix]->getSize().x;
                scale.y = (float)_tileSize / (float)_textures[ix]->getSize().y;
                sp.setTexture(*_textures[ix]);
                sp.scale(scale);
            }
            player[i]->setSpriteSFML(sp);
        }
        player[i]->changePosSpriteSFML(((float)_mapStartX + player[i]->getPos()[0]) * (float)_tileSize, ((float)_mapStartY + player[i]->getPos()[1]) * (float)_tileSize);
    }
    _player = player;
}

void Sfml::set_enemy(std::vector<IEntity *> &enemies)
{
    for (size_t i = 0; i < enemies.size(); i++)
    {
        _textures.push_back(new sf::Texture);
        int ix = _textures.size() - 1;
        sf::Sprite sp;

        if (_textures[ix]->loadFromFile(enemies[i]->getNameSprite()))
        {
            sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
            scale.x = (float)_tileSize / (float)_textures[ix]->getSize().x;
            scale.y = (float)_tileSize / (float)_textures[ix]->getSize().y;
            sp.setTexture(*_textures[ix]);
            sp.scale(scale);
        }
        enemies[i]->setSpriteSFML(sp);
        enemies[i]->changePosSpriteSFML((_mapStartX + enemies[i]->getPos()[0]) * _tileSize, (_mapStartY + enemies[i]->getPos()[1]) * _tileSize);
    }
    _enemies = enemies;
}

void Sfml::set_bonus(std::vector<IObject *> &bonus)
{
    for (size_t i = 0; i < bonus.size(); i++)
    {
        if (!bonus[i]->getSpriteSFML().getTexture())
        {
            _textures.push_back(new sf::Texture);
            int ix = _textures.size() - 1;
            sf::Sprite sp;

            if (_textures[ix]->loadFromFile(bonus[i]->getNameSprite()))
            {
                sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f);
                scale.x = (float)_tileSize / (float)_textures[ix]->getSize().x;
                scale.y = (float)_tileSize / (float)_textures[ix]->getSize().y;
                sp.setTexture(*_textures[ix]);
                sp.scale(scale);
            }
            sp.setPosition((_mapStartX + bonus[i]->getPos()[0]) * _tileSize, (_mapStartY + bonus[i]->getPos()[1]) * _tileSize);
            bonus[i]->setSpriteSFML(sp);
        }
    }
    _bonus = bonus;
}

void Sfml::display_all()
{
    _window.clear(sf::Color::Black);
    for (IObject *sp : _map)
        _window.draw(sp->getSpriteSFML());
    for (IObject *sp : _bonus)
        _window.draw(sp->getSpriteSFML());
    for (IEntity *sp : _enemies)
        _window.draw(sp->getSpriteSFML());
    for (IEntity *sp : _player)
        _window.draw(sp->getSpriteSFML());
    _window.draw(text);
    _window.display();
    _textures.clear();
}

int Sfml::game_over()
{
    Clock clock;
    clock.start();
    text.setString("GameOver");
    text.setCharacterSize(30);
    text.setPosition((_mapStartX + 8) * _tileSize, (_mapStartY + 14) * _tileSize);
    _window.draw(text);
    while (clock.get_time() < 5000)
    {
        _window.display();
    }
    return (0);
}

extern "C" IDisplayModule *create()
{
    return new Sfml;
}

extern "C" void destroy(IDisplayModule *p)
{
    delete p;
}

__attribute__((constructor)) void init()
{
}

__attribute__((destructor)) void stop()
{
}
