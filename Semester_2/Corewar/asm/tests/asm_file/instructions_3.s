.name "Abel"
	.comment "L'amer noir."

	sti r1, %:hi, %1

hi:     live %234
	ld %0, r-3
	zjmp %:hi
