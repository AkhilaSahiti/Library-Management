#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void library();

class add{
	public:
		char bname[10];
       		char author[10];
        	int qty;
		void addition()
		{
			char ch;
            		fstream file;
            		string line;
			file.open("books.txt",ios::in|ios::out|ios::app);
			if(!file.is_open()){
				cout<<"file not found";
			}
            		cout<<"Enter book name:\t";
            		cin>>bname;
            		cout<<endl;
            		/*while(!file.eof()){
                		getline(file,line);    //istream& getline (istream& is, string& str);
                		if (line.find(bname)!= string::npos) {  //std::string::npos means not found, npos=-1
                    			cout<<"already in the stock"<<endl;
                    			goto start;
                		}
            		}*/
            		cout<<"Author name:\t";
            		cin>>author;
            		cout<<endl;
            		cout<<"Quantity:\t";
            		cin>>qty;
            		cout<<endl;

            		start:
              			cout<<"\npress 'y' to continue, 'm' for menu and 'n' to exit\n";
              			cin>>ch;
              			if(ch=='y')
                   			addition();
              			if(ch=='m')
                  			library();
              			else if(ch=='n')
                  			return;
              			else{
                   			cout<<"Invalid selection"<<endl;
                   			goto start;
                   		}
				file<<bname<<"\t"<<author<<"\t"<<qty<<endl;
				file.close();
			}

};
class view_stock//:public add
{
	public:
	friend void display();

};
class Search//:public view_stock
{
    public:
    	char ch,bname[10];
        void searches(){
    	    string line;
            ifstream myfile;
            myfile.open("books.txt");

            cout<<"Enter the book name that needs to be searched"<<endl;
            cin>>bname;
            while(!myfile.eof()){
                getline(myfile,line);
                if (line.find(bname)!= string::npos) {
                    cout<<"Found!"<<endl;
                    cout<<line<<endl;
                    break;
                }
            }

        start:
              cout<<"\npress 'y' to continue, 'm' for menu and 'n' to exit\n";
              cin>>ch;
              if(ch=='y')
                   searches();
              if(ch=='m')
                  library();
              else if(ch=='n')
                  return;
              else{
                   cout<<"Invalid selection"<<endl;
                   goto start;
                   }
        }
};
class issue//:public view_stock
{
    public:
        //add a;
        char ch,bname[10];
        //friend void display();
        void issues(){
            string line;
            ifstream myfile;

            cout<<"Enter the book name that needs to be issued"<<endl;
            cin>>bname;

            myfile.open("books.txt");

            while(!myfile.eof()){
                getline(myfile,line);
                if (line.find(bname)!= string::npos) {
                    cout<<"Book issued"<<endl;

                    fstream file;
                    file.open("issue.txt",ios::in|ios::out|ios::app);
                    file<<line<<std::endl;
                    file.close();
                }
            }

        start:
              cout<<"\npress 'y' to continue, 'm' for menu and 'n' to exit\n";
              cin>>ch;
              if(ch=='y')
                   issues();
              if(ch=='m')
                  library();
              else if(ch=='n')
                  return;
              else{
                   cout<<"Invalid selection"<<endl;
                   goto start;
                   }
        }
};
class view_issuedbooks
{
 public:
     char ch;
     void issue_stock(){
        fstream file;
        file.open("issue.txt",ios::in);
        if(file.is_open()){
            string line;
            while(getline(file, line)){
                cout<< line<< endl;
            }
        }

    start:
              cout<<"\npress 'm' for menu and 'n' to exit\n";
              cin>>ch;
              if(ch=='m')
                  library();
              else if(ch=='n')
                  return;
              else{
                   cout<<"Invalid selection"<<endl;
                   goto start;
                   }
     }
};
class deposit:public add
{
    public:
        void deposits(){
            add a;
            a.addition();
        }
};
void display()
{
    char ch;
    fstream file;
    file.open("books.txt",ios::in);
    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            cout<< line<< endl;
        }
    }
    start:
              cout<<"\npress 'm' for menu and 'n' to exit\n";
              cin>>ch;
              if(ch=='m')
                  library();
              else if(ch=='n')
                  return;
              else{
                   cout<<"Invalid selection"<<endl;
                   goto start;
                   }
    
}


void library(){
    int n;
	add a;
	issue i;
	view_issuedbooks vi;
	//view_stock v;
	Search s;
	deposit d;

	cout<<"1. Add Books \n"<<"2. Issue \n"<<"3. View Issued Stock \n"<<"4. Deposition \n"<<"5. View Library Stock \n"<<"6. Searching \n"<<"7. Exit \n"<<endl;
	cout<<"Select options"<<endl;
	cin>>n;
	switch(n)
	{
		case 1: a.addition(); //add books
		break;
		case 2: i.issues();  //issue
		break;
		case 3: vi.issue_stock();
		break;
		case 4: d.deposits();
		break;
		case 5: display();
        break;
		case 6: s.searches();
		break;
		case 7: return;
		break;
		default: cout<<"invalid";
	}
}

int main()
{
	library();
	return 0;
}
