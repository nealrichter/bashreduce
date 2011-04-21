CFLAGS = -O3 -Wall
OBJS_BRP = brp.o
OBJS_BRM = brm.o
OBJS_BRCAT = brcat.o
HEADERS = brutils.h
LIBS =
TARGET_BRP = brp
TARGET_BRM = brm
TARGET_BRCAT = brcat
BINDIR=/usr/local/bin

all:	$(TARGET_BRP) $(TARGET_BRM) $(TARGET_BRCAT)

$(TARGET_BRP):	$(OBJS_BRP) $(HEADERS)
	$(CC) -o $(TARGET_BRP) $(OBJS_BRP) $(LIBS)

$(TARGET_BRM):	$(OBJS_BRM) $(HEADERS)
	$(CC) -o $(TARGET_BRM) $(OBJS_BRM) $(LIBS)

$(TARGET_BRCAT):	$(OBJS_BRCAT) $(HEADERS)
	$(CC) -o $(TARGET_BRCAT) $(OBJS_BRCAT) $(LIBS) -larchive

clean:
	rm -f $(OBJS_BRP) $(OBJS_BRM) $(OBJS_BRCAT) $(TARGET_BRP) $(TARGET_BRM) $(TARGET_BRCAT)

install: all
	install -c brp $(BINDIR)
	install -c brm $(BINDIR)
	install -c brcat $(BINDIR)

