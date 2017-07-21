# Phillips_CSCI2270_FinalProject
CSCI 2270 final project

Project Idea: Travel Simulator: Country

Technical Requirements:
Class: Main class program that will hold the functions for navigating the simulator, holding values that you input, keeping track of your progress, etc...

Graph: Each step of the sim will be a vertices. Each step of the simulator will be adjacent vertices. Each college career path will have different values in the graph.

Each point in the graph will have a connected linked list that will hold text information for that specific step.
Ie the starting point will hold  a list that hold the first three available options
===============
You've landed in Mongilia Where wil you head nex
nullptr < AreaInfo <> Choice1 <> choice2 <> choice3 > nullptr
===============

Public methods: used to traverse the graph/linked lists
Hold information about your decisions

The simulator will have you choose decisions based on each previous decision you have made. The edges between vertices
will hold values that correspond to how good your choice was. Reaching the end of the graph will be considered a "victory" where your score will be compared to the lowest possible score. The lowest possible score will be found using dijkstras algorithm. You'll have an option after playing of being taken through the best case scenario.
