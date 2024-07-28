COMPILER=gcc
OBJS=main.c lexer.c token.c parser.c
default: json_parser
json_parser: $(OBJS)
	$(COMPILER) -o main $(OBJS)
