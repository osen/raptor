cmake_minimum_required(VERSION 2.6)
project(RAPTOR)

include_directories(
  src
)

add_library(raptor
  src/raptor/Application.cpp
  src/raptor/Label.cpp
  src/raptor/TextComponent.cpp
  src/raptor/Component.cpp
  src/raptor/Container.cpp
  src/raptor/Form.cpp
  src/raptor/Button.cpp
  src/raptor/TextBox.cpp
  src/raptor/mongoose.c
  src/raptor/mongoosemm.cpp
  src/raptor/Session.cpp
)

if(WIN32)
  target_link_libraries(raptor)
else()
  target_link_libraries(raptor pthread)
endif()

add_executable(helloworld
  src/helloworld/main.cpp
  src/helloworld/HelloForm.cpp
)

target_link_libraries(helloworld raptor)

add_executable(login
  src/login/main.cpp
  src/login/LoginForm.cpp
)

target_link_libraries(login raptor)

