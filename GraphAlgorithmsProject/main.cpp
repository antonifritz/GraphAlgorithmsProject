// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Graph.h"
#include <Windows.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

int main()
{
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    int number;
    std::fstream inputDataFile;
    std::string line;
    int numberOfVertexes, numberOfEdges, vertex, destinationVertex, weight;
    
    srand(time(NULL));

    Graph* graph = NULL;

    printf("MENU\n");
    printf("Wybierz problem ktory ma zostac rozwiazany:\n");
    printf("1. Wyznaczanie minimalnego drzewa rozpinajacego MST\n");
    printf("2. Znajdowanie najkrotszych sciezek w grafie\n");
    printf("3. Wyjdz z programu\n");

    std::cin >> number;

    if (number == 1)
    {
        while (true)
        {
            printf("Problem minimalnego drzewa rozpinajacego MST\n\n");
            printf("1. Wczytaj dane z pliku\n");
            printf("2. Wygeneruj graf losowo\n");
            printf("3. Wyswietl graf listowo i macierzowo\n");
            printf("4. Algorytm Prima\n");
            printf("5. Algorytm Kruskala\n");
            printf("6. Przejdz do glownego menu\n");

            std::cin >> number;

            if (number == 1)
            {
                printf("Wczytywanie danych z pliku...\n");

                inputDataFile.open("input_data.txt", std::ios::out | std::ios::in);
                std::string s = "";

                if (inputDataFile.is_open())
                {
                    std::getline(inputDataFile, line);
                    int i = 0;

                    while (line.at(i) != 32)
                    {
                        s.push_back(line.at(i));
                        i++;
                    }
                    
                    numberOfEdges = atoi(s.c_str());
                    s = "";

                    do
                    {
                        i++;
                        s.push_back(line.at(i));

                    } while (i < line.length() - 1);

                    numberOfVertexes = atoi(s.c_str());

                    printf("Liczba krawedzi: %d\nLiczba wierzcholkow: %d\n", numberOfEdges, numberOfVertexes);

                    if (graph != NULL)
                    {
                        graph->~Graph();
                    }

                    graph = new Graph(numberOfEdges, numberOfVertexes);

                    for (int j = 0; j < numberOfEdges; j++)
                    {
                        i = 0;
                        std::getline(inputDataFile, line);
                        s = "";

                        while (line.at(i) != 32)
                        {
                            s.push_back(line.at(i));
                            i++;
                        }

                        vertex = atoi(s.c_str());

                        s = "";
                        i++;

                        while (line.at(i) != 32)
                        {
                            s.push_back(line.at(i));
                            i++;
                        }

                        destinationVertex = atoi(s.c_str());

                        s = "";

                        do
                        {
                            i++;
                            s.push_back(line.at(i));

                        } while (i < line.length() - 1);

                        weight = atoi(s.c_str());

                        graph->edgeArray[j] = new Edge(vertex, destinationVertex, weight);
                    }
                  
                    inputDataFile.close();

                    graph->fillAdjacencyList();
                }

            }

            else if (number == 2)
            {

            }

            else if (number == 3)
            {

            }

            else if (number == 4)
            {
                if (graph != NULL)
                {
                    printf("\nLista sasiedztwa:\n");
                    double interval = 0;
                    QueryPerformanceFrequency(&frequency);
                    QueryPerformanceCounter(&start);

                    graph->primAlgorithmAdjacencyList();

                    QueryPerformanceCounter(&end);
                    interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
                    
                    printf("Czas realizacji algorytmu wyniosl: %f\n", interval);
                    graph->printMST();

                    /*
                    printf("Macierz sasiedztwa:\n");
                    double interval = 0;
                    QueryPerformanceFrequency(&frequency);
                    QueryPerformanceCounter(&start);

                    //graph->primAlgorithmAdjacencyList();

                    QueryPerformanceCounter(&end);
                    interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

                    printf("Czas realizacji algorytmu wyniosl: %f", interval);
                    graph->printMST();
                    */
                }
                else
                {
                    printf("Graf pusty!");
                }
            }

            else if (number == 5)
            {

            }

            else if (number == 6)
            {
                break;
            }

            else
            {
                printf("Podaj prawidlowa wartosc\n");
            }
        }
    }
    else if (number == 2)
    {
        printf("1. Wczytaj dane z pliku\n");
        printf("2. Wygeneruj graf losowo\n");
        printf("3. Wyświetl graf listowo i macierzowo\n");
        printf("4. Algorytm Dijkstry");
        printf("5. Algorytm Bellmana - Forda");
    }
    







    /*
    int numberOfVertexes = 5;
    double sum = 0;
    //std::cout << "Enter number of vertexes: " << std::endl;
    //std::cin >> numberOfVertexes;
    for (int i = 0; i < 20; i++)
    {
        Graph* graph = new Graph(numberOfVertexes);
        graph->generateGraphIndirected(99);
        graph->fillAdjacencyList();
        double interval = 0;
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);

        graph->printAdjacencyList();
        graph->primAlgorithmAdjacencyList();

        QueryPerformanceCounter(&end);
        interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
        sum = sum + interval;
        std::cout <<std::endl<<interval<<std::endl;

        graph->printMST();
    }

    std::cout <<std::endl<< std::endl<<sum;
    */

    return 0;
}

