AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = slicehack
AM_CPPFLAGS = $(DEPS_CFLAGS)
slicehack_LDADD = $(DEPS_LIBS)
slicehack_SOURCES = \
  main.cpp \
	signal_handlers.cpp \
	\
	logic/game.cpp \
	logic/eventloop.cpp \
	\
	logic/events/event.cpp \
	logic/events/attackevent.cpp \
	logic/events/chatevent.cpp \
	logic/events/itemuseevent.cpp \
	logic/events/moveevent.cpp \
	\
	logic/game_map/gamemap.cpp \
	logic/game_map/gamemapsection.cpp \
	logic/game_map/gamemaprandomizer.cpp \
	logic/game_map/position.cpp \
	\
	logic/game_map/entities/entity.cpp \
	logic/game_map/entities/monster.cpp \
	logic/game_map/entities/player.cpp \
	logic/game_map/entities/entitymanager.cpp \
	logic/game_map/entities/health.cpp \
	\
	logic/game_map/entities/inventory/item.cpp \
	logic/game_map/entities/inventory/itemslot.cpp
