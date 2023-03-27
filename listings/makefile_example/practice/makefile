src=$(wildcard *.c ./src/*.c)

obj=$(patsubst %.c, %.o, $(src))
target=calc

include=./include

# $(info $(src) $(obj) $(target) %(include))
$(target):$(obj)
	gcc $^ -o $@
%.o:%.c
	gcc $< -c -I $(include) -o $@ # main.c需要include头文件

.PHONY:clean
clean:
	-rm $(obj) $(target) -f

# gcc $(obj) -o $(target) 


