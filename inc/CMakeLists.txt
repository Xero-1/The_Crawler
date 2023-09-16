add_library(Game SHARED 
	Game.h ${PROJECT_SOURCE_DIR}/src/Game.cpp 
	Character.h ${PROJECT_SOURCE_DIR}/src/Character.cpp 
	Roll.h ${PROJECT_SOURCE_DIR}/src/Roll.cpp 
	Ui.h ${PROJECT_SOURCE_DIR}/src/Ui.cpp
	Post.h ${PROJECT_SOURCE_DIR}/src/Post.cpp
	Menu.h ${PROJECT_SOURCE_DIR}/src/Menu.cpp
	Camera.h ${PROJECT_SOURCE_DIR}/src/Camera.cpp
	Status.h ${PROJECT_SOURCE_DIR}/src/Status.cpp
	Item.h ${PROJECT_SOURCE_DIR}/src/Item.cpp
	Armor.h ${PROJECT_SOURCE_DIR}/src/Armor.cpp
	Weapon.h ${PROJECT_SOURCE_DIR}/src/Weapon.cpp
	Inventory.h ${PROJECT_SOURCE_DIR}/src/Inventory.cpp
	Creature.h ${PROJECT_SOURCE_DIR}/src/Creature.cpp
	Map.h ${PROJECT_SOURCE_DIR}/src/Map.cpp)
target_include_directories(Game PUBLIC ${CMAKE_CURRENT_LIST_DIR})
