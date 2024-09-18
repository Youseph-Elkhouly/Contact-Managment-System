myContacts: contactsA2.o readContactsA2.o searchContactsA2.o myContacts.o
	gcc contactsA2.o readContactsA2.o searchContactsA2.o myContacts.o -o bin/myContacts
contactsA2.o: src/contactsA2.c
	gcc -Wall -std=c99 -Iinclude -c src/contactsA2.c -o contactsA2.o
readContactsA2.o: src/readContactsA2.c
	gcc -Wall -std=c99 -Iinclude -c src/readContactsA2.c -o readContactsA2.o
searchContactsA2.o: src/searchContactsA2.c
	gcc -Wall -std=c99 -Iinclude -c src/searchContactsA2.c -o searchContactsA2.o
myContacts.o: bin/myContacts.c
	gcc -Wall -std=c99 -Iinclude -c bin/myContacts.c -o myContacts.o
clean:
	rm -f *.o bin/myContacts

