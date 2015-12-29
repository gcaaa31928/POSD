cmake_minimum_required(VERSION 3.3)
project(Visitor1013_2015)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set (CMAKE_PREFIX_PATH "F:\\Qt\\5.5\\mingw492_32\\")
find_package(Qt5Widgets)
set(SOURCE_FILES
    AreaVisitor.h
    Circle.cpp
    Circle.h
    CompositeGraphics.cpp
    CompositeGraphics.h
    Graphics.h
    main.cpp
    Rectangle.cpp
    Rectangle.h
    Shape.h
    SimpleGraphics.cpp
    SimpleGraphics.h
    Square.cpp
    Square.h
    util.cpp
    util.h GraphicsVisitor.cpp GraphicsVisitor.h DescriptionVisitor.cpp DescriptionVisitor.h
    GraphicsFactory.h GraphicsFactory.cpp utHW3.h Gui.cpp Gui.h Painter.cpp Painter.h utHW4.h PaintVisitor.cpp PaintVisitor.h GraphicsItemFactory.cpp GraphicsItemFactory.h CirclePainter.cpp CirclePainter.h RectanglePainter.cpp RectanglePainter.h SquarePainter.cpp SquarePainter.h CommandManager.cpp CommandManager.h Command.cpp Command.h AddCommand.cpp AddCommand.h Model.cpp Model.h MoveCommand.cpp MoveCommand.h GroupCommand.cpp GroupCommand.h UngroupCommand.cpp UngroupCommand.h DeleteCommand.cpp DeleteCommand.h CustomScene.cpp CustomScene.h MoveUpCommand.cpp MoveUpCommand.h Graphics.cpp MoveDownCommand.cpp MoveDownCommand.h Observer.cpp Observer.h Subject.cpp Subject.h Views.cpp Views.h Controller.cpp Controller.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(Visitor1013_2015 ${SOURCE_FILES})
target_link_libraries(Visitor1013_2015 Qt5::Widgets Qt5::Core Qt5::Gui)
target_link_libraries(Visitor1013_2015
        ${CMAKE_CURRENT_SOURCE_DIR}/cppunitlite/cppunitlite.a
)