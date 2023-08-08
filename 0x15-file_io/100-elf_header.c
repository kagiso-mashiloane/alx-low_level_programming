#include "main.h"
#include <elf.h>

/**
 * check_elf - check if a header file is an ELF file.
 * @ident: an array containing the ELF magic numbers.
 * Description: If the file is not an ELF file, or on error,
 * exit with status code 98 and display a comprehensive
 * error message to stderr
 */
void check_elf(unsigned char *ident)
{
	int num;

	num = 0;
	while (num < 4)
	{
		if (ident[num] != 127 &&
			ident[num] != 'E' &&
			ident[num] != 'L' &&
			ident[num] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	num++;
	}
}

/**
 * print_magic - the magic numbers of an ELF header.
 * @ident: an array containing the ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *ident)
{
	int num;

	printf("  Magic:   ");

	num = 0;
	while (num < EI_NIDENT)
	{
		printf("%02x", ident[num]);
		if (num == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		num++
	}
}

/**
 * print_class - the class of an ELF header.
 * @ident:  an array containing the ELF class.
 */
void print_class(unsigned char *ident)
{
	printf("  Class:                             ");

	if (ident[EI_CLASS] == ELFCLASSNONE)
		{
			printf("none\n");
		}
		else if (ident[EI_CLASS] == ELFCLASS32)
			{
				printf("ELF32\n");
			}
			else if (ident[EI_CLASS] == ELFCLASS64)
				{
					printf("ELF64\n");
				}
				else
					{
						printf("<unknown: %x>\n", ident[EI_CLASS]);
				}
	}
}

/**
 * print_data - the data of an ELF header.
 * @ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *ident)
{
	printf("  Data:                              ");

if (ident[EI_CLASS] == ELFCLASSNONE)
		{
			printf("none\n");
		}
		else if (ident[EI_CLASS] == ELFDATA2LSB)
			{
				printf("2's complement, little endian\n");
			}
			else if (ident[EI_CLASS] == ELFDATA2MSB)
				{
					printf("2's complement, big endian\n");
				}
				else
					{
						printf("<unknown: %x>\n", e_ident[EI_CLASS]);
				}
	}
}

/**
 * print_version - the version of an ELF header.
 * @ident: an array containing the ELF version.
 */
void print_version(unsigned char *ident)
{
	printf("  Version:                           %d",
		   ident[EI_VERSION]);

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
 * @ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *ident)
{
	printf("  OS/ABI:                            ");

	if (ident[EI_OSABI] == ELFCLASSNONE)
		{
			printf("UNIX - System V\n");
		}
		else if (ident[EI_OSABI] == ELFOSABI_HPUX)
			{
				printf("UNIX - HP-UX\n");
			}
			else if (ident[EI_OSABI] == ELFOSABI_NETBSD)
				{
					printf("UNIX - NetBSD\n");
				}
				else if (ident[EI_OSABI] == ELFOSABI_LINUX)
					{
						printf("UNIX - Linux\n");
					}
					else if (ident[EI_OSABI] == ELFOSABI_SOLARIS)
					{
						printf("UNIX - Solaris\n");
					}
					else if (ident[EI_OSABI] == ELFOSABI_IRIX)
					{
						printf("UNIX - IRIX\n");
					}
					else if (ident[EI_OSABI] == ELFOSABI_FREEBSD)
					{
						printf("UNIX - FreeBSD\n");
					}
					else if (ident[EI_OSABI] == ELFOSABI_TRU64)
					{
						printf("UNIX - TRU64\n");
					}
					else if (ident[EI_OSABI] == ELFOSABI_ARM)
					{
						printf("ARM\n");
					}
					else if (ident[EI_OSABI] == ELFOSABI_STANDALON)
					{
						printf("Standalone App\n");
					}
					else
						{
							printf("<unknown: %x>\n", e_ident[EI_OSABI]);
						}
	}
}

/**
 * print_abi - ABI version of an ELF header.
 * @ident:  an array containing the ELF ABI version.
 */
void print_abi(unsigned char *ident)
{
	printf("  ABI Version:                       %d\n",
		   ident[EI_ABIVERSION]);
}

/**
 * print_type -  the type of an ELF header.
 * @e_type: The ELF type.
 * @ident:  an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *ident)
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
 * @ident: an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *ident)
{
	printf("  Entry point address:               ");

	if (ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (ident[EI_CLASS] == ELFCLASS32)
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

	check_elf(header->ident);
	printf("ELF Header:\n");
	print_magic(header->ident);
	print_class(header->ident);
	print_data(header->ident);
	print_version(header->ident);
	print_osabi(header->ident);
	print_abi(header->ident);
	print_type(header->e_type, header->ident);
	print_entry(header->e_entry, header->ident);

	free(header);
	close_elf(k);
	return (0);
}
