.global reset // make this reset section global symbol, to be seen later by the linker script

reset:
	ldr sp, =stack_top //load this value in stack pointer register
						// stack_top symbol will be calculated by the linker script 
	bl 	c_is_powerful	// branch label on main
stop: b stop 			// if you get out of main come here