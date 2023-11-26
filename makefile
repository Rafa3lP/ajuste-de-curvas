TARGET=prog

$(TARGET): main.o linear_system.a
	gcc $^ -o $@

main.o: src/main.c
	gcc -c $< -o $@

linear_system.a: linear_system.o
	ar rcs $@ $^

linear_system.o: src/lib/linear_system.c src/lib/linear_system.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)