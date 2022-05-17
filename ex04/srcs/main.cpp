/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 07:19:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/16 18:06:58 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

static int	openFiles(std::string baseName, std::ifstream &inputFile, std::ofstream &outputFile);
static void	closeFiles(std::ifstream &inputFile, std::ofstream &outputFile);

int	main(int ac, char **av)
{
	std::string		baseName;
	int				err;
	std::ifstream	inputFile;
	std::ofstream	outputFile;

	if (ac < 4)
	{
		std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	baseName = av[1];
	err = openFiles(baseName, inputFile, outputFile);
	if (err)
		return (err);
	replace(inputFile, outputFile, std::string(av[2]), std::string(av[3]));
	closeFiles(inputFile, outputFile);
}

static int	openFiles(std::string baseName, std::ifstream &inputFile, std::ofstream &outputFile)
{
	inputFile.open(baseName.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "An error occured while opening file " << baseName << std::endl;
		return (1);
	}
	outputFile.open((baseName + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "An error occured while opening file " << baseName << ".replace" << std::endl;
		inputFile.close();
		return (1);
	}
	return (0);
}

static void	replace(std::ifstream &inputFile, std::ofstream &outputFile, std::string s1, std::string s2)
{
	std::string		line;
	char			*patternPtr;
	char			*cur;

	while (getline(inputFile, line))
	{
		patternPtr = strstr(line, s1);
		cur = line;
		while (cur)
		{
			
		}
	}
}

static void	appendNextPattern(std::ifstream &inputFile, std::ofstream &outputFile, std::string &s1, std::string &s2)
{
	for (int i = 0; s2[i] == s1[i] && s2[i]; i++)
		i++;
	
}

static void	closeFiles(std::ifstream &inputFile, std::ofstream &outputFile)
{
	inputFile.close();
	outputFile.close();
}
