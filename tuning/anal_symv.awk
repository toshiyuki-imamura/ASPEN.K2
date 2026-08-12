function print_out() {
	BASE=UX/VX;
	if ( 1 ) { # || OK[BASE" "_M_] != 0 ) {
		err=0;
		for(j=0;j<i;j++) if(line[j]~/ERR/)err=1;
		for(j=0;j<i;j++) if(line[j]~/cannot/)err=1;
		if ( err == 0 ) {
			for(j=0;j<i;j++) {
				split(line[j], a);
				printf("%s %d %08d %3d %d %2d %d %d %d\n",
					a[1], a[2], int(a[5]*1000),
					BLOCK_SIZE, VX, UX, MULTI, _M_, GY);
			}
			print "EOR";
		}
	} else {
		print "*** SAME PATTERN: "BLOCK" "VX" "UX" "MULTI" "_M_" "GY;
	}
}

BEGIN{
        flag=0;
	if ( 0 ) {
	while ( 1 ) {
		j = getline < "OK-pat-symv"
		if ( j <= 0 ) break;
		OK[$0] = 1;
	}
	}
	i=0;
}
/#define/{
        if ( flag == 1 ) {
		print_out();
                flag=0;
        }
	if ( $0~/N=/ ) gsub(/N= [0-9]* /,"");
        if ( $0~/BLOCK_SIZE/ ) BLOCK_SIZE=$3;
        if ( $0~/VX/ ) VX = $3;
        if ( $0~/UX/ ) UX = $3;
        if ( $0~/MULTIPLICITY/ ) MULTI=$3;
        if ( $0~/_M_/ ) _M_=$3;
        if ( $0~/GY/ ) GY=$3;
        i=0;
}
/N= /{
        line[i++] = $0; flag=1;
}
END{
	print_out();
}

