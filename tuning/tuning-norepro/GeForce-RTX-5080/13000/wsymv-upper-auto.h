int done = 0;
switch (BLK) {
#if __KERNEL1
case 1:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL11
case 11:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL21
case 21:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL31
case 31:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL41
case 41:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL51
case 51:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL61
case 61:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL71
case 71:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL81
case 81:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL91
case 91:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 1, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL101
case 101:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL111
case 111:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL121
case 121:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL131
case 131:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL141
case 141:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL151
case 151:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL161
case 161:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL171
case 171:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL181
case 181:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL191
case 191:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 2, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL201
case 201:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL211
case 211:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL221
case 221:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL231
case 231:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL241
case 241:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL251
case 251:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL261
case 261:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL271
case 271:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL281
case 281:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL291
case 291:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 3, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL301
case 301:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL311
case 311:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL321
case 321:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL331
case 331:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL341
case 341:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL351
case 351:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL361
case 361:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL371
case 371:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL381
case 381:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL391
case 391:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 4, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL401
case 401:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL411
case 411:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL421
case 421:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL431
case 431:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL441
case 441:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL451
case 451:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL461
case 461:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL471
case 471:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL481
case 481:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL491
case 491:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 5, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL501
case 501:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL511
case 511:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL521
case 521:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL531
case 531:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL541
case 541:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL551
case 551:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL561
case 561:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL571
case 571:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL581
case 581:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL591
case 591:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 6, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL601
case 601:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL611
case 611:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL621
case 621:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL631
case 631:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL641
case 641:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL651
case 651:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL661
case 661:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL671
case 671:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL681
case 681:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL691
case 691:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 7, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL701
case 701:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL711
case 711:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL721
case 721:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL731
case 731:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL741
case 741:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL751
case 751:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL761
case 761:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL771
case 771:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL781
case 781:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL791
case 791:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 8, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL801
case 801:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL811
case 811:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL821
case 821:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL831
case 831:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL841
case 841:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL851
case 851:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL861
case 861:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL871
case 871:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL881
case 881:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL891
case 891:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 9, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL901
case 901:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL911
case 911:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL921
case 921:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL931
case 931:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL941
case 941:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL951
case 951:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL961
case 961:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL971
case 971:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL981
case 981:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL991
case 991:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 10, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1001
case 1001:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1011
case 1011:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1021
case 1021:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1031
case 1031:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1041
case 1041:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1051
case 1051:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1061
case 1061:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1071
case 1071:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1081
case 1081:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1091
case 1091:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 11, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1101
case 1101:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1111
case 1111:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1121
case 1121:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1131
case 1131:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1141
case 1141:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1151
case 1151:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1161
case 1161:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1171
case 1171:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1181
case 1181:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1191
case 1191:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 12, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1201
case 1201:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1211
case 1211:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1221
case 1221:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1231
case 1231:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1241
case 1241:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1251
case 1251:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1261
case 1261:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1271
case 1271:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1281
case 1281:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1291
case 1291:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 13, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1301
case 1301:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1311
case 1311:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1321
case 1321:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1331
case 1331:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1341
case 1341:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1351
case 1351:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1361
case 1361:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1371
case 1371:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1381
case 1381:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1391
case 1391:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 14, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1401
case 1401:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1411
case 1411:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1421
case 1421:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1431
case 1431:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1441
case 1441:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1451
case 1451:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1461
case 1461:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1471
case 1471:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1481
case 1481:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1491
case 1491:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 15, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1501
case 1501:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1511
case 1511:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1521
case 1521:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1531
case 1531:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1541
case 1541:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1551
case 1551:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1561
case 1561:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1571
case 1571:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1581
case 1581:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1591
case 1591:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 16, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1601
case 1601:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1611
case 1611:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1621
case 1621:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1631
case 1631:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1641
case 1641:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1651
case 1651:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1661
case 1661:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1671
case 1671:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1681
case 1681:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1691
case 1691:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 17, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1701
case 1701:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1711
case 1711:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1721
case 1721:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1731
case 1731:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1741
case 1741:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1751
case 1751:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1761
case 1761:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1771
case 1771:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1781
case 1781:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1791
case 1791:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 18, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1801
case 1801:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1811
case 1811:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1821
case 1821:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1831
case 1831:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1841
case 1841:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1851
case 1851:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1861
case 1861:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1871
case 1871:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1881
case 1881:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1891
case 1891:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 19, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1901
case 1901:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1911
case 1911:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1921
case 1921:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1931
case 1931:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1941
case 1941:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1951
case 1951:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1961
case 1961:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1971
case 1971:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1981
case 1981:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL1991
case 1991:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 20, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2001
case 2001:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2011
case 2011:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2021
case 2021:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2031
case 2031:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2041
case 2041:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2051
case 2051:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2061
case 2061:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2071
case 2071:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2081
case 2081:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2091
case 2091:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 21, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2101
case 2101:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2111
case 2111:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2121
case 2121:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2131
case 2131:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2141
case 2141:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2151
case 2151:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2161
case 2161:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2171
case 2171:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2181
case 2181:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2191
case 2191:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 22, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2201
case 2201:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2211
case 2211:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2221
case 2221:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2231
case 2231:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2241
case 2241:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2251
case 2251:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2261
case 2261:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2271
case 2271:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2281
case 2281:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2291
case 2291:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 23, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2301
case 2301:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2311
case 2311:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2321
case 2321:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2331
case 2331:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2341
case 2341:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2351
case 2351:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2361
case 2361:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2371
case 2371:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2381
case 2381:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2391
case 2391:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 24, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2401
case 2401:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2411
case 2411:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2421
case 2421:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2431
case 2431:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2441
case 2441:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2451
case 2451:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2461
case 2461:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2471
case 2471:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2481
case 2481:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2491
case 2491:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 25, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2501
case 2501:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2511
case 2511:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2521
case 2521:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2531
case 2531:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2541
case 2541:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2551
case 2551:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2561
case 2561:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2571
case 2571:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2581
case 2581:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2591
case 2591:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 26, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2601
case 2601:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2611
case 2611:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2621
case 2621:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2631
case 2631:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2641
case 2641:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2651
case 2651:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2661
case 2661:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2671
case 2671:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2681
case 2681:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2691
case 2691:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 27, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2701
case 2701:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2711
case 2711:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2721
case 2721:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2731
case 2731:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2741
case 2741:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2751
case 2751:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2761
case 2761:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2771
case 2771:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2781
case 2781:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2791
case 2791:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 28, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2801
case 2801:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2811
case 2811:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2821
case 2821:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2831
case 2831:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2841
case 2841:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2851
case 2851:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2861
case 2861:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2871
case 2871:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2881
case 2881:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2891
case 2891:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 29, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2901
case 2901:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2911
case 2911:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2921
case 2921:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2931
case 2931:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2941
case 2941:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2951
case 2951:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2961
case 2961:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2971
case 2971:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2981
case 2981:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL2991
case 2991:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 30, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3001
case 3001:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3011
case 3011:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3021
case 3021:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3031
case 3031:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3041
case 3041:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3051
case 3051:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3061
case 3061:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3071
case 3071:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3081
case 3081:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3091
case 3091:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 31, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3101
case 3101:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 0 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3111
case 3111:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 10 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3121
case 3121:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 20 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3131
case 3131:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 30 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3141
case 3141:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 40 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3151
case 3151:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 50 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3161
case 3161:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 60 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3171
case 3171:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 70 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3181
case 3181:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 80 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
#if __KERNEL3191
case 3191:
done = 
	API_private(HESYMVu_ATOMIC__host) < GPU_ARCH, scalar_t, BLOCK_SIZE, GY2D, VX, UX, 32, 90 >
	( n, a, lda, x, incx, y, incy, alpha, beta ); break;
#endif
default:
	fprintf( stderr, "Not proper Parameter %d ", BLK );
	break;
}
if ( ! done ) {
	perror( "Incorrect kernel ID has been specified." );
	exit(1);
}
