#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Header.hpp"
using namespace std;


bool GLOBALWIN = false;
bool PLAYAGAIN = true;


Project::Project(){

}

Project::~Project(){
	
}

void Project::insertVertex(string value){
	
	bool found = false;
	
	for (int i = 0; i < vertices.size(); i++){
		
		if (vertices[i].key == value){
			
			found = true;
			cout << vertices[i].key << "found" << endl;
		}
	}
		
	if (found == false){
			
			vertex v;
			v.key = value;
			v.head = data("GameData.txt",value);
			vertices.push_back(v);
	}
}

void Project::insertEdge(string v1, string v2, int weight){
	
	for (int x = 0; x < vertices.size();x++){
		if (vertices[x].key == v1){
		
			for (int y = 0; y < vertices.size(); y++){
				if(vertices[y].key == v2 && x != y){
					
					adjVertex av;
					av.v = &vertices[y];
					av.weight = weight;
					vertices[x].adjacent.push_back(av);
				
					
				}
			}
		}
	}
}

Choice *Project::data(string file,string room){
	
	Choice *head = new Choice;
	Choice *tmp = new Choice;
	int mastercount = 0;
	
	if (head != nullptr){
		
		string match;
		
		bool fnode = true;
		string str;
		ifstream rfile;
		rfile.open(file);
	
		if (rfile.is_open()){
			
			while (!rfile.eof()){
				
				while (getline(rfile, str)){
					
					stringstream ss(str);
					
					// THIS PARSES LINE INTO USABLE INFO
					int k = 0;
					
					if (fnode == true){
						while (getline(ss,str,'~')){
						
						
							if (k == 0){
								match = str;
							}
							
							if (match == room && k == 1){
								fnode = false;
								head -> choice = stoi(str);
								head -> previous = nullptr;
								head -> next = nullptr;
								tmp -> previous = head;
							}
							
							if (match == room && k == 2){
								head -> message = str;
							}
							
							if (match == room && k == 3){
								head -> sent = str;
								
							}
							
							k++;
						}
						
						
						
					}
					else{
						while (getline(ss,str,'~')){
						
							
							
							if (k == 0){
								match = str;
							}
							
							if (match == room && k == 1){
								mastercount++;
								
								tmp -> next = nullptr;
								tmp -> choice = stoi(str);
							}
							if (match == room && k == 2){
								tmp -> message = str;
							}
							if (match == room && k == 3){
							
								tmp -> sent = str;
								
								Choice *copy = new Choice;
								copy -> choice = tmp -> choice;
								copy -> message = tmp -> message;
								copy -> sent = tmp -> sent;
								
								if (mastercount == 1){
									head -> next = copy;
									copy -> next = nullptr;
								}
								if (mastercount == 2){
									head -> next -> next = copy;
									copy -> next = nullptr;
								}
								if (mastercount == 3){
									head -> next -> next -> next = copy;
									copy -> next = nullptr;
								}
						
								
							}
							
							k++;	
						}
						
					}
					//END PARSE HERE

				}
			}
		} 
		
		else {
			cout << "file not open" << endl;
		}
		
		
		rfile.close();
		
	}
	
		
	

	return head;
	
}

void Project::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        //cout<<vertices[i].key << "-->";
        for(int j = 0; j < vertices[i].adjacent.size(); j++){
			
		
            cout << vertices[i].adjacent[j].v->key<<"***";
      
        }
        cout<<endl;
	}
	
}

void Project::Menu(){
	
	cout << "==================================" << endl;
	cout << "QQQQQQ  UU  UU EEEEE SSSSS  TTTTTT" << endl;
	cout << "QQ  QQ  UU  UU EE    SS       TT  " << endl;
	cout << "QQ  QQ  UU  UU EEEE    S      TT  " << endl;
	cout << "QQ  QQ  UU  UU EE       SS    TT  " << endl;
	cout << "QQQQQQQ UUUUUU EEEEE SSSSS    TT  " << endl;
	
	cout << "==================================" << endl;
	cout << "Please Select an option" << endl;
	cout << "1. Begin Adventure" << endl;
	cout << "2. Lil bit of info for ya" << endl;
	cout << "3. Quit" << endl;
	cout << "==================================" << endl;

	
}

void Project::start(){
	
	int option = -1;
	
	cout << "=====================================================================================================================================" << endl;
	cout << "You begin your adventure on a small plane over Norway. You are headed to Oslo for a nice vacation when suddenly one of the engines on your plane gives out! The plane spirals down toward a magical Norweigan jungle where you crash. You awake several hours later and find that you are indeed stuck in a jungle. Attempt to make it back to Oslo in the most obscure way possible." << endl;
	cout << "=====================================================================================================================================" << endl;
	
	cout << "Please Select an option" << endl;
	cout << "1. Leave" << endl;
	cout << "2. Search Plane" << endl;
	cout << "3. Sleep" << endl;
	
	while ((option) <=0 || (option) >= 4){
		cin >> option;
		 
	}
	
	string condition;
	string tonext;
	
	if (option == 1){
		tonext = vertices[0].head -> sent;
		cout << "=====================================================================================================================================" << endl;
		cout << vertices[0].head -> message << endl;
		cout << "=====================================================================================================================================" << endl;
	}
	if (option == 2){
		tonext = vertices[0].head -> next -> sent;
		cout << "=====================================================================================================================================" << endl;
		cout << vertices[0].head -> next -> message << endl;
		cout << "=====================================================================================================================================" << endl;
	}
	if (option == 3){
		tonext = vertices[0].head -> next -> next -> sent;
		cout << "=====================================================================================================================================" << endl;
		cout << vertices[0].head -> next -> next -> message << endl;
		cout << "=====================================================================================================================================" << endl;
	}
		
	
	cout << "CAW" << endl;
	cout << vertices[7].head -> sent << endl;
	
	string blah;
	
	condition = move(tonext);
		
	
	
	
	//MASTER LOOP
	
	if (condition != "END"){
		while (condition != "brack"){	
		
		condition = move(condition);
		if (condition == "END")
			break;
		if (condition == "WIN")
			break;
		
	
		}
	}
	
	//END MASTER LOOP
	
	if (condition == "END"){
		cout << "LL    OOOOOO SSSSS EEEEE" << endl;
		cout << "LL    OO  OO SS    EE   "<< endl;
		cout << "LL    OO  OO   S   EEEE " << endl;
		cout << "LL    OO  OO    SS EE   " << endl;
		cout << "LLLLL OOOOOO SSSSS EEEEE" << endl;
	}
	if (condition == "WIN"){
		cout << "WW       WW  IIII  NN   NN "<< endl;
		cout << " WW     WW    II   NNN  NN  "<< endl;
		cout << "  WW W WW     II   NN N NN  " << endl;
		cout << "   WW WW     IIII  NN  NNN  " << endl;
	}
	
	cout << " ==============================================================" << endl;
	cout << "PLAY AGAIN?" << endl;
	cout << "1. YES" << endl;
	cout << "2. NO" << endl;
	
	int hi = -1;
	
	cin >> hi;
	
	if (hi == 2)
		PLAYAGAIN = false;

}

string Project::move(string send){
	
	int option = -1;
	string REE;
	
	//SURVIVOR
	if (send == "Survivor"){
		
		
		cout << "Please Select an option" << endl;
		cout << "1. Ditch the Survivor" << endl;
		cout << "2. Free the Survivor" << endl;
		
		while ((option) <=0 || (option) >= 3){
			cin >> option;
		 
		}
	
		if (option == 1){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[7].head -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[7].head -> sent;
		}
		
		else if (option == 2){
			
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[7].head -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[7].head -> next -> sent;
		}
		
		
	}
	
	//CATS
	else if (send == "Cats"){
		
		cout << "Please Select an option" << endl;
		cout << "1. Fight those pussies" << endl;
		cout << "2. Assimilate" << endl;
		cout << "3. Steal a Kitten" << endl;
		cout << "4. RUN" << endl;
		
		while ((option) <=0 || (option) >= 5){
			cin >> option;
		 
		}
		
		if (option == 1){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[2].head -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[2].head -> sent;
		}
		
		else if (option == 2){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[2].head -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[2].head -> next -> sent;
		}
		
		else if (option == 3){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[2].head -> next -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[2].head -> next -> next -> sent;
		}
		
		else if (option == 4){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[2].head -> next -> next -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[2].head -> next -> next -> next -> sent;
		}
	
	
	}
	
	//CORNER
	else if (send == "Corner"){
		
		cout << "Please Select an option" << endl;
		cout << "1. Defend your newfound Kitten Friend" << endl;
		cout << "2. Return the stolen kitten" << endl;
		
		
		while ((option) <=0 || (option) >= 3){
			cin >> option;
		 
		}
		
		if (option == 1){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[3].head -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[3].head -> sent;
			cout << REE << endl;
			return "i";
		}
		
		else if (option == 2){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[3].head -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[3].head -> next -> sent;
			return "i";
		}
		
	}
	
	//TREE
	else if (send == "Tree"){
		
		cout << "Please Select an option" << endl;
		cout << "1. Head South" << endl;
		cout << "2. Head East" << endl;
		cout << "3. Head West" << endl;
		cout << "4. Head North" << endl;
		
		while ((option) <=0 || (option) >= 5){
			cin >> option;
		 
		}
		
		if (option == 1){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[1].head -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[1].head -> sent;
		}
		
		else if (option == 2){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[1].head -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[1].head -> next -> sent;
		}
		
		else if (option == 3){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[1].head -> next -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[1].head -> next -> next -> sent;
		}
		
		else if (option == 4){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[1].head -> next -> next -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[1].head -> next -> next -> next -> sent;
		}
	}
	
	//STARBUCKS
	else if (send == "Starbucks"){
		
		cout << "Please Select an option" << endl;
		cout << "1. WOof Once" << endl;
		cout << "2. WooF twice" << endl;
		cout << "3. Three WoOFS!" << endl;
		
		while ((option) <=0 || (option) >= 4){
			cin >> option;
		 
		}
		
		if (option == 1){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[4].head -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[4].head -> sent;
		}
		
		else if (option == 2){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[4].head -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[4].head -> next -> sent;
		}
		
		else if (option == 3){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[4].head -> next -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[4].head -> next -> next -> sent;
		}
	
	}
	
	//Pasture
	else if (send == "Pasture"){
		
		cout << "Please Select an option" << endl;
		cout << "1. This is weird. Go back to the jungle" << endl;
		cout << "2. Pet a nice cow friend" << endl;
		cout << "3. Drink the cow's milk. That's not nice" << endl;
		
		while ((option) <=0 || (option) >= 4){
			cin >> option;
		 
		}
		
		if (option == 1){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[5].head -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[5].head -> sent;
		}
		
		else if (option == 2){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[5].head -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[5].head -> next -> sent;
		}
		
		else if (option == 3){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[5].head -> next -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[5].head -> next -> next -> sent;
		}
	
	}
	
	//BURIAL
	else if (send == "Burial"){
		
		cout << "Please Select an option" << endl;
		cout << "1. Leave" << endl;
		cout << "2. Fight the spooky Ghost" << endl;
		cout << "3. Ask to play a game" << endl;
		cout << "4. Become a ghost slave. Why not" << endl;
		
		while ((option) <=0 || (option) >= 5){
			cin >> option;
		 
		}
		
		if (option == 1){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[6].head -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[2].head -> sent;
		}
		
		else if (option == 2){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[6].head -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[7].head -> next -> sent;
		}
		
		else if (option == 3){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[6].head -> next -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			
			cout << "The question is, Which of the following is not a line of IKEA Furniture?" << endl;
			cout << "1. KULLEN" << endl;
			cout << "2. VÄRGBÄ" << endl;
			cout << "3. VÄDDÖ" << endl;
			cout << "4. FLÖNG" << endl;
			cout << "5. These are Swedish, Not Norweigan" << endl;
			
			int option2 = -1;
			
			while ((option2) <=0 || (option) >= 6){
			cin >> option2;
		 
			}
			
			if (option2 != 2){
				cout << "HE DOES NOT LIKE YOUR ANSWER" << endl;
				return "END";
			}
			
			else{
				cout << "CORRECT! GOOD JOB. HERE IS A SCROLL FOR THE TROUBLE. I'M GOING TO SEND  YOU TO A CAT VILLAGE NOW FOR NO SPECIFIC REASON." << endl; 
				GLOBALWIN = true;
				REE = vertices[6].head -> next -> next -> sent;
			}
		}
		
		else if (option == 4){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[6].head -> next -> next -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[6].head -> next -> next -> next -> sent;
		}
	}
	//Endish
	else if (send == "Endish"){
		
		cout << "Please Select an option" << endl;
		cout << "1. Plead for forgiveness. Pathetic" << endl;
		cout << "2. Apoligize, but not sincerely" << endl;
		
		
		while ((option) <=0 || (option) >= 3){
			cin >> option;
		 
		}
		
		if (option == 1){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[8].head -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[8].head -> sent;
		}
		
		else if (option == 2){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[8].head -> next -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[8].head -> next -> sent;
		}
		
	}
	//Door
	else if (send == "Door"){
		
		cout << "Please Select an option" << endl;
		cout << "1. Open the door You're next to I guess" << endl;
		cout << "2. Use a scroll! If you have it" << endl;
		
		
		while ((option) <=0 || (option) >= 3){
			cin >> option;
		 
		}
		
		if (option == 2){
			
			if (GLOBALWIN == false){
				cout << "YOU HAVE NO SCROLL AND NO FUTURE, IMMEDIATELY LOSE." << endl;
				return "END";
			}
			
			else{
				cout << "=====================================================================================================================================" << endl;
				cout << vertices[9].head -> next -> message << endl;
				cout << "=====================================================================================================================================" << endl;
				REE = vertices[9].head -> next -> sent;
			}
		}
		
		else if (option == 1){
			cout << "=====================================================================================================================================" << endl;
			cout << vertices[9].head -> message << endl;
			cout << "=====================================================================================================================================" << endl;
			REE = vertices[9].head -> sent;
		}
		
	}
	
	return REE;
		
	
}

int main(){
	
	Project obj1;
	
	
	
	
	obj1.insertVertex("Plane");
	obj1.insertVertex("Tree");
	obj1.insertVertex("Cats");
	obj1.insertVertex("Corner");
	obj1.insertVertex("Starbucks");
	obj1.insertVertex("Pasture");
	obj1.insertVertex("Burial");
	obj1.insertVertex("Survivor");
	obj1.insertVertex("Endish");
	obj1.insertVertex("Door");
	
	obj1.insertEdge("Plane","Tree",1);
	obj1.insertEdge("Plane","Cats",1000);
	obj1.insertEdge("Plane","Survivor",100);
	
	obj1.insertEdge("Tree","Cats",30);
	obj1.insertEdge("Tree","Starbucks",10);
	obj1.insertEdge("Tree","Pasture",10);
	obj1.insertEdge("Tree","Burial",15);
	
	obj1.insertEdge("Pasture","Burial",5);
	obj1.insertEdge("Burial","Cats",1);
	
	obj1.insertEdge("Cats","Corner",40);
	obj1.insertEdge("Cats","Endish",1);
	
	obj1.insertEdge("Endish","Door",1);
	
	while (PLAYAGAIN == true){
		
		if (PLAYAGAIN == false){
			break;
		}
		obj1.Menu();
		
		int select = -1;
		
		while (select <=0 || select >=4){
		
			cin >> select;
			
			if (select == 1)
				obj1.start();
			
			if (select == 2){
				cout << "=======================================================================================" << endl;
				cout << " JOHN PHILLIPS CSCI 2270" << endl;
				cout << " FOR AUSTIN HOLLER'S CLASS M-T 1-2:20" << endl;
				cout << "=======================================================================================" << endl;
			}
			if (select == 3){
				PLAYAGAIN = false;
				break;
			}
		}
		
		
	}
	
	cout << "GOODBYE FREN" << endl;
	
	
	//obj1.displayEdges();
	
	
	
	
	return 0;
	
}
