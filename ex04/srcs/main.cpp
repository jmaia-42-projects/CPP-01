/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 07:19:13 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/17 15:02:20 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void	appendNextPattern(std::ifstream &inputFile, std::ofstream &outputFile, std::string &inputFileBuffer, std::string &s1, std::string &s2);
static void	closeFiles(std::ifstream &inputFile, std::ofstream &outputFile);
static bool	isDirectory(char *path);
static int	openFiles(std::string baseName, std::ifstream &inputFile, std::ofstream &outputFile);
static void	replace(std::ifstream &inputFile, std::ofstream &outputFile, std::string s1, std::string s2);

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
	if (av[2][0] == 0)
	{
		std::cerr << "s1 cannot be empty !" << std::endl;
		return (2);
	}
	if (isDirectory(av[1]))
	{
		std::cerr << "filename can't be a directory !" << std::endl;
		return (3);
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

static bool	isDirectory(char *path)
{
	struct stat	statFile;

	stat(path, &statFile);
	return (S_ISDIR(statFile.st_mode));
}

static void	replace(std::ifstream &inputFile, std::ofstream &outputFile, std::string s1, std::string s2)
{
	std::string		inputFileBuffer;
	std::string		line;

	inputFileBuffer = "";
	while (inputFile && outputFile)
		appendNextPattern(inputFile, outputFile, inputFileBuffer, s1, s2);
	outputFile << inputFileBuffer;
}

static void	appendNextPattern(std::ifstream &inputFile, std::ofstream &outputFile, std::string &inputFileBuffer, std::string &s1, std::string &s2)
{
	char	c;

	while (s1.length() != inputFileBuffer.length() && inputFile && !inputFile.eof())
	{
		inputFile.read(&c, 1);
		if (inputFile)
			inputFileBuffer += c;
	}
	if (!inputFile.eof() && inputFile.fail())
		std::cerr << "An error occured while reading file. Exiting..." << std::endl;
	else if (inputFileBuffer == s1)
	{
		outputFile << s2;
		if (outputFile.fail())
		{
			std::cerr << "An error occured while writing file. Exiting..." << std::endl;
			return ;
		}
		inputFileBuffer = "";
	}
	else if (!inputFile.eof())
	{
		outputFile << inputFileBuffer[0];
		if (outputFile.fail())
		{
			std::cerr << "An error occured while writing file. Exiting..." << std::endl;
			return ;
		}
		inputFileBuffer = inputFileBuffer.substr(1);
	}
}

static void	closeFiles(std::ifstream &inputFile, std::ofstream &outputFile)
{
	inputFile.close();
	outputFile.close();
}
