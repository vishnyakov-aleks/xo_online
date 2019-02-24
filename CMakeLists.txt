cmake_minimum_required(VERSION 3.13)
project(xo_online)

set(CMAKE_CXX_STANDARD 17)

# включаем поиск библиотек с использованием find_package()
# через REQUIRED указываем, что библиотеки обязательны
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)


add_executable(xo_online main.cpp layout/mainmenu/QMainMenuLayout.cpp layout/mainmenu/QMainMenuLayout.h layout/gameboard/BoardController.cpp layout/gameboard/BoardController.h layout/gameboard/BoardLayout.cpp layout/gameboard/BoardLayout.h routing/Router.cpp routing/Router.h routing/IScreen.h routing/MainMenuScreen.cpp routing/MainMenuScreen.h routing/BoardScreen.cpp routing/BoardScreen.h layout/gamesettings/BoardSettingsLayout.cpp layout/gamesettings/BoardSettingsLayout.h routing/BoardSettingsScreen.cpp routing/BoardSettingsScreen.h)

# указываем, какие библиотеки необходимо подключить
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)