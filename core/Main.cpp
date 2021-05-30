/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Main
*/

#include <dlfcn.h>
#include <iostream>
#include <dirent.h>
#include <cstring>
#include "./Event.hpp"
#include "../lib/include/IDisplayModule.hpp"
#include "../games/include/IGameModule.hpp"

std::vector<std::string> get_all(std::string path)
{
    DIR *dir;
    struct dirent *ent;
    std::vector<std::string> list;

    if ((dir = opendir(path.c_str())) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
            list.push_back(ent->d_name);
        closedir(dir);
        return (list);
    }
    return (list);
}

std::vector<std::string> recup_lib(std::vector<std::string> list)
{
    bool inc = false;
    std::vector<std::string> lib_name;

    for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++)
    {
        if ((*it).find("lib_arcade") != std::string::npos)
            inc = true;
        if (inc == true)
        {
            lib_name.push_back(*it);
            inc = false;
        }
    }
    return (lib_name);
}

std::vector<std::string> list_so(std::string path)
{
    std::vector<std::string> list = get_all(path);
    std::vector<std::string> lib_name;
    lib_name = recup_lib(list);
    return (lib_name);
}

void *load_lib(void *lib, char const *str)
{
    lib = dlopen(str, RTLD_LAZY);
    const char *dlsym_error = dlerror();

    if (dlsym_error)
    {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit(84);
    }
    return (lib);
}

void check_lib_create()
{
    const char *dlsym_error = dlerror();

    if (dlsym_error)
    {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit(84);
    }
}

void check_lib_destroy()
{
    const char *dlsym_error = dlerror();

    if (dlsym_error)
    {
        std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        exit(84);
    }
}

void check_game_create()
{
    const char *dlsym_error = dlerror();
    if (dlsym_error)
    {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit(84);
    }
}

void check_game_destroy()
{
    const char *dlsym_error = dlerror();

    if (dlsym_error)
    {
        std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
        exit(84);
    }
}

int main(int ac, char const **av)
{
    void *lib = nullptr;
    void *game = nullptr;

    create_t *create_lib_graph = nullptr;
    destroy_t *destroy_lib_graph = nullptr;

    create_t *create_lib_game = nullptr;
    destroy_t *destroy_lib_game = nullptr;

    if (ac == 2)
    {
        std::vector<std::string> list_lib = list_so("lib/.");
        int i = 0;

        for (std::string m : list_lib)
        {
            if (strcmp(("./lib/" + m).c_str(), av[1]) == 0)
                break;
            i += 1;
        }
        if (i == (int)list_lib.size())
            return (84);
        std::vector<std::string> list_game = list_so("games/.");
        int int_game = 0;

        lib = load_lib(lib, ("./lib/" + list_lib[i]).c_str());
        create_lib_graph = (create_t *)dlsym(lib, "create");
        check_lib_create();
        destroy_lib_graph = (destroy_t *)dlsym(lib, "destroy");
        check_lib_destroy();

        IDisplayModule *module = (IDisplayModule *)create_lib_graph();

        std::string game_selected = module->menu(list_game);
        for (std::string m : list_game)
        {
            if (strcmp(m.c_str(), game_selected.c_str()) == 0)
                break;
            int_game += 1;
        }

        if (game_selected.empty())
            return (0);
        game = load_lib(game, ("./games/" + game_selected).c_str());
        create_lib_game = (create_t *)dlsym(game, "create");
        check_lib_create();
        destroy_lib_game = (destroy_t *)dlsym(game, "destroy");
        check_lib_destroy();

        IGameModule *module_game = (IGameModule *)create_lib_game();
        Event evt;

        module_game->init_all();
        module->InitWindow();
        module->set_map(module_game->getMap());

        while (42)
        {
            if (module_game->game_over())
            {
                module->game_over();
                break;
            }
            module->getevent(evt);
            if (evt._evtType == Event::EXIT)
                break;
            if (evt._evtType == Event::ENTER && int_game + 1 < (int)list_game.size())
            {
                int_game += 1;
                destroy_lib_game(module_game);
                dlclose(game);
                game_selected = list_game[int_game];
                game = nullptr;
                game = load_lib(game, ("./games/" + game_selected).c_str());
                create_lib_game = (create_t *)dlsym(game, "create");
                check_lib_create();
                destroy_lib_game = (destroy_t *)dlsym(game, "destroy");
                check_lib_destroy();
                module_game = (IGameModule *)create_lib_game();
                module_game->init_all();
                evt._evtType = Event::NONE;
            }
            if (evt._evtType == Event::SPACE && int_game - 1 >= 0)
            {
                int_game -= 1;
                destroy_lib_game(module_game);
                dlclose(game);
                game_selected = list_game[int_game];
                game = nullptr;
                game = load_lib(game, ("./games/" + game_selected).c_str());
                create_lib_game = (create_t *)dlsym(game, "create");
                check_lib_create();
                destroy_lib_game = (destroy_t *)dlsym(game, "destroy");
                check_lib_destroy();
                module_game = (IGameModule *)create_lib_game();
                module_game->init_all();
                evt._evtType = Event::NONE;
            }
            if (evt._evtType == Event::R)
            {
                destroy_lib_game(module_game);
                dlclose(game);
                game = nullptr;
                game = load_lib(game, ("./games/" + game_selected).c_str());
                create_lib_game = (create_t *)dlsym(game, "create");
                check_lib_create();
                destroy_lib_game = (destroy_t *)dlsym(game, "destroy");
                check_lib_destroy();
                module_game = (IGameModule *)create_lib_game();
                module_game->init_all();
                evt._evtType = Event::NONE;
            }
            if (evt._evtType == Event::L && i + 1 < (int)list_lib.size())
            {
                i += 1;
                destroy_lib_graph(module);
                dlclose(lib);
                lib = nullptr;
                lib = load_lib(lib, ("./lib/" + list_lib[i]).c_str());
                create_lib_graph = (create_t *)dlsym(lib, "create");
                check_lib_create();
                destroy_lib_graph = (destroy_t *)dlsym(lib, "destroy");
                check_lib_destroy();
                //module_game->destroy_sprite();
                module = (IDisplayModule *)create_lib_graph();
                module->InitWindow();
                module->set_map(module_game->getMap());
                evt._evtType = Event::NONE;
            }
            if (evt._evtType == Event::K && i - 1 >= 0)
            {
                i -= 1;
                destroy_lib_graph(module);
                dlclose(lib);
                lib = nullptr;
                lib = load_lib(lib, ("./lib/" + list_lib[i]).c_str());
                create_lib_graph = (create_t *)dlsym(lib, "create");
                check_lib_create();
                destroy_lib_graph = (destroy_t *)dlsym(lib, "destroy");
                check_lib_destroy();
                //module_game->destroy_sprite();
                module = (IDisplayModule *)create_lib_graph();
                module->InitWindow();
                module->set_map(module_game->getMap());
                evt._evtType = Event::NONE;
            }
            if (evt._evtType == Event::M)
            {
                destroy_lib_game(module_game);
                dlclose(game);
                game = nullptr;
                game_selected = module->menu(list_game);
                int_game = 0;
                for (std::string m : list_game)
                {
                    if (strcmp(m.c_str(), game_selected.c_str()) == 0)
                        break;
                    int_game += 1;
                }
                if (game_selected.empty())
                    return (0);
                game = load_lib(game, ("./games/" + game_selected).c_str());
                create_lib_game = (create_t *)dlsym(game, "create");
                check_lib_create();
                destroy_lib_game = (destroy_t *)dlsym(game, "destroy");
                check_lib_destroy();
                module_game = (IGameModule *)create_lib_game();
                module_game->init_all();
                evt._evtType = Event::NONE;
            }
            if (evt._evtType == Event::O)
            {
                module_game->init_all();
                module_game->init_all();
                module_game->init_all();
            }
            module_game->getevent(evt);
            module->set_map(module_game->getMap());
            module->set_enemy(module_game->getEnemies());
            module->set_bonus(module_game->getBonus());
            module->set_player(module_game->getPlayer());
            module_game->setScore(module->getScore());
            module->display_all();
        }
        destroy_lib_graph(module);
        destroy_lib_game(module_game);
        dlclose(lib);
        dlclose(game);
        return (0);
    }
    else
        return (84);
}
