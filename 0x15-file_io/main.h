#ifndef _MAIN_H_
#define _MAIN_H_

#define MAGIC_NUMBER_LENGTH 16

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int _strlen(char *str);
int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

int main(int argc, char *argv[]);
void print_magic_number(const unsigned char *magic);
void print_error(const char *message);
void check_elf(unsigned char *ident);
void print_magic(unsigned char *ident);
void print_class(unsigned char *ident);
void print_abi(unsigned char *ident);
void print_osabi(unsigned char *ident);
void print_type(unsigned int e_type, unsigned char *ident);
void print_entry(unsigned long int e_entry, unsigned char *ident);
void close_elf(int elf);

#endif
