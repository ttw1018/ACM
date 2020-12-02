
run: a.out in
	@ echo ------ input -------
	@ tee  < in
	@ echo
	@ echo ------ output -------
	@ ./a.out <in
