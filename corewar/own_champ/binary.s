.name "Binary"
.comment "attacking the DNA"

entree:
        ld %0, r5
        fork %:survive_entree
        st r1, 6
        live %7
        lfork %899
        sti r1, %:damage, %1
        ld %9000, r11
        fork %:damage
        sti r5, %:entree , %0
        sti r1, %:repeat, %1
repeat:
        live %7
        ld %0, r5
        zjmp %:repeat

survive_entree:
        sti r1, %:survive, %1

survive:
        live %7
        ld %0, r5
        zjmp %:survive

damage:
        live %7
        ld %:kill, r6
        ld %10, r7
        ld %20, r9
        add r6, r7, r6
        sti r1, %:kill, %1
        fork %:kill
        st r1, 6
        live %7
        ld %0, r5
        zjmp %:damage
kill:
        live %7
        add r6, r9, r6
        sti r11, r6, %1
        st r11, 30
        ld %0, r12
        zjmp %:kill

