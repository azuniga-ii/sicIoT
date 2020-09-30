LEX = flex
YACC = bison 
CXX = g++
CXXFLAGS = `pkg-config libgvc --cflags`
LDLIBS = `pkg-config libgvc --libs`


sicIoT: sicIoT.cc grm.tab.o lex.o node.o tvisitor.o 
	$(CXX) -o sicIoT sicIoT.cc grm.tab.o lex.o node.o tvisitor.o $(CXXFLAGS) $(LDLIBS)

grm.tab.cc: grm.yy
	$(YACC) grm.yy

grm.tab.o: grm.tab.cc tbder.h tvisitor.h
	$(CXX) -c grm.tab.cc $(CXXFLAGS)

lex.c: lex.l
	$(LEX) lex.l

lex.o: lex.c grm.tab.hh
	$(CXX) -c lex.c

node.o: node.cc node.h tvisitor.h
	$(CXX) -c node.cc $(CXXFLAGS)

tvisitor.o: tvisitor.cc tvisitor.h
	$(CXX) -c tvisitor.cc $(CXXFLAGS)


check: sicIoT tests/*.nl
	for i in tests/*.nl; do  \
		echo "Compiling " $$i; \
		./sicIoT -tree $$i -o $${i%.nl}.c ; \
	done


tinstall: check
	cd tests; for i in *.c; do \
		echo "Installing program" $$i "in contiki exsicIoT directory"; \
		mkdir -p ../contiki/exsicIoT/$${i%.c}; \
		printf "CONTIKI_PROJECT = $${i%.c}\nall: \$$(CONTIKI_PROJECT)\n\nCONTIKI = ../..\nCONTIKI_WITH_RIME = 1\ninclude \$$(CONTIKI)/Makefile.include" > ../contiki/exsicIoT/$${i%.c}/Makefile; \
		mv $$i ../contiki/exsicIoT/$${i%.c}; \
	done; \
	cd ..;
	mkdir -p contiki-ng/exsicIoT; \
	mv contiki/exsicIoT/send_messages_periodically/ contiki-ng/exsicIoT/; \
	mv contiki/exsicIoT/receive_messages_and_reply/ contiki-ng/exsicIoT/
.PHONY: clean

cctc: tinstall
	cd contiki/exsicIoT; for i in *; do \
	echo "Compiling" $$i "using Contiki toolchain"; \
	cd $$i; make TARGET=sky; \
	cd ..;  \
	done; \
	cd ../..; \
	cd contiki-ng/exsicIoT/send_messages_periodically; \
	echo "Compiling send_messages_periodically using Contiki-NG toolchain"; \
	make TARGET=sky; \
	cd ../receive_messages_and_reply;  \
	echo "Compiling receive_messages_and_reply using Contiki-NG toolchain"; \
	make BOARD=launchpad/cc2650 TARGET=cc26x0-cc13x0

clean:
	rm -f lex.c lex.h grm.tab.cc grm.tab.hh stack.hh grm.tab.cc *.o tests/*.c tests/*.png -r contiki/exsicIoT contiki-ng/exsicIoT sicIoT
