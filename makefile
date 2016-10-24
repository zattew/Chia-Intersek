compila:
	g++ -o main.x main.C leggi_tss.C leggi_ancore.C scambia.C bubble.C mappa_ancore.C unico.C stampa_ancore.C carica_mappa.C lettura_ancore.C pacman.C mappa_ordinata.C casi_particolari.C leggi_ancore_sox2.C lettura_ancore_sox.C

esegui:
	./main.x crom_coord_ord.txt ancore_left ancore_right
