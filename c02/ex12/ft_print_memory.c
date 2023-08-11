/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:35:03 by egualand          #+#    #+#             */
/*   Updated: 2023/07/25 16:10:00 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <string.h>

void	write_character(char c)
{
	write(1, &c, 1);
}

void	print_hexadecimal(char c)
{
	int		negative_char;
	char	hex_digit1;
	char	hex_digit2;

	if (c < 0)
	{
		negative_char = (-128 - (c)) * -1 + 128;
		hex_digit1 = negative_char / 16;
		hex_digit2 = negative_char % 16;
	}
	else
	{
		hex_digit1 = c / 16;
		hex_digit2 = c % 16;
	}
	if (hex_digit1 < 10)
		write_character(hex_digit1 + '0');
	else
		write_character(hex_digit1 + 87);
	if (hex_digit2 < 10)
		write_character(hex_digit2 + '0');
	else
		write_character(hex_digit2 + 87);
}

void	print_memory_address(void *address)
{
	char	address_chars[16];
	long	address_long;
	int		counter;

	address_long = (long)address;
	counter = 0;
	while (address_long > 0)
	{
		address_chars[counter] = address_long % 16;
		if (address_chars[counter] < 10)
			address_chars[counter] += '0';
		else
			address_chars[counter] += 87;
		address_long = address_long / 16;
		counter++;
	}
	while (counter < 16)
	{
		address_chars[counter] = '0';
		counter++;
	}
	while (--counter >= 0)
		write_character(address_chars[counter]);
}

void	print_hex_and_ascii_line(void *address, int size)
{
	int		counter;
	int		spaces_to_print;
	char	*char_address;

	char_address = (char *)address;
	counter = 0;
	while (counter < size)
	{
		print_hexadecimal(char_address[counter++]);
		if (counter % 2 == 0)
			write_character(' ');
	}
	spaces_to_print = ((16 - size) * 2) + (19 - size) / 2;
	while (--spaces_to_print > 0)
		write_character(' ');
	counter = -1;
	while (++counter < size)
	{
		if (char_address[counter] >= 32 && char_address[counter] <= 126)
			write_character(char_address[counter]);
		else
			write_character('.');
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	chars_to_print;
	unsigned int	offset;

	offset = 0;
	while (size > 0)
	{
		if (size >= 16)
		{
			chars_to_print = 16;
			size -= 16;
		}
		else
		{
			chars_to_print = size;
			size = 0;
		}
		print_memory_address(addr + offset);
		write_character(':');
		write_character(' ');
		print_hex_and_ascii_line(addr + offset, chars_to_print);
		write_character('\n');
		offset += 16;
	}
	return (addr);
}

/*int main(void)
{
    char *str = "Bonjour les amis. C'est un test de ft_print_memory!\n";
    ft_print_memory(str, strlen(str));
    return 0;
}*/
