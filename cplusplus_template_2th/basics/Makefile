CC = $(shell which g++)

GLOBAL_CPPFLAGS_STR = -D_GNU_SOURCE -DNDEBUG -D__const__= -DBABYLON_DEFINE_EXPECT=0

GLOBAL_CFLAGS_STR := -g -O3 -pipe -W -Wall -Werror -fPIC -mavx -ffast-math -fno-omit-frame-pointer
GLOBAL_CXXFLAGS_STR = $(GLOBAL_CFLAGS_STR) -ftemplate-backtrace-limit=0 -std=c++17
# GLOBAL_CXXFLAGS_STR = 
GLOBAL_LDFLAGS_STR = -ldl -lz -lpthread -lssl -lcrypto

GLOBAL_INCLUDE_FOLDER = -I. 

bin_all = main_max1 main_max1_decltypedecay main_max3ref main_stack_1 main_stack_3_default_template_para \
		  main_move2 main_stack9template_template_param  main_array main_lesstest \
		  main_vartemplate main_varindices main_forthermoreprint main_foldtraverse main_print_addspace main_stack_deduction_test main_stack_nontype_auto  # c++17

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

obj_stack_nontype_auto = stack_nontype_auto.o
$(obj_stack_nontype_auto) : stackauto.cpp stackauto.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@
main_stack_nontype_auto : $(obj_stack_nontype_auto)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

obj_print_addspace = print_addspace.o
# $(obj_print_addspace) : varprint.cpp addspace.hpp
$(obj_print_addspace) : varprint.cpp varprint2.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@
main_print_addspace : $(obj_print_addspace)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

obj_foldtraverse = foldtraverse.o
$(obj_foldtraverse) : foldtraverse.cpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@
main_foldtraverse : $(obj_foldtraverse)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

obj_forthermoreprint = forthermoreprint.o
$(obj_forthermoreprint) : forthermoreprint_test.cpp forthermoreprint.hpp addspace.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@
main_forthermoreprint : $(obj_forthermoreprint)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

obj_varindices = varindices.o
$(obj_varindices) : varindices.cpp varindices.hpp addspace.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@
main_varindices : $(obj_varindices)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

obj_lesstest = lesstest.o
$(obj_lesstest) : lesstest.cpp lessarray.hpp lessstring.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@
main_lesstest : $(obj_lesstest)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

obj_arrays = arrays.o
$(obj_arrays) : arrays.cpp arrays.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@
main_array : $(obj_arrays)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

main_stack9template_template_param : stack9test.cpp stack9.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $< -o $@

obj_vartemplate = vartemplate.o
$(obj_vartemplate) : vartemplate.cpp vartemplate.hpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@
main_vartemplate : $(obj_vartemplate)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

obj_move2 = move2.o
$(obj_move2) : move2.cpp
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER)  -c $< -o $@
main_move2 : $(obj_move2)
	$(CC) $(GLOBAL_CXXFLAGS_STR) $(GLOBAL_INCLUDE_FOLDER) $^ -o $@

.PHONY: clean clean_bin
clean:
	rm -rf $(obj_max1)
	rm -rf $(obj_max1_decltypedecay)
	rm -rf $(obj_stack_1)
	rm -rf $(obj_stack_3_default)
	rm -rf $(obj_stack_deduction_test)
	rm -rf $(obj_stack_nontype_auto)
	rm -rf $(obj_print_addspace) $(obj_foldtraverse)
	rm -rf $(obj_arrays) $(obj_forthermoreprint) $(obj_lesstest) $(obj_varindices)
	rm -rf $(obj_vartemplate)
	rm -rf $(obj_move2)
	rm -rf *.dSYM

clean_bin:
	rm -rf $(bin_all)
