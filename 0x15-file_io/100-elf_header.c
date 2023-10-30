#include "main.h"
#include <elf.h>

/**
 * check_elf - check if a header file is an ELF file.
 * @e_ident: an array containing the ELF magic numbers.
 * Description: If the file is not an ELF file, or on error,
 * exit with status code 98 and display a comprehensive
 * error message to stderr
 */
void check_elf(unsigned char *e_ident)
{
	int num;

	num = 0;
	while (num < 4)
	{
		if (e_ident[num] != 127 &&
			e_ident[num] != 'E' &&
			e_ident[num] != 'L' &&
			e_ident[num] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	num++;
	}
}

/**
 * print_magic - the magic numbers of an ELF header.
 * @e_ident: an array containing the ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int num;

	printf("  Magic:   ");

	num = 0;
	while (num < EI_NIDENT)
	{
		printf("%02x", e_ident[num]);
		if (num == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		num++;
	}
}

/**
 * print_class - the class of an ELF header.
 * @e_ident:  an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	if (e_ident[EI_CLASS] == ELFCLASSNONE)
		{
			printf("none\n");
		}
		else if (e_ident[EI_CLASS] == ELFCLASS32)
			{
				printf("ELF32\n");
			}
			else if (e_ident[EI_CLASS] == ELFCLASS64)
				{
					printf("ELF64\n");
				}
				else
					{
					printf("<unknown: %x>\n", e_ident[EI_CLASS]);
					}
}

/**
 * print_data - the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

if (e_ident[EI_CLASS] == ELFCLASSNONE)
		{
			printf("none\n");
		}
		else if (e_ident[EI_CLASS] == ELFDATA2LSB)
			{
				printf("2's complement, little endian\n");
			}
			else if (e_ident[EI_CLASS] == ELFDATA2MSB)
				{
					printf("2's complement, big endian\n");
				}
				else
					{
					printf("<unknown: %x>\n", e_ident[EI_CLASS]);
					}
}

/**
 * print_version - the version of an ELF header.
 * @e_ident: an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
		   e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
		{
			printf(" (current)\n");
		}
			else
				{
					printf("\n");
				}
}

/**
 * print_osabi -the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	if (e_ident[EI_OSABI] == ELFCLASSNONE)
		{
			printf("UNIX - System V\n");
		}
		else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
			{
				printf("UNIX - HP-UX\n");
			}
			else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
				{
					printf("UNIX - NetBSD\n");
				}
				else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
					{
						printf("UNIX - Linux\n");
					}
					else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
					{
						printf("UNIX - Solaris\n");
					}
					else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
					{
						printf("UNIX - IRIX\n");
					}
					else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
					{
						printf("UNIX - FreeBSD\n");
					}
					else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
					{
						printf("UNIX - TRU64\n");
					}
					else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
					{
						printf("ARM\n");
					}
					else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
					{
						printf("Standalone App\n");
					}
					else
						{
							printf("<unknown: %x>\n", e_ident[EI_OSABI]);
						}
}

/**
 * print_abi - ABI version of an ELF header.
 * @e_ident:  an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * print_type -  the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident:  an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                              ");

	if (e_type == ET_NONE)
		{
			printf("NONE (None)\n");
		}
		else if (e_type == ET_REL)
			{
				printf("REL (Relocatable file)\n");
			}
			else if (e_type == ET_EXEC)
				{
					printf("EXEC (Executable file)\n");
				}
				else if (e_type == ET_DYN)
				{
					printf("DYN (Shared object file)\n");
				}
				else if (e_type == ET_CORE)
				{
					printf("CORE (Core file)\n");
				}
					else
						{
							printf("<unknown: %x>\n", e_type);
						}
}

/**
 * print_entry -  the entry point of an ELF header.
 * @e_entry: address of the ELF entry point.
 * @e_ident: an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: file descriptor of the ELF file.
 * Description: file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - information displayed in the ELF header
 *        at the start of an ELF file.
 * @argc: arguments number supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return:return 0 on success.
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int k, j;

	k = open(argv[1], O_RDONLY);
	if (k == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(k);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	j = read(k, header, sizeof(Elf64_Ehdr));
	if (j == -1)
	{
		free(header);
		close_elf(k);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(k);
	return (0);
}
