CC = $(shell which g++)

GLOBAL_CPPFLAGS_STR = -D_GNU_SOURCE -DNDEBUG -D__const__= -DBABYLON_DEFINE_EXPECT=0

GLOBAL_CFLAGS_STR := -g -O3 -pipe -W -Wall -Werror -fPIC -mavx -ffast-math -fno-omit-frame-pointer
GLOBAL_CXXFLAGS_STR = $(GLOBAL_CFLAGS_STR) -ftemplate-backtrace-limit=0 -std=c++11
# GLOBAL_CXXFLAGS_STR = 
GLOBAL_LDFLAGS_STR = -ldl -lz -lpthread -lssl -lcrypto

GLOBAL_INCLUDE_FOLDER = -I. 

bin_all = main_max1 main_max1_decltypedecay main_max3ref main_stack_1 main_stack_3_default_template_para \
		  main_stack_deduction_test

.PHONY: all
all : $(bin_all)

# obj_max1 = max1_hpp.o max1_cpp.o
obj_max1 = max1_cpp.o

main_max1:$(obj_max1)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

# hpp is similar to .h, it's not necessary to compile
# max1_hpp.o : max1.hpp
# 	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) -c $^ -o $@

$(obj_max1) : max1.cpp max1.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) -c $< -o $@


obj_max1_decltypedecay = max1_decltypedecay.o

main_max1_decltypedecay:$(obj_max1_decltypedecay)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

$(obj_max1_decltypedecay) : max1_decltypedecay.cpp maxdecltypedecay.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) -c $< -o $@

main_max3ref : max3ref.cpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  $^ -o $@

obj_stack_1 = stack1test.o
main_stack_1 : $(obj_stack_1)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

$(obj_stack_1) : stack1test.cpp stack1.hpp stack2.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@

obj_stack_3_default = stack_3_default_para.o
$(obj_stack_3_default) : stack3test.cpp stack3.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@

main_stack_3_default_template_para : $(obj_stack_3_default)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

obj_stack_deduction_test = stack_deduction_test.o
$(obj_stack_deduction_test) : stack_deduction_test.cpp stack_deduction.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@

main_stack_deduction_test : $(obj_stack_deduction_test)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@


.PHONY: clean
clean:
	rm -rf $(obj_max1)
	rm -rf $(obj_max1_decltypedecay)
	rm -rf $(obj_stack_1)
	rm -rf $(obj_stack_3_default)
	rm -rf $(obj_stack_deduction_test)
	rm -rf $(bin_all)
	rm -rf *.dSYM
