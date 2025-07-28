cmake_minimum_required(VERSION 3.19)
project(recipe_catalog LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets PdfWidgets WebEngineWidgets)

qt_standard_project_setup()

qt_add_executable(recipe_catalog
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(recipe_catalog
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::PdfWidgets
        Qt6::WebEngineWidgets
)

include(GNUInstallDirs)

install(TARGETS recipe_catalog
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET recipe_catalog
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
