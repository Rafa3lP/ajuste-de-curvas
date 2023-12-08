TARGET=ajusteDeCurva
SRC_DIR=src
LIB_DIR=src/lib
BUILD_DIR=build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
LIBOBJS := $(patsubst $(LIB_DIR)/%.c, $(BUILD_DIR)/%.o, $(wildcard $(LIB_DIR)/*.c))

$(TARGET): $(OBJS) $(BUILD_DIR)/linear_system.a
	gcc $^ -o $@ -lm

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	gcc -c $< -o $@

$(BUILD_DIR)/linear_system.a: $(LIBOBJS)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c $(LIB_DIR)/%.h
	mkdir -p $(dir $@)
	gcc -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: clean