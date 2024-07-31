cmake_minimum_required(VERSION 3.28)
project(Library_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library_Management_System main.cpp
        src/Library.cpp
        include/Library.h
        src/Person.cpp
        include/Person.h
        src/Member.cpp
        include/Member.h
        src/Librarian.cpp
        include/Librarian.h
        src/Book.cpp
        include/Book.h)
