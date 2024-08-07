(01) +850 INPUT 50          ; Input first number into address 50
(02) +851 INPUT 51          ; Input second number into address 51
(03) +150 LOAD 50           ; Load the value at address 50 into AC
(04) +351 ADD 51            ; Add the value at address 51 to AC
(05) +252 STORE 52          ; Store the result from AC into address 52
(06) +952 OUTPUT 52         ; Output the value stored in address 52
(07) +500 HALT              ; Halt the machine