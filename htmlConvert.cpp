#include <fstream>
#include <iostream>
#include <cassert>

using namespace std;

main (){
	ifstream instream;										//create input stream
	ofstream outstream;										//create output stream
	char next;	
	string userFile;						
	
	cout << "Which file do you want to modify?:";			//User define file
	cin >> userFile;
	instream.open(userFile.c_str());								//open local example file
	outstream.open("outputHTML.txt");						//write to file and if not exist create the file named outputHTML
	outstream.write("<PRE>",5);								//HTML header
	if (instream.fail()){									//if no local file exist
		cout << "File open failed.\n";						//print message
		exit(1);											//exit program
	}
	else{													//if the local file opened
		while((next = instream.get()) != EOF){				//until the end of character
			if(next == '<'){								// if it find the '<' character
				outstream.write("&lt;",4);					//rewrite it as '&lt' to file new file
			}
			else if(next == '>'){							//if it find the '>' character
				outstream.write("&gt;",4);					//rewrite it as '&gt' to file new file
			}
			else{
				outstream << next;							//if dont find either, then write same char to file
			}
		}
		outstream.write("</PRE>",6);						//HTML footer
		cout << "File modification completed!";				//print message
	}
	instream.close();										//close
	outstream.close();										//close
}
