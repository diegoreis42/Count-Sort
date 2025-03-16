all: 
	@echo "Compiling all sorting files..."
	cd sorting && gcc main_count.c sorting.c -lm -o main_count.out \
				&& gcc main_insertion.c sorting.c -lm -o main_insertion.out \
				&& gcc main_merge.c sorting.c -lm -o main_merge.out \
				&& gcc main_quick.c sorting.c -lm -o main_quick.out

	@echo "Running all sorting files..."
	cd sorting && ./main_count.out \
				&& ./main_merge.out \
				&& ./main_quick.out \
				&& ./main_insertion.out 

clean:
	@echo "Cleaning all sorting files..."
	rm -f sorting/*.out