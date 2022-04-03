CC = gcc
# C compilation flags
CFLAGS = -Wall #Warning all, Optimization level 2 

# header files path
INC = -I../App/Inc/

# src files path
SRC_DIR = ../App/Src

# obj files path
OBJ_DIR = .

# Output(Target) file name
TARGET = Dinosaurs

# wildcard 로 SRC_DIR 에서 *.c 로 된 파일들 목록을 뽑아낸 뒤에
# notdir 로 파일 이름만 뽑아낸다.
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))

#SRCS에서 .c를 .o로 대체한다.
OBJS = $(SRCS:.c=.o)
# #SRCS에서 .c를 .d로 대체한다.
# DEPS = $(SRCS:.c=.d)

# OBJS 안의 object 파일들 이름 앞에 $(OBJ_DIR)/ 을 붙인다.
OBJECTS = $(patsubst %.o,$(OBJ_DIR)/%.o,$(OBJS))
# DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

$(OBJECTS) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

#만약 clean 이라는 file이 있을 때 make clean 명령이 clean 파일 build가 아닌 아래 명령을 수행하도록
.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(TARGET)