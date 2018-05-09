CC = gcc
CFLAGS = -Wall -ansi

contactsList : contactsList.o addContacts.o findPosns.o getContactInformation.o getCompanyName.o getEmail.o getFile.o getFirstName.o getLastName.o getPhoneNumber.o removeNewLine.o retrieveContacts.o toAdd.o toRetrieve.o
	$(CC) -o contactsList contactsList.o addContacts.o findPosns.o getContactInformation.o getCompanyName.o getEmail.o getFile.o getFirstName.o getLastName.o getPhoneNumber.o removeNewLine.o retrieveContacts.o toAdd.o toRetrieve.o

contactsList.o : contactsList.c functionDefns.h
	$(CC) $(CFLAGS) -c contactsList.c

getPhoneNumber.o : getPhoneNumber.c functionDefns.h
	$(CC) $(CFLAGS) -c getPhoneNumber.c

addContacts.o : addContacts.c functionDefns.h
	$(CC) $(CFLAGS) -c addContacts.c

findPosns.o : findPosns.c functionDefns.h
	$(CC) $(CFLAGS) -c findPosns.c

getCompanyName.o : getCompanyName.c functionDefns.h
	$(CC) $(CFLAGS) -c getCompanyName.c

getContactInformation.o : getContactInformation.c functionDefns.h
	$(CC) $(CFLAGS) -c getContactInformation.c

getEmail.o : getEmail.c functionDefns.h
	$(CC) $(CFLAGS) -c getEmail.c

removeNewLine.o : removeNewLine.c functionDefns.h
	$(CC) $(CFLAGS) -c removeNewLine.c

toRetrieve.o : toRetrieve.c functionDefns.h
	$(CC) $(CFLAGS) -c toRetrieve.c

toAdd.o : toAdd.c functionDefns.h
	$(CC) $(CFLAGS) -c toAdd.c

getFile.o : getFile.c functionDefns.h
	$(CC) $(CFLAGS) -c getFile.c

getFirstName.o : getFirstName.c functionDefns.h
	$(CC) $(CFLAGS) -c getFirstName.c

getLastName.o : getLastName.c functionDefns.h
	$(CC) $(CFLAGS) -c getLastName.c

retrieveContacts.o : retrieveContacts.c functionDefns.h
	$(CC) $(CFLAGS) -c retrieveContacts.c

clean :
	rm contactsList contactsList.o addContacts.o findPosns.o getContactInformation.o getCompanyName.o getEmail.o getFile.o getFirstName.o getLastName.o getPhoneNumber.o removeNewLine.o retrieveContacts.o toAdd.o toRetrieve.o
