# version1
# # 这是一个规则，普通写法 
# calc:add.o  div.o  main.o  mult.o  sub.o
#         gcc  add.o  div.o  main.o  mult.o  sub.o -o calc

# version1版本的优点：书写简单
# 这版本的缺点：只要依赖中的某一个源文件被修改，所有的源文件都需要被重新编译，太耗时、效率低
# 改进方式：提高效率，修改哪一个源文件，哪个源文件被重新编译，不修改就不重新编译

# version2
# 这是一个规则，里边使用了自定义变量
# 使用自动变量, 替换相关的内容
# calc:add.o  div.o  main.o  mult.o  sub.o
# 	gcc $^ -o $@ 			# 自动变量只能在规则的命令中使用 $@表示目标，$^表示依赖列表add.o  div.o  main.o  mult.o  sub.o。



# version3
# # 这是一个规则，里边使用了自定义变量和预定义变量 变量用$(var_name)表示
# obj=add.o  div.o  main.o  mult.o  sub.o
# target=calc
# CFLAGS=-O3 # 代码优化
# $(target):$(obj)
# 	$(CC)  $(obj) -o $(target) $(CFLAGS) # CC是c语言编译器 CXX是C++编译器

# version4
# 可以单独编译add.o div.o等

# calc:add.o  div.o  main.o  mult.o  sub.o
# 	gcc  add.o  div.o  main.o  mult.o  sub.o -o calc
# # 语法格式重复的规则, 将 .c -> .o, 使用的命令都是一样的 gcc *.c -c
# add.o:add.c
# 	gcc add.c -c

# div.o:div.c
# 	gcc div.c -c

# main.o:main.c
# 	gcc main.c -c

# sub.o:sub.c
# 	gcc sub.c -c

# mult.o:mult.c
# 	gcc mult.c -c

# version5
# 模式匹配 -> 通过一个公式, 代表若干个满足条件的规则
# 依赖有一个, 后缀为.c, 生成的目标是一个 .o 的文件, % 是一个通配符, 匹配的是文件名 
# 这里%.o:%.c其实被执行了5次

# calc:add.o  div.o  main.o  mult.o  sub.o
# 	gcc  add.o  div.o  main.o  mult.o  sub.o -o calc

# %.o:%.c
# 	gcc $< -c # 表示依赖项中第一个依赖文件的名称

# version5版本的优点：文件精简不少，变得简洁了
# 这个版本的缺点：变量 obj 的值需要手动的写出来，如果需要编译的项目文件很多，都用手写出来不现实
# 改进方式：在 makefile 中使用函数


# version6 
# 添加自定义变量 -> makefile中注释前 使用 # 
# 使用函数搜索当前目录下的源文件 .c
# src=$(wildcard *.c)
# # 将源文件的后缀替换为 .o
# # % 匹配的内容是不能被替换的, 需要替换的是第一个参数中的后缀, 替换为第二个参数中指定的后缀
# # obj=$(patsubst %.cpp, %.o, $(src)) 将src中的关键字 .cpp 替换为 .o
# obj=$(patsubst %.c, %.o, $(src))
# target=calc

# $(target):$(obj)
# 	gcc $(obj)  -o $(target)

# %.o:%.c
# 	gcc $< -c

# version6这个版本的优点：解决了自动加载项目文件的问题，解放了双手
# 这个版本的缺点：没有文件删除的功能，不能删除项目编译过程中生成的目标文件（*.o）和可执行程序
# 改进方式：在 makefile 文件中添加新的规则用于删除生成的目标文件（*.o）和可执行程序



# 添加自定义变量 -> makefile中注释前 使用 # 
# 使用函数搜索当前目录下的源文件 .c
src=$(wildcard *.c)
# 将源文件的后缀替换为 .o
obj=$(patsubst %.c, %.o, $(src))
target=calc

$(target):$(obj)
	gcc $(obj)  -o $(target)

%.o:%.c
	gcc $< -c

# 添加规则, 删除生成文件 *.o 可执行程序
# 声明clean为伪文件 防止有一个目标文件叫clean造成冲突
.PHONY:clean
clean:
# shell命令前的 - 表示强制这个指令执行, 如果执行失败也不会终止
	-rm $(obj) $(target) 
	echo "hello, 我是测试字符串"

