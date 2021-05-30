/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Main
*/

#include <dlfcn.h>
#include <iostream>
#include "./includes/IDisplayModule.hpp"
#include "./includes/IGameModule.hpp"

int main(int argc, char const *argv[])
{
    void *lib = nullptr;
    void *game = nullptr;
    IDisplayModule *test = nullptr;
    IGameModule *tmp = nullptr;

    lib = dlopen("./lib_arcade_SFML.so", RTLD_LAZY);
    std::cerr << dlerror() << std::endl;
    if (lib != nullptr)
    {
        create_t *create_lib_graph = (create_t *)dlsym(lib, "create");
        const char *dlsym_error = dlerror();
        if (dlsym_error)
        {
            std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
            return 1;
        }
        destroy_t *destroy_lib_graph = (destroy_t *)dlsym(lib, "destroy");
        dlsym_error = dlerror();
        if (dlsym_error)
        {
            std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
            return 1;
        }
        game = dlopen("./Pacman.so", RTLD_LAZY);
        std::cerr << dlerror() << std::endl;
        if (game != nullptr)
        {
            create_t *create_lib_game = (create_t *)dlsym(game, "create");
            const char *dlsym_error = dlerror();
            if (dlsym_error)
            {
                std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
                return 1;
            }
            destroy_t *destroy_lib_game = (destroy_t *)dlsym(game, "destroy");
            dlsym_error = dlerror();
            if (dlsym_error)
            {
                std::cerr << "Cannot load symbol destroy: " << dlsym_error << '\n';
                return 1;
            }

            IDisplayModule *module = (IDisplayModule *)create_lib_graph();
            std::cout << std::endl;

            module_game->setup(module->getName());
            module->InitWindow();
            module->create_perso(module_game->getPng(), module_game->getPos()[0], module_game->getPos()[1]);
            module->create_back(module_game->getBackPng(), module_game->getPosBack()[0], module_game->getPosBack()[1]);

            int evt = 0;
            while ((evt = module->event(evt)) != 1)
            {
                module_game->setPos(module->event_move((int *)module_game->getPos(), evt));
                module->display_all();
            }
            destroy_lib_graph(module);
            destroy_lib_game(module_game);
            dlclose(lib);
            dlclose(game);
            return (0);
        }
        return 1;
    }
    return 1;
}
