CC = $(shell which g++)

GLOBAL_CPPFLAGS_STR = -D_GNU_SOURCE -DNDEBUG -D__const__= -DBABYLON_DEFINE_EXPECT=0

GLOBAL_CFLAGS_STR := -g -O3 -pipe -W -Wall -Werror -fPIC -mavx -ffast-math -fno-omit-frame-pointer
GLOBAL_CXXFLAGS_STR = $(GLOBAL_CFLAGS_STR)   -ftemplate-backtrace-limit=0 -std=c++11
# GLOBAL_CXXFLAGS_STR = 
GLOBAL_LDFLAGS_STR = -ldl -lz -lpthread -lssl -lcrypto

GLOBAL_INCLUDE_FOLDER = -I. 


# obj_max1 = max1_hpp.o max1_cpp.o
obj_max1 = max1_cpp.o

main_max1:$(obj_max1)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

# hpp is similar to .h, it's not necessary to compile
# max1_hpp.o : max1.hpp
# 	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) -c $^ -o $@

max1_cpp.o : max1.cpp max1.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) -c $< -o $@


.PHONY: clean
clean:
	rm -rf $(obj_max1) main_max1


