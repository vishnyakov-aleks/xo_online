cmake_minimum_required(VERSION 3.13)
project(xo_online)

set(CMAKE_CXX_STANDARD 17)

# включаем поиск библиотек с использованием find_package()
# через REQUIRED указываем, что библиотеки обязательны
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)


add_executable(xo_online main.cpp layout/mainmenu/QMainMenuLayout.cpp layout/mainmenu/QMainMenuLayout.h layout/gameboard/BoardController.cpp layout/gameboard/BoardController.h layout/gameboard/BoardLayout.cpp layout/gameboard/BoardLayout.h routing/Router.cpp routing/Router.h routing/IScreen.h layout/mainmenu/MainMenuScreen.cpp layout/mainmenu/MainMenuScreen.h layout/gameboard/BoardScreen.cpp layout/gameboard/BoardScreen.h layout/boardsettings/BoardSettingsLayout.cpp layout/boardsettings/BoardSettingsLayout.h layout/boardsettings/BoardSettingsScreen.cpp layout/boardsettings/BoardSettingsScreen.h layout/boardsettings/BoardSettingsController.cpp layout/boardsettings/BoardSettingsController.h)

# указываем, какие библиотеки необходимо подключить
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)