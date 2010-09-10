AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = slicehack
AM_CPPFLAGS = $(DEPS_CFLAGS)
slicehack_LDADD = $(DEPS_LIBS)
slicehack_SOURCES = \
  main.cpp \
	logic/game.cpp \
	\
	logic/events/event.cpp \
	\
	logic/game_map/gamemap.cpp \
	logic/game_map/gamemapsection.cpp \
	logic/game_map/position.cpp \
	\
	logic/game_map/entities/entity.cpp \
	logic/game_map/entities/entitymanager.cpp \
	logic/game_map/entities/health.cpp
