#include<iostream>
#include<string>
#include<fstream>
void library();

class add{
	public:
	    char bname[10];
        char author[10];
        int qty;
		void addition()
		{
			char ch;
            std::fstream file;
            std::string line;
			file.open("books.txt",std::ios::in|std::ios::out|std::ios::app);
			if(!file.is_open()){
				std::cout<<"file not found";
			}
            std::cout<<"Enter book name:\t";
            std::cin>>bname;
            std::cout<<std::endl;
            while(!file.eof()){
                getline(file,line);
                if (line.find(bname)!= std::string::npos) {
                    std::cout<<"already in the stock"<<std::endl;
                    return;
                }
            }
            std::cout<<"Author name:\t";
            std::cin>>author;
            std::cout<<std::endl;
            std::cout<<"Quantity:\t";
            std::cin>>qty;
            std::cout<<std::endl;

            start:
              std::cout<<"\npress 'y' to continue, 'm' for menu and 'n' to exit\n";
              std::cin>>ch;
              if(ch=='y')
                   addition();
              if(ch=='m')
                  library();
              else if(ch=='n')
                  return;
              else{
                   std::cout<<"Invalid selection"<<std::endl;
                   goto start;
                   }
			file<<bname<<"\t"<<author<<"\t"<<qty<<std::endl;
			file.close();
		}

};
class view_stock:public add
{
	public:
	friend void display();

};
class Search:public view_stock
{
    public:
        char ch,bname[10];
        void searches(){
            std::string line;
            std::ifstream myfile;
            myfile.open("books.txt");

            std::cout<<"Enter the book name that needs to be searched"<<std::endl;
            std::cin>>bname;
            while(!myfile.eof()){
                getline(myfile,line);
                if (line.find(bname)!= std::string::npos) {
                    std::cout<<"Found!"<<std::endl;
                    std::cout<<line<<std::endl;
                }
            }

        start:
              std::cout<<"\npress 'y' to continue, 'm' for menu and 'n' to exit\n";
              std::cin>>ch;
              if(ch=='y')
                   searches();
              if(ch=='m')
                  library();
              else if(ch=='n')
                  return;
              else{
                   std::cout<<"Invalid selection"<<std::endl;
                   goto start;
                   }
        }
};
class issue:public view_stock
{
    public:
        //add a;
        char ch,bname[10];
        //friend void display();
        void issues(){
            std::string line;
            std::ifstream myfile;

            std::cout<<"Enter the book name that needs to be issued"<<std::endl;
            std::cin>>bname;

            myfile.open("books.txt");

            while(!myfile.eof()){
                getline(myfile,line);
                if (line.find(bname)!= std::string::npos) {
                    std::cout<<"Book issued"<<std::endl;

                    std::fstream file;
                    file.open("issue.txt",std::ios::in|std::ios::out|std::ios::app);
                    file<<line<<std::endl;
                    file.close();
                }
            }

        start:
              std::cout<<"\npress 'y' to continue, 'm' for menu and 'n' to exit\n";
              std::cin>>ch;
              if(ch=='y')
                   issues();
              if(ch=='m')
                  library();
              else if(ch=='n')
                  return;
              else{
                   std::cout<<"Invalid selection"<<std::endl;
                   goto start;
                   }
        }
};
class view_issuedbooks
{
 public:
     char ch;
     void issue_stock(){
        std::fstream file;
        file.open("issue.txt",std::ios::in);
        if(file.is_open()){
            std::string line;
            while(getline(file, line)){
                std::cout<< line<< std::endl;
            }
        }

    start:
              std::cout<<"\npress 'm' for menu and 'n' to exit\n";
              std::cin>>ch;
              if(ch=='m')
                  library();
              else if(ch=='n')
                  return;
              else{
                   std::cout<<"Invalid selection"<<std::endl;
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
    std::fstream file;
    file.open("books.txt",std::ios::in);
    if(file.is_open())
    {
        std::string line;
        while(getline(file, line))
        {
            std::cout<< line<< std::endl;
        }
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

	std::cout<<"1. Add Books \n"<<"2. Issue \n"<<"3. View Issued Stock \n"<<"4. Deposition \n"<<"5. View Library Stock \n"<<"6. Searching"<<"7. Exit \n"<<std::endl;
	std::cout<<"Select options"<<std::endl;
	std::cin>>n;
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
		default: std::cout<<"invalid";
	}
}

int main()
{
	library();
	return 0;
}
