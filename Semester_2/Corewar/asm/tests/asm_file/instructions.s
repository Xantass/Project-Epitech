.name "Abel"
	.comment "L'amer noir."

	sti r1, %:hi, %1

hi:	live %k
	ld %123, r3
	zjmp %:hi
