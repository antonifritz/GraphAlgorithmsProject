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
    int number, number2, number3, number4;
    std::fstream inputDataFile;
    std::string line;
    std::string s = "";
    int numberOfVertexes, numberOfEdges, vertex, destinationVertex, weight;
    
    srand(time(NULL));

    Graph* graph = NULL;

    printf("MENU\n");
    printf("Wybierz problem ktory ma zostac rozwiazany:\n");
    printf("1. Wyznaczanie minimalnego drzewa rozpinajacego MST\n");
    printf("2. Znajdowanie najkrotszych sciezek w grafie\n");
    printf("3. Testuj automatycznie\n");
    printf("4. Wyjdz z programu\n");

    std::cin >> number;

    if (number == 1)
    {
        while (true)
        {
            printf("\nProblem minimalnego drzewa rozpinajacego MST\n\n");
            printf("1. Wczytaj dane z pliku\n");
            printf("2. Wygeneruj graf losowo\n");
            printf("3. Wyswietl graf listowo i macierzowo\n");
            printf("4. Algorytm Prima\n");
            printf("5. Algorytm Kruskala\n");
            printf("6. Przejdz do glownego menu\n");

            std::cin >> number;

            if (number == 1)
            {
                if (graph != NULL)
                {
                    printf("Usuwanie grafu...\n");
                    graph->~Graph();
                }

                printf("Wczytywanie danych z pliku...\n");

                inputDataFile.open("input_data.txt", std::ios::out | std::ios::in);               

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

                    graph->fillAdjacencyMatrixIndirected();
                    graph->fillAdjacencyListIndirected();
                }

            }

            else if (number == 2)
            {
                if (graph != NULL)
                {
                    printf("Usuwanie grafu...\n");
                    graph->~Graph();
                    graph = NULL;
                }

                printf("Podaj liczbe wierzcholkow:\n");
                std::cin >> number;

                graph = new Graph(number);

                printf("Podaj gestosc grafu: [%c]\n", 37);
                std::cin >> number;

                graph->generateGraphIndirected(number);

                graph->fillAdjacencyListIndirected();
                graph->fillAdjacencyMatrixIndirected();
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

                    
                    printf("Macierz sasiedztwa:\n");

                    interval = 0;
                    QueryPerformanceFrequency(&frequency);
                    QueryPerformanceCounter(&start);

                    graph->primAlgorithmAdjacencyMatrix();

                    QueryPerformanceCounter(&end);
                    interval = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

                    printf("Czas realizacji algorytmu wyniosl: %f\n", interval);
                    graph->printMST();

                    if (graph != NULL)
                    {
                        printf("Usuwanie grafu...\n");
                        graph->~Graph();
                        graph = NULL;
                    }
                    
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

        while (true)
        {
            printf("Problem znajdowania najkrotszych sciezek w grafie\n");
            printf("1. Wczytaj dane z pliku\n");
            printf("2. Wygeneruj graf losowo\n");
            printf("3. Wyswietl graf listowo i macierzowo\n");
            printf("4. Algorytm Dijkstry\n");
            printf("5. Algorytm Bellmana - Forda\n");
            printf("6. Przejdz do glownego menu\n");

            std::cin >> number;
            if (number == 1)
            {
                if (graph != NULL)
                {
                    printf("Usuwanie grafu...\n");
                    graph->~Graph();
                    graph = NULL;
                }

                printf("Wczytywanie danych z pliku...\n");

                inputDataFile.open("input_data.txt", std::ios::out | std::ios::in);

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

                    graph->fillAdjacencyMatrixDirected();
                    graph->fillAdjacencyListDirected();
                }
            }
            else if (number == 2)
            {
                if (graph != NULL)
                {
                    printf("Usuwanie grafu...\n");
                    graph->~Graph();
                    graph = NULL;
                }

                printf("Podaj liczbe wierzcholkow:\n");
                std::cin >> number;

                graph = new Graph(number);

                printf("Podaj gestosc grafu: [%c]\n", 37);
                std::cin >> number;

                graph->generateGraphDirected(number);

                graph->fillAdjacencyListDirected();
                graph->fillAdjacencyMatrixDirected();
            }
            else if (number == 3)
            {
            if (graph != NULL)
            {
                graph->printAdjacencyMatrix();
                graph->printAdjacencyList();
            }

            else
                printf("Graf pusty!\n");

            }
            else if (number == 4)
            {
                if(graph != NULL)
                {
                    graph->dijkstraAlgorithmAdjacencyMatrix();
                    printf("Macierz sasiedztwa:\n");
                    graph->printShortestPaths();      
                    graph->dijkstraAlgorithmAdjacencyList();
                    printf("Lista sasiedztwa:\n");
                    graph->printShortestPaths();
                }
                else
                {
                    printf("Graf pusty!\n");
                }
            }
            else if (number == 5)
            {

            }
            else if (number == 6)
            {
                if (graph != NULL)
                {
                    graph->~Graph();
                    graph = NULL;
                } 
                break;
            }
        }
    }

    else if (number == 3)
    {       
        
        printf("Podaj algorytm do testowania:\n");
        printf("1. Algorytm Prima\n");
        printf("2. Algorytm Dijkstry\n");
        std::cin >> number;
        if (number == 1)
        {
            printf("Podaj liczbe powtorzen:\n");
            std::cin >> number2;
            printf("Podaj liczbe wierzcholkow:\n");
            std::cin >> number3;
            printf("Podaj gestosc grafu: [%c]\n", 37);
            std::cin >> number4;

            double sum1 = 0;
            double sum2 = 0;

            for (int i = 0; i < number2; i++)
            {
                graph = new Graph(number3);
                graph->generateGraphIndirected(number4);
                graph->fillAdjacencyListIndirected();
                graph->fillAdjacencyMatrixIndirected();

                double interval1 = 0;
                QueryPerformanceFrequency(&frequency);
                QueryPerformanceCounter(&start);

                graph->primAlgorithmAdjacencyList();

                QueryPerformanceCounter(&end);
                interval1 = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart; 

                sum1 = sum1 + interval1;

                double interval2 = 0;
                QueryPerformanceFrequency(&frequency);
                QueryPerformanceCounter(&start);

                graph->primAlgorithmAdjacencyMatrix();

                QueryPerformanceCounter(&end);
                interval2 = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

                sum2 = sum2 + interval2;

                if (graph != NULL)
                {
                    printf("Usuwanie grafu...\n");
                    graph->~Graph();
                    graph = NULL;
                }
            }

            printf("Czas lista sasiedztwa: %f\nCzas macierz sasiedztwa: %f\n", sum1, sum2);
        }
        else if (number == 2)
        {
            printf("Podaj liczbe powtorzen:\n");
            std::cin >> number2;
            printf("Podaj liczbe wierzcholkow:\n");
            std::cin >> number3;
            printf("Podaj gestosc grafu: [%c]\n", 37);
            std::cin >> number4;

            for (int i = 0; i < number2; i++)
            {
                graph = new Graph(number3);
                graph->generateGraphDirected(number4);
                graph->fillAdjacencyListDirected();
                graph->fillAdjacencyMatrixDirected();

                printf("Lista sasiedztwa:\n");
                graph->dijkstraAlgorithmAdjacencyList();
                graph->printShortestPaths();
                printf("Macierz sasiedztwa:\n");
                graph->dijkstraAlgorithmAdjacencyMatrix();
                graph->printShortestPaths();
                if (graph != NULL)
                {
                    printf("Usuwanie grafu...\n");
                    graph->~Graph();
                    graph = NULL;
                }
            }
        }
        
    }
    

    if (graph != NULL)
    {
        graph->~Graph();
    }

    return 0;
}

