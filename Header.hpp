#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Choice{
	
		Choice* next;
		Choice* previous;
		
		int choice;
		string message;
		string sent;
	
	};
struct vertex;

struct adjVertex{
	
	vertex *v;
	int weight;
	
};

struct vertex{
	
	string key;
	
	Choice *head;
	
	vector <adjVertex> adjacent;
};



class Project{
	
	public:
		
		Project();
		~Project();
		
		void insertVertex(string);
		void insertEdge(string, string, int);
		void displayEdges();
		
		void Menu();
		Choice *data(string,string);
	
		void start();
		string move(string);
	
	private:
		
		vector <vertex> vertices;
	
	
	
};
