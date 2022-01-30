#include<bits/stdc++.h>
using namespace std;

class Item{
	private:
		char *name;
		int *price;
		int *quantity;
		int *rating;
	public:
		Item()
		{
			name=new char[20];
		    price=new int;
			quantity=new int;
			rating=new int;
		}
		void addNewItem();
		void buyItem();
        bool searchByName(char na[20]);
		void showItems();
		bool isPopularItem();

};
void Item::addNewItem()
{
	cin.ignore();
	cout<<"\n                                            Enter Name of an item: ";
	cin.getline(name,20);
	cout<<"\n                                            Enter price of an item: ";
	cin>>*price;
	cout<<"\n                                            Enter quantity : ";
	cin>>*quantity;
	cout<<"\n                                            Enter rating of an item out of 5: ";
	cin>>*rating;

}


bool Item::searchByName(char na[20])
{
	if(strcmp(na,name)==0)
	return true;

	else
	return false;
}
void Item::showItems()
{
    cout<<"\n                                             Name: "<<name<<endl;
	cout<<"                                               Price: "<<*price<<endl;
	cout<<"                                               Quantity available: "<<*quantity<<endl;
	cout<<"                                               Rating out of 5: "<<*rating<<endl;
}
bool Item::isPopularItem()
{
	if(*rating>=4)
	return true;

	else
	return false;
}
void Item::buyItem()
{
	int money,q;

	cout<<"\n                                                          No. of dishes available: "<<*quantity;
	cout<<"\n                                                          How many dishes to buy? ";cin>>q;
	cout<<"\n                                                          Amount to be paid: "<<(*price)*q<<"\n";
	cout<<"                                                            Please pay the amount : ";cin>>money;
    int extraMoney;
    extraMoney=money-(*price)*q;
    if(money>(*price)*q)
        cout<<"\n                                                      Please take "<<extraMoney<<"that you paid extra!";
	if(money>=((*price)*q) && *quantity!=0)
	{
		cout<<"\n                                                      ------- Item bought!!---------";
		cout<<"\n                                                      -----Details of item bought------\n\n";
		cout<<"                                                         Name: "<<name<<"    "<<"Quantity: "<<q<<"  "<<"Amount paid: "<<money<<endl;
		*quantity=*quantity-q;
	}

	else
	cout<<"\n                                                          Sorry item cannot be bought\n";
}
int main()
{
   Item *I[20];
   cout<<"\n\n\n\n                                                   <--------------------Welcome to GCEK's Canteen-------------------->"<<"\n"<<"\n"<<"\n";

   int i=0,choice,no;
   char order[20];

   while(choice<5)
   {

  	 cout<<"\n                                               1.Add Item";
   	 cout<<"\n                                               2.Buy Item";
     cout<<"\n                                               3.Display all items";
     cout<<"\n                                               4.Display popular Items";
     cout<<"\n                                               5.Exit";
   	 cout<<"\n                                               Enter choice from above: ";
   	 cin>>choice;
   	 switch(choice)
   	 {
   	 	case 1:
   	 		{
   	 			I[i]=new Item;
   	 			I[i]->addNewItem();
   	 			i++;
   	 			break;
			}
		case 2:
			{
				cin.ignore();
				int f=0;
				cout<<"\n                                            Enter name of an item to buy: ";
				cin.getline(order,20);
				for(int t=0;t<i;t++)
				{
					if(I[t]->searchByName(order))
					{
						I[t]->buyItem();
						f=1;
						break;
					}
				}
				if(f==0)cout<<"\n                                 Item not found!!\n";
				break;
			}

		case 3:
			{
				cout<<"\n                                        ----------Items available at canteen:------------\n\n ";
				for(int t=0;t<i;t++)
				{
					I[t]->showItems();
					cout<<"\n";
				}
				break;
			}
		case 4:
			{
				cout<<"\n                                          -----------Popular Items at canteen--------------\n";
				cout<<"\n";
				for(int t=0;t<i;t++)
				{
					if(I[t]->isPopularItem())
					{
						I[t]->showItems();
						cout<<"\n";
					}
				}
				break;
			}
			case 5:
				exit(0);
				break;
			default:
				cout<<"\n\n                                        Enter a valid choice\n";

		}
   }
	return 0;
}
