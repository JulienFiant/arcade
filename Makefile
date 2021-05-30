all:
	@make --no-print-directory -C lib
	@make --no-print-directory -C games
	@make --no-print-directory -C core

clean:
	@make clean  --no-print-directory -C lib
	@make clean  --no-print-directory -C games
	@make clean  --no-print-directory -C core

fclean:
	@make fclean  --no-print-directory -C lib
	@make fclean  --no-print-directory -C games
	@make fclean  --no-print-directory -C core

re:
	@make re  --no-print-directory -C lib
	@make re  --no-print-directory -C games
	@make re  --no-print-directory -C core

core:
	@make re  --no-print-directory -C core

games:
	@make re  --no-print-directory -C games

graphicals:
	@make re  --no-print-directory -C lib

.PHONY: all clean fclean re core games graphicals