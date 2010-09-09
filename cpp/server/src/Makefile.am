AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = sh
AM_CPPFLAGS = $(DEPS_CFLAGS)
sh_LDADD = $(DEPS_LIBS)
sh_SOURCES = \
  main.cpp \
	logic/game.cpp \
	\
	logic/events/event.cpp \
	\
	logic/game_map/position.cpp \
	\
	logic/game_map/entities/entity.cpp \
	logic/game_map/entities/health.cpp
