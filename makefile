
run: a.out in
	@ echo ------ input -------
	@ tee  < in
	@ echo ------ output -------
	@./a.out <in
